def valuechecker(values,colour):
    old = ''.join(values)
    for i in range(len(old)):
        #Setting Variables
        currentnum = old[i]
        if (i+1) == len(old):
            nextnum = old[0]
        else:
            nextnum = old[i+1]
        #Setting in new values
        if currentnum == colour and nextnum == '.':
            values[i] = '.'
            if i+1 == len(values):
                values[0] = colour
            else:
                values[i+1] = colour
        else:
            pass
    return(values)
def graphic(bluevalues,redvalues):
    middle = int(len(redvalues)/2-0.5)
    for col in range(len(redvalues)):
        line = []
        for row in range(len(bluevalues)):
            if col == middle and row == middle:
                line.append(redvalues[middle])
            elif col == middle:
                line.append(bluevalues[row])
            elif row == middle:
                line.append(redvalues[col])
            else:
                line.append(' ')
        print(' '.join(line))
    
def main():
    redvalues = [value for value in input('Enter the traffic values of red: ')]
    bluevalues = [value for value in input('Enter the traffic values of blue: ')]
    cycles = int(input('Enter the number of cycles: '))*2
    middle = int(len(redvalues)/2-0.5)
    for i in range(cycles):
        if i%2 == 0 or i==0:
            redvalues = valuechecker(redvalues,'R')
            bluevalues[middle] = redvalues[middle]
            print('CURRENT RED : '+ ''.join(redvalues))
            print('CURRENT BLUE: '+ ''.join(bluevalues))
            graphic(redvalues,bluevalues)
        else:
            bluevalues = valuechecker(bluevalues,'B')
            redvalues[middle] = bluevalues[middle]
            print('CURRENT RED : '+ ''.join(redvalues))
            print('CURRENT BLUE: '+ ''.join(bluevalues))
            graphic(redvalues,bluevalues)
    print('--------------------------------------------')
    bluevalues[middle] = redvalues[middle]
    print('FINAL RED : '+ ''.join(redvalues))
    print('FINAL BLUE: '+ ''.join(bluevalues))
            
main()
