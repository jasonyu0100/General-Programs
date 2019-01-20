from math import inf
from word_conversion import word_conversion

names = {}

with open('pokemon_names.txt') as f:
  count = 0
  for name in f:
    name = name.strip()
    names[name] = 0
    count += 1
    if count == 12:
      break

num_names = len(names)
for curr_name in names:
  for comp_name in names:
    if curr_name != comp_name:
      cost = word_conversion(curr_name,comp_name)
      names[curr_name] += cost / (num_names-1)

print(max(names.items(),key=lambda item:item[1])) # least similar name
  
