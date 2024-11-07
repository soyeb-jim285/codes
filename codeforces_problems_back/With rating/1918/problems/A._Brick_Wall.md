<h1 style='text-align: center;'> A. Brick Wall</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A brick is a strip of size $1 \times k$, placed horizontally or vertically, where $k$ can be an arbitrary number that is at least $2$ ($k \ge 2$).

A brick wall of size $n \times m$ is such a way to place several bricks inside a rectangle $n \times m$, that all bricks lie either horizontally or vertically in the cells, do not cross the border of the rectangle, and that each cell of the $n \times m$ rectangle belongs to exactly one brick. Here $n$ is the height of the rectangle $n \times m$ and $m$ is the width. ## Note

 that there can be bricks with different values of k in the same brick wall.

The wall stability is the difference between the number of horizontal bricks and the number of vertical bricks. ## Note

 that if you used $0$ horizontal bricks and $2$ vertical ones, then the stability will be $-2$, not $2$.

What is the maximal possible stability of a wall of size $n \times m$?

It is guaranteed that under restrictions in the statement at least one $n \times m$ wall exists.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 10\,000$), the number of test cases. 

The only line of each test case contains two integers $n$ and $m$ ($2 \le n,\,m \le 10^4$).

## Output

For each test case, print one integer, the maximum stability of a wall of size $n \times m$.

## Example

## Input


```

52 27 816 93 510000 10000
```
## Output


```

2
28
64
6
50000000

```
## Note

In the 1st test case, the maximum stability of $2$ is obtained by placing two horizontal bricks $1 \times 2$ one on top of the other.

In the 2nd test case, one can get the maximum stability of $28$ by placing $4$ horizontal bricks $1 \times 2$ in each of the $7$ rows.



#### tags 

#800 #constructive_algorithms #greedy #implementation #math 