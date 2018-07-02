num = input('Enter a number between 1-999: ')
number = []
unique = []
for i in num:number.append(int(i))
while num:
    total = 0
    for i in number:total += i**2
    if total not in unique:
        unique.append(total)
    else:
        print('Unhappy number!')
        break
    number = []
    if total == 1:
        print("Is a happy number ")
        break
    for i in str(total):
        number.append(int(i))
