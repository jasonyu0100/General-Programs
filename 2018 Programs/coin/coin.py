import math

coins = [1,3,10]
goal = 11

prices = {0:0}
for i in range(0,goal+1):
    if i in prices:
        continue

    prices[i] = math.inf
    
    for coin in coins:
        if coin <= i:
            total = i - coin
            totalCoins = prices[total] + 1
            if prices[i] > totalCoins:
                prices[i] = totalCoins

print(prices)