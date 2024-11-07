<h1 style='text-align: center;'> B. Swaps</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$ of length $n$. Array $a$ contains each odd integer from $1$ to $2n$ in an arbitrary order, and array $b$ contains each even integer from $1$ to $2n$ in an arbitrary order.

You can perform the following operation on those arrays: 

* choose one of the two arrays
* pick an index $i$ from $1$ to $n-1$
* swap the $i$-th and the $(i+1)$-th elements of the chosen array

 Compute the minimum number of operations needed to make array $a$ lexicographically smaller than array $b$.For two different arrays $x$ and $y$ of the same length $n$, we say that $x$ is lexicographically smaller than $y$ if in the first position where $x$ and $y$ differ, the array $x$ has a smaller element than the corresponding element in $y$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$).

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the arrays.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 2n$, all $a_i$ are odd and pairwise distinct) — array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le 2n$, all $b_i$ are even and pairwise distinct) — array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print one integer: the minimum number of operations needed to make array $a$ lexicographically smaller than array $b$.

We can show that an answer always exists.

## Example

### Input


```text
3
2
3 1
4 2
3
5 3 1
2 4 6
5
7 5 9 1 3
2 4 6 10 8
```
### Output


```text
0
2
3
```
## Note

In the first example, the array $a$ is already lexicographically smaller than array $b$, so no operations are required.

In the second example, we can swap $5$ and $3$ and then swap $2$ and $4$, which results in $[3, 5, 1]$ and $[4, 2, 6]$. Another correct way is to swap $3$ and $1$ and then swap $5$ and $1$, which results in $[1, 5, 3]$ and $[2, 4, 6]$. Yet another correct way is to swap $4$ and $6$ and then swap $2$ and $6$, which results in $[5, 3, 1]$ and $[6, 2, 4]$.



#### Tags 

#1400 #NOT OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_743_(Div._2).md)
- [Codeforces Round #743 (en)](../blogs/Codeforces_Round_743_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
