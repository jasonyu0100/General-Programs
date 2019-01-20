import time


def timer(func):
    def wrapper(l):
        start = time.time()
        val = func(l)
        end = time.time()
        print(end - start)
        return val
    return wrapper
