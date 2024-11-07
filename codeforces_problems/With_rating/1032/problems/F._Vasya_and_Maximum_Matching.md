<h1 style='text-align: center;'> F. Vasya and Maximum Matching</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has got a tree consisting of $n$ vertices. He wants to delete some (possibly zero) edges in this tree such that the maximum matching in the resulting graph is unique. He asks you to calculate the number of ways to choose a set of edges to remove.

A matching in the graph is a subset of its edges such that there is no vertex incident to two (or more) edges from the subset. A maximum matching is a matching such that the number of edges in the subset is maximum possible among all matchings in this graph.

Since the answer may be large, output it modulo $998244353$.

##### Input

The first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of vertices in the tree.

Each of the next $n − 1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n, u \neq v$) denoting an edge between vertex $u$ and vertex $v$. It is guaranteed that these edges form a tree.

##### Output

Print one integer — the number of ways to delete some (possibly empty) subset of edges so that the maximum matching in the resulting graph is unique. Print the answer modulo $998244353$.

## Examples

##### Input


```text
4  
1 2  
1 3  
1 4  

```
##### Output


```text
4  

```
##### Input


```text
4  
1 2  
2 3  
3 4  

```
##### Output


```text
6  

```
##### Input


```text
1  

```
##### Output


```text
1  

```
## Note

Possible ways to delete edges in the first example: 

* delete $(1, 2)$ and $(1, 3)$.
* delete $(1, 2)$ and $(1, 4)$.
* delete $(1, 3)$ and $(1, 4)$.
* delete all edges.

Possible ways to delete edges in the second example: 

* delete no edges.
* delete $(1, 2)$ and $(2, 3)$.
* delete $(1, 2)$ and $(3, 4)$.
* delete $(2, 3)$ and $(3, 4)$.
* delete $(2, 3)$.
* delete all edges.


#### Tags 

#2400 #NOT OK #dp #trees 

## Blogs
- [All Contest Problems](../Technocup_2019_-_Elimination_Round_3.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (ru)](../blogs/Tutorial_1_(ru).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
