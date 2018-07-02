from functools import reduce

class Grid:
	def __init__(self,grid,rowSums,colSums,rows,cols):
		self.grid = grid
		self.rowSums = rowSums
		self.colSums = colSums
		self.empty = self.getEmpty()
		self.rowNum = rows
		self.colNum = cols
		self.numberSet = set(range(1,(self.rowNum * self.colNum) + 1))
		self.iterations = 0

	def solved(self):
		return self.checkSums() and self.checkGridSet()

	def possiblities(self,row,col):
		rowValues = set(self.grid[row])
		filteredSet = self.numberSet - rowValues
		maxValue = self.rowSums[row] - sum(filter(lambda x:type(x)==int,rowValues))
		possibilities = list(filter(lambda x:x<=maxValue,filteredSet))
		return possibilities

	def getEmpty(self):
		empty = []
		for r,row in enumerate(self.grid):
			for c,value in enumerate(row):
				if value == '.':
					empty.append((r,c))
		return empty

	def checkSums(self):
		rowCheck = all([sum(row) == rowSum for row,rowSum in zip(self.grid,self.rowSums)])
		transposed = [[row[col] for row in self.grid] for col in range(len(self.grid))]
		colCheck = all([sum(col) == colSum for col,colSum in zip(transposed,self.colSums)])
		return rowCheck and colCheck

	def checkGridSet(self):
		return set(reduce((lambda x,y:x+y),self.grid)) == self.numberSet

	@staticmethod
	def importFile(name):
		grid = []
		rowSums = []
		with open(name) as f:
			rows,cols = list(map((lambda x:int(x) if x.isdigit() else str(x)),f.readline().split()))
			for row in range(rows):
				line = list(map((lambda x:int(x) if x.isdigit() else str(x)),f.readline().split()))
				grid.append(line[:-1])
				rowSums.append(line[-1])
			colSums = list(map(int,f.readline().split()))
		return Grid(grid,rowSums,colSums,rows,cols)
		
	def completeGrid(self):
		for row,col in self.getEmpty():
			if self.grid[row][col] != '.':
				continue
			for possiblity in sorted(self.possiblities(row,col)):
				self.iterations += 1
				self.grid[row][col] = possiblity
				if self.completeGrid() == True:
					break
				else:
					self.grid[row][col] = '.'
			else:
				self.grid[row][col] = '.'
				return False
		return self.solved()

	def display(self):
		for r,row in enumerate(self.grid):
			print('-'.join(map(str,row)) + ' ' + str(self.rowSums[r]))
		print('-'.join(map(str,self.colSums)) + '\n')
			
grid = Grid.importFile('input.txt')
grid.display()
print(grid.completeGrid())
print(grid.iterations)
grid.display()