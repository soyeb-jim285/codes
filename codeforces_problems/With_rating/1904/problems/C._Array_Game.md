<h1 style='text-align: center;'> C. Array Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ positive integers. In one operation, you must pick some $(i, j)$ such that $1\leq i < j\leq |a|$ and append $|a_i - a_j|$ to the end of the $a$ (i.e. increase $n$ by $1$ and set $a_n$ to $|a_i - a_j|$). Your task is to minimize and print the minimum value of $a$ after performing $k$ operations.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2\le n\le 2\cdot 10^3$, $1\le k\le 10^9$) — the length of the array and the number of operations you should perform.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1\le a_i\le 10^{18}$) — the elements of the array $a$.

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $4\cdot 10^6$.

### Output

For each test case, print a single integer — the smallest possible value of the minimum of array $a$ after performing $k$ operations.

## Example

### Input


```text
45 23 9 7 15 14 37 4 15 126 242 47 50 54 62 792 1500000000000000000 1000000000000000000
```
### Output

```text

1
0
3
500000000000000000

```
## Note

In the first test case, after any $k=2$ operations, the minimum value of $a$ will be $1$.

In the second test case, an optimal strategy is to first pick $i=1, j=2$ and append $|a_1 - a_2| = 3$ to the end of $a$, creating $a=[7, 4, 15, 12, 3]$. Then, pick $i=3, j=4$ and append $|a_3 - a_4| = 3$ to the end of $a$, creating $a=[7, 4, 15, 12, 3, 3]$. In the final operation, pick $i=5, j=6$ and append $|a_5 - a_6| = 0$ to the end of $a$. Then the minimum value of $a$ will be $0$.

In the third test case, an optimal strategy is to first pick $i=2, j=3$ to append $|a_2 - a_3| = 3$ to the end of $a$. Any second operation will still not make the minimum value of $a$ be less than $3$.



#### Tags 

#1400 #NOT OK #binary_search #brute_force #data_structures #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_914_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
