import math
def generateVectorComponents(mag,direction):
	radians = direction / 180 * math.pi
	return (math.cos(radians) * mag,math.sin(radians) * mag)

# mag,direction = [float(i) for i in input('Enter magnitude and direction in degrees: ').split()]
# print(mag,direction)
# x,y = generateVectorComponents(mag,direction)
# print('x:',x,'y:',y)
xSum = 0
ySum = 0
while True:
	try:
		mag,direction = [float(i) for i in input('Enter magnitude and direction in degrees: ').split()]
	except:
		break
	x,y = generateVectorComponents(mag,direction)
	xSum += x
	ySum += y
print(xSum)
print(ySum)
