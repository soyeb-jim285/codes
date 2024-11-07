<h1 style='text-align: center;'> B. Binary Colouring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $x$. Find any array of integers $a_0, a_1, \ldots, a_{n-1}$ for which the following holds: 

* $1 \le n \le 32$,
* $a_i$ is $1$, $0$, or $-1$ for all $0 \le i \le n - 1$,
* $x = \displaystyle{\sum_{i=0}^{n - 1}{a_i \cdot 2^i}}$,
* There does not exist an index $0 \le i \le n - 2$ such that both $a_{i} \neq 0$ and $a_{i + 1} \neq 0$.

It can be proven that under the constraints of the problem, a valid array always exists.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains a single positive integer $x$ ($1 \le x < 2^{30}$).

### Output

For each test case, output two lines.

On the first line, output an integer $n$ ($1 \le n \le 32$) — the length of the array $a_0, a_1, \ldots, a_{n-1}$.

On the second line, output the array $a_0, a_1, \ldots, a_{n-1}$.

If there are multiple valid arrays, you can output any of them.

## Example

### Input


```text
71142415271119
```
### Output

```text

1
1
5
0 -1 0 0 1
6
0 0 0 -1 0 1
5
-1 0 0 0 1
6
-1 0 -1 0 0 1
5
-1 0 -1 0 1
5
-1 0 1 0 1
```
## Note

In the first test case, one valid array is $[1]$, since $(1) \cdot 2^0 = 1$.

In the second test case, one possible valid array is $[0,-1,0,0,1]$, since $(0) \cdot 2^0 + (-1) \cdot 2^1 + (0) \cdot 2^2 + (0) \cdot 2^3 + (1) \cdot 2^4 = -2 + 16 = 14$.



#### Tags 

#1100 #NOT OK #bitmasks #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_948_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
