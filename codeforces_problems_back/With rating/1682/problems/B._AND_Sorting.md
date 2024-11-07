<h1 style='text-align: center;'> B. AND Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of integers from $0$ to $n-1$ (each of them occurs exactly once). Initially, the permutation is not sorted (that is, $p_i>p_{i+1}$ for at least one $1 \le i \le n - 1$). 

The permutation is called $X$-sortable for some non-negative integer $X$ if it is possible to sort the permutation by performing the operation below some finite number of times: 

* Choose two indices $i$ and $j$ $(1 \le i \lt j \le n)$ such that $p_i \\& p_j = X$.
* Swap $p_i$ and $p_j$.

Here $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

Find the maximum value of $X$ such that $p$ is $X$-sortable. It can be shown that there always exists some value of $X$ such that $p$ is $X$-sortable.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ $(1 \le t \le 10^4)$  — the number of test cases. Description of test cases follows.

The first line of each test case contains a single integer $n$ $(2 \le n \le 2 \cdot 10^5)$  — the length of the permutation.

The second line of each test case contains $n$ integers $p_1, p_2, ..., p_n$ ($0 \le p_i \le n-1$, all $p_i$ are distinct)  — the elements of $p$. It is guaranteed that $p$ is not sorted.

It is guaranteed that the sum of $n$ over all cases does not exceed $2 \cdot 10^5$.

## Output

For each test case output a single integer — the maximum value of $X$ such that $p$ is $X$-sortable.

## Example

## Input


```

440 1 3 221 070 1 2 3 5 6 450 3 2 1 4
```
## Output


```

2
0
4
1

```
## Note

In the first test case, the only $X$ for which the permutation is $X$-sortable are $X = 0$ and $X = 2$, maximum of which is $2$.

Sorting using $X = 0$: 

* Swap $p_1$ and $p_4$, $p = [2, 1, 3, 0]$.
* Swap $p_3$ and $p_4$, $p = [2, 1, 0, 3]$.
* Swap $p_1$ and $p_3$, $p = [0, 1, 2, 3]$.

Sorting using $X = 2$: 

* Swap $p_3$ and $p_4$, $p = [0, 1, 2, 3]$.

In the second test case, we must swap $p_1$ and $p_2$ which is possible only with $X = 0$.



#### tags 

#1100 #bitmasks #constructive_algorithms #sortings 