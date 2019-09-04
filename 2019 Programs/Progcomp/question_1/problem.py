keypad = ["ABCDEFG","HIJKLMN","OPQRSTU","VWXYZ"]
def find(char):
  for i,row in enumerate(keypad):
    if char in row:
      return i,row.index(char)

out = open("output.txt", "w")
with open("input.txt") as f:
  for line in f:
    line = line.strip()
    line = line.upper()
    valid = True
    for prev,cur in zip(line[:-1],line[1:]):
      if prev == cur:
        continue
      prev = find(prev)
      cur = find(cur)
      if prev[0] == cur[0]:
        continue
      elif prev[1] == cur[1]:
        continue
      valid = False
      break
    if valid:
      print(line.lower(), file=out)

out.close()
