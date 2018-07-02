Public Class FoodMenu
    Public foodMenuDB As DataTable
    Public currentUser As Person

    Private Sub SubmitOrderButton_Click(sender As Object, e As EventArgs) Handles SubmitOrderButton.Click
        'Submits Order to orders folder
        Dim file As System.IO.StreamWriter
        Dim todaysdate As String = String.Format("{0:dd-MM-yyyy}", DateTime.Now)
        file = My.Computer.FileSystem.OpenTextFileWriter("\\SR8137CF01-FS02\StudentUsers\2019\432518663\Desktop\Project\Database\orders\order" & todaysdate & ".txt", True)
        file.WriteLine("Test")
        file.Close()
    End Sub

    Private Sub Button2_MouseClick(sender As Object, e As MouseEventArgs) Handles SubmitOrderButton.MouseClick
        'TO Be deleted
        Dim row = RegistrationForm.foodMenuDB(0)
        Dim ImageName = row.Item("imageName")
        PictureBox1.ImageLocation = "\\SR8137CF01-FS02\StudentUsers\2019\432518663\Desktop\Project\Database\images\" & ImageName
    End Sub

    Private Sub MakeFoodGroup(name As String, price As Double, category As String, description As String, imagePath As String)
        'Makes food group
        Dim foodGroup = New System.Windows.Forms.GroupBox()
        Me.Controls.Add(foodGroup)
        foodGroup.Text = name
        foodGroup.Name = name & "group"
        Dim foodPicture = New System.Windows.Forms.PictureBox()
        Me.Controls.Add(foodPicture)
        foodPicture.ImageLocation = imagePath
        foodPicture.Name = name & "picture"
        foodPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Dim purchaseButton = New System.Windows.Forms.Button()
        Me.Controls.Add(purchaseButton)
        purchaseButton.Text = "$" & System.Convert.ToString(price)
        purchaseButton.Name = name & "button"

        foodGroup.Controls.Add(foodPicture)
        foodGroup.Controls.Add(purchaseButton)

        purchaseButton.Location = New System.Drawing.Point(0, 170)
        purchaseButton.Size = New System.Drawing.Size(30, 30)
        foodPicture.Location = New System.Drawing.Point(0, 20)
        foodPicture.Size = New System.Drawing.Size(150, 150)
        foodGroup.Location = New System.Drawing.Point(0, 0)
        foodGroup.Size = New System.Drawing.Size(200, 200)

        Me.Menu.Controls.Add(foodGroup)

    End Sub

    Public Sub LoadFoodMenu()
        For Each row As DataRow In foodMenuDB.Rows
            Me.MakeFoodGroup(row.Item("name"), row.Item("price"), row.Item("category"), row.Item("description"), row.Item("imageName"))
        Next
    End Sub


    Private Sub FoodMenu_Closed(sender As Object, e As EventArgs) Handles Me.Closed
        RegistrationForm.Show()
        'Save receipt of user
        Me.Hide()
    End Sub

    Private Sub FoodMenu_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub
End Class