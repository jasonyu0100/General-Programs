word = input('Enter a word: ')
vowels = ['a','e','i','o','u','y']
total = 0
for pos in range(len(word)):
    if pos == 0 and word[pos].lower() == 'y':
        pass
    elif word[pos].lower() in vowels:
        total += 1
    else:
        pass
number = round(total/len(word),2)
print(int(number*100))
