from testFunction import testFunction
def mult(x,y):
  return x*y

testCases = [
  ([1,2],2),
  ([3,4],12),
  ([3,4],12),
  ([3,4],32),
  ([3,4],12),
  ([3,4],12),]

testFunction(mult,testCases)
