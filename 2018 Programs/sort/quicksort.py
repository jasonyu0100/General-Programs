import random
l = [random.random() for i in range(1000)]
from timer import timer

@timer
def quicksort(l):
    return _quicksort(l)

def _quicksort(l):
    if l == []: return []
    pivot_index = int(len(l)/2)
    pivot = l[pivot_index]
    less = []
    more = []
    for val in l[:pivot_index-1] + l[pivot_index+1:]:
        if val < pivot: less.append(val)
        else:more.append(val)
    return _quicksort(less) + [pivot] + _quicksort(more)
