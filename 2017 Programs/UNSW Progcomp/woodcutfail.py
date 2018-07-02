def FindDuo(cuts):
    bigdif = 0
    for i in range(len(cuts)):
        currentnum = cuts[i][0]
        nextnum = cuts[i][1]
        dif = abs(currentnum - nextnum)
        if dif > bigdif:
            bigdif = dif
            position = i
    return(position)#Finds the duo that has highest difference

def Duos(cuts):
    duos = []
    for pos in range(len(cuts)):
        if pos == (len(cuts)-1):
            pass
        else:
            current = cuts[pos]
            consecutive = cuts[pos+1]
            duo = []
            duo.append(current)
            duo.append(consecutive)
            duos.append(duo)
    return(duos)
    

def main():
    length = int(input('Enter the length: '))
    cuts = [int(pos) for pos in (input('Enter the position of the cuts: ').split())]
    cuts.append(length)
    cuts.insert(0,0)
    total = 0
    actions = []
    duos = Duos(cuts)
    #append to actions
    while len(duos) > 0:
        if duos[FindDuo(duos)][0] == 0:
            actions.append(cuts[1])
            duos.pop(0)
            duos.pop(0)
        else:
            actions.append(duos[FindDuo(duos)][0])
            duos.pop(FindDuo(duos))
    print(actions)
    
main()

