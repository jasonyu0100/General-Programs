#BODMAS
#BRACKET
#ORDERS
#DIVISION
#MULITPLICATOIN
#ADDITION
#SUBTRACTION

import math

class Symbol:
	def __init__(self,left,right):
		self.left = left
		self.right = right

class Equation:
	def __init__(self,equation,initial=False):
		if initial == False:
			self.equation = equation
		else:
			self.equation = [float(value) if value.isdigit() else value for value in equation]

	def solve(self):
		self.bracketTokenisation()
		self.powerApplication()
		self.productApplication()
		self.linearApplication()
		finalValue = self.equation[0]
		return finalValue

	def bracketTokenisation(self):
		start = None
		end = None
		for i,token in enumerate(self.equation):
			if token == '(':
				start = i
			elif token == ')':
				end = i
				break
			else:
				pass
		if start != None and end != None:
			bracketEquation = Equation(self.equation[start+1:end]).solve()
			if end != len(self.equation) - 1:
				self.equation = self.equation[:start] + [bracketEquation] + self.equation[end+1:]
			else:
				self.equation = self.equation[:start] + [bracketEquation]
			self.bracketTokenisation()
	def powerApplication(self):
		for i,token in enumerate(self.equation):
			if token == "**" or token == "^":
				base = self.equation[i-1]
				power = self.equation[i+1]
				powerValue = Power(base,power).solve()
				break
		else:
			return
		if i+1 != len(self.equation):
			self.equation = self.equation[:i-1] + [powerValue] + self.equation[i+2:]
		else:
			self.equation = self.equation[:i-1] + [powerValue]
		self.powerApplication()

	def productApplication(self):
		for i,token in enumerate(self.equation):
			if token == "*":
				firstNumber = self.equation[i-1]
				secondNumber = self.equation[i+1]
				product = Multiply(firstNumber,secondNumber).solve()
				break
			elif token == "/":
				firstNumber = self.equation[i-1]
				secondNumber = self.equation[i+1]
				product = Divide(firstNumber,secondNumber).solve()
				break
		else:
			return
		if i+1 != len(self.equation):
			self.equation = self.equation[:i-1] + [product] + self.equation[i+2:]
		else:
			self.equation = self.equation[:i-1] + [product]
		self.productApplication()

	def linearApplication(self):
		for i,token in enumerate(self.equation):
			if token == "+":
				firstNumber = self.equation[i-1]
				secondNumber = self.equation[i+1]
				total = Add(firstNumber,secondNumber).solve()
				break
			elif token == "/":
				firstNumber = self.equation[i-1]
				secondNumber = self.equation[i+1]
				total = Sub(firstNumber,secondNumber).solve()
				break
		else:
			return
		if i+1 != len(self.equation):
			self.equation = self.equation[:i-1] + [total] + self.equation[i+2:]
		else:
			self.equation = self.equation[:i-1] + [total]
		self.linearApplication()
		

class Power(Symbol):
	def __init__(self,left,right):
		super().__init__(left,right)

	def solve(self):
		return math.pow(self.left,self.right)

class Multiply(Symbol):
	def __init__(self,left,right):
		super().__init__(left,right)

	def solve(self):
		return self.left * self.right

class Divide(Symbol):
	def __init__(self,left,right):
		super().__init__(left,right)

	def solve(self):
		return self.left / self.right

class Add(Symbol):
	def __init__(self,left,right):
		super().__init__(left,right)

	def solve(self):
		return self.left + self.right

class Sub(Symbol):
	def __init__(self,left,right):
		super().__init__(left,right)

	def solve(self):
		return self.left - self.right


sequence = input("Enter a maths equation: ").split(" ")
equation = Equation(sequence,initial=True)
print(equation.solve())

