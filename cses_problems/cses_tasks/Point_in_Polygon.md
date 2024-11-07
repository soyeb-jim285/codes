![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Point in Polygon

  * Task
  * Statistics

CSES - Point in Polygon

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a polygon of $n$ vertices and a list of $m$ points. Your task is
to determine for each point if it is inside, outside or on the boundary of the
polygon.

The polygon consists of $n$ vertices $(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)$.
The vertices $(x_i,y_i)$ and $(x_{i+1},y_{i+1})$ are adjacent for
$i=1,2,\dots,n-1$, and the vertices $(x_1,y_1)$ and $(x_n,y_n)$ are also
adjacent.

# Input

The first input line has two integers $n$ and $m$: the number of vertices in
the polygon and the number of points.

After this, there are $n$ lines that describe the polygon. The $i$th such line
has two integers $x_i$ and $y_i$.

You may assume that the polygon is simple, i.e., it does not intersect itself.

Finally, there are $m$ lines that describe the points. Each line has two
integers $x$ and $y$.

# Output

For each point, print "INSIDE", "OUTSIDE" or "BOUNDARY".

# Constraints

  * $3 \le n,m \le 1000$
  * $1 \le m \le 1000$
  * $-10^9 \le x_i, y_i \le 10^9$
  * $-10^9 \le x, y \le 10^9$

# Example

Input:

``` 4 3 1 1 4 2 3 5 1 4 2 3 3 1 1 3 ```

Output:

``` INSIDE OUTSIDE BOUNDARY ```

#### Geometry

Point Location TestLine Segment IntersectionPolygon AreaPoint in
PolygonPolygon Lattice PointsMinimum Euclidean DistanceConvex Hull

* * *

