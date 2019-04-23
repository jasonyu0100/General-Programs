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

    def __hash__(self): 
        return hash((self.x, self.y))

    def __iter__(self):
        return iter((self.x, self.y))
    
    def __repr__(self):
        return f'(x={self.x}, y={self.y})'

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
    @staticmethod
    def get_starting_point(points):
        """Returns the bottom-most point"""
        return min(points, key=lambda point: point.y)

    @staticmethod
    def radians_to_degrees(radians):
        return radians / math.pi * 180

    @staticmethod
    def gradient(point1,point2):
      delta_y = (point2.y - point1.y)
      delta_x = (point2.x - point1.x)
      if delta_y == 0: return 0
      elif delta_x == 0: return math.inf
      else: return delta_y / delta_x

    @staticmethod
    def check_below_line(point,left_point,right_point):
      gradient = Point.gradient(left_point,right_point)
      if gradient == 0: return point.y < left_point.y # If point y is less, it is below
      elif gradient == math.inf: return point.y < max([left_point.y,right_point.y]) # point y is less than max, it is below
      else:
        line_equation = lambda x: gradient * (x - left_point.x) + left_point.y
        return point.y <= line_equation(point.x) #Below line


def alternative_bounding_box(points):
  starting_point = Point.get_starting_point(points)
  points.remove(starting_point)
  theta_dict = {}
  for point in points:
    delta_x = point.x - starting_point.x
    delta_y = point.y - starting_point.y
    theta = Point.radians_to_degrees(math.atan2(delta_y,delta_x))
    theta_dict[point] = theta
  sorted_points = sorted(theta_dict, key=lambda k:theta_dict[k])
  left = []
  right = []
  while True:
    if len(sorted_points) == 0:
      break
    elif len(sorted_points) == 1:
      left.append(sorted_points[0])
      break
    left_point = sorted_points.pop()
    right_point = sorted_points.pop(0)
    left.append(left_point)
    right.append(right_point)
    sorted_points = [point for point in sorted_points if not Point.check_below_line(point,left_point,right_point)]
  return [starting_point] + right + list(reversed(left)) + [starting_point]
  



def get_random_points(n=10):
    ret = []
    for _ in range(n):
        ret.append(
            Point(random.randint(1, 100), random.randint(1, 100))
        )
    return ret

if __name__ == '__main__':
    import matplotlib.pyplot as plt
    points = get_points("data2.txt")
    import time

    start = time.time()
    box = alternative_bounding_box(points)
    end = time.time()
    print(end - start)
    plt.plot(*zip(*box), color='red')
    plt.show()