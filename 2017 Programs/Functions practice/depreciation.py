def depreciation():
    interest = float(input('Enter interest in decimal: '))
    years = int(input('Enter period invested: '))
    principal = float(input('Enter the amount of money invested at the start: '))
    money = (1-interest)**years*principal
    print('Final amount:',money)

depreciation()
