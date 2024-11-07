<h1 style='text-align: center;'> B. Reverse Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ashish has a binary string $s$ of length $n$ that he wants to sort in non-decreasing order.

He can perform the following operation: 

1. Choose a subsequence of any length such that its elements are in non-increasing order. Formally, choose any $k$ such that $1 \leq k \leq n$ and any sequence of $k$ indices $1 \le i_1 \lt i_2 \lt \ldots \lt i_k \le n$ such that $s_{i_1} \ge s_{i_2} \ge \ldots \ge s_{i_k}$.
2. Reverse this subsequence in-place. Formally, swap $s_{i_1}$ with $s_{i_k}$, swap $s_{i_2}$ with $s_{i_{k-1}}$, $\ldots$ and swap $s_{i_{\lfloor k/2 \rfloor}}$ with $s_{i_{\lceil k/2 \rceil + 1}}$ (Here $\lfloor x \rfloor$ denotes the largest integer not exceeding $x$, and $\lceil x \rceil$ denotes the smallest integer not less than $x$)

Find the minimum number of operations required to sort the string in non-decreasing order. It can be proven that it is always possible to sort the given binary string in at most $n$ operations.

## Input

The first line contains a single integer $t$ $(1 \le t \le 1000)$  — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ $(1 \le n \le 1000)$  — the length of the binary string $s$.

The second line of each test case contains a binary string $s$ of length $n$ containing only $0$s and $1$s.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

## Output

For each test case output the following:

* The minimum number of operations $m$ in the first line ($0 \le m \le n$).
* Each of the following $m$ lines should be of the form: $k$ $i_1$ $i_2$ ... $i_{k}$, where $k$ is the length and $i_1 \lt i_2 \lt ... \lt i_{k}$ are the indices of the chosen subsequence. For them the conditions from the statement must hold.
## Example

## Input


```

3
7
0011111
5
10100
6
001000

```
## Output


```

0
1
4 1 3 4 5 
1
3 3 5 6 

```
## Note

In the first test case, the binary string is already sorted in non-decreasing order.

In the second test case, we can perform the following operation: 

* $k = 4:$ choose the indices $\{1, 3, 4, 5\}$$\underline{1}$ $0$ $\underline{1}$ $\underline{0}$ $\underline{0}$ $\rightarrow $ $\underline{0}$ $0$ $\underline{0}$ $\underline{1}$ $\underline{1}$

In the third test case, we can perform the following operation:

* $k = 3:$ choose the indices $\{3, 5, 6\}$$0$ $0$ $\underline{1}$ $0$ $\underline{0}$ $\underline{0}$ $\rightarrow $ $0$ $0$ $\underline{0}$ $0$ $\underline{0}$ $\underline{1}$


#### tags 

#1000 #greedy #sortings 