numeral = input('Enter a Roman Numeral: ')
values = {'M':1000,
          'D':500,
          'C':100,
          'L':50,
          'X':10,
          'V':5,
          'I':1
}
total = 0
counter = 1
firstcompound = []
broken = None
numerals = []
for i in numeral:
    if i not in values:
        #RULE 1
        broken = ('False Rule 1')
    else:
        numerals.append(i)
for listnum in range(len(numerals)):
    currentnum = values[numerals[listnum]]
    if (listnum+1) == len(numerals):
        nextnum = currentnum
    else:
        nextnum = values[numerals[listnum+1]]
    if currentnum < nextnum and (currentnum == 100 or currentnum == 10 or currentnum == 1):
        currentnum = -(currentnum)
        firstcompound.append(currentnum)
        firstcompound.append(nextnum)
        if listnum+1 >= len(numerals):
            break
        firstcompound.append(values[numerals[listnum+1]])
        if firstcompound[0] < firstcompound[2]:
            broken = ('False Rule 3')
    elif currentnum < nextnum:
        broken = ('False Rule 2')
    if currentnum == nextnum:
        counter += 1
        if counter > 3:
            broken = ('False Rule 4')
    else:
        counter = 0
    total = total + currentnum
if broken != None:
    print(broken)
else:
    print(total)
