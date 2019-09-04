def generate_solution(a,b):
  path_dict = {(a,b):[]}
  found = False
  while found is False:
    new_dict = dict()
    for combo, path in path_dict.items():
      new_a,new_b = combo
      new_dict[(new_a+1,2*new_b)] = path + ['R1']
      new_dict[(2*new_a,new_b+1)] = path + ['R2']
    path_dict = new_dict
    for c,d in new_dict:
      if c == d: 
        return new_dict[(c,d)]
  

  

def generate_sequence(a,b,actions):
  output = [(a,b)]
  for action in actions:
    previous_output = output[-1]
    old_a,old_b = previous_output
    if action == 'R1':
      output.append((old_a+1,old_b*2))
    else:
      output.append((old_a*2,old_b+1))
  return output


out = []
with open('input.txt') as f:
  num_lines = f.readline()
  for line in f.readlines():
    a, b = [int(i) for i in line.split()]
    actions = generate_solution(a,b)
    output = generate_sequence(a,b, actions)
    print('  '.join(','.join(map(str,item)) for item in output))


