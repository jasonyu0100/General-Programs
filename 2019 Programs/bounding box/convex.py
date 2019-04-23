import math
import random
from dataclasses import dataclass

def get_points(file):
    with open(file) as f:
        lines = f.read().splitlines()
    points = []
    for line in lines:
        x, y = map(float, line.split(','))
        points.append(Point(x, y))
    return points

def get_random_points(n=10):
    ret = []
    for _ in range(n):
        ret.append(
            Point(random.randint(1, 100), random.randint(1, 100))
        )
    return ret

@dataclass
class Point:
    x: float 
    y: float

    def __iter__(self):
        return iter((self.x, self.y))
    
    def __eq__(self, other):
        return tuple(self) != tuple(other)
    
    def __hash__(self):
        return hash(tuple(self))
    
    def __lt__(self, other):
        return tuple(self) < tuple(other)


def convex_hull(points):
    """Computes the convex hull of a set of 2D points."""

    points = sorted(set(points))

    def cross(o, a, b):
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x)

    # Build lower hull 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)

    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper
    
if __name__ == '__main__':
    import matplotlib.pyplot as plt

    points = get_random_points(n=100)
    plt.scatter(*zip(*points))
    import time
    start = time.time()
    hull = convex_hull(points)
    end = time.time()
    print(end - start)
    plt.plot(*zip(*hull), color='red')
    plt.show()