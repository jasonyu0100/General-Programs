nums = [7,5,6,3,10]
m = 3
cache = {}
infinity = 479827304985702398457

def solve(nums, m):
    if (tuple(nums), m) in cache:
        return cache[(tuple(nums), m)]
    if m == 1:
        return sum(nums)
    if m > len(nums):
        return infinity
    x = infinity
    for i in range(1, len(nums)):
        y = max(sum(nums[:i]), solve(nums[i:], m-1))
        if y < x:
            x = y
    cache[(tuple(nums), m)] = x
    return x

print(solve(nums, m))