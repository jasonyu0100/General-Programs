import math
def radiansToDegree(radians):
    return radians / math.pi * 180

def degreeToRadian(degree):
    return degree / 180 * math.pi

val = input("Enter a radian")
print(radiansToDegree(val))
