<h1 style='text-align: center;'> A. X Axis</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three points with integer coordinates $x_1$, $x_2$, and $x_3$ on the $X$ axis ($1 \leq x_i \leq 10$). You can choose any point with an integer coordinate $a$ on the $X$ axis. 
## Note

 that the point $a$ may coincide with $x_1$, $x_2$, or $x_3$. Let $f(a)$ be the total distance from the given points to the point $a$. Find the smallest value of $f(a)$.

The distance between points $a$ and $b$ is equal to $|a - b|$. For example, the distance between points $a = 5$ and $b = 2$ is $3$.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. Then follows their descriptions.

The single line of each test case contains three integers $x_1$, $x_2$, and $x_3$ ($1 \leq x_i \leq 10$) — the coordinates of the points.

### Output

For each test case, output the smallest value of $f(a)$.

## Example

### Input


```text
81 1 11 5 98 2 810 9 32 1 12 4 17 3 51 9 4
```
### Output

```text

0
8
6
7
1
3
4
8

```
## Note

In the first test case, the smallest value of $f(a)$ is achieved when $a = 1$: $f(1) = |1 - 1| + |1 - 1| + |1 - 1| = 0$.

In the second test case, the smallest value of $f(a)$ is achieved when $a = 5$: $f(5) = |1 - 5| + |5 - 5| + |9 - 5| = 8$.

In the third test case, the smallest value of $f(a)$ is achieved when $a = 8$: $f(8) = |8 - 8| + |2 - 8| + |8 - 8| = 6$.

In the fourth test case, the smallest value of $f(a)$ is achieved when $a = 9$: $f(10) = |10 - 9| + |9 - 9| + |3 - 9| = 7$.



#### Tags 

#800 #NOT OK #brute_force #geometry #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_954_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Tutorial #2](../blogs/Tutorial_2.md)
