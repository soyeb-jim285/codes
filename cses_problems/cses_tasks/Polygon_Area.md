![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Polygon Area

  * Task
  * Statistics

CSES - Polygon Area

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to calculate the area of a given polygon.

The polygon consists of $n$ vertices $(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)$.
The vertices $(x_i,y_i)$ and $(x_{i+1},y_{i+1})$ are adjacent for
$i=1,2,\dots,n-1$, and the vertices $(x_1,y_1)$ and $(x_n,y_n)$ are also
adjacent.

# Input

The first input line has an integer $n$: the number of vertices.

After this, there are $n$ lines that describe the vertices. The $i$th such
line has two integers $x_i$ and $y_i$.

You may assume that the polygon is simple, i.e., it does not intersect itself.

# Output

Print one integer: $2a$ where the area of the polygon is $a$ (this ensures
that the result is an integer).

# Constraints

  * $3 \le n \le 1000$
  * $-10^9 \le x_i, y_i \le 10^9$

# Example

Input:

``` 4 1 1 4 2 3 5 1 4 ```

Output:

``` 16 ```

#### Geometry

Point Location TestLine Segment IntersectionPolygon AreaPoint in
PolygonPolygon Lattice PointsMinimum Euclidean DistanceConvex Hull

* * *

