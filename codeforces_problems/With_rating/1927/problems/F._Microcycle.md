<h1 style='text-align: center;'> F. Microcycle</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an undirected weighted graph with $n$ vertices and $m$ edges. There is at most one edge between each pair of vertices in the graph, and the graph does not contain loops (edges from a vertex to itself). The graph is not necessarily connected.

A cycle in the graph is called simple if it doesn't pass through the same vertex twice and doesn't contain the same edge twice.

Find any simple cycle in this graph in which the weight of the lightest edge is minimal.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follow the descriptions of the test cases.

The first line of each test case contains two integers $n$ and $m$ ($3 \le n \le m \le \min(\frac{n\cdot(n - 1)}{2}, 2 \cdot 10^5)$) — the size of the graph and the number of edges.

The next $m$ lines of the test case contain three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $u \ne v$, $1 \le w \le 10^6$) — vertices $u$ and $v$ are connected by an edge of weight $w$.

It is guaranteed that there is at most one edge between each pair of vertices. Note that under the given constraints, there is always at least one simple cycle in the graph.

It is guaranteed that the sum of the values of $m$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a pair of numbers $b$ and $k$, where:

* $b$ — the minimum weight of the edge in the found cycle,
* $k$ — the number of vertices in the found cycle.

On the next line, output $k$ numbers from $1$ to $n$  — the vertices of the cycle in traversal order.

Note that the answer always exists, as under the given constraints, there is always at least one simple cycle in the graph.

## Example

### Input


```text
56 61 2 12 3 13 1 14 5 15 6 16 4 16 61 2 102 3 83 1 54 5 1005 6 406 4 36 151 2 45 2 86 1 76 3 106 5 13 2 84 3 45 3 62 6 65 4 54 1 36 4 54 2 13 1 71 5 54 62 3 21 3 101 4 13 4 72 4 51 2 24 52 1 103 1 34 2 61 4 72 3 3
```
### Output

```text

1 3
1 2 3 
3 3
6 4 5 
1 5
4 2 1 6 3 
1 4
1 4 3 2 
3 3
2 3 1 

```


#### Tags 

#1900 #NOT OK #data_structures #dfs_and_similar #dsu #graphs #greedy #implementation #sortings #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_923_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
