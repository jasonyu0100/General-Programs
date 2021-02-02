from math import floor, ceil
a = [1,5,7,10]

def binary_search(value, array):
    start = 0
    end = len(array)
    mid = floor((start + end) / 2)
    while array[mid] != value:
        if value < array[mid]:
            end = mid - 1
        else:
            start = mid + 1
        mid = floor((start + end) / 2)
    return mid, array[mid]

def binary_search_2(value, array):
    start = 0
    end = len(array)
    mid = floor((start + end) / 2)
    while True:
        if value > array[mid]:
            start = mid
        else:
            end = mid
        mid = floor((start + end) / 2)
        if abs(start - end) == 1:
            return min([start,end])

def binary_search_3(value, array, dictionary):
    start = 0
    end = len(array)
    mid = floor((start + end) / 2)
    while True:
        if value > array[mid]:
            start = mid
        else:
            end = mid
        mid = floor((start + end) / 2)

        if abs(start - end) <= 1:
            pos = min([start,end])
            if array[pos] < value:
                array.insert(pos + 1, value) # Adding val after
                dictionary[value] = dictionary[array[pos]] + [value]
            else:
                array.insert(pos, value) # Adding val before
                dictionary[value] = [value]
            return


import random
array =(list(range(10)))
random.shuffle(array)
print(array)

def find_largest_ascending_subsequence(array):
    previous = []
    dictionary = {}
    for pos, val in enumerate(array):
        if len(previous) == 0:
            previous.append(val)
            dictionary[val] = [val]
        else:
            binary_search_3(val, previous, dictionary)
    a = max(dictionary.values(), key=lambda value: len(value))
    print(a)

    

find_largest_ascending_subsequence(array)