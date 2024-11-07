![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Line Segment Intersection

  * Task
  * Statistics

CSES - Line Segment Intersection

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are two line segments: the first goes through the points $(x_1,y_1)$ and
$(x_2,y_2)$, and the second goes through the points $(x_3,y_3)$ and
$(x_4,y_4)$.

Your task is to determine if the line segments intersect, i.e., they have at
least one common point.

# Input

The first input line has an integer $t$: the number of tests.

After this, there are $t$ lines that describe the tests. Each line has eight
integers $x_1$, $y_1$, $x_2$, $y_2$, $x_3$, $y_3$, $x_4$ and $y_4$.

# Output

For each test, print "YES" if the line segments intersect and "NO" otherwise.

# Constraints

  * $1 \le t \le 10^5$
  * $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4 \le 10^9$
  * $(x_1,y_1) \neq (x_2,y_2)$
  * $(x_3,y_3) \neq (x_4,y_4)$

# Example

Input:

``` 5 1 1 5 3 1 2 4 3 1 1 5 3 1 1 4 3 1 1 5 3 2 3 4 1 1 1 5 3 2 4 4 1 1 1 5 3
3 2 7 4 ```

Output:

``` NO YES YES YES YES ```

#### Geometry

Point Location TestLine Segment IntersectionPolygon AreaPoint in
PolygonPolygon Lattice PointsMinimum Euclidean DistanceConvex Hull

* * *

