import math
# from TestFunction import testFunction
inputFile = 'streetin.txt'
outputFile = 'streetout.txt'
fileIn = open(inputFile,'r')
fileOut = open(outputFile,'w')

def getMinMaxBlockCount(landNum,parks): 
  houses = landNum - parks
  val = math.ceil(houses / (parks + 1))
  return val

# def getAlternateMinMaxBlockCount(landNum,parks): 
#   houses = landNum - parks
#   availableParkPositions = houses - 1
#   availableParkPositions / park


# testCases = [
#   ([3,1],1),
#   ([3,3],0),
#   ([7,2],2),
#   ([5,4],1),
#   ([6,3],1),
#   ([4,2],1),
#   ([5,3],1),
#   ([10,2],3)
# ]
# testFunction(getMinMaxBlockCount,testCases)

landNum,parks = map(int,fileIn.readline().split())
outputValue = getMinMaxBlockCount(landNum,parks)
fileOut.write(str(outputValue))

fileIn.close()
fileOut.close()