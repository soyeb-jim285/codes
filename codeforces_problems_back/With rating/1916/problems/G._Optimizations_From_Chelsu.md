<h1 style='text-align: center;'> G. Optimizations From Chelsu</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with $n$ vertices, whose vertices are numbered from $1$ to $n$. Each edge is labeled with some integer $w_i$.

Define $len(u, v)$ as the number of edges in the simple path between vertices $u$ and $v$, and $gcd(u, v)$ as the Greatest Common Divisor of all numbers written on the edges of the simple path between vertices $u$ and $v$. For example, $len(u, u) = 0$ and $gcd(u, u) = 0$ for any $1 \leq u \leq n$.

You need to find the maximum value of $len(u, v) \cdot gcd(u, v)$ over all pairs of vertices in the tree.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. This is followed by their description.

The first line of each test case contains the number $n$ ($2 \leq n \leq 10^5$) — the number of vertices in the tree.

The next $n-1$ lines specify the edges in the format $u$, $v$, $w$ ($1 \leq u, v \leq n$, $1 \leq w \leq 10^{12}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single number equal to the maximum value of $len(u, v) \cdot gcd(u, v)$ over all pairs of vertices in the tree.

## Example

## Input


```

421 2 100000000000043 2 62 1 102 4 681 2 122 3 93 4 94 5 65 6 126 7 47 8 9121 2 122 3 122 4 62 5 95 6 61 7 44 8 128 9 48 10 122 11 97 12 9
```
## Output


```

1000000000000
12
18
24

```


#### tags 

#3500 #divide_and_conquer #dp #number_theory #trees 