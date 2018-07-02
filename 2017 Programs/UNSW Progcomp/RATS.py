number = int(input('Enter a number: '))
times = int(input('Enter a number of times: '))
for i in range(times):
    changed = 0
    current = int(number)
    changed = str(number)
    changed = list(changed)
    changed.reverse()
    changed = ''.join(changed)
    changed = int(changed)
    print(str(current)+'+'+str(changed) +' = '+str(current+changed),end = ' ')
    number = current+changed
    number = str(number)
    number = list(number)
    number.sort()
    number = ''.join(number)
    number = int(number)
    print('')
