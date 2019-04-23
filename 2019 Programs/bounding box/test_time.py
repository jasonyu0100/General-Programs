from alternative_bounding import get_points
from alternative_bounding import *
# from bounding_box import *
# from convex import *

if __name__ == '__main__':
    points = get_points('data2.txt')
    import timeit
    # start = timeit.timeit()
    # box = bounding_box(points)
    # end = timeit.timeit()
    # print(end - start)

    # start = timeit.timeit()
    # box = convex_hull(points)
    # end = timeit.timeit()
    # print(end - start)

    start = timeit.timeit()
    box = alternative_bounding_box(points)
    end = timeit.timeit()
    print(end - start)