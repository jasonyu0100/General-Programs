row = int(input('How many rows? '))
col = int(input('How many columns? '))
data = input('Enter the matrix values: ').split()
matrix = []
for i in range(1,row+1):
    matrix.append(data[(-1+i)*col:i*col])
print(matrix)
