def createArrangements(footMen,horseMen,consecutiveFootMen,consecutiveHorseMen,arrangement):
    print(arrangement)
    if footMen == 0 and horseMen == 0:
        return [arrangement]
    leftArrangement = []
    rightArrangement = []

    consecutive = 0
    if len(arrangement) > 0:
        value = arrangement[-1]
        for num in reversed(arrangement):
            if num != value:
                break
            consecutive += 1
    else:
        value = None
        
    if footMen > 0:
        if (value == 1 and consecutive < consecutiveFootMen) or value == 2 or value == None:
            leftArrangement = createArrangements(footMen-1,horseMen,consecutiveFootMen,consecutiveHorseMen,arrangement + [1])
    if horseMen > 0:
        if (value == 2 and consecutive < consecutiveHorseMen) or value == 1 or value == None:
            rightArrangement = createArrangements(footMen,horseMen-1,consecutiveFootMen,consecutiveHorseMen,arrangement + [2])
    return leftArrangement + rightArrangement
