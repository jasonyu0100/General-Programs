  import random
  #Generate start
  size = 9
  array = []
  left = True
  for row in range(1,size-1,2):
    array.append("+"*size)
    if left:
      array.append("+"+" "*(size-1))
    else:
      array.append(" "+(size-1)*"+")
    left= not left
  array.append("+"*size)

  def find_neighbours(row,col):
    neighbours = [(row-1,col),(row+1,col),(row,col-1),(row,col+1)]
    for row,col in neighbours:
      if row < 0 or col < 0:
        neighbours.remove((row,col))
      elif row >= size or col >= size:
        neighbours.remove((row,col))
    return neighbours

  def num_adjacent(row,col):
    num = 0
    for n in find_neighbours(row,col):
      if array[row][col] == "+":
        num += 1
    return num

  def find_adjacent(row,col):
    adjacent = []
    for n in find_neighbours(row,col):
      if array[row][col] == "+":
        adjacent.append((row,col))
    return random.choice(adjacent)

  def tail_pos(find_first):
    tails = []
    for i,row in enumerate(array):
      for j,cell in enumerate(row):
        if cell == "+":
          if num_adjacent(i,j) == 1:
            if find_first:
              return (i,j)
            else:
              tails.append((i,j))
    return tails

  for _ in range(10):
    tail = tail_pos(True)
    link = find_adjacent(*tail)
    array[link[0]][link[1]] = "+"
    
    for i,row in enumerate(array):
      for j,cell in enumerate(row):
        if cell == "+":
          if num_adjacent(i,j) == 3:
            crossing = (i,j)
    
    for n in find_neighbours(*crossing):
      array[n[0]][n[1]] = " "
      if len(tail_pos(False)) >= 2:
        array[n[0]][n[1]] = "+"
      else:
        broken = n
        break
    
    print("tail: {}  link: {}  break:{}".format(tail,link,broken))

  for line in array:
    print(line)
    
