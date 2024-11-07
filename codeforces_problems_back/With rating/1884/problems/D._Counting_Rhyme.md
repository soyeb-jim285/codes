<h1 style='text-align: center;'> D. Counting Rhyme</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a_1, a_2, \ldots, a_n$.

A pair of integers $(i, j)$, such that $1 \le i < j \le n$, is called good, if there does not exist an integer $k$ ($1 \le k \le n$) such that $a_i$ is divisible by $a_k$ and $a_j$ is divisible by $a_k$ at the same time.

Please, find the number of good pairs.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2 \cdot 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^6$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

## Output

For each test case, output the number of good pairs.

## Example

## Input


```

642 4 4 442 3 4 496 8 9 4 6 8 9 4 997 7 4 4 9 9 6 2 91810 18 18 15 14 4 5 6 8 9 10 12 15 16 18 17 13 112112 19 19 18 18 12 2 18 19 12 12 3 12 12 12 18 19 16 18 19 12
```
## Output


```

0
3
26
26
124
82

```
## Note

In the first test case, there are no good pairs. 

In the second test case, here are all the good pairs: $(1, 2)$, $(2, 3)$, and $(2, 4)$.



#### tags 

#2100 #dp #math #number_theory 