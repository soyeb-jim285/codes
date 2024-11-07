![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Point Location Test

  * Task
  * Statistics

CSES - Point Location Test

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is a line that goes through the points $p_1=(x_1,y_1)$ and
$p_2=(x_2,y_2)$. There is also a point $p_3=(x_3,y_3)$.

Your task is to determine whether $p_3$ is located on the left or right side
of the line or if it touches the line when we are looking from $p_1$ to $p_2$.

# Input

The first input line has an integer $t$: the number of tests.

After this, there are $t$ lines that describe the tests. Each line has six
integers: $x_1$, $y_1$, $x_2$, $y_2$, $x_3$ and $y_3$.

# Output

For each test, print "LEFT", "RIGHT" or "TOUCH".

# Constraints

  * $1 \le t \le 10^5$
  * $-10^9 \le x_1, y_1, x_2, y_2, x_3, y_3 \le 10^9$
  * $x_1 \neq x_2$ or $y_1 \neq y_2$

# Example

Input:

``` 3 1 1 5 3 2 3 1 1 5 3 4 1 1 1 5 3 3 2 ```

Output:

``` LEFT RIGHT TOUCH ```

#### Geometry

Point Location TestLine Segment IntersectionPolygon AreaPoint in
PolygonPolygon Lattice PointsMinimum Euclidean DistanceConvex Hull

* * *

