with open("factorialin.txt") as f:
    num = int(f.readline())
    

def factorial(num):
    total = 1
    for i in range(1,num+1):
        total *= i
    print(total)

factorial(num)