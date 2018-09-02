# from TestFunction import testFunction
inputFile = 'cloudin.txt'
outputFile = 'cloudout.txt'
fileIn = open(inputFile,'r')
fileOut = open(outputFile,'w')

def function(maxFriendsCovered,distances): 
  possibleStartingPoints = len(distances) - maxFriendsCovered
  cloudDistances = []
  for i in range(0,possibleStartingPoints):
    cloudDistance = distances[i+maxFriendsCovered]-distances[i]
    print(cloudDistance)
    cloudDistances.append(cloudDistance)

  return min(cloudDistances)
  # return x*y


# testCases = [
#   ([2,2],4),
#   ([3,3],9),
#   ([4,4],16),
# ]
# testFunction(function,testCases)

line = map(int,fileIn.readline().split())
distances = [0]
friends,maxCovered = line
for i in range(friends):
  line = fileIn.readline().strip()
  if line == '':
    break
  distance = int(line)
  distances.append(distances[-1] + distance)
fileOut.write(str(function(maxCovered,distances)))

fileIn.close()
fileOut.close()

#fileIn.read() reads whole file and puts in string
#fileIn.readline() reads a line 
#fileOut.write() writes a line without new line