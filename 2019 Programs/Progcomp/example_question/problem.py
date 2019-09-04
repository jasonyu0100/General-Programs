def add(a,b):
  return a + b

def output_to_file(l):
  with open('output.txt','w') as f:
    for i in l:
      string_output = str(i)
      f.write(string_output+'\n')

with open('input.txt') as f:
  lines = int(f.readline())
  params = list(map(int,f.readline().split()))
  a,b = params
  output = []
  for i in range(10):
    output.append(add(a,b))
  output_to_file(output)




    