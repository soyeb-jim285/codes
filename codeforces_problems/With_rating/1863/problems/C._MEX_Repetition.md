<h1 style='text-align: center;'> C. MEX Repetition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1,a_2,\ldots, a_n$ of pairwise distinct integers from $0$ to $n$. Consider the following operation:

* consecutively for each $i$ from $1$ to $n$ in this order, replace $a_i$ with $\operatorname{MEX}(a_1, a_2, \ldots, a_n)$.

Here $\operatorname{MEX}$ of a collection of integers $c_1, c_2, \ldots, c_m$ is defined as the smallest non-negative integer $x$ which does not occur in the collection $c$. For example, $\operatorname{MEX}(0, 2, 2, 1, 4) = 3$ and $\operatorname{MEX}(1, 2) = 0$.

Print the array after applying $k$ such operations.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1\le n\le 10^5$, $1\le k\le 10^9$).

The second line contains $n$ pairwise distinct integers $a_1,a_2,\ldots, a_n$ ($0\le a_i\le n$) representing the elements of the array before applying the operations.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print all $n$ elements of the array after applying $k$ operations.

## Example

### Input


```text
51 213 10 1 32 20 25 51 2 3 4 510 1005 3 0 4 2 1 6 9 10 8
```
### Output

```text

1
2 0 1
2 1
2 3 4 5 0
7 5 3 0 4 2 1 6 9 10

```
## Note

In the first test case, here is the entire process:

1. On the first operation, the array changes from $[1]$ to $[0]$, since $\operatorname{MEX}(1) = 0$.
2. On the second operation, the array changes from $[0]$ to $[1]$, since $\operatorname{MEX}(0) = 1$.

Thus, the array becomes $[1]$ after two operations.

In the second test case, the array changes as follows during one operation: $[{\mkern3mu\underline{\mkern-3mu {\bf 0}\mkern-3mu}\mkern3mu}, 1, 3] \rightarrow [2, {\mkern3mu\underline{\mkern-3mu {\bf 1}\mkern-3mu}\mkern3mu}, 3] \rightarrow [2, 0, {\mkern3mu\underline{\mkern-3mu {\bf 3}\mkern-3mu}\mkern3mu}] \rightarrow [2, 0, 1]$.

In the third test case, the array changes as follows during one operation: $[{\mkern3mu\underline{\mkern-3mu {\bf 0}\mkern-3mu}\mkern3mu}, 2] \rightarrow [1, {\mkern3mu\underline{\mkern-3mu {\bf 2}\mkern-3mu}\mkern3mu}] \rightarrow [1, 0]$. And during the second operation: $[{\mkern3mu\underline{\mkern-3mu {\bf 1}\mkern-3mu}\mkern3mu}, 0] \rightarrow [2, {\mkern3mu\underline{\mkern-3mu {\bf 0}\mkern-3mu}\mkern3mu}] \rightarrow [2, 1]$.



#### Tags 

#1100 #OK #implementation #math 

## Blogs
- [All Contest Problems](../Pinely_Round_2_(Div._1_+_Div._2).md)
- [Pinely Round 2](../blogs/Pinely_Round_2.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
