start = int(input('Enter the start number: '))
length = int(input('Enter how many numbers you want: '))
#1,1,2,3
numbers = []
previous = 0
total = start
for i in range(length):
    numbers.append(total)
    current = numbers[i]
    if i == 0:
        pass
    else:
        previous = numbers[i-1]
    total = previous + current
    
print(numbers)
