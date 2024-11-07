<h1 style='text-align: center;'> E. Maximum Monogonosity</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ of length $n$ and an array $b$ of length $n$. The cost of a segment $[l, r]$, $1 \le l \le r \le n$, is defined as $|b_l - a_r| + |b_r - a_l|$.

Recall that two segments $[l_1, r_1]$, $1 \le l_1 \le r_1 \le n$, and $[l_2, r_2]$, $1 \le l_2 \le r_2 \le n$, are non-intersecting if one of the following conditions is satisfied: $r_1 < l_2$ or $r_2 < l_1$.

The length of a segment $[l, r]$, $1 \le l \le r \le n$, is defined as $r - l + 1$.

Find the maximum possible sum of costs of non-intersecting segments $[l_j, r_j]$, $1 \le l_j \le r_j \le n$, whose total length is equal to $k$.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ $(1 \le t \le 1000)$ — the number of sets of input data. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 3000$) — the length of array $a$ and the total length of segments.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the elements of array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($-10^9 \le b_i \le 10^9$) — the elements of array $b$.

It is guaranteed that the sum of $n$ over all test case does not exceed $3000$.

## Output

For each test case, output a single number — the maximum possible sum of costs of such segments.

## Example

## Input


```

54 41 1 1 11 1 1 13 21 3 25 2 35 11 2 3 4 51 2 3 4 57 21 3 7 6 4 7 21 5 3 2 7 4 54 217 3 5 816 2 5 9
```
## Output


```

0
10
0
16
28

```
## Note

In the first test case, the cost of any segment is $0$, so the total cost is $0$.

In the second test case, we can take the segment $[1, 1]$ with a cost of $8$ and the segment $[3, 3]$ with a cost of $2$ to get a total sum of $10$. It can be shown that this is the optimal solution.

In the third test case, we are only interested in segments of length $1$, and the cost of any such segment is $0$.

In the fourth test case, it can be shown that the optimal sum is $16$. For example, we can take the segments $[3, 3]$ and $[4, 4]$.



#### tags 

#2500 #brute_force #dp #math 