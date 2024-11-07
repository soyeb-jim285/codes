<h1 style='text-align: center;'> G. Eligible Segments</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ distinct points $p_1, p_2, \ldots, p_n$ on the plane and a positive integer $R$. 

Find the number of pairs of indices $(i, j)$ such that $1 \le i < j \le n$, and for every possible $k$ ($1 \le k \le n$) the distance from the point $p_k$ to the segment between points $p_i$ and $p_j$ is at most $R$.

#### Input

The first line contains two integers $n$, $R$ ($1 \le n \le 3000$, $1 \le R \le 10^5$) — the number of points and the maximum distance between a point and a segment.

Each of the next $n$ lines contains two integers $x_i$, $y_i$ ($-10^5 \le x_i, y_i \le 10^5$) that define the $i$-th point $p_i=(x_i, y_i)$. All points are distinct.

It is guaranteed that the answer does not change if the parameter $R$ is changed by at most $10^{-2}$.

#### Output

Print the number of suitable pairs $(i, j)$.

## Examples

#### Input


```text
4 2
0 1
0 -1
3 0
-3 0
```
#### Output


```text
1
```
#### Input

```text

3 3
1 -1
-1 -1
0 1

```
#### Output


```text

3
```
## Note

In the first example, the only pair of points $(-3, 0)$, $(3, 0)$ is suitable. The distance to the segment between these points from the points $(0, 1)$ and $(0, -1)$ is equal to $1$, which is less than $R=2$.

In the second example, all possible pairs of points are eligible.



#### Tags 

#3200 #NOT OK #geometry 

## Blogs
- [All Contest Problems](../Technocup_2022_-_Elimination_Round_2.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
