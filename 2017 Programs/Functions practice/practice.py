def beef():
    print('Dayum, functions are cool!')

def bitcoin_to_usd(btc):
    amount = btc*527
    print(amount)

def inputs():
    money = float(input('Enter an amount'))
    return(bitcoin_to_usd(money))
inputs()
beef()

bitcoin_to_usd(3.85)
