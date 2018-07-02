import time
def highest(numbers):
    top = numbers[0]
    for i in numbers:
        if i > top:
            top = i
    return(top)
def lowest(numbers):
    low = int(numbers[0])
    for i in numbers:
        if int(i) < low:
            low = int(i)
    return(int(low))
def drawer(nums):
    grid = []
    line = []
    top = highest(nums)
    for i in range(top):
        for a in range(len(nums)):
            line.append(' ')
        grid.append(line)
        line = []
    for row in range(top):
        for col in range(len(nums)):
            if int(nums[col]) >= (row+1):
                grid[row][col] = 'o'
    grid.reverse()
    for i in grid:
        print('|'+'|'.join(i)+'|')
def main():
    nums = [int(num) for num in input("Enter numbers: ").split()]
    start = time.clock()
    #DRAWER
    drawer(nums)
    towerlist = []
    total = 0
    for i in range(len(nums)):
        #Asign Variables
        currentnum = nums[i]
        if i+1 == len(nums):
            nextnum = currentnum
        else:
            nextnum = nums[i+1]
        #Make List
        if currentnum > nextnum and len(towerlist) == 0:
            towerlist.append(currentnum)
        elif currentnum <= nextnum and len(towerlist) == 0:
            pass
        #Evaluate List or add to List
        elif towerlist[0] <= (currentnum) and len(towerlist) > 1:
            towerlist.append(currentnum)
            for i in towerlist[:-1]:
                total += (towerlist[0]-i)
            towerlist = []
            if currentnum > nextnum:
                towerlist.append(currentnum)           
        else:
            towerlist.append(currentnum)
    #Last List Catch
    while len(towerlist) > 2:
        top = highest(towerlist[1:])
        if top == towerlist[0]:
            endnum = ((towerlist[::-1]).index(top))
            endnum = len(towerlist)-1 - endnum
        else:
            endnum = (towerlist.index(top))
        for i in towerlist[1:endnum]:
            total += (towerlist[endnum] - i)
        towerlist = towerlist[endnum:]
    print(total)
    print(time.clock() - start)
main()



    
    
