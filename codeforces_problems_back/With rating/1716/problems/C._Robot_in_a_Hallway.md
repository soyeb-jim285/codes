<h1 style='text-align: center;'> C. Robot in a Hallway</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a grid, consisting of $2$ rows and $m$ columns. The rows are numbered from $1$ to $2$ from top to bottom. The columns are numbered from $1$ to $m$ from left to right.

The robot starts in a cell $(1, 1)$. In one second, it can perform either of two actions: 

* move into a cell adjacent by a side: up, right, down or left;
* remain in the same cell.

The robot is not allowed to move outside the grid.

Initially, all cells, except for the cell $(1, 1)$, are locked. Each cell $(i, j)$ contains a value $a_{i,j}$ — the moment that this cell gets unlocked. The robot can only move into a cell $(i, j)$ if at least $a_{i,j}$ seconds have passed before the move.

The robot should visit all cells without entering any cell twice or more (cell $(1, 1)$ is considered entered at the start). It can finish in any cell.

What is the fastest the robot can achieve that?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $m$ ($2 \le m \le 2 \cdot 10^5$) — the number of columns of the grid.

The $i$-th of the next $2$ lines contains $m$ integers $a_{i,1}, a_{i,2}, \dots, a_{i,m}$ ($0 \le a_{i,j} \le 10^9$) — the moment of time each cell gets unlocked. $a_{1,1} = 0$. If $a_{i,j} = 0$, then cell $(i, j)$ is unlocked from the start.

The sum of $m$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the minimum amount of seconds that the robot can take to visit all cells without entering any cell twice or more.

## Example

## Input


```

430 0 14 3 250 4 8 12 162 6 10 14 1840 10 10 1010 10 10 1020 00 0
```
## Output


```

5
19
17
3

```


#### tags 

#2000 #data_structures #dp #greedy #implementation #ternary_search 