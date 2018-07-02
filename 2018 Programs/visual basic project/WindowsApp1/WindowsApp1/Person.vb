Public Class Person
    'Name of users
    Public userName As String
    'Id of user can be barcode
    Public id As String
    'Payment details of user, for now credit card number
    Public paymentDetails As String
    'Current items
    Public items() As Food = {}
    'Total Cost of all items
    Public itemCount As Integer = 0
    'Number of food items in order
    Public totalCost As Integer = 0

    Public Sub New(name As String, id As String, paymentDetails As String)
        'Registers User
        Me.userName = name
        Me.id = id
        Me.paymentDetails = paymentDetails
    End Sub

    Public Sub addItem(item As Food)
        'Adds 
        Me.itemCount += 1
        ReDim Me.items(Me.itemCount)
        Me.items(itemCount - 1) = item
        Me.totalCost += item.price
    End Sub


End Class
