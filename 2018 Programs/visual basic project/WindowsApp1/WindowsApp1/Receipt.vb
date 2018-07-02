Public Class Receipt
    'Receipt item that might be a group box or flow container that store all the purchases made
    'Purchases can be stored in labels with reference to the user and food item



    'List of items
    Public items As Food()
    'Number of items
    Public itemCount As Integer = 0
    'Total cumulative cost
    Public totalCost As Integer = 0
    'TODO Dictionary with people as keys and their food items as values

    Public Sub New()
        'Initialize Receipt
    End Sub

    Public Sub Add(item As Food)
        'Add to receipt
        Me.itemCount += 1
        ReDim Me.items(Me.itemCount)
        Me.items(itemCount - 1) = item
        Me.totalCost += item.price
        'TODO Add to dictionary
    End Sub

    'Receipt
    'Burger $5 Jack
    'Burger $5 Johnny
    'Cumulative Cost: $10

    'By Person Receipt
    '
    'Jason Yu 
    'Burger $5
    'Sausage $3
    'Total Cost: $8
    'Brian 
    'Burger $5
    'Apple $2
    'Total Cost: $7

End Class
