grid = [[5,2,4],
        [1,5,7],
        [9,5,6]]

states = {}

for i in range(len(grid)):
    row = grid[i]
    for j in range(len(row)):
        try:
            left = grid[i][j-1]
        except:
            left = 0
        try:
            right = grid[i-1][j]
        except:
            right = 0
        states[(i,j)] = grid[i][j] + max(left,right)

print(max(states))
