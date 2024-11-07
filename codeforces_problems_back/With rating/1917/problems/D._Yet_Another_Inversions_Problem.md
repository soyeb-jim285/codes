<h1 style='text-align: center;'> D. Yet Another Inversions Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p_0, p_1, \ldots, p_{n-1}$ of odd integers from $1$ to $2n-1$ and a permutation $q_0, q_1, \ldots, q_{k-1}$ of integers from $0$ to $k-1$.

An array $a_0, a_1, \ldots, a_{nk-1}$ of length $nk$ is defined as follows:

 $a_{i \cdot k+j}=p_i \cdot 2^{q_j}$ for all $0 \le i < n$ and all $0 \le j < k$ For example, if $p = [3, 5, 1]$ and $q = [0, 1]$, then $a = [3, 6, 5, 10, 1, 2]$.

## Note

 that all arrays in the statement are zero-indexed. ## Note

 that each element of the array $a$ is uniquely determined.

Find the number of inversions in the array $a$. Since this number can be very large, you should find only its remainder modulo $998\,244\,353$.

An inversion in array $a$ is a pair $(i, j)$ ($0 \le i < j < nk$) such that $a_i > a_j$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n, k \le 2 \cdot 10^5$) — the lengths of arrays $p$ and $q$.

The second line of each test case contains $n$ distinct integers $p_0, p_1, \ldots, p_{n-1}$ ($1 \le p_i \le 2n-1$, $p_i$ is odd) — the array $p$.

The third line of each test case contains $k$ distinct integers $q_0, q_1, \ldots, q_{k-1}$ ($0 \le q_i < k$) — the array $q$.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$ and the sum of $k$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, output one integer: the number of inversions in array $a$ modulo $998\,244\,353$.

## Example

## Input


```

43 23 5 10 13 41 3 53 2 0 11 510 1 2 3 48 35 1 7 11 15 3 9 132 0 1
```
## Output


```

9
25
0
104

```
## Note

In the first test case, array $a$ is equal to $[3, 6, 5, 10, 1, 2]$. There are $9$ inversions in it: $(0, 4)$, $(0, 5)$, $(1, 2)$, $(1, 4)$, $(1, 5)$, $(2, 4)$, $(2, 5)$, $(3, 4)$, $(3, 5)$. ## Note

 that these are pairs $(i, j)$ such that $i < j$ and $a_i > a_j$.

In the second test case, array $a$ is equal to $[8, 4, 1, 2, 24, 12, 3, 6, 40, 20, 5, 10]$. There are $25$ inversions in it.

In the third test case, array $a$ is equal to $[1, 2, 4, 8, 16]$. There are no inversions in it.



#### tags 

#2300 #combinatorics #data_structures #dp #implementation #math #number_theory 