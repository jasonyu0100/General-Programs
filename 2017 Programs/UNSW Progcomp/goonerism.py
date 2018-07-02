sentence = input('Enter a sentence: ').split()
vowel = ['a','e','i','o','u']
prefix = []
prevfix = []
prevword = ''
newsentence = []
previous = ''
for word in sentence:
    if word[0].lower() in vowel:
        if previous != '':
            newsentence.append(previous)
        newsentence.append(word)
    else:
        if prevword != '':
            newword = word
            for letter in word:
                if letter.lower() in vowel:
                    break
                else:
                    prevfix.append(letter)
                    newword = newword[1:]
            prefix = ''.join(prefix)
            prevfix = ''.join(prevfix)
            prevword = prevfix+prevword
            newword = prefix+newword
            newsentence.append(prevword)
            newsentence.append(newword)
            prevword = ''
            prevfix = []
            prefix = []
        else:
            prevword = word
            previous = word
            for letter in word:
                if letter.lower() in vowel:
                    break
                else:
                    prefix.append(letter)
                    prevword = prevword[1:]
print(newsentence)
    
