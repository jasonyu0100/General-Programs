sentence = input('Enter a sentnece').split()
new = []
for i in sentence:
    if i[0] != i[0].upper():
        i = i.title()
    else:
        pass
    new.append(i)
print(new)
