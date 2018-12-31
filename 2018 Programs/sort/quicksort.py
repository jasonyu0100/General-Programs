l = [3,-5,19,1,13,12,7,-1]
import random
big_l = [random.random() for i in range(1000)]

def quicksort(l):
    if l == []: return []
    pivot = l[-1]
    less = []
    more = []
    for val in l[:-1]:
        if val < pivot: less.append(val)
        else:more.append(val)
    return quicksort(less) + [pivot] + quicksort(more)

print(quicksort(big_l))
