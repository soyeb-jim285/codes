<h1 style='text-align: center;'> E. Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given $n$ points on the plane, the coordinates of the $i$-th point are $(x_i, y_i)$. No two points have the same coordinates.

The distance between points $i$ and $j$ is defined as $d(i,j) = |x_i - x_j| + |y_i - y_j|$.

For each point, you have to choose a color, represented by an integer from $1$ to $n$. For every ordered triple of different points $(a,b,c)$, the following constraints should be met:

* if $a$, $b$ and $c$ have the same color, then $d(a,b) = d(a,c) = d(b,c)$;
* if $a$ and $b$ have the same color, and the color of $c$ is different from the color of $a$, then $d(a,b) < d(a,c)$ and $d(a,b) < d(b,c)$.

Calculate the number of different ways to choose the colors that meet these constraints.

## Input

The first line contains one integer $n$ ($2 \le n \le 100$) — the number of points.

Then $n$ lines follow. The $i$-th of them contains two integers $x_i$ and $y_i$ ($0 \le x_i, y_i \le 10^8$).

No two points have the same coordinates (i. e. if $i \ne j$, then either $x_i \ne x_j$ or $y_i \ne y_j$).

## Output

Print one integer — the number of ways to choose the colors for the points. Since it can be large, print it modulo $998244353$.

## Examples

## Input


```

3
1 0
3 0
2 1

```
## Output


```

9

```
## Input


```

5
1 2
2 4
3 4
4 4
1 3

```
## Output


```

240

```
## Input


```

4
1 0
3 0
2 1
2 0

```
## Output


```

24

```
## Note

In the first test, the following ways to choose the colors are suitable:

* $[1, 1, 1]$;
* $[2, 2, 2]$;
* $[3, 3, 3]$;
* $[1, 2, 3]$;
* $[1, 3, 2]$;
* $[2, 1, 3]$;
* $[2, 3, 1]$;
* $[3, 1, 2]$;
* $[3, 2, 1]$.


#### tags 

#2400 #brute_force #combinatorics #constructive_algorithms #dp #geometry #graphs #greedy #implementation #math 