import random
l = [random.random() for i in range(1000)]
from timer import timer

@timer
def mergesort(l):
    return _mergesort(l)

def _mergesort(l):
    if len(l) <= 1: return l
    split = int(len(l)/2)
    left = _mergesort(l[:split])
    right = _mergesort(l[split:])
    return merge(left,right)

def merge(l1,l2):
    new_list = []
    ln1 = len(l1)
    ln2 = len(l2)
    while True:
        if l1[0] < l2[0]:
            new_list.append(l1.pop(0))
            ln1 -= 1
        else:
            new_list.append(l2.pop(0))
            ln2 -= 1

        #Checks if one part has fully merged and then joins other part
        if ln1 == 0:
            new_list += l2
            break
        elif ln2 == 0:
            new_list += l1
            break
    return new_list
