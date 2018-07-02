<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class RegistrationForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip()
        Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ImportUsersToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ImportMenuToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.statusStripMenu = New System.Windows.Forms.StatusStrip()
        Me.user = New System.Windows.Forms.ToolStripStatusLabel()
        Me.status = New System.Windows.Forms.ToolStripStatusLabel()
        Me.DataSet1 = New System.Data.DataSet()
        Me.TabControl1 = New System.Windows.Forms.TabControl()
        Me.TabPage1 = New System.Windows.Forms.TabPage()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.txtBarcodeID = New System.Windows.Forms.TextBox()
        Me.TabPage2 = New System.Windows.Forms.TabPage()
        Me.RegisterUserButton = New System.Windows.Forms.Button()
        Me.PaymentNumberGroup = New System.Windows.Forms.GroupBox()
        Me.PaymentNumber = New System.Windows.Forms.TextBox()
        Me.LastNameGroup = New System.Windows.Forms.GroupBox()
        Me.LastName = New System.Windows.Forms.TextBox()
        Me.IDGroup = New System.Windows.Forms.GroupBox()
        Me.ID = New System.Windows.Forms.TextBox()
        Me.FirstNameGroup = New System.Windows.Forms.GroupBox()
        Me.FirstName = New System.Windows.Forms.TextBox()
        Me.TabPage3 = New System.Windows.Forms.TabPage()
        Me.FoodImageGroup = New System.Windows.Forms.GroupBox()
        Me.FoodImage = New System.Windows.Forms.PictureBox()
        Me.ImageUploadButton = New System.Windows.Forms.Button()
        Me.FoodCategoryGroup = New System.Windows.Forms.GroupBox()
        Me.FoodCategory = New System.Windows.Forms.TextBox()
        Me.RegisterFoodButton = New System.Windows.Forms.Button()
        Me.TableLayoutPanel7 = New System.Windows.Forms.TableLayoutPanel()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.FoodDescription = New System.Windows.Forms.TextBox()
        Me.FoodNameGroup = New System.Windows.Forms.GroupBox()
        Me.FoodName = New System.Windows.Forms.TextBox()
        Me.FoodPriceGroup = New System.Windows.Forms.GroupBox()
        Me.FoodPrice = New System.Windows.Forms.TextBox()
        Me.MenuStrip1.SuspendLayout()
        Me.statusStripMenu.SuspendLayout()
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.TabControl1.SuspendLayout()
        Me.TabPage1.SuspendLayout()
        Me.TabPage2.SuspendLayout()
        Me.PaymentNumberGroup.SuspendLayout()
        Me.LastNameGroup.SuspendLayout()
        Me.IDGroup.SuspendLayout()
        Me.FirstNameGroup.SuspendLayout()
        Me.TabPage3.SuspendLayout()
        Me.FoodImageGroup.SuspendLayout()
        CType(Me.FoodImage, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.FoodCategoryGroup.SuspendLayout()
        Me.TableLayoutPanel7.SuspendLayout()
        Me.FoodNameGroup.SuspendLayout()
        Me.FoodPriceGroup.SuspendLayout()
        Me.SuspendLayout()
        '
        'MenuStrip1
        '
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Size = New System.Drawing.Size(612, 24)
        Me.MenuStrip1.TabIndex = 1
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'FileToolStripMenuItem
        '
        Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ImportUsersToolStripMenuItem, Me.ImportMenuToolStripMenuItem})
        Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
        Me.FileToolStripMenuItem.Size = New System.Drawing.Size(37, 20)
        Me.FileToolStripMenuItem.Text = "File"
        '
        'ImportUsersToolStripMenuItem
        '
        Me.ImportUsersToolStripMenuItem.Name = "ImportUsersToolStripMenuItem"
        Me.ImportUsersToolStripMenuItem.Size = New System.Drawing.Size(144, 22)
        Me.ImportUsersToolStripMenuItem.Text = "Import Users"
        '
        'ImportMenuToolStripMenuItem
        '
        Me.ImportMenuToolStripMenuItem.Name = "ImportMenuToolStripMenuItem"
        Me.ImportMenuToolStripMenuItem.Size = New System.Drawing.Size(144, 22)
        Me.ImportMenuToolStripMenuItem.Text = "Import Menu"
        '
        'statusStripMenu
        '
        Me.statusStripMenu.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.user, Me.status})
        Me.statusStripMenu.Location = New System.Drawing.Point(0, 311)
        Me.statusStripMenu.Name = "statusStripMenu"
        Me.statusStripMenu.Size = New System.Drawing.Size(612, 22)
        Me.statusStripMenu.TabIndex = 3
        Me.statusStripMenu.Text = "StatusStrip1"
        '
        'user
        '
        Me.user.Name = "user"
        Me.user.Size = New System.Drawing.Size(73, 17)
        Me.user.Text = "Current User"
        '
        'status
        '
        Me.status.Name = "status"
        Me.status.Size = New System.Drawing.Size(38, 17)
        Me.status.Text = "status"
        '
        'DataSet1
        '
        Me.DataSet1.DataSetName = "NewDataSet"
        '
        'TabControl1
        '
        Me.TabControl1.Controls.Add(Me.TabPage1)
        Me.TabControl1.Controls.Add(Me.TabPage2)
        Me.TabControl1.Controls.Add(Me.TabPage3)
        Me.TabControl1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TabControl1.Location = New System.Drawing.Point(0, 24)
        Me.TabControl1.Name = "TabControl1"
        Me.TabControl1.SelectedIndex = 0
        Me.TabControl1.Size = New System.Drawing.Size(612, 287)
        Me.TabControl1.TabIndex = 9
        '
        'TabPage1
        '
        Me.TabPage1.Controls.Add(Me.Label1)
        Me.TabPage1.Controls.Add(Me.txtBarcodeID)
        Me.TabPage1.Location = New System.Drawing.Point(4, 22)
        Me.TabPage1.Name = "TabPage1"
        Me.TabPage1.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage1.Size = New System.Drawing.Size(604, 261)
        Me.TabPage1.TabIndex = 0
        Me.TabPage1.Text = "User Login"
        Me.TabPage1.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(243, 73)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(122, 31)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Enter ID:"
        '
        'txtBarcodeID
        '
        Me.txtBarcodeID.Location = New System.Drawing.Point(155, 137)
        Me.txtBarcodeID.Multiline = True
        Me.txtBarcodeID.Name = "txtBarcodeID"
        Me.txtBarcodeID.Size = New System.Drawing.Size(308, 38)
        Me.txtBarcodeID.TabIndex = 2
        '
        'TabPage2
        '
        Me.TabPage2.Controls.Add(Me.RegisterUserButton)
        Me.TabPage2.Controls.Add(Me.PaymentNumberGroup)
        Me.TabPage2.Controls.Add(Me.LastNameGroup)
        Me.TabPage2.Controls.Add(Me.IDGroup)
        Me.TabPage2.Controls.Add(Me.FirstNameGroup)
        Me.TabPage2.Location = New System.Drawing.Point(4, 22)
        Me.TabPage2.Name = "TabPage2"
        Me.TabPage2.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage2.Size = New System.Drawing.Size(604, 261)
        Me.TabPage2.TabIndex = 1
        Me.TabPage2.Text = "User Registration"
        Me.TabPage2.UseVisualStyleBackColor = True
        '
        'RegisterUserButton
        '
        Me.RegisterUserButton.Location = New System.Drawing.Point(114, 135)
        Me.RegisterUserButton.Name = "RegisterUserButton"
        Me.RegisterUserButton.Size = New System.Drawing.Size(380, 48)
        Me.RegisterUserButton.TabIndex = 0
        Me.RegisterUserButton.Text = "Register User"
        Me.RegisterUserButton.UseVisualStyleBackColor = True
        '
        'PaymentNumberGroup
        '
        Me.PaymentNumberGroup.Controls.Add(Me.PaymentNumber)
        Me.PaymentNumberGroup.Location = New System.Drawing.Point(409, 12)
        Me.PaymentNumberGroup.Name = "PaymentNumberGroup"
        Me.PaymentNumberGroup.Size = New System.Drawing.Size(187, 67)
        Me.PaymentNumberGroup.TabIndex = 11
        Me.PaymentNumberGroup.TabStop = False
        Me.PaymentNumberGroup.Text = "Payment Number"
        '
        'PaymentNumber
        '
        Me.PaymentNumber.Location = New System.Drawing.Point(14, 19)
        Me.PaymentNumber.Multiline = True
        Me.PaymentNumber.Name = "PaymentNumber"
        Me.PaymentNumber.Size = New System.Drawing.Size(155, 32)
        Me.PaymentNumber.TabIndex = 7
        '
        'LastNameGroup
        '
        Me.LastNameGroup.Controls.Add(Me.LastName)
        Me.LastNameGroup.Location = New System.Drawing.Point(295, 12)
        Me.LastNameGroup.Name = "LastNameGroup"
        Me.LastNameGroup.Size = New System.Drawing.Size(108, 67)
        Me.LastNameGroup.TabIndex = 10
        Me.LastNameGroup.TabStop = False
        Me.LastNameGroup.Text = "Last Name"
        '
        'LastName
        '
        Me.LastName.Location = New System.Drawing.Point(6, 19)
        Me.LastName.Multiline = True
        Me.LastName.Name = "LastName"
        Me.LastName.Size = New System.Drawing.Size(90, 35)
        Me.LastName.TabIndex = 6
        '
        'IDGroup
        '
        Me.IDGroup.Controls.Add(Me.ID)
        Me.IDGroup.Location = New System.Drawing.Point(8, 12)
        Me.IDGroup.Name = "IDGroup"
        Me.IDGroup.Size = New System.Drawing.Size(144, 67)
        Me.IDGroup.TabIndex = 8
        Me.IDGroup.TabStop = False
        Me.IDGroup.Text = "ID"
        '
        'ID
        '
        Me.ID.Location = New System.Drawing.Point(6, 19)
        Me.ID.Multiline = True
        Me.ID.Name = "ID"
        Me.ID.Size = New System.Drawing.Size(132, 32)
        Me.ID.TabIndex = 4
        '
        'FirstNameGroup
        '
        Me.FirstNameGroup.Controls.Add(Me.FirstName)
        Me.FirstNameGroup.Location = New System.Drawing.Point(158, 12)
        Me.FirstNameGroup.Name = "FirstNameGroup"
        Me.FirstNameGroup.Size = New System.Drawing.Size(131, 67)
        Me.FirstNameGroup.TabIndex = 9
        Me.FirstNameGroup.TabStop = False
        Me.FirstNameGroup.Text = "First Name"
        '
        'FirstName
        '
        Me.FirstName.Location = New System.Drawing.Point(6, 19)
        Me.FirstName.Multiline = True
        Me.FirstName.Name = "FirstName"
        Me.FirstName.Size = New System.Drawing.Size(119, 35)
        Me.FirstName.TabIndex = 5
        '
        'TabPage3
        '
        Me.TabPage3.Controls.Add(Me.FoodImageGroup)
        Me.TabPage3.Controls.Add(Me.FoodCategoryGroup)
        Me.TabPage3.Controls.Add(Me.RegisterFoodButton)
        Me.TabPage3.Controls.Add(Me.TableLayoutPanel7)
        Me.TabPage3.Controls.Add(Me.FoodNameGroup)
        Me.TabPage3.Controls.Add(Me.FoodPriceGroup)
        Me.TabPage3.Location = New System.Drawing.Point(4, 22)
        Me.TabPage3.Name = "TabPage3"
        Me.TabPage3.Size = New System.Drawing.Size(604, 261)
        Me.TabPage3.TabIndex = 2
        Me.TabPage3.Text = "Add Food"
        Me.TabPage3.UseVisualStyleBackColor = True
        '
        'FoodImageGroup
        '
        Me.FoodImageGroup.Controls.Add(Me.FoodImage)
        Me.FoodImageGroup.Controls.Add(Me.ImageUploadButton)
        Me.FoodImageGroup.Location = New System.Drawing.Point(366, 3)
        Me.FoodImageGroup.Name = "FoodImageGroup"
        Me.FoodImageGroup.Size = New System.Drawing.Size(230, 173)
        Me.FoodImageGroup.TabIndex = 11
        Me.FoodImageGroup.TabStop = False
        Me.FoodImageGroup.Text = "Image"
        '
        'FoodImage
        '
        Me.FoodImage.Location = New System.Drawing.Point(18, 21)
        Me.FoodImage.Name = "FoodImage"
        Me.FoodImage.Size = New System.Drawing.Size(189, 103)
        Me.FoodImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.FoodImage.TabIndex = 11
        Me.FoodImage.TabStop = False
        '
        'ImageUploadButton
        '
        Me.ImageUploadButton.Location = New System.Drawing.Point(61, 130)
        Me.ImageUploadButton.Name = "ImageUploadButton"
        Me.ImageUploadButton.Size = New System.Drawing.Size(90, 37)
        Me.ImageUploadButton.TabIndex = 10
        Me.ImageUploadButton.Text = "Upload Image"
        Me.ImageUploadButton.UseVisualStyleBackColor = True
        '
        'FoodCategoryGroup
        '
        Me.FoodCategoryGroup.Controls.Add(Me.FoodCategory)
        Me.FoodCategoryGroup.Location = New System.Drawing.Point(244, 3)
        Me.FoodCategoryGroup.Name = "FoodCategoryGroup"
        Me.FoodCategoryGroup.Size = New System.Drawing.Size(116, 100)
        Me.FoodCategoryGroup.TabIndex = 14
        Me.FoodCategoryGroup.TabStop = False
        Me.FoodCategoryGroup.Text = "Category"
        '
        'FoodCategory
        '
        Me.FoodCategory.Location = New System.Drawing.Point(15, 36)
        Me.FoodCategory.Name = "FoodCategory"
        Me.FoodCategory.Size = New System.Drawing.Size(65, 20)
        Me.FoodCategory.TabIndex = 6
        '
        'RegisterFoodButton
        '
        Me.RegisterFoodButton.Location = New System.Drawing.Point(102, 195)
        Me.RegisterFoodButton.Name = "RegisterFoodButton"
        Me.RegisterFoodButton.Size = New System.Drawing.Size(384, 50)
        Me.RegisterFoodButton.TabIndex = 1
        Me.RegisterFoodButton.Text = "Register Item"
        Me.RegisterFoodButton.UseVisualStyleBackColor = True
        '
        'TableLayoutPanel7
        '
        Me.TableLayoutPanel7.ColumnCount = 2
        Me.TableLayoutPanel7.ColumnStyles.Add(New System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25.26042!))
        Me.TableLayoutPanel7.ColumnStyles.Add(New System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 74.73959!))
        Me.TableLayoutPanel7.Controls.Add(Me.Label10, 0, 0)
        Me.TableLayoutPanel7.Controls.Add(Me.FoodDescription, 1, 0)
        Me.TableLayoutPanel7.Location = New System.Drawing.Point(11, 109)
        Me.TableLayoutPanel7.Name = "TableLayoutPanel7"
        Me.TableLayoutPanel7.RowCount = 1
        Me.TableLayoutPanel7.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100.0!))
        Me.TableLayoutPanel7.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 67.0!))
        Me.TableLayoutPanel7.Size = New System.Drawing.Size(349, 67)
        Me.TableLayoutPanel7.TabIndex = 2
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Dock = System.Windows.Forms.DockStyle.Fill
        Me.Label10.Location = New System.Drawing.Point(3, 0)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(82, 67)
        Me.Label10.TabIndex = 8
        Me.Label10.Text = "Description"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'FoodDescription
        '
        Me.FoodDescription.Dock = System.Windows.Forms.DockStyle.Fill
        Me.FoodDescription.Location = New System.Drawing.Point(91, 3)
        Me.FoodDescription.Multiline = True
        Me.FoodDescription.Name = "FoodDescription"
        Me.FoodDescription.Size = New System.Drawing.Size(255, 61)
        Me.FoodDescription.TabIndex = 7
        '
        'FoodNameGroup
        '
        Me.FoodNameGroup.Controls.Add(Me.FoodName)
        Me.FoodNameGroup.Location = New System.Drawing.Point(8, 3)
        Me.FoodNameGroup.Name = "FoodNameGroup"
        Me.FoodNameGroup.Size = New System.Drawing.Size(130, 100)
        Me.FoodNameGroup.TabIndex = 12
        Me.FoodNameGroup.TabStop = False
        Me.FoodNameGroup.Text = "Name"
        '
        'FoodName
        '
        Me.FoodName.Location = New System.Drawing.Point(3, 36)
        Me.FoodName.Name = "FoodName"
        Me.FoodName.Size = New System.Drawing.Size(121, 20)
        Me.FoodName.TabIndex = 5
        '
        'FoodPriceGroup
        '
        Me.FoodPriceGroup.Controls.Add(Me.FoodPrice)
        Me.FoodPriceGroup.Location = New System.Drawing.Point(144, 3)
        Me.FoodPriceGroup.Name = "FoodPriceGroup"
        Me.FoodPriceGroup.Size = New System.Drawing.Size(94, 100)
        Me.FoodPriceGroup.TabIndex = 13
        Me.FoodPriceGroup.TabStop = False
        Me.FoodPriceGroup.Text = "Price"
        '
        'FoodPrice
        '
        Me.FoodPrice.Location = New System.Drawing.Point(15, 36)
        Me.FoodPrice.Name = "FoodPrice"
        Me.FoodPrice.Size = New System.Drawing.Size(65, 20)
        Me.FoodPrice.TabIndex = 6
        '
        'RegistrationForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(612, 333)
        Me.Controls.Add(Me.TabControl1)
        Me.Controls.Add(Me.statusStripMenu)
        Me.Controls.Add(Me.MenuStrip1)
        Me.Name = "RegistrationForm"
        Me.Text = "Form1"
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.statusStripMenu.ResumeLayout(False)
        Me.statusStripMenu.PerformLayout()
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.TabControl1.ResumeLayout(False)
        Me.TabPage1.ResumeLayout(False)
        Me.TabPage1.PerformLayout()
        Me.TabPage2.ResumeLayout(False)
        Me.PaymentNumberGroup.ResumeLayout(False)
        Me.PaymentNumberGroup.PerformLayout()
        Me.LastNameGroup.ResumeLayout(False)
        Me.LastNameGroup.PerformLayout()
        Me.IDGroup.ResumeLayout(False)
        Me.IDGroup.PerformLayout()
        Me.FirstNameGroup.ResumeLayout(False)
        Me.FirstNameGroup.PerformLayout()
        Me.TabPage3.ResumeLayout(False)
        Me.FoodImageGroup.ResumeLayout(False)
        CType(Me.FoodImage, System.ComponentModel.ISupportInitialize).EndInit()
        Me.FoodCategoryGroup.ResumeLayout(False)
        Me.FoodCategoryGroup.PerformLayout()
        Me.TableLayoutPanel7.ResumeLayout(False)
        Me.TableLayoutPanel7.PerformLayout()
        Me.FoodNameGroup.ResumeLayout(False)
        Me.FoodNameGroup.PerformLayout()
        Me.FoodPriceGroup.ResumeLayout(False)
        Me.FoodPriceGroup.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents MenuStrip1 As MenuStrip
    Friend WithEvents FileToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents ImportUsersToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents statusStripMenu As StatusStrip
    Friend WithEvents user As ToolStripStatusLabel
    Friend WithEvents status As ToolStripStatusLabel
    Friend WithEvents ImportMenuToolStripMenuItem As ToolStripMenuItem
    Friend WithEvents DataSet1 As DataSet
    Friend WithEvents DataGridView1 As DataGridView
    Friend WithEvents TabControl1 As TabControl
    Friend WithEvents TabPage1 As TabPage
    Friend WithEvents TabPage2 As TabPage
    Friend WithEvents TabPage3 As TabPage
    Friend WithEvents RegisterUserButton As Button
    Friend WithEvents PaymentNumber As TextBox
    Friend WithEvents LastName As TextBox
    Friend WithEvents FirstName As TextBox
    Friend WithEvents ID As TextBox
    Friend WithEvents FoodDescription As TextBox
    Friend WithEvents FoodPrice As TextBox
    Friend WithEvents FoodName As TextBox
    Friend WithEvents Label10 As Label
    Friend WithEvents RegisterFoodButton As Button
    Friend WithEvents TableLayoutPanel7 As TableLayoutPanel
    Friend WithEvents FoodImageGroup As GroupBox
    Friend WithEvents ImageUploadButton As Button
    Friend WithEvents FoodCategoryGroup As GroupBox
    Friend WithEvents FoodCategory As TextBox
    Friend WithEvents FoodImage As PictureBox
    Friend WithEvents FoodNameGroup As GroupBox
    Friend WithEvents FoodPriceGroup As GroupBox
    Friend WithEvents PaymentNumberGroup As GroupBox
    Friend WithEvents LastNameGroup As GroupBox
    Friend WithEvents FirstNameGroup As GroupBox
    Friend WithEvents IDGroup As GroupBox
    Friend WithEvents txtBarcodeID As TextBox
    Friend WithEvents Label1 As Label
End Class
