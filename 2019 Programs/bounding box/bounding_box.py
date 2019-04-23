import math
import random

def get_points(file):
    with open(file) as f:
        lines = f.read().splitlines()
    points = []
    for line in lines:
        x, y = map(float, line.split(','))
        points.append(Point(x, y))
    return points


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __iter__(self):
        return iter((self.x, self.y))
    
    def __repr__(self):
        return f'(x={self.x}, y={self.y})'

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def positive_theta(self,other):
        """
        Theta ranging from 0->360, angle vector from self to other
        """
        delta_x = other.x - self.x
        delta_y = other.y - self.y
        theta = self.radians_to_degrees(math.atan2(delta_y,delta_x))
        if theta < 0: theta += 360
        return theta
    
    @staticmethod
    def get_starting_point(points):
        """Returns the bottom-most point"""
        return min(points, key=lambda point: point.y)

    @staticmethod
    def radians_to_degrees(radians):
        return radians / math.pi * 180

def bounding_box(points):
    bounding_box = []
    current_theta = 0
    starting = current = Point.get_starting_point(points)

    while True:
        bounding_box.append(current) 
        points.remove(current)

        point_thetas = [
            [other, current.positive_theta(other)]
            for other in points + [starting] 
                if current.positive_theta(other) >= current_theta and current is not other
        ]
        current, current_theta = min(point_thetas, key=lambda pt: pt[1]) 
        if current is starting: 
            return bounding_box + [starting]

def get_random_points(n=10):
    ret = []
    for _ in range(n):
        ret.append(
            Point(random.randint(1, 20), random.randint(1, 20))
        )
    return ret

if __name__ == '__main__':
    import matplotlib.pyplot as plt

    points = get_points('data2.txt')
    print(points)
    plt.scatter(*zip(*points))
    import timeit
    start = timeit.timeit()
    box = bounding_box(points)
    end = timeit.timeit()
    print(end - start)
    plt.plot(*zip(*box))
    plt.show()