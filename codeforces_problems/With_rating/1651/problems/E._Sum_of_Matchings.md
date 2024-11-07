<h1 style='text-align: center;'> E. Sum of Matchings</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's denote the size of the maximum matching in a graph $G$ as $\mathit{MM}(G)$.

You are given a bipartite graph. The vertices of the first part are numbered from $1$ to $n$, the vertices of the second part are numbered from $n+1$ to $2n$. Each vertex's degree is $2$.

For a tuple of four integers $(l, r, L, R)$, where $1 \le l \le r \le n$ and $n+1 \le L \le R \le 2n$, let's define $G'(l, r, L, R)$ as the graph which consists of all vertices of the given graph that are included in the segment $[l, r]$ or in the segment $[L, R]$, and all edges of the given graph such that each of their endpoints belongs to one of these segments. In other words, to obtain $G'(l, r, L, R)$ from the original graph, you have to remove all vertices $i$ such that $i \notin [l, r]$ and $i \notin [L, R]$, and all edges incident to these vertices.

Calculate the sum of $\mathit{MM}(G(l, r, L, R))$ over all tuples of integers $(l, r, L, R)$ having $1 \le l \le r \le n$ and $n+1 \le L \le R \le 2n$.

### Input

The first line contains one integer $n$ ($2 \le n \le 1500$) — the number of vertices in each part.

Then $2n$ lines follow, each denoting an edge of the graph. The $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i \le n$; $n + 1 \le y_i \le 2n$) — the endpoints of the $i$-th edge.

There are no multiple edges in the given graph, and each vertex has exactly two incident edges.

### Output

Print one integer — the sum of $\mathit{MM}(G(l, r, L, R))$ over all tuples of integers $(l, r, L, R)$ having $1 \le l \le r \le n$ and $n+1 \le L \le R \le 2n$.

## Example

### Input


```text
5
4 6
4 9
2 6
3 9
1 8
5 10
2 7
3 7
1 10
5 8
```
### Output


```text
314
```


#### Tags 

#2600 #NOT OK #brute_force #combinatorics #constructive_algorithms #dfs_and_similar #graph_matchings #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_124_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
