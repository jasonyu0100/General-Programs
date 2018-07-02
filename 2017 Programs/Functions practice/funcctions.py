def quadratic(a, b, c):
    squareroot = (((b**2)-4*a*c)**0.5)
    minus = (-b - squareroot)/(2*a)
    plus = (-b + squareroot)/(2*a)
    if minus == plus:
        print(minus)
    elif ((b**2)-(4*a*c)) < 0:
        print('No real roots')
    else:
        print(minus,plus)


def getValues():
    a = float(input('Enter a: '))
    b = float(input('Enter b: '))
    c = float(input('Enter c: '))
    quadratic(a, b, c)

getValues()
