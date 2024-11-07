<h1 style='text-align: center;'> B. Grid Reconstruction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a $2 \times n$ grid, where $n$ is an even integer. You may place the integers $1, 2, \ldots, 2n$ on the grid, using each integer exactly once.

A path is a sequence of cells achieved by starting at $(1, 1)$, then repeatedly walking either downwards or to the right, and stopping when $(2, n)$ is reached. The path should not extend beyond the grid.

The cost of a path is the alternating sum of the numbers written on the cells in a path. That is, let the numbers written on the cells be $a_1, a_2, \ldots, a_k$ (in the order that it is visited), the cost of the path is $a_1 - a_2 + a_3 - a_4 + \ldots = \sum_{i=1}^k a_i \cdot (-1)^{i+1}$.

Construct a way to place the integers $1, 2, \ldots, 2n$ on the grid, such that the minimum cost over all paths from $(1, 1)$ to $(2, n)$ is maximized. If there are multiple such grids that result in the maximum value, output any of them.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of test cases follows.

The first and the only line of each test case contains a single integer $n$ ($2 \leq n \leq 10^5$, $n$ is even) — the number of the columns in the grid.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output $2$ lines, each containing $n$ integers — the desired grid. If there are multiple solutions, output any of them.

## Example

## Input


```

3246
```
## Output


```

3 2
1 4
8 2 6 4
1 5 3 7
11 5 9 1 7 3
6 10 2 8 4 12

```
## Note

In the first test case, there are only two paths from cell $(1, 1)$ to cell $(2, 2)$. Their costs are $3-1+4=6$ and $3-2+4=5$. Then the minimum cost is $5$, which is the maximum possible value.

In the second test case, there are four paths from cell $(1, 1)$ to cell $(2, 4)$. Their costs are $8-1+5-3+7=16$, $8-2+5-3+7=15$, $8-2+6-3+7=16$, and $8-2+6-4+7=15$. Then the minimum value is $15$, which is the maximum possible value.



#### tags 

#1000 #constructive_algorithms #greedy 