import itertools
import copy
def PossibleNumbers(row,col,data):
    unique = []
    for num in range(1,(row*col)+1):
        unique.append(str(num))
    for num in data:
        try:
            unique.remove(str(num))
        except:
            pass
    unique = ''.join(unique)
    return(unique)

row = int(input('How many rows? '))
col = int(input('How many columns? '))
data = input('Enter the game: ').split()
rowtotal = input('Enter the row totals: ').split()
matrix = []
unique = PossibleNumbers(row,col,data)
for i in range(1,row+1):
    matrix.append(data[(-1+i)*col:i*col])
unique = list(map("".join, itertools.permutations(unique)))
listnum = 0
template = []
for i in range(row):
        rows = []
        for cols in range(col):
            rows.append(cols)
        template.append(rows)
        
for i in unique:
    newmatrix = template[:]
    permutation = unique[listnum]
    
    pos = 0
    for rowpos in range(len(newmatrix)):
        for colpos in range(col):
            if matrix[rowpos][colpos] == '.':
                newmatrix[rowpos][colpos] = permutation[pos]
                pos += 1
            else:
                newmatrix[rowpos][colpos] = matrix[rowpos][colpos]
    listnum += 1
    
    position = 0
    count = 0
    for rows in newmatrix:
        total = 0 
        for number in rows:
            total += int(number)
        if total == int(rowtotal[position]):
            count += 1
            position += 1
    if count == len(rowtotal):
        print(newmatrix)
        break
    
    
