from heapsort import heap_sort
from insertion import insertion_sort
from mergesort import mergesort
from quicksort import quicksort
from radixsort import radix_sort

import random
l = [random.random() * 100 for i in range(10000)]

heap_sort(l)
insertion_sort(l)
mergesort(l)
quicksort(l)
radix_sort(l)
