<h1 style='text-align: center;'> E. Counting Prefixes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a hidden array $a$ of size $n$ consisting of only $1$ and $-1$. Let $p$ be the prefix sums of array $a$. More formally, $p$ is an array of length $n$ defined as $p_i = a_1 + a_2 + \ldots + a_i$. Afterwards, array $p$ is sorted in non-decreasing order. For example, if $a = [1, -1, -1, 1, 1]$, then $p = [1, 0, -1, 0, 1]$ before sorting and $p = [-1, 0, 0, 1, 1]$ after sorting.

You are given the prefix sum array $p$ after sorting, but you do not know what array $a$ is. Your task is to count the number of initial arrays $a$ such that the above process results in the given sorted prefix sum array $p$. As this number can be large, you are only required to find it modulo $998\,244\,353$.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5000$) — the size of the hidden array $a$.

The second line of each test case contains $n$ integers $p_1, p_2, \ldots, p_n$ ($|p_i| \le n$) — the $n$ prefix sums of $a$ sorted in non-decreasing order.

It is guaranteed that $p_1 \le p_2 \le \ldots \le p_n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$.

## Output

For each test case, output the answer modulo $998\,244\,353$.

## Example

## Input


```

510113-1 1 25-1 0 0 1 15-4 -3 -3 -2 -1
```
## Output


```

0
1
0
3
1

```
## Note

In the first two test cases, the only possible arrays $a$ for $n = 1$ are $a = [1]$ and $a = [-1]$. Their respective sorted prefix sum arrays $p$ are $p = [1]$ and $p = [-1]$. Hence, there is no array $a$ that can result in the sorted prefix sum array $p = [0]$ and there is exactly $1$ array $a$ that can result in the sorted prefix sum array $p = [1]$.

In the third test case, it can be proven that there is no array $a$ that could result in the sorted prefix sum array $p = [-1, 1, 2]$.

In the fourth test case, the $3$ possible arrays $a$ that could result in the sorted prefix sum array $p = [-1, 0, 0, 1, 1]$ are:

* $a = [1, -1, 1, -1, -1]$. The prefix sum array before sorting is $p = [1, 0, 1, 0, -1]$, which after sorting gives $p = [-1, 0, 0, 1, 1]$.
* $a = [1, -1, -1, 1, 1]$. The prefix sum array before sorting is $p = [1, 0, -1, 0, 1]$, which after sorting gives $p = [-1, 0, 0, 1, 1]$.
* $a = [-1, 1, 1, -1, 1]$. The prefix sum array before sorting is $p = [-1, 0, 1, 0, 1]$, which after sorting gives $p = [-1, 0, 0, 1, 1]$.

For the fifth test case, the only possible array $a$ that could result in the sorted prefix sum array $p = [-4, -3, -3, -2, -1]$ is $a = [-1, -1, -1, -1, 1]$.



#### tags 

#2600 #combinatorics #constructive_algorithms #dp #implementation #math 