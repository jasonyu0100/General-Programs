# num = int(input("Enter a number: "))
from functools import reduce
import time
import math

def prime(num):
    for divisor in range(2,(math.sqrt(num))+1):
        if num % divisor == 0:
            quotient = int(num / divisor)
            return prime(quotient) + prime(divisor)
    else:
        return [num]

start = time.monotonic()
num = '1111111111111111111111'
numbers = (prime(int(num)))
print(numbers)

end = time.monotonic()


print(f'{(end-start)*1000}')
print(num)
print(reduce(lambda x,y : x*y,numbers))
