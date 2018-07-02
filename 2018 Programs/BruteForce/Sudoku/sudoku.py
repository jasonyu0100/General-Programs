class Sudoku:
	def __init__(self,grid):
		self.grid = grid
		self.numberSet = set(range(1,10))
		self.iterations = 0

	@staticmethod
	def importGrid(fileName):
		grid = []
		with open(fileName) as f:
			for line in f:
				row = list(map(int,line.split()))
				grid.append(row)
		return Sudoku(grid)

	def getRowSet(self,row):
		return set(self.grid[row])

	def getColSet(self,col):
		return set(self.grid[r][col] for r in range(9))

	def getSquareSet(self,row,col):
		rowBounds = range(row - (row % 3),row - (row % 3) + 3)
		colBounds = range(col - (col % 3),col - (col % 3) + 3)
		return set(self.grid[rowValue][colValue] for rowValue in rowBounds for colValue in colBounds)

	def getPossibilities(self,row,col):
		rowSet = self.getRowSet(row)
		colSet = self.getColSet(col)
		squareSet = self.getSquareSet(row,col)
		return self.numberSet - (rowSet | colSet | squareSet)

	def display(self):
		for row in self.grid:
			print(' '.join(map(str,row)))
		print('')

	def getEmpty(self):
		empty = []
		for r,row in enumerate(self.grid):
			for c,value in enumerate(row):
				if value == 0:
					empty.append((r,c))
		return empty

	def solved(self):
		for r,row in enumerate(self.grid):
			rowSet = self.getRowSet(r)
			for c,value in enumerate(row):
				colSet = self.getColSet(c)
				squareSet = self.getSquareSet(r,c)
				if any(map(lambda x:x!=self.numberSet,[squareSet,colSet,rowSet])):
					return False
		return True

	def getSortedPossiblities(self):
		values = {}
		for row,col in self.getEmpty():
			values[(row,col)] = self.getPossibilities(row,col)
		sortedValues = sorted(values.items(),key=lambda x:len(x[1]))
		return sortedValues

	def solve2(self):
		for coord,possibilities in self.getSortedPossiblities():
			row,col = coord
			if self.grid[row][col] != 0:
				continue
			for possibility in possibilities:
				self.iterations += 1
				self.grid[row][col] = possibility
				if self.solve2() == True:
					break
				else:
					self.grid[row][col] = 0
			else:
				return False
		return self.solved()

	def solve(self):
		for row,col in self.getEmpty():
			if self.grid[row][col] != 0:
				continue
			for possibility in sorted(self.getPossibilities(row,col)):
				self.iterations += 1
				self.grid[row][col] = possibility
				if self.solve() == True:
					break
				else:
					self.grid[row][col] = 0
			else:
				return False
		return self.solved()




sudoku = Sudoku.importGrid('input.txt')
sudoku.solve()
sudoku.display()
print(sudoku.iterations)