<h1 style='text-align: center;'> B. Longest Divisors Interval</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a positive integer $n$, find the maximum size of an interval $[l, r]$ of positive integers such that, for every $i$ in the interval (i.e., $l \leq i \leq r$), $n$ is a multiple of $i$.

Given two integers $l\le r$, the size of the interval $[l, r]$ is $r-l+1$ (i.e., it coincides with the number of integers belonging to the interval).

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of the description of each test case contains one integer $n$ ($1 \leq n \leq 10^{18}$).

### Output

For each test case, print a single integer: the maximum size of a valid interval.

## Example

### Input


```text
1014099099042044745601699589137065729723659882203458280803877017195378264306201968835781298538648023412808056621000000000000000000
```
### Output

```text

1
2
3
6
4
22
3
1
2
2

```
## Note

In the first test case, a valid interval with maximum size is $[1, 1]$ (it's valid because $n = 1$ is a multiple of $1$) and its size is $1$.

In the second test case, a valid interval with maximum size is $[4, 5]$ (it's valid because $n = 40$ is a multiple of $4$ and $5$) and its size is $2$.

In the third test case, a valid interval with maximum size is $[9, 11]$.

In the fourth test case, a valid interval with maximum size is $[8, 13]$.

In the seventh test case, a valid interval with maximum size is $[327869, 327871]$.



#### Tags 

#900 #OK #brute_force #combinatorics #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_889_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
