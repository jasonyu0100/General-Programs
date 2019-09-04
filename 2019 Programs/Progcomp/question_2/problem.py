import random


def center(string, max_size):
  out = ' ' *  ( (max_size - len(string)) // 2 )
  return out + string

def christmas_tree(n):

  leaves = []

  if n < 12:
    trunk = '#'
  else:
    trunk = '##'

  k = max(1, int(n/6))
  base_width = int(2*k+1)
  base = '=' * base_width

  max_size = n * 2 - 1

  size = 1

  for row in range(0, n):
    
    row_str = ''

    row_str += ' ' * ( (max_size - size) // 2)

    if row == 0:
      row_str += '+'
      leaves.append(row_str)
      size += 2
      continue

    for i in range(size):

      previous = row_str[-1] if row_str else ' '

      if i == 0 or i == size - 1:
        row_str += '*'
        continue
      if random.random() < 0.4 and previous != 'o':
        row_str += 'o'
      else:
        row_str += '*'

    size += 2

    leaves.append(row_str)
  

  leaves.append(center(trunk, max_size))
  leaves.append(center(base, max_size))


  for leave in leaves:
    print(leave)


christmas_tree(22)



    