import random
from timer import timer
l = [random.random() for i in range(1000)]

@timer
def radix_sort(l):
    string_list = [str(val) for val in l]
    max_length = max(len(val) for val in string_list)
    index = max_length
    string_list = [(max_length - len(string)) * '0' + string for i,string in enumerate(string_list)]
    new_list = string_list
    for index in range(max_length-1,-1,-1):
        new_list = sorted(new_list,key=lambda x:x[index])
    return new_list
