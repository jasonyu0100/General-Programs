
def flag(first,second):
    final = ''
    if first > 7:
        final += "Danish\n"
        if second < 3:
            final += "happy"
    else:
        if second > 8:
            final += "Dan"
        elif second > 4:
            final += "Sally"
    if second < 10:
        final += ("ish\n")
    if first > second:
        final += ("\nFlag\n")
    else:
        final +=("Flag\n")
    return final


possibilities = set()
for i in range(1,12):
    for j in range(1,12):
        value = flag(i,j)
        possibilities.add(value)


first = 7
for i in range(1,12):
    value = flag(first,i)
    if value == "Danish\nFlag\n":
        print(i)
