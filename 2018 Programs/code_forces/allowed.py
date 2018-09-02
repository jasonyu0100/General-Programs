inputString = """bedefead
5
2 e
1 dc
5 b
7 ef
6 ef
"""
lines = inputString.split('\n')
lineNum = 0
word = lines[0]
indexes = int(lines[1])
wordIndexes = {}
for i in range(1,indexes+1):
    index,letters = lines[1+i].split()
    index = int(index)
    wordIndexes[index-1] = set(letters)

for i in range(len(word)):
    if i in wordIndexes:
        min(wordIndexes[i],key=lambda x:ord(x))
    else:

    print(word[i])


