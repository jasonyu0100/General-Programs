def highest(numbers):
    top = 0 
    for i in numbers:
        if int(i) > top:
            top = int(i)
    return(int(top))
def lowest(numbers):
    low = int(numbers[0])
    for i in numbers:
        if int(i) < low:
            low = int(i)
    return(int(low))         
heights = input('Enter a series of numbers: ').split()
numberlist = []
ascending = False
area = 0
for listnum in range(len(heights)):
    #Set Variable Names
    currentnum = int(heights[listnum])
    if (listnum + 1) == len(heights):
        nextnum = int(currentnum)
    else:
        nextnum = int(heights[listnum + 1])
    #Make list
    if len(numberlist) == 0 and currentnum > nextnum:
        numberlist.append(currentnum)
    elif len(numberlist) == 1:
        numberlist.append(currentnum)
    #Count Area
    if currentnum >= nextnum and ascending == True:
        newlist = []
        newlist.append(numberlist[0])
        newlist.append(numberlist[-1])
        key = lowest(newlist)
        numberlist = numberlist[1:-1]
        for i in numberlist:
            currentarea = key - int(i)
            area = area + currentarea
            print(area)
        numberlist = []
        numberlist.append(currentnum)
        ascending = False
    elif int(numberlist[0]) < int(numberlist[-1]):
        newlist = []
        newlist.append(numberlist[0])
        newlist.append(numberlist[-1])
        key = lowest(newlist)
        numberlist = numberlist[1:-1]
        for i in numberlist:
            currentarea = key - int(i)
            area = area + currentarea
        numberlist = []
        numberlist.append(currentnum)
        ascending = False
    #Append to list
    elif currentnum >= nextnum:
        numberlist.append(nextnum)
    elif currentnum < nextnum and len(numberlist) != 0:
        ascending = True
        numberlist.append(nextnum)
print(area)
#-------------------------------------------------------
grid = []
line = []
top = highest(heights)
for i in range(top):
    for a in range(len(heights)):
        line.append(' ')
    grid.append(line)
    line = []
for row in range(top):
    for col in range(len(heights)):
        if int(heights[col]) >= (row+1):
            grid[row][col] = '*'
grid.reverse()
for i in grid:
    print('| '+' | '.join(i)+' |')
#-------------------------------------------------------
        
        

        
        
    
