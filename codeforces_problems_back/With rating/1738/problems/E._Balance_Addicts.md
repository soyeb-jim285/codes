<h1 style='text-align: center;'> E. Balance Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Given an integer sequence $a_1, a_2, \dots, a_n$ of length $n$, your task is to compute the number, modulo $998244353$, of ways to partition it into several non-empty continuous subsequences such that the sums of elements in the subsequences form a balanced sequence.

A sequence $s_1, s_2, \dots, s_k$ of length $k$ is said to be balanced, if $s_{i} = s_{k-i+1}$ for every $1 \leq i \leq k$. For example, $[1, 2, 3, 2, 1]$ and $[1,3,3,1]$ are balanced, but $[1,5,15]$ is not. 

Formally, every partition can be described by a sequence of indexes $i_1, i_2, \dots, i_k$ of length $k$ with $1 = i_1 < i_2 < \dots < i_k \leq n$ such that 

1. $k$ is the number of non-empty continuous subsequences in the partition;
2. For every $1 \leq j \leq k$, the $j$-th continuous subsequence starts with $a_{i_j}$, and ends exactly before $a_{i_{j+1}}$, where $i_{k+1} = n + 1$. That is, the $j$-th subsequence is $a_{i_j}, a_{i_j+1}, \dots, a_{i_{j+1}-1}$.

 There are $2^{n-1}$ different partitions in total. Let $s_1, s_2, \dots, s_k$ denote the sums of elements in the subsequences with respect to the partition $i_1, i_2, \dots, i_k$. Formally, for every $1 \leq j \leq k$, $$ s_j = \sum_{i=i_{j}}^{i_{j+1}-1} a_i = a_{i_j} + a_{i_j+1} + \dots + a_{i_{j+1}-1}. $$ For example, the partition $[1\,|\,2,3\,|\,4,5,6]$ of sequence $[1,2,3,4,5,6]$ is described by the sequence $[1,2,4]$ of indexes, and the sums of elements in the subsequences with respect to the partition is $[1,5,15]$.

Two partitions $i_1, i_2, \dots, i_k$ and $i'_1, i'_2, \dots, i'_{k'}$ (described by sequences of indexes) are considered to be different, if at least one of the following holds. 

* $k \neq k'$,
* $i_j \neq i'_j$ for some $1 \leq j \leq \min\left\{ k, k' \right\}$.
## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$), indicating the length of the sequence $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \leq a_i \leq 10^9$), indicating the elements of the sequence $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output the number of partitions with respect to which the sum of elements in each subsequence is balanced, modulo $998244353$.

## Example

## Input


```

61100000000021 140 0 1 051 2 3 2 151 3 5 7 9320 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
## Output


```

1
2
3
4
2
150994942

```
## Note

For the first test case, there is only one way to partition a sequence of length $1$, which is itself and is, of course, balanced. 

For the second test case, there are $2$ ways to partition it: 

* The sequence $[1, 1]$ itself, then $s = [2]$ is balanced;
* Partition into two subsequences $[1\,|\,1]$, then $s = [1, 1]$ is balanced.

For the third test case, there are $3$ ways to partition it: 

* The sequence $[0, 0, 1, 0]$ itself, then $s = [1]$ is balanced;
* $[0 \,|\, 0, 1 \,|\, 0]$, then $s = [0, 1, 0]$ is balanced;
* $[0, 0 \,|\, 1 \,|\, 0]$, then $s = [0, 1, 0]$ is balanced.

For the fourth test case, there are $4$ ways to partition it: 

* The sequence $[1, 2, 3, 2, 1]$ itself, then $s = [9]$ is balanced;
* $[1, 2 \,|\, 3 \,|\, 2, 1]$, then $s = [3, 3, 3]$ is balanced;
* $[1 \,|\, 2, 3, 2 \,|\, 1]$, then $s = [1, 7, 1]$ is balanced;
* $[1 \,|\, 2 \,|\, 3 \,|\, 2 \,|\, 1]$, then $s = [1, 2, 3, 2, 1]$ is balanced.

For the fifth test case, there are $2$ ways to partition it: 

* The sequence $[1, 3, 5, 7, 9]$ itself, then $s = [25]$ is balanced;
* $[1, 3, 5 \,|\, 7 \,|\, 9]$, then $s = [9, 7, 9]$ is balanced.

For the sixth test case, every possible partition should be counted. So the answer is $2^{32-1} \equiv 150994942 \pmod {998244353}$.



#### tags 

#2300 #combinatorics #dp #math #two_pointers 