<h1 style='text-align: center;'> B. Make Array Good</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array $b$ of $m$ positive integers is good if for all pairs $i$ and $j$ ($1 \leq i,j \leq m$), $\max(b_i,b_j)$ is divisible by $\min(b_i,b_j)$.

You are given an array $a$ of $n$ positive integers. You can perform the following operation:

* Select an index $i$ ($1 \leq i \leq n$) and an integer $x$ ($0 \leq x \leq a_i$) and add $x$ to $a_i$, in other words, $a_i := a_i+x$.
* After this operation, $a_i \leq 10^{18}$ should be satisfied.

You have to construct a sequence of at most $n$ operations that will make $a$ good. It can be proven that under the constraints of the problem, such a sequence of operations always exists.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ space-separated integers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq 10^9$) — representing the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test, output a single integer $p$ ($0 \leq p \leq n$) — denoting the number of operations in your solution. 

In each of the following $p$ lines, output two space-separated integers — $i$ and $x$.

You do not need to minimize the number of operations. It can be proven that a solution always exists.

## Example

## Input


```

442 3 5 524 853 4 343 5 6331 5 17
```
## Output


```

4
1 2
1 1
2 2
3 0
0
5
1 3
1 4
2 1
5 4
3 7
3
1 29
2 5
3 3

```
## Note

In the first test case, array $a$ becomes $[5,5,5,5]$ after the operations. It is easy to see that $[5,5,5,5]$ is good.

In the second test case, array $a$ is already good.

In the third test case, after performing the operations, array $a$ becomes $[10,5,350,5,10]$, which is good.

In the fourth test case, after performing the operations, array $a$ becomes $[60,10,20]$, which is good.



#### tags 

#1100 #constructive_algorithms #implementation #number_theory #sortings 