<h1 style='text-align: center;'> C. Sequence Master</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

For some positive integer $m$, YunQian considers an array $q$ of $2m$ (possibly negative) integers good, if and only if for every possible subsequence of $q$ that has length $m$, the product of the $m$ elements in the subsequence is equal to the sum of the $m$ elements that are not in the subsequence. Formally, let $U=\{1,2,\ldots,2m\}$. For all sets $S \subseteq U$ such that $|S|=m$, $\prod\limits_{i \in S} q_i = \sum\limits_{i \in U \setminus S} q_i$.

Define the distance between two arrays $a$ and $b$ both of length $k$ to be $\sum\limits_{i=1}^k|a_i-b_i|$.

You are given a positive integer $n$ and an array $p$ of $2n$ integers.

Find the minimum distance between $p$ and $q$ over all good arrays $q$ of length $2n$. It can be shown for all positive integers $n$, at least one good array exists. ## Note

 that you are not required to construct the array $q$ that achieves this minimum distance.

## Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le 2\cdot10^5$).

The second line of each test case contains $2n$ integers $p_1, p_2, \ldots, p_{2n}$ ($|p_i| \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, output the minimum distance between $p$ and a good $q$.

## Example

## Input


```

416 921 2 2 12-2 -2 2 24-3 -2 -1 0 1 2 3 4
```
## Output


```

3
2
5
13

```
## Note

In the first test case, it is optimal to let $q=[6,6]$.

In the second test case, it is optimal to let $q=[2,2,2,2]$.



#### tags 

#1600 #brute_force #constructive_algorithms #math 