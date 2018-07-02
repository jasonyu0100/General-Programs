Public Class RegistrationForm

    Public userIDDB As New DataTable("User IDs") 'Where the users are stored
    Public foodMenuDB As New DataTable("Food Menu") 'Where food is stored
    Public currUser As Person 'Current User that is selected

    Private Sub ImportUsersToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ImportUsersToolStripMenuItem.Click
        'Imports users 
        Dim openFileDialog1 As New OpenFileDialog()
        openFileDialog1.Filter = "CSV Files|*.csv"
        openFileDialog1.Title = "Select a CSV file"
        'Open file dialoge
        If openFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
            'If file dialogue is entered
            'Read file and create a database
            Dim values() As String
            userIDDB.Columns.AddRange({New DataColumn("idNumber"),
                                      New DataColumn("fName"),
                                      New DataColumn("lName"),
                                      New DataColumn("paymentDetails")})
            For Each line As String In IO.File.ReadAllLines(openFileDialog1.FileName, System.Text.Encoding.Default)
                values = line.Split(",")
                If values.Length = 4 Then
                    'Check if row is valid
                    userIDDB.Rows.Add(values)
                End If
            Next
            'Updates status
            statusStripMenu.Text = ""
        End If

    End Sub

    Private Sub txtBarcodeID_TextChanged(sender As Object, e As EventArgs) Handles txtBarcodeID.TextChanged
        Dim found As Boolean = False
        If txtBarcodeID.Text.Length = 10 Then
            'Checks barcode length and if 10 executes
            For Each row As DataRow In userIDDB.Rows
                'Checks everyrow for id
                If txtBarcodeID.Text = row.Item("idNumber") Then
                    'Edits name in status strip
                    user.Text = row.Item("fName") & row.Item("lName")
                    currUser = New Person(row.Item("fname") & row.Item("lname"), row.Item("idNumber"), row.Item("paymentDetails"))
                    found = True
                    Exit For
                End If
            Next
            If found = False Then
                'Shows that user id doesn't exist
                MsgBox("User Id:" & txtBarcodeID.Text & "Was not found")
                statusStripMenu.Text = "User" & txtBarcodeID.Text & "does not exist."
            End If
            'Resets Text Input
            txtBarcodeID.Text = ""
            Me.logToFoodMenu()
        End If

    End Sub

    Private Sub ImportMenuToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ImportMenuToolStripMenuItem.Click
        'Imports database 
        Dim openFileDialog1 As New OpenFileDialog()
        openFileDialog1.Filter = "CSV Files|*.csv"
        openFileDialog1.Title = "Select a CSV file"
        'Open file dialoge
        If openFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
            foodMenuDB.Columns.AddRange({
               New DataColumn("name"),
               New DataColumn("price"),
               New DataColumn("category"),
               New DataColumn("description"),
               New DataColumn("imageName")
            })
            For Each line As String In IO.File.ReadAllLines(openFileDialog1.FileName, System.Text.Encoding.Default)
                Dim values = line.Split(",")
                If values.Length = 5 Then
                    foodMenuDB.Rows.Add(values)
                End If
                'TODO update status strip

            Next
        End If
    End Sub

    Private Sub logToFoodMenu()
        FoodMenu.Show()
        FoodMenu.foodMenuDB = Me.foodMenuDB
        FoodMenu.currentUser = Me.currUser
        FoodMenu.LoadFoodMenu()
        Me.Hide()

    End Sub

    Function getCSVFile(filePath As String)
        Return My.Computer.FileSystem.OpenTextFileWriter(filePath, True)
    End Function

    Private Sub addToCSVFile(file As System.IO.StreamWriter, csvLine As String())
        Dim line As String = String.Join(",", csvLine)
        MsgBox(line)
        file.WriteLine(line)
        file.Close()
    End Sub

    Function verifyID()
        'verify id length
        Return False
    End Function

    Function checkduplicates()
        'Check for duplicates in database
        Return False
    End Function

    Private Sub RegisterUserButton_Click(sender As Object, e As EventArgs) Handles RegisterUserButton.Click
        Dim idNumber As String = ID.Text
        Dim first As String = FirstName.Text
        Dim last As String = LastName.Text
        Dim payment As String = PaymentNumber.Text
        If Not idNumber.Length = 10 Then
            MsgBox("Please enter an ID of length 10.")
            ID.Text = ""
        Else
            Dim found = False
            For Each row As DataRow In userIDDB.Rows
                If ID = row.Item("idNumber") Then
                    found = True
                    Exit For
                End If
            Next
            If found = False Then
                Dim filePath As String = "\\SR8137CF01-FS02\StudentUsers\2019\432518663\Desktop\Project\Database\users.csv"
                Dim file As System.IO.StreamWriter = Me.getCSVFile(filePath)
                Dim csvLine As String() = {idNumber, first, last, payment}
                Me.addToCSVFile(file, csvLine)
                MsgBox("User ID: " & idNumber & " has been registered into database.")
            Else
                MsgBox("User ID: " & idNumber & " is already in database. Please select a unique ID.")
            End If
        End If
    End Sub

    Private Sub ImageUploadButton_Click(sender As Object, e As EventArgs) Handles ImageUploadButton.Click
        Dim openFileDialog1 As New OpenFileDialog()
        openFileDialog1.Filter = "Food Image|*.jpg"
        openFileDialog1.Title = "Select a jpg file"
        'Open file dialoge
        If openFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
            FoodImage.ImageLocation = openFileDialog1.FileName
        End If
    End Sub

    Function verifyPrice(price As String)
        Dim check As Boolean
        If price.Length = 0 Then
            MsgBox("Please enter a price")
            Return False
        ElseIf price.Chars(0) = "$" Then
            check = IsNumeric(price.Substring(1, price.Length - 1))
        Else
            check = IsNumeric(price)
        End If
        If check = False Then
            MsgBox("Please enter a valid number format")
        End If
        Return check
    End Function

    Function getPrice(price As String)
        If price.Chars(0) = "$" Then
            Return Convert.ToDecimal(price.Substring(1, price.Length - 1))
        Else
            Return Convert.ToDecimal(price)
        End If
    End Function


    Private Sub RegisterFoodButton_Click(sender As Object, e As EventArgs) Handles RegisterFoodButton.Click
        Dim name As String = FoodName.Text
        Dim priceVerification As Boolean = Me.verifyPrice(FoodPrice.Text)
        Dim category As String = FoodCategory.Text
        Dim description As String = FoodDescription.Text
        Dim imagePath As String = FoodImage.ImageLocation
        If priceVerification = True Then
            Dim priceValue As Decimal = Me.getPrice(FoodPrice.Text)
            Dim filePath As String = "\\SR8137CF01-FS02\StudentUsers\2019\432518663\Desktop\Project\Database\food.csv"
            Dim file As System.IO.StreamWriter = Me.getCSVFile(filePath)
            Dim csvLine As String() = {name, priceValue, category, description, imagePath}
            Me.addToCSVFile(file, csvLine)
            MsgBox("Food Item: " & name & " has been registered into database.")
        Else
            MsgBox("Registration of Food Item " & name & " could not be completed")
        End If
    End Sub
End Class
