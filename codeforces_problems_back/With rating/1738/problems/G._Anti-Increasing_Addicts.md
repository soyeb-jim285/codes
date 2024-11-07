<h1 style='text-align: center;'> G. Anti-Increasing Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an $n \times n$ grid. 

We write $(i, j)$ to denote the cell in the $i$-th row and $j$-th column. For each cell, you are told whether yon can delete it or not. 

Given an integer $k$, you are asked to delete exactly $(n-k+1)^2$ cells from the grid such that the following condition holds. 

* You cannot find $k$ not deleted cells $(x_1, y_1), (x_2, y_2), \dots, (x_k, y_k)$ that are strictly increasing, i.e., $x_i < x_{i+1}$ and $y_i < y_{i+1}$ for all $1 \leq i < k$.

 Your task is to find a solution, or report that it is impossible. ## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains two integers $n$ and $k$ ($2 \leq k \leq n \leq 1000$). 

Then $n$ lines follow. The $i$-th line contains a binary string $s_i$ of length $n$. The $j$-th character of $s_i$ is 1 if you can delete cell $(i, j)$, and 0 otherwise.

It's guaranteed that the sum of $n^2$ over all test cases does not exceed $10^6$.

## Output

For each test case, if there is no way to delete exactly $(n-k+1)^2$ cells to meet the condition, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output $n$ lines. The $i$-th line should contain a binary string $t_i$ of length $n$. The $j$-th character of $t_i$ is 0 if cell $(i, j)$ is deleted, and 1 otherwise.

If there are multiple solutions, you can output any of them.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

42 210014 311100101101001115 501111101111101111101111105 21000001111011110111101111
```
## Output


```

YES
01
11
YES
0011
1111
1111
1100
NO
YES
01111
11000
10000
10000
10000

```
## Note

For the first test case, you only have to delete cell $(1, 1)$.

For the second test case, you could choose to delete cells $(1,1)$, $(1,2)$, $(4,3)$ and $(4,4)$.

For the third test case, it is no solution because the cells in the diagonal will always form a strictly increasing sequence of length $5$.



#### tags 

#2900 #constructive_algorithms #dp #greedy #math 