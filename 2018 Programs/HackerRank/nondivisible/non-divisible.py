def maxNonDivisibleSubSet(nonFactor,numbers):
    nonDivisblePairings = dict()
    for number in numbers:
        nonDivisblePairings[number] = []
        for compareNumber in numbers:
            if compareNumber == number:
                continue
            if (number + compareNumber)%nonFactor != 0:
                nonDivisblePairings[number].append(compareNumber)
        print(nonDivisblePairings[number])
    currentMax = 0
    for number in numbers:
        checkMax = len(nonDivisblePairings[number]) + 1
        if (checkMax) > currentMax:
            currentMax = checkMax
    return currentMax


print(maxNonDivisibleSubSet(3,[1,7,2,4]))
