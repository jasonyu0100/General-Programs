string = list(input("Enter a string"))
letters = set(string)
found = set()
newString = ''
for char in string:
	if char not in found:
		newString += char
		found.add(char)
print(newString)
