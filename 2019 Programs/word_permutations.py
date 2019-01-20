from math import factorial
word = input("Enter a word: ")
comb_len = int(input("Enter a comb length: "))
letters  = set(word)
print(nPermK(len(letters),comb_len))

def nPermK(n,k):
  return factorial(n) / factorial(k)

