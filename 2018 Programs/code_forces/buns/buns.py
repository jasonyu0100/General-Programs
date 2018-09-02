import copy

def getMaxSale(dough,baseDoughCost,baseSaleCost,bunTypeDescriptions,currentCost):
    print(currentCost)
    paths = []
    if dough-baseDoughCost >= 0:
        paths.append(getMaxSale(dough-baseDoughCost,baseDoughCost,baseSaleCost,bunTypeDescriptions,currentCost+baseSaleCost))
    for index,bunType in enumerate(bunTypeDescriptions):
        stuffingAvailable,stuffingCost,doughCost,saleCost = bunType
        if (stuffingAvailable - stuffingCost) >= 0 and (dough-baseDoughCost) >= 0:
            newDescription = copy.deepcopy(bunTypeDescriptions)
            newDescription[index][0] -= stuffingCost
            paths.append(getMaxSale(dough-doughCost,baseDoughCost,baseSaleCost,newDescription,currentCost+saleCost))
    if len(paths) == 0:
        return currentCost
    else:
        return max(paths)


fileIn = open("bunsin.txt")
fileOut = open("bunsout.txt","w")
dough,types,baseDoughCost,baseSaleCost = map(int,fileIn.readline().split())

bunTypeDescriptions = []
for bunType in range(types):
    stuffingAvailable,stuffingCost,doughCost,saleCost = map(int,fileIn.readline().split())
    bunTypeDescriptions.append([stuffingAvailable,stuffingCost,doughCost,saleCost])
fileOut.write(str(getMaxSale(dough,baseDoughCost,baseSaleCost,bunTypeDescriptions,0)))

fileIn.close()
fileOut.close()