<h1 style='text-align: center;'> B. Vittorio Plays with LEGO Bricks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vittorio is playing with his new LEGO Duplo bricks. All the bricks have the shape of a square cuboid with a $2 \times 2$ square base and a height of $1$. They can be arranged in the 3D space to build structures, provided that the following rules are met:

1. No two bricks can intersect, but they can touch on their faces.
2. The corners of every brick must have integer coordinates (so bricks are axis-aligned) and the $z$ coordinates of all corners must be non-negative.
3. The square bases of every brick must be parallel to the ground (i.e. the plane $z=0$).
4. The lower base of any brick that is not touching the ground must touch the upper base of some other brick in a region of positive area (when this happens, the two bricks stay attached to each other thanks to small studs).

For example, this is a valid structure:

 ![](images/9afb503018bc602002aa5e9fefb7b294f7df1d8d.png) Vittorio wants to build a structure that includes purple bricks in the following $n$ positions: $(x_1, 0, h)$, $(x_2, 0, h)$, $\dots$, $(x_n, 0, h)$ — these are the coordinates of the centers of their lower bases; note that all of these bricks have $y$ coordinate equal to $0$ and $z$ coordinate equal to $h$. Vittorio will use additional bricks of other colors to support the purple bricks. He is willing to place bricks only in positions where the center of the lower base has $y$ coordinate equal to $0$. What is the minimum number of additional bricks needed?

It can be shown that a valid construction always exists.

## Input

The first line contains two integers $n$ and $h$ ($1 \le n \le 300$, $0 \le h \le 10^9$) — the number of purple bricks and their common $z$ coordinate.

The second line contains $n$ integers $x_1, \, x_2, \, \dots, \, x_n$ ($1 \le x_i \le 10^9$, $x_i + 1 < x_{i+1}$) — the $x$ coordinates of the purple bricks (centers of the bases), given in increasing order.

## Output

Print the minimum number of additional bricks needed.

## Examples

## Input


```

4 0
2 7 11 13

```
## Output


```

0

```
## Input


```

4 1
2 7 11 13

```
## Output


```

3

```
## Input


```

4 100
2 7 11 13

```
## Output


```

107

```
## Input


```

4 3
2 5 8 11

```
## Output


```

8

```
## Note

In the first sample, all the purple bricks lie on the ground, so no additional bricks are needed.

In the second sample, Vittorio will have to place supporting bricks under the purple bricks, and he can use a single brick to support both the third and the fourth purple bricks. For example, he can place additional bricks at positions $(3, 0, 0)$, $(7, 0, 0)$ and $(12, 0, 0)$. It can be shown that it is impossible to build a valid construction using less than $3$ additional bricks.

In the fourth sample, a possible structure that minimizes the number of additional bricks is shown in the problem description.



#### tags 

#2200 #dp #geometry 