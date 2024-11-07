<h1 style='text-align: center;'> F. Unique Occurrences</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a tree, consisting of $n$ vertices. Each edge has an integer value written on it.

Let $f(v, u)$ be the number of values that appear exactly once on the edges of a simple path between vertices $v$ and $u$.

Calculate the sum of $f(v, u)$ over all pairs of vertices $v$ and $u$ such that $1 \le v < u \le n$.

####### Input

The first line contains a single integer $n$ ($2 \le n \le 5 \cdot 10^5$) — the number of vertices in the tree.

Each of the next $n-1$ lines contains three integers $v, u$ and $x$ ($1 \le v, u, x \le n$) — the description of an edge: the vertices it connects and the value written on it.

The given edges form a tree.

####### Output

Print a single integer — the sum of $f(v, u)$ over all pairs of vertices $v$ and $u$ such that $v < u$.

## Examples

####### Input


```text
3
1 2 1
1 3 2
```
####### Output


```text
4
```
####### Input


```text
3
1 2 2
1 3 2
```
####### Output


```text
2
```
####### Input


```text
5
1 4 4
1 2 3
3 4 4
4 5 5
```
####### Output


```text
14
```
####### Input


```text
2
2 1 1
```
####### Output


```text
1
```
####### Input


```text
10
10 2 3
3 8 8
4 8 9
5 8 5
3 10 7
7 8 2
5 6 6
9 3 4
1 6 3
```
####### Output


```text
120
```


#### Tags 

#2300 #NOT OK #data_structures #dfs_and_similar #divide_and_conquer #dp #dsu #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_129_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
