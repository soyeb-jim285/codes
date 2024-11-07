<h1 style='text-align: center;'> D. A Wide, Wide Graph</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree (a connected graph without cycles) with $n$ vertices. 

Consider a fixed integer $k$. Then, the graph $G_k$ is an undirected graph with $n$ vertices, where an edge between vertices $u$ and $v$ exists if and only if the distance between vertices $u$ and $v$ in the given tree is at least $k$.

For each $k$ from $1$ to $n$, print the number of connected components in the graph $G_k$.

#### Input

The first line contains the integer $n$ ($2 \le n \le 10^5$) — the number of vertices in the graph.

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), denoting an edge between vertices $u$ and $v$ in the tree. It is guaranteed that these edges form a valid tree.

#### Output

#### Output

 $n$ integers: the number of connected components in the graph $G_k$ for each $k$ from $1$ to $n$.

## Examples

#### Input


```text
6
1 2
1 3
2 4
2 5
3 6
```
#### Output


```text
1 1 2 4 6 6 
```
#### Input


```text
5
1 2
2 3
3 4
3 5
```
#### Output


```text
1 1 3 5 5 
```
## Note

In the first example: If $k=1$, the graph has an edge between each pair of vertices, so it has one component. If $k=4$, the graph has only edges $4 \leftrightarrow 6$ and $5 \leftrightarrow 6$, so the graph has $4$ components.

In the second example: when $k=1$ or $k=2$ the graph has one component. When $k=3$ the graph $G_k$ splits into $3$ components: one component has vertices $1$, $4$ and $5$, and two more components contain one vertex each. When $k=4$ or $k=5$ each vertex is a separate component.



#### Tags 

#1800 #NOT OK #dfs_and_similar #dp #graphs #greedy #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_862_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
