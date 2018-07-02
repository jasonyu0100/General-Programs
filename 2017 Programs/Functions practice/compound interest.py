def compoundinterest():
    interest = float(input('Enter interest per annum in decimal: '))
    years = int(input('Enter amount of years invested: '))
    principal = float(input('Enter the amount of money invested at the start: '))
    money = (1+interest)**years*principal
    gain = money - principal
    growth = (money/principal)-1
    print('Interest:',gain)
    print('Final amount:',money)
    print('Growth:',growth)

compoundinterest()
