<h1 style='text-align: center;'> B. XY Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given four integers $n$, $B$, $x$ and $y$. You should build a sequence $a_0, a_1, a_2, \dots, a_n$ where $a_0 = 0$ and for each $i \ge 1$ you can choose: 

* either $a_i = a_{i - 1} + x$
* or $a_i = a_{i - 1} - y$.

Your goal is to build such a sequence $a$ that $a_i \le B$ for all $i$ and $\sum\limits_{i=0}^{n}{a_i}$ is maximum possible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Next $t$ cases follow.

The first and only line of each test case contains four integers $n$, $B$, $x$ and $y$ ($1 \le n \le 2 \cdot 10^5$; $1 \le B, x, y \le 10^9$).

It's guaranteed that the total sum of $n$ doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the maximum possible $\sum\limits_{i=0}^{n}{a_i}$.

## Example

### Input


```text
35 100 1 307 1000000000 1000000000 10000000004 1 7 3
```
### Output

```text

15
4000000000
-10

```
## Note

In the first test case, the optimal sequence $a$ is $[0, 1, 2, 3, 4, 5]$.

In the second test case, the optimal sequence $a$ is $[0, 10^9, 0, 10^9, 0, 10^9, 0, 10^9]$.

In the third test case, the optimal sequence $a$ is $[0, -3, -6, 1, -2]$.



#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_125_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
