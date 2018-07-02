def recursion(num):
    if num <= 1:
        return 1
    return recursion(num-2) + recursion(num-1)


def memoized(func):
    cache = func.cache = {}
    def wrapper(*args):
        key = str(args)
        if key not in cache:
            cache[key] = func(*args)
        return cache[key]
    return wrapper
        

fib = memoized(recursion)
print(fib(20))
print(fib(20))
