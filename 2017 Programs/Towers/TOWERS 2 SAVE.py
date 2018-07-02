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
    #Exceptions NEEDS MORE WORK
    bignumbers = []
    endvalue = False
    for i in range(len(towerlist)):
        currentnum = towerlist[i]
        if i+1 == len(towerlist):
            nextnum = currentnum
        else:
            nextnum = towerlist[i+1]
        if currentnum < nextnum:
            endvalue = i + 1
    if endvalue != False:
        towerlist = towerlist[:endvalue+1]
        for i in range(len(towerlist)):
            if towerlist[i] > towerlist[-1]:
                start = i
        towerlist = towerlist[start:]
        for i in towerlist[1:]:
                total += (towerlist[-1]-i)
    print(total)
main()


    
    
