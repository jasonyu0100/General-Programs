def square(num):
    num = num**2
    print(num)
def trianglearea(base,height):
    area = base*height/2
    print(area)
def mean(numbers):
    numbers = numbers.split()
    mean = 0
    for i in numbers:
        mean+=int(i)
    print(mean/len(numbers))
def median(numbers):
    numbers = numbers.split()
    numbers.sort()
    if len(numbers)%2 == 0:
        num1 = len(numbers)/2-1
        num2 = len(numbers)/2
        median = (int(numbers[int(num1)]) + int(numbers[int(num2)]))/2
        print(median)
    else:
        median = len(numbers)/2+1
        print(numbers[int(median-1)])

median('1 2 3 4 5')
        
