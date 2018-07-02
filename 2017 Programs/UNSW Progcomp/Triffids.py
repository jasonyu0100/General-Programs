import string
code = input('Enter a code: ')
scrambled = input('Enter the scrambled code: ')
alphabet = list(string.ascii_uppercase)
newcode = []
for letter in code:
    if letter in newcode:
        pass
    else:
        newcode.append(letter)
newalphabet = []
for letter in newcode:
    newalphabet.append(letter)
newalphabet.append(' ')
for letter in alphabet:
    if letter in newalphabet:
        pass
    else:
        newalphabet.append(letter)


codecracker = {}
startnum = 110
for letter in newalphabet:
    stringnum = str(startnum)
    if stringnum[0] == '3' and str(startnum)[1] == '3' and str(startnum)[-1] == '3':
            break
    elif stringnum[1] == '3' and str(startnum)[-1] == '3':
        startnum += 100
        startnum -= 20
        startnum -= 2
    elif stringnum[-1] == '3':
        startnum += 10
        startnum -= 2
    else:
        startnum += 1
    codecracker[letter] = startnum

finaline = []
for letter in scrambled:
    finaline.append(str(codecracker[letter]))
finaline = ''.join(finaline)
print(finaline)
for i in range(len(scrambled)):
    first = finaline[i]
    second = finaline[i+len(scrambled)]
    third = finaline[i+(2*len(scrambled))]
    total = int(first+second+third)
    for letter,number in codecracker.items():
        if number == total:
            print(letter,end='')


    
