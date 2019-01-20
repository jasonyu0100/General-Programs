from math import inf
from functools import reduce

def word_conversion(word, target):
  target_len = len(target)
  word_len = len(word)
  len_dif = target_len-word_len
  if len_dif == 0: # Target and word length are the same
    total_cost = 0
    for index in range(target_len):
      target_letter = target[index]
      current_letter = word[index]
      if target_letter != current_letter: total_cost += 1 #Conversion Cost
    return total_cost
  elif len_dif > 0: # Target length is bigger than word length
    current_min = inf
    current_min_index = 0
    for starting_index in range(0, len_dif+1):
      compare_word = word[starting_index:starting_index+word_len]
      cost = word_conversion(target,compare_word)
      if cost < current_min:
        current_min, current_min_index = cost, starting_index
    total_cost = current_min + len_dif
    return total_cost
  else: # Target length is less than word length
    current_min = inf
    compare_words = getRemovalWordCombinations(word,target_len)
    for compare_word in compare_words:
      cost = word_conversion(target,compare_word)
      if cost < current_min:
        current_min = cost
    total_cost = current_min + abs(len_dif)
    return total_cost

def getRemovalWordCombinations(word,goal_word_length):
  if len(word) == goal_word_length:
    return [word]
  all_words = []
  for index in range(len(word)):
    if index+1 == len(word): adjusted_word = word[:index]
    else: adjusted_word = word[:index] + word[index+1:]
    words = getRemovalWordCombinations(adjusted_word,goal_word_length)
    all_words += words
  return set(all_words)




if __name__ == "__main__":
  word = input("Enter a word: ")
  target = input("Enter a target word: ")
  print(word_conversion(word,target))