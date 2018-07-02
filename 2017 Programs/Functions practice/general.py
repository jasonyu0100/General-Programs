def thing(general):
    values = general.replace('x^2',':').replace('x',':').replace('= 0','').replace(' ','')
    values = values.split(':')
    a = values[0]
    if a == '':
        a = 1
    else:
        a = int(values[0])
    b = int(values [1])
    c = int(values [2])
    return(quadratic(a,b,c))

def quadratic(a,b,c):
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
    general = input('Enter quadratic in general form: ')
    thing(general)
getValues()
