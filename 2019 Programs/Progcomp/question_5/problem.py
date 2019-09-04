losing_grids = [
  [
    [1,1],
    [1,1],
    [1,0]
  ],
  [
    [1,1,1],
    [1,1,0],
  ]
  ,
  [
    [1,1,1,1],
    [1,1,0,0]
    [1,1,0,0]
  ],
  [
    [1,1,1],
    [1,1,1],
    [1,0,0],
    [1,0,0]
  ]
]

def is_losing(grid):
  if len(grid) == length_of_col(grid, 0):
    return True
  else:
    for losing_grid in losing_grids:
      for i in range(losing_grid):
        for j in range(losing_grid[i]):
          if losing_grid[i][j] != grid[i][j]
            break
      else:
        return True
    else:
      return False

def winnning_move(grid, possible_moves,player_move):
  for move in possible_moves:
    new_grid = take(grid, move, player_move)
    if is_losing(new_grid):
      return move
  else:
    return False

def player_A_strategy():
  # eats right most square of the last row of second 2 or more
  # else eat right most col square of first row
  pass


def player_B_strategy():
  # Eat right most square of second row from topp
  # else eat right most col square of first row
  pass

def length_of_col(grid, col_num):
  length = 0
  for r in range(len(grid))
    if grid[r][0] == 0:
      break
    else:
      length += 1
  return length

def display_board_position(grid):
  for r in range(len(grid)):
    for c in range(len(grid[r])):
      if r == 1 == c:
        print('&',end='')
      if grid[r][c] == 1:
        print('#',end='')
    print()
  

def take(grid, move, player):
  r,c = move
  grid[r][c] = 0
  for new_c in range(c,len(grid[r])):
    grid[r][new_c] = 0
  length_of_col(grid,c)
  for new_c in range(r,length_of_col)):
    grid[r][new_c] = 0
  print(f'{player} eats {move}')
  return grid

def possible_moves(grid):
  possible=[]
  for r in range(len(grid)):
    for c in range(len(grid[r])):
      if grid[r][c] == 0:
        possible.append((r,c))
  return possible


initial_board = 
"""
@##
###
###
###
###
""".split('\n')


player_move = 'A'
win = False
while win is False:
  if is_losing(grid):
    take(1,1, player_move)
  else:
    possible_moves = get_possible_moves(grid)
    winning_move = check_winning_move(grid, possible_moves, player_move)
    if winnning_move == False:
      if player_move == 'A':
        player_A_strategy()
      else:
        player_B_strategy()
    else:
      take(winning_move)
  if player_move == 'A':
    player_move = 'B'
  else: player_move = 'A'

