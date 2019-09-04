def output_to_file(l):
  with open('output.txt','w') as f:
    for i in l:
      initial, final = map(lambda x: ' '.join(x), i)
      f.write(initial+'\n')
      f.write(final+'\n')
      f.write('\n')

import string
import copy

def swap(position_one, position_two, l):
  temp = l[position_one]
  l[position_one] = l[position_two]
  l[position_two] = temp

def get_final_position(length, actions):
  letters = (list(string.ascii_uppercase))
  final = letters[:length]
  initial = letters[:length]
  queue = copy.deepcopy(initial)
  count = 0
  letter_position_dict = {letter:position for position,letter in enumerate(initial)}
  while len(queue) != 0:
    letter = queue.pop(0)
    action = actions[count]
    position_one = letter_position_dict[letter]
    position_two = action - 1
    if action == 0:
      pass
    else:
      other_letter = final[position_two]
      letter_position_dict[letter] = position_two
      letter_position_dict[other_letter] = position_one
      swap(position_one,position_two, final)
    count += 1
  return initial,final




with open('input.txt') as f:
  lines = int(f.readline())
  output = []
  for i in range(lines):
    params = list(map(int,f.readline().split()))
    length = params[0]
    actions = params[1:]
    output.append(get_final_position(length,actions))
  output_to_file(output)




    