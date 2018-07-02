number = float(input('Enter a number: '))
guess = 1
increment = 1
value = 1
while number:
    value = guess - ((guess**2 - number) / (2*guess))
    print(value)
    if guess == 1:
        previous = value
    if float(number) == float(value**2):
        break
    if previous < value:
        guess -= 2*increment
        increment = increment/10
    if count == 9:
        increment = increment/10
    
    guess += increment
    
