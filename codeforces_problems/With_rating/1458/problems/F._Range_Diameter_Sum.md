<h1 style='text-align: center;'> F. Range Diameter Sum</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tree with $n$ vertices numbered $1, \ldots, n$. A tree is a connected simple graph without cycles.

Let $\mathrm{dist}(u, v)$ be the number of edges in the unique simple path connecting vertices $u$ and $v$.

Let $\mathrm{diam}(l, r) = \max \mathrm{dist}(u, v)$ over all pairs $u, v$ such that $l \leq u, v \leq r$.

Compute $\sum_{1 \leq l \leq r \leq n} \mathrm{diam}(l, r)$.

#### Input

The first line contains a single integer $n$ ($1 \leq n \leq 10^5$) — the number of vertices in the tree.

The next $n - 1$ lines describe the tree edges. Each of these lines contains two integers $u, v$ ($1 \leq u, v \leq n$) — endpoint indices of the respective tree edge. It is guaranteed that the edge list indeed describes a tree.

#### Output

Print a single integer — $\sum_{1 \leq l \leq r \leq n} \mathrm{diam}(l, r)$.

## Examples

#### Input


```text
4
1 2
2 4
3 2
```
#### Output


```text
10
```
#### Input


```text
10
1 8
2 9
5 6
4 8
4 2
7 9
3 6
10 4
3 9
```
#### Output


```text
224
```


#### Tags 

#3500 #NOT OK #data_structures #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_691_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
