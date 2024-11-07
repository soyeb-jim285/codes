<h1 style='text-align: center;'> F. Simple Cycles Edges</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected graph, consisting of $n$ vertices and $m$ edges. The graph does not necessarily connected. Guaranteed, that the graph does not contain multiple edges (more than one edges between a pair of vertices) or loops (edges from a vertex to itself).

A cycle in a graph is called a simple, if it contains each own vertex exactly once. So simple cycle doesn't allow to visit a vertex more than once in a cycle.

Determine the edges, which belong to exactly on one simple cycle.

##### Input

The first line contain two integers $n$ and $m$ $(1 \le n \le 100\,000$, $0 \le m \le \min(n \cdot (n - 1) / 2, 100\,000))$ — the number of vertices and the number of edges.

Each of the following $m$ lines contain two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$) — the description of the edges.

##### Output

In the first line print the number of edges, which belong to exactly one simple cycle.

In the second line print the indices of edges, which belong to exactly one simple cycle, in increasing order. The edges are numbered from one in the same order as they are given in the input.

## Examples

##### Input


```text
3 3  
1 2  
2 3  
3 1  

```
##### Output


```text
3  
1 2 3   

```
##### Input


```text
6 7  
2 3  
3 4  
4 2  
1 2  
1 5  
5 6  
6 1  

```
##### Output


```text
6  
1 2 3 5 6 7   

```
##### Input


```text
5 6  
1 2  
2 3  
2 4  
4 3  
2 5  
5 3  

```
##### Output


```text
0  
  

```


#### Tags 

#2400 #NOT OK #dfs_and_similar #graphs #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_42_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Разбор задач](../blogs/Разбор_задач.md)
