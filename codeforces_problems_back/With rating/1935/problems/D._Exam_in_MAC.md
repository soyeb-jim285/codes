<h1 style='text-align: center;'> D. Exam in MAC</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Master's Assistance Center has announced an entrance exam, which consists of the following.

The candidate is given a set $s$ of size $n$ and some strange integer $c$. For this set, it is needed to calculate the number of pairs of integers $(x, y)$ such that $0 \leq x \leq y \leq c$, $x + y$ is not contained in the set $s$, and also $y - x$ is not contained in the set $s$.

Your friend wants to enter the Center. Help him pass the exam!

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $c$ ($1 \leq n \leq 3 \cdot 10^5$, $1 \leq c \leq 10^9$) — the size of the set and the strange integer.

The second line of each test case contains $n$ integers $s_1, s_2, \ldots, s_{n}$ ($0 \leq s_1 < s_2 < \ldots < s_{n} \leq c$) — the elements of the set $s$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, output a single integer — the number of suitable pairs of integers.

## Example

## Input


```

83 31 2 31 179574 60 3 5 61 115 100 2 4 8 105 101 3 5 7 94 102 4 6 73 1000000000228 1337 998244353
```
## Output


```

3
16139
10
2
33
36
35
499999998999122959

```
## Note

In the first test case, the following pairs are suitable: $(0, 0)$, $(2, 2)$, $(3, 3)$.

In the third test case, the following pairs are suitable: $(0, 1)$, $(0, 2)$, $(0, 4)$, $(1, 3)$, $(2, 6)$, $(3, 4)$, $(3, 5)$, $(4, 5)$, $(4, 6)$, $(5, 6)$.



#### tags 

#1800 #binary_search #combinatorics #implementation #math 