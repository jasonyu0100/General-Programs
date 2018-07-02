num = int(input("Enter a number: "))
square = num**2
square = str(square)
if len(square)%2 == 0:
    first = square[0:int(len(square)/2)]
    second = square[int(len(square)/2):]
elif len(square) == 1:
    first = 0
    second = square
else:
    first = square[0:int(len(square)/2-0.5)]
    second = square[int(len(square)/2-0.5):]
if (int(first)+int(second)) == num:
    print('YES')
