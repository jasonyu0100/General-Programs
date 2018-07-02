words = input('Enter words: ').split()
firstlist = []
secondlist = []
first = words[0]
second = words[1]
firstsort = sorted(words[0])
secondsort = sorted(words[1])
print(firstsort)
print(secondsort)
for pos in range(len(firstsort)):
    current = firstsort[pos]
    if pos == (len(firstsort)-1):
        break
    after = firstsort[pos+1]
    if after == current:
        one = first.index(firstsort[pos],0)
        two = first.index(firstsort[pos],1)
        firstlist.append(('+'+str(two + one + 1)))
    else:
        firstlist.append(('0'))
for pos in range(len(secondsort)):
    current = secondsort[pos]
    if pos == (len(secondsort)-1):
        break
    after = secondsort[pos+1]
    if after == current:
        one = second.index(secondsort[pos],0)
        two = second.index(secondsort[pos],1)
        secondlist.append(('+'+str(two + one + 1)))
    else:
        secondlist.append(('0'))

print(firstlist)
print(secondlist)
    
            
