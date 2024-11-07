<h1 style='text-align: center;'> F. Good Pairs </h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers and an integer $k$.

A pair $(l,r)$ is good if there exists a sequence of indices $i_1, i_2, \dots, i_m$ such that 

* $i_1=l$ and $i_m=r$;
* $i_j < i_{j+1}$ for all $1 \leq j < m$; and
* $|a_{i_j}-a_{i_{j+1}}| \leq k$ for all $1 \leq j < m$.

Find the number of pairs $(l,r)$ ($1 \leq l \leq r \leq n$) that are good.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two space-separated integers $n$ and $k$ ($1 \leq n \leq 5 \cdot 10^5$; $0 \leq k \leq 10^5$) — the length of the array $a$ and the integer $k$.

The second line of each test case contains $n$ space-separated integers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq 10^5$) — representing the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, print the number of good pairs.

## Example

## Input


```

43 01 1 14 24 8 6 86 47 2 5 8 3 820 23110 57 98 14 20 1 60 82 108 37 82 73 8 46 38 35 106 115 58 112
```
## Output


```

6
9
18
92

```
## Note

In the first test case, good pairs are $(1,1)$, $(1,2)$, $(1,3)$, $(2,2)$, $(2,3)$, and $(3,3)$.

In the second test case, good pairs are $(1,1)$, $(1,3)$, $(1,4)$, $(2,2)$, $(2,3)$, $(2,4)$, $(3,3)$, $(3,4)$ and $(4,4)$. Pair $(1,4)$ is good because there exists a sequence of indices $1, 3, 4$ which satisfy the given conditions.



#### tags 

#2600 #binary_search #data_structures #dp 