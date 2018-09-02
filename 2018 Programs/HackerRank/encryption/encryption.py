import math

def squareEncyrpt(text):
    string = ''.join(text.split())
    rows = math.floor(math.sqrt(len(string)))
    cols = math.ceil(math.sqrt(len(string)))
    if (rows*cols) < len(string):
        rows += 1
    strings = []
    current = ''
    for index,char in enumerate(string):
        current += char
        if (index+1)%cols == 0:
            strings.append(current)
            current = ''
    
    newSentence = []
    for col in range(cols):
        newString = ''
        for row in range(rows):
            try:
                newString += strings[row][col]
            except:
                pass
        newSentence.append(newString)
    print(' '.join(newSentence))
            
        



    

fileIn = open("encryptionin.txt")
squareEncyrpt(fileIn.read())