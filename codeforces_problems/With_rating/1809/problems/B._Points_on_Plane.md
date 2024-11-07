<h1 style='text-align: center;'> B. Points on Plane</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a two-dimensional plane, and you need to place $n$ chips on it. 

You can place a chip only at a point with integer coordinates. The cost of placing a chip at the point $(x, y)$ is equal to $|x| + |y|$ (where $|a|$ is the absolute value of $a$).

The cost of placing $n$ chips is equal to the maximum among the costs of each chip.

You need to place $n$ chips on the plane in such a way that the Euclidean distance between each pair of chips is strictly greater than $1$, and the cost is the minimum possible.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Next $t$ cases follow.

The first and only line of each test case contains one integer $n$ ($1 \le n \le 10^{18}$) — the number of chips you need to place.

### Output

For each test case, print a single integer — the minimum cost to place $n$ chips if the distance between each pair of chips must be strictly greater than $1$.

## Example

### Input


```text
4135975461057789971042
```
### Output

```text

0
1
2
987654321

```
## Note

In the first test case, you can place the only chip at point $(0, 0)$ with total cost equal to $0 + 0 = 0$.

In the second test case, you can, for example, place chips at points $(-1, 0)$, $(0, 1)$ and $(1, 0)$ with costs $|-1| + |0| = 1$, $|0| + |1| = 1$ and $|0| + |1| = 1$. Distance between each pair of chips is greater than $1$ (for example, distance between $(-1, 0)$ and $(0, 1)$ is equal to $\sqrt{2}$). The total cost is equal to $\max(1, 1, 1) = 1$.

In the third test case, you can, for example, place chips at points $(-1, -1)$, $(-1, 1)$, $(1, 1)$, $(0, 0)$ and $(0, 2)$. The total cost is equal to $\max(2, 2, 2, 0, 2) = 2$.



#### Tags 

#1000 #OK #binary_search #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
