<h1 style='text-align: center;'> D. Nearest Excluded Points</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ distinct points on a plane. The coordinates of the $i$-th point are $(x_i, y_i)$.

For each point $i$, find the nearest (in terms of Manhattan distance) point with integer coordinates that is not among the given $n$ points. If there are multiple such points — you can choose any of them.

The Manhattan distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is $|x_1 - x_2| + |y_1 - y_2|$.

#### Input

The first line of the input contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of points in the set.

The next $n$ lines describe points. The $i$-th of them contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le 2 \cdot 10^5$) — coordinates of the $i$-th point.

It is guaranteed that all points in the input are distinct.

#### Output

Print $n$ lines. In the $i$-th line, print the point with integer coordinates that is not among the given $n$ points and is the nearest (in terms of Manhattan distance) to the $i$-th point from the input.

#### Output

 coordinates should be in range $[-10^6; 10^6]$. It can be shown that any optimal answer meets these constraints.

If there are several answers, you can print any of them.

## Examples

#### Input


```text
6
2 2
1 2
2 1
3 2
2 3
5 5
```
#### Output


```text
1 1
1 1
2 0
3 1
2 4
5 4
```
#### Input


```text
8
4 4
2 4
2 2
2 3
1 4
4 2
1 3
3 3
```
#### Output


```text
4 3
2 5
2 1
2 5
1 5
4 1
1 2
3 2
```


#### Tags 

#1900 #NOT OK #binary_search #data_structures #dfs_and_similar #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_124_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
