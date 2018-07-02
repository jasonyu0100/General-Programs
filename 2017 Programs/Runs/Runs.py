def checkRuns(line):
    nums = [int(num) for num in line.split()]
    return(nums)
def main():
    with open("in.txt") as f:
        numLines = f.readline()
        for lines in f:
            linecheck = checkRuns(lines)
            checkchange(linecheck)
                       
def checkchange(linecheck):
    count = 0
    descending = 0
    ascending = 0
    for i in range(len(linecheck)):
        current = linecheck[i]
        if i == 0:
            previous = current
        else:
            previous = linecheck[i-1]
        if previous > current and descending == 1:
            descending = 1
            ascending = 0
        elif previous > current:
            descending = 1
            ascending = 0
            count += 1
        if previous < current and ascending == 1:
            descending = 0
            ascending = 1
        elif previous < current:
            ascending = 1
            descending = 0
            count += 1
    print('| ',end = '')
    for i in linecheck:
        print(str(i), end = ' ')
    print('|',end = '')
    print(str(count))
main()
