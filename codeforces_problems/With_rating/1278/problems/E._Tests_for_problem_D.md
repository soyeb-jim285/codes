<h1 style='text-align: center;'> E. Tests for problem D</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We had a really tough time generating tests for problem D. In order to prepare strong tests, we had to solve the following problem.

Given an undirected labeled tree consisting of $n$ vertices, find a set of segments such that:

1. both endpoints of each segment are integers from $1$ to $2n$, and each integer from $1$ to $2n$ should appear as an endpoint of exactly one segment;
2. all segments are non-degenerate;
3. for each pair $(i, j)$ such that $i \ne j$, $i \in [1, n]$ and $j \in [1, n]$, the vertices $i$ and $j$ are connected with an edge if and only if the segments $i$ and $j$ intersect, but neither segment $i$ is fully contained in segment $j$, nor segment $j$ is fully contained in segment $i$.

Can you solve this problem too?

#### Input

The first line contains one integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the number of vertices in the tree.

Then $n - 1$ lines follow, each containing two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$, $x_i \ne y_i$) denoting the endpoints of the $i$-th edge.

It is guaranteed that the given graph is a tree.

#### Output

Print $n$ pairs of integers, the $i$-th pair should contain two integers $l_i$ and $r_i$ ($1 \le l_i < r_i \le 2n$) — the endpoints of the $i$-th segment. All $2n$ integers you print should be unique.

It is guaranteed that the answer always exists.

## Examples

#### Input


```text
6
1 2
1 3
3 4
3 5
2 6
```
#### Output


```text
9 12
7 10
3 11
1 5
2 4
6 8
```
#### Input


```text
1
```
#### Output


```text
1 2
```


#### Tags 

#2200 #NOT OK #constructive_algorithms #dfs_and_similar #divide_and_conquer #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_78_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
