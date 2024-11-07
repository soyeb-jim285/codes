<h1 style='text-align: center;'> F. Next and Prev</h1>

<h5 style='text-align: center;'>time limit per test: 15 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Let $p_1, \ldots, p_n$ be a permutation of $[1, \ldots, n]$.

Let the $q$-subsequence of $p$ be a permutation of $[1, q]$, whose elements are in the same relative order as in $p_1, \ldots, p_n$. That is, we extract all elements not exceeding $q$ together from $p$ in the original order, and they make the $q$-subsequence of $p$.

For a given array $a$, let $pre(i)$ be the largest value satisfying $pre(i) < i$ and $a_{pre(i)} > a_i$. If it does not exist, let $pre(i) = -10^{100}$. Let $nxt(i)$ be the smallest value satisfying $nxt(i) > i$ and $a_{nxt(i)} > a_i$. If it does not exist, let $nxt(i) = 10^{100}$.

For each $q$ such that $1 \leq q \leq n$, let $a_1, \ldots, a_q$ be the $q$-subsequence of $p$. For each $i$ such that $1 \leq i \leq q$, $pre(i)$ and $nxt(i)$ will be calculated as defined. Then, you will be given some integer values of $x$, and for each of them you have to calculate $\sum\limits_{i=1}^q \min(nxt(i) - pre(i), x)$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 3\cdot 10^5$) — the length of the permutation.

The second line of each test case contains $n$ integers $p_1, \ldots, p_n$ ($1 \leq p_i \leq n$) — the initial permutation.

Then, for each $q$ such that $1 \leq q \leq n$ in ascending order, you will be given an integer $k$ ($0 \leq k \leq 10^5$), representing the number of queries for the $q$-subsequence. Then $k$ numbers in a line follow: each of them is the value of $x$ for a single query ($1 \leq x \leq q$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $3\cdot 10^5$ and the sum of $k$ over all test cases does not exceed $10^5$.

## Output

For each test case, for each query, print a single line with an integer: the answer to the query.

## Example

## Input


```

176 1 4 3 2 5 71 101 31 23 1 2 31 32 2 6
```
## Output


```

1
9
8
5
10
14
16
14
30

```
## Note

The $1$-subsequence is $[1]$, and $pre=[-10^{100}]$, $nxt=[10^{100}]$. $ans(1)=\min(10^{100}-(-10^{100}),1)=1$.

The $5$-subsequence is $[1,4,3,2,5]$, and $pre=[-10^{100},-10^{100},2,3,-10^{100}]$, $nxt=[2,5,5,5,10^{100}]$. $ans(1)=5,ans(2)=10,ans(3)=14$.



#### tags 

#3200 #brute_force #data_structures #implementation 