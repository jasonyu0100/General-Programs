def arithmeticTerm(a,d,t):
	return a + d * (t-1)

def arithmeticSum(a,d,t):
	return t/2(a + arithmeticTerm(a,d,t))

def geometricTerm(a,r,t):
	return a*r**(t-1)

def geometricSum(a,r,t):
	return a * (1-r**t / 1 - r)

def infiniteGeometricSum(a,r,t):
	if -1 < r < 1 and r != 0:
		return a / (1-r)
	elif r == 0:
		return a
	elif r < 0:
		return 'Negative Infinte Sum'
	elif r > 0:
		return 'Positive Infinte Sum'

