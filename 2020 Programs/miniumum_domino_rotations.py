A = [1,2,1,1,1,2,2,2]
B = [2,1,2,2,2,2,2,2]

def min_rotations(A,B):
    a = list(zip(A,B))
    values = set(a[0])
    for pair in a:
        values &= set(pair)
    if len(values) == 0:
        return -1
    else:
        totals = []
        for val in values:
            total = 0
            for curr_val in A:
                if curr_val != val: total += 1
            totals.append(total)
            total = 0
            for curr_val in B:
                if curr_val != val: total += 1
            totals.append(total)
        return min(totals)
print(min_rotations(A,B))