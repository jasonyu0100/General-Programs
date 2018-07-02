def PossibleNumbers(rows,columns,values):
    #Possible Numbers
    numbers = []
    for num in range(1,(rows*columns)+1):
        numbers.append(num)
    for num in values:
        try:
            numbers.remove(int(num))
        except:
            pass
    return(numbers)
def GridMaker(rows,columns,values):
    #Creating Grid
    grid = []
    for i in range(rows):
        row = []
        for i in range(columns):
            row.append('')
        grid.append(row)

    #Adding to Grid
    count = -1
    for row in range(rows):
        for col in range(columns):
            count += 1
            grid[row][col] = values[count]
    return(grid)
def main():
    rows = int(input('Enter the number of rows: '))
    columns = int(input('Enter the number of columns: '))
    values = input('Enter the grid of numbers with . as empty numbers: ').split()
    rowtotals = input('Enter totals corresponding to rows: ').split()
    columntotals = input('Enter totals corresponding to columns: ').split()
    numbers = PossibleNumbers(rows,columns,values)
    grid = GridMaker(rows,columns,values)
    for num in numbers:
        for row in range(len(grid)):
            for col in range(row):
                if grid[row][col] == '.':
                    grid[row][col].replace(str(num))
    print(numbers)
    print(grid)
main()
    

            
