with open('Question1.txt') as f:
    firstline = f.readline()
    firstline = firstline.split()
    target = int(firstline[1])
    motivation = int(firstline[0])
    targets = []
    for i in f:
        targets.append(int(i.strip()))
targets = targets[:-1]
for stepcount in targets:
    stepcount = int(round(stepcount,0))
    if stepcount >= target:
        motivation = motivation/100
        tommorowtarget = target + (motivation**2)*(stepcount-target)
        print(int(round(tommorowtarget,0)), end = ' ')
    else:
        motivation = motivation/100
        tommorowtarget = target + ((1-motivation)**2)*(stepcount-target)
        print(int(round(tommorowtarget,0)),end = ' ')

average = 0
for i in targets:
    average += i
average = average/len(targets)
nettotal = 0
for i in targets:
    nettotal += i
netgoal = target*len(targets)
percent = int(100*round(nettotal/netgoal,0))
motivation = firstline[0]
print('\nMotivation '+ motivation +', days ' + str(len(targets))+', mean steps '+str(int(round(average,0)))+', goal reached ' + str(percent)+'. Final target ' + str(int(round(tommorowtarget,0))))
