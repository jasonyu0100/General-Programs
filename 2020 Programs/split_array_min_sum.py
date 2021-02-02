nums = [7,5,3,6,10]
m = 3
cache = {}
infinity = 1000

def helper_func(nums, m):
    if m == 1:
        return sum(nums)
    elif m>len(nums):
        return 1000
    else:
        x = infinity
        for pos in range(1, len(nums)):
            left_array = nums[:pos]
            right_array = nums[pos:]
            right = helper_func(right_array, m - 1)
            y= max(right, sum(left_array))
            if y < x:
                x = y
        return x 

def split_array_min_sum(nums, m):
    return helper_func(nums, m)

print(split_array_min_sum(nums, m))