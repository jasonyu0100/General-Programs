import math
with open('input.txt') as f:
    grid = []
    r,c,rotations = map(int,f.readline().split())
    for i in range(r):
        row = list(map(int,f.readline().split()))
        grid.append(row)

    ordered_squares = []
    width = c
    height = r
    layer_num = 0
    while width > 0 and height > 0:
        top    =  list((0,col_change) for col_change in range(width))
        right  =  list((row_change,width-1)for row_change in range(1,height))
        bottom =  list((height-1,width-1-col_change) for col_change in range(1,width))
        left   =  list((height-1-row_change,0) for row_change in range(1,height-1))
        ordered_changes = top + right + bottom + left
        ordered_square = [grid[layer_num + row_change][layer_num + col_change] for row_change,col_change in ordered_changes]
        ordered_squares.append(ordered_square)
        width -= 2
        height -= 2
        layer_num += 1

    for n in range(rotations):
        for square in ordered_squares:
            square.append(square.pop(0))

    width = c
    height = r
    layer_num = 0
    new_grid = [[0]*width for i in range(height)]
    while width > 0 and height > 0:
        ordered_square = ordered_squares[layer_num]
        top    =  list((0,col_change) for col_change in range(width))
        right  =  list((row_change,width-1)for row_change in range(1,height))
        bottom =  list((height-1,width-1-col_change) for col_change in range(1,width))
        left   =  list((height-1-row_change,0) for row_change in range(1,height-1))
        ordered_changes = top + right + bottom + left
        ordered_coords = [(layer_num + row_change,layer_num + col_change) for row_change,col_change in ordered_changes]
        for n,coord in enumerate(ordered_coords):
            row,col = coord
            new_grid[row][col] = ordered_square[n]
        width -= 2
        height -= 2
        layer_num += 1
    for row in (new_grid):
        print(row)
