<h1 style='text-align: center;'> A. Tit for Tat</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of length $n$, you can do at most $k$ operations of the following type on it:

* choose $2$ different elements in the array, add $1$ to the first, and subtract $1$ from the second. However, all the elements of $a$ have to remain non-negative after this operation.

What is lexicographically the smallest array you can obtain?

An array $x$ is [lexicographically smaller](https://en.wikipedia.org/wiki/Lexicographical_order) than an array $y$ if there exists an index $i$ such that $x_i<y_i$, and $x_j=y_j$ for all $1 \le j < i$. Less formally, at the first index $i$ in which they differ, $x_i<y_i$.

## Input

The first line contains an integer $t$ ($1 \le t \le 20$) – the number of test cases you need to solve.

The first line of each test case contains $2$ integers $n$ and $k$ ($2 \le n \le 100$, $1 \le k \le 10000$) — the number of elements in the array and the maximum number of operations you can make.

The second line contains $n$ space-separated integers $a_1$, $a_2$, $\ldots$, $a_{n}$ ($0 \le a_i \le 100$) — the elements of the array $a$.

## Output

For each test case, print the lexicographically smallest array you can obtain after at most $k$ operations.

## Example

## Input


```

2
3 1
3 1 4
2 10
1 0

```
## Output


```

2 1 5 
0 1 

```
## Note

In the second test case, we start by subtracting $1$ from the first element and adding $1$ to the second. Then, we can't get any lexicographically smaller arrays, because we can't make any of the elements negative.



#### tags 

#800 #greedy 