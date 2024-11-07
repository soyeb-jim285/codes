<h1 style='text-align: center;'> B. Rising Sand</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ piles of sand where the $i$-th pile has $a_i$ blocks of sand. The $i$-th pile is called too tall if $1 < i < n$ and $a_i > a_{i-1} + a_{i+1}$. That is, a pile is too tall if it has more sand than its two neighbours combined. (## Note

 that piles on the ends of the array cannot be too tall.)

You are given an integer $k$. An operation consists of picking $k$ consecutive piles of sand and adding one unit of sand to them all. Formally, pick $1 \leq l,r \leq n$ such that $r-l+1=k$. Then for all $l \leq i \leq r$, update $a_i \gets a_i+1$.

What is the maximum number of piles that can simultaneously be too tall after some (possibly zero) operations?

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($3 \leq n \leq 2 \cdot 10^5$; $1 \leq k \leq n$) — the number of piles of sand and the size of the operation, respectively.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the sizes of the piles.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the maximum number of piles that are simultaneously too tall after some (possibly zero) operations.

## Example

## Input


```

35 22 9 2 4 14 41 3 2 13 11 3 1
```
## Output


```

2
0
1

```
## Note

In the first test case, we can perform the following three operations: 

* Add one unit of sand to piles $1$ and $2$: $[\color{red}{3}, \color{red}{10}, 2, 4, 1]$.
* Add one unit of sand to piles $4$ and $5$: $[3, 10, 2, \color{red}{5}, \color{red}{2}]$.
* Add one unit of sand to piles $3$ and $4$: $[3, 10, \color{red}{3}, \color{red}{6}, 2]$.

 Now piles $2$ and $4$ are too tall, so in this case the answer is $2$. It can be shown that it is impossible to make more than $2$ piles too tall.In the second test case, any operation will increase all piles by $1$ unit, so the number of too tall piles will always be $0$.

In the third test case, we can increase any pile by $1$ unit of sand. It can be shown that the maximum number of too tall piles is $1$.



#### tags 

#800 #constructive_algorithms #greedy #implementation 