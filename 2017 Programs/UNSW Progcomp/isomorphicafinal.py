f = open('file.txt')
f.readline()
for line in f:
    
    words = line.split()
    char = 'fasd'
    first = list(words[0])
    second = list(words[1])
    firstlist = []
    secondlist = []
    for letter in first:
        if char != letter:
            
            if first.count(letter)>1:
                try:
                    char = letter
                    pos1 = (first.index(letter,0))
                    reverse = first[::-1]
                    pos2 = ((len(reverse)-1) - reverse.index(letter,1))
                    firstlist.append(pos2-pos1)
                except:
                    pass
            else:
                firstlist.append('0')
        else:
            firstlist.append('0')
    for letter in second:
        if char != letter:
            if second.count(letter)>1:
                try:
                    char = letter
                    pos1 = (second.index(letter,0))
                    reverse = second[::-1]
                    pos2 = ((len(reverse)-1) - reverse.index(letter,1))
                    secondlist.append(pos2-pos1)
                except:
                    pass
            else:
                secondlist.append('0')
        else:
            secondlist.append('0')
    print(secondlist)
    print(firstlist)
    if secondlist == firstlist:
        print('Isomorph',firstlist)
    elif len(firstlist) != len(secondlist):
        print('Different length')
    else:
        print('Not an isomorph!')
