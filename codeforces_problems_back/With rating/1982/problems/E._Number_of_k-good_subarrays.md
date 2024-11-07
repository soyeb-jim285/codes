<h1 style='text-align: center;'> E. Number of k-good subarrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $bit(x)$ denote the number of ones in the binary representation of a non-negative integer $x$.

A subarray of an array is called $k$-good if it consists only of numbers with no more than $k$ ones in their binary representation, i.e., a subarray $(l, r)$ of array $a$ is good if for any $i$ such that $l \le i \le r$ condition $bit(a_{i}) \le k$ is satisfied.

You are given an array $a$ of length $n$, consisting of consecutive non-negative integers starting from $0$, i.e., $a_{i} = i$ for $0 \le i \le n - 1$ (in $0$-based indexing). You need to count the number of $k$-good subarrays in this array.

As the answer can be very large, output it modulo $10^{9} + 7$.

## Input

Each test consists of multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^{4}$) — the number of test cases. The following lines describe the test cases.

The single line of each test case contains two integers $n$, $k$ ($1 \le n \le 10^{18}, 1 \le k \le 60$).

## Output

For each test case, output a single integer — the number of $k$-good subarrays modulo $10^{9} + 7$.

## Example

## Input


```

106 116 21 13 131 314 11337 5100000 20795569939321040850 56576460752303423268 59
```
## Output


```

7
35
1
6
155
8
7323
49965
741136395
66679884

```
## Note

For the first test case $a = [0, 1, 2, 3, 4, 5]$, $k = 1$.

To find the answer, let's write all the numbers in binary representation:

$$a = [\color{green}{000}, \color{green}{001}, \color{green}{010}, \color{red}{011}, \color{green}{100}, \color{red}{101}]$$

From this, it can be seen that the numbers $3$ and $5$ have $2 \ge (k = 1)$ ones in their binary representation, so the answer should include all subarrays that do not contain either $3$ or $5$, which are the subarrays (in $0$-based indexing): ($0$, $0$), ($0$, $1$), ($0$, $2$), ($1$, $1$), ($1$, $2$), ($2$, $2$), ($4$, $4$).



#### tags 

#2300 #bitmasks #brute_force #combinatorics #divide_and_conquer #dp #math #meet-in-the-middle 