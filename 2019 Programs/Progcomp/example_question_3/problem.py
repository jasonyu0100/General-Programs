num = 180
# reverse add  sort
cycles = dict()
for num in range(1,10000):
  seen = dict()
  values = [num]
  i = 0
  while True:
    reversed_num = int(''.join(reversed(str(num))))
    total = reversed_num + num
    sorted_num = int(''.join(sorted(str(total))))
    if sorted_num > 10**12: break
    num = sorted_num
    values.append(num)
    if num in seen:
      cycle = ' '.join(str(values[j]) for j in range(seen[num], i+1))
      cycles[cycle] = cycles.get(cycle,0) + 1
      break
    else:
      seen[num] = i+1
    i += 1
    
for cycle in (cycles):
  print(f"Period: {len(cycle.split(' '))}, occurs {cycles[cycle]} times, cycle: {cycle}")
  