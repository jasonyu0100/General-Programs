import random
l = [random.random() for i in range(1000)]
from timer import timer

@timer
def insertion_sort(l):
    for current in range(1,len(l)):
        if l[current] < l[current-1]:
            for check in range(current-2,-1,-1):
                if l[current] > l[check]:
                    l.insert(check+1,l.pop(current))
                    break
            else:
                l.insert(0,l.pop(current))
    return l
