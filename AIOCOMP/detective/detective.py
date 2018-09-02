from TestFunction import testFunction
inputFile = 'in.txt'
outputFile = 'out.txt'
fileIn = open(inputFile,'r')
fileOut = open(outputFile,'w')

def function(x,y): 
  #Program function
  return x*y


testCases = [
  ([2,2],4),
  ([3,3],9),
  ([4,4],16),
]
testFunction(function,testCases)

children,statements = list(map(int,fileIn.readline().split()))
allStatements = {}
for statement in range(statements):
  child,otherChild,accusation = list(map(int,fileIn.readline().split()))
  if child in allStatements:
    allStatements[child] = [[otherChild,accusation]]
  else:
    allStatements[child].append([otherChild,accusation])
  allStatements.append([child,otherChild,accusation])

for statement in allStatements:
  child,otherChild,accusation = statement
  if accusation == 3: #assumptino made that child is honest
    



  

fileIn.close()
fileOut.close()

#fileIn.read() reads whole file and puts in string
#fileIn.readline() reads a line 
#fileOut.write() writes a line without new line