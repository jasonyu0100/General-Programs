string = input('Enter a string: ')
numbers = ['0','1','2','3','4','5','6','7','8','9']
newlist = []
for i in string:
    if i in numbers:
        newlist.append(i)
print(''.join(newlist))
