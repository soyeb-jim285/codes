<h1 style='text-align: center;'> E. Girl Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Some permutation of length $n$ is guessed.

You are given the indices of its prefix maximums and suffix maximums.

Recall that a permutation of length $k$ is an array of size $k$ such that each integer from $1$ to $k$ occurs exactly once.

Prefix maximums are the elements that are the maximum on the prefix ending at that element. More formally, the element $a_i$ is a prefix maximum if $a_i > a_j$ for every $j < i$.

Similarly, suffix maximums are defined, the element $a_i$ is a suffix maximum if $a_i > a_j$ for every $j > i$.

You need to output the number of different permutations that could have been guessed.

As this number can be very large, output the answer modulo $10^9 + 7$.

## Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains three integers $n, m_1$ and $m_2$ ($1 \le m_1, m_2 \le n \le 2 \cdot 10^5$) — the length of the permutation, the number of prefix maximums, and the number of suffix maximums, respectively.

The second line of each test case contains $m_1$ integers $p_1 < p_2 < \ldots < p_{m_1}$ ($1 \le p_i \le n$) — the indices of the prefix maximums in increasing order.

The third line of each test case contains $m_2$ integers $s_1 < s_2 < \ldots < s_{m_2}$ ($1 \le s_i \le n$) — the indices of the suffix maximums in increasing order.

It is guaranteed that the sum of the values of $n$ for all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer on a separate line — the number of suitable permutations modulo $10^9 + 7$.

## Example

## Input


```

61 1 1114 2 31 22 3 43 3 11 2 335 3 41 2 32 3 4 520 5 41 2 3 4 1212 13 18 206 2 31 33 4 6
```
## Output


```

1
3
1
0
317580808
10

```
## Note

The following permutations are suitable for the second set of input data:

* $[1, 4, 3, 2]$
* $[2, 4, 3, 1]$
* $[3, 4, 2, 1]$

The following permutations are suitable for the sixth set of input data:

* $[2, 1, 6, 5, 3, 4]$
* $[3, 1, 6, 5, 2, 4]$
* $[3, 2, 6, 5, 1, 4]$
* $[4, 1, 6, 5, 2, 3]$
* $[4, 2, 6, 5, 1, 3]$
* $[4, 3, 6, 5, 1, 2]$
* $[5, 1, 6, 4, 2, 3]$
* $[5, 2, 6, 4, 1, 3]$
* $[5, 3, 6, 4, 1, 2]$
* $[5, 4, 6, 3, 1, 2]$


#### tags 

#2200 #combinatorics #dp #math #number_theory 