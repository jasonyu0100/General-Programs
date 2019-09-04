"""
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
...
"""
cache = {}
def pascals_triangle(number):
  if number == 1:
    return[1] 
  else:
    if number in cache:
      return cache[number]
    array = [0 for i in range(number)]
    array[0],array[-1] = 1,1
    for i in range(1,number-1):
      previous = pascals_triangle(number-1)
      array[i] = previous[i] + previous[i-1]
    if number not in cache: cache[number] = array
    return array

length = 50
for i in range(1,length):
  line = map(lambda x: str(x%2),pascals_triangle(i))
  print((length-i)*' ',end='')
  print(' '.join(line))


"""
     1
    1 1
   1 2 1
  1 2 2 1
 1 3 4 3 1
1 3 12 12 3 1
Rules if even n then multiply
else add
"""
cache_2 = {}
def pascals_triangle_2(number):
  if number == 1:
    return [1]
  else:
    if number in cache_2:
      return cache_2[number]
    array = [0 for i in range(number)]
    array[0], array[-1] = 1,1
    previous = pascals_triangle_2(number-1)
    if number % 2 == 0: 
      for i in range(1,number-1):
        array[i] = previous[i] * previous[i-1]
    else:
      for i in range(1,number-1):
        array[i] = previous[i] + previous[i-1]
    cache_2[number] = array
    return array

#for i in range(1,12):
#  print(pascals_triangle_2(i))

