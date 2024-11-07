<h1 style='text-align: center;'> C. Unequal Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$. We define the equality of the array as the number of indices $1 \le i \le n - 1$ such that $a_i = a_{i + 1}$. We are allowed to do the following operation:

* Select two integers $i$ and $x$ such that $1 \le i \le n - 1$ and $1 \le x \le 10^9$. Then, set $a_i$ and $a_{i + 1}$ to be equal to $x$.

Find the minimum number of operations needed such that the equality of the array is less than or equal to $1$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($2 \le n \le 2 \cdot 10 ^ 5$) — the length of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$

### Output

For each test case, print the minimum number of operations needed.

## Example

### Input


```text
451 1 1 1 152 1 1 1 261 1 2 3 3 461 2 1 4 5 4
```
### Output

```text

2
1
2
0

```
## Note

In the first test case, we can select $i=2$ and $x=2$ to form $[1, 2, 2, 1, 1]$. Then, we can select $i=3$ and $x=3$ to form $[1, 2, 3, 3, 1]$.

In the second test case, we can select $i=3$ and $x=100$ to form $[2, 1, 100, 100, 2]$.



#### Tags 

#1100 #NOT OK #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_20.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
