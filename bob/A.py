import sys
import math

input = sys.stdin.read
output = sys.stdout.write


def area(ax, ay, bx, by, cx, cy):
    # Compute the area as a floating-point value when necessary
    return abs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) / 2.0


def dist_squared(ax, ay, bx, by):
    # Return squared distance between points a and b as integers
    return (ax - bx) ** 2 + (ay - by) ** 2


def solve(l, coords):
    r = l / 2.0  # Convert to floating-point for radius calculation
    ax, ay, bx, by, cx, cy = coords

    # If any two points are the same, it's a degenerate triangle
    if (ax == bx and ay == by) or (bx == cx and by == cy) or (cx == ax and cy == ay):
        output("0\n")
        return

    # Calculate the triangle area (floating-point)
    triangle_area = area(ax, ay, bx, by, cx, cy)

    # Calculate side lengths as integers, then cast to floating-point
    ab = math.sqrt(dist_squared(ax, ay, bx, by))
    bc = math.sqrt(dist_squared(bx, by, cx, cy))
    ca = math.sqrt(dist_squared(cx, cy, ax, ay))
    s = (ab + bc + ca) / 2.0  # Semi-perimeter (floating-point)

    # Calculate the inradius (floating-point)
    r_in = triangle_area / s

    # If inradius is smaller than blade radius, the blade can't cover the triangle
    if r_in < r:
        output("0\n")
        return

    # Calculate the corner area (floating-point)
    corner_area = r * r * s / r_in
    result = triangle_area - corner_area + r * r * math.pi
    output(f"{result:.6f}\n")  # Print result with 6 decimal precision


def main():
    data = input().split()
    idx = 0
    t = int(data[idx])  # Number of test cases
    idx += 1

    for _ in range(t):
        l = int(data[idx])  # Length of blade
        idx += 1
        coords = list(map(int, data[idx : idx + 6]))  # Read 6 integer coordinates
        idx += 6
        solve(l, coords)


if __name__ == "__main__":
    main()
