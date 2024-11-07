<h1 style='text-align: center;'> G. Four Vertices</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected weighted graph, consisting of $n$ vertices and $m$ edges.

Some queries happen with this graph:

* Delete an existing edge from the graph.
* Add a non-existing edge to the graph.

At the beginning and after each query, you should find four different vertices $a$, $b$, $c$, $d$ such that there exists a path between $a$ and $b$, there exists a path between $c$ and $d$, and the sum of lengths of two shortest paths from $a$ to $b$ and from $c$ to $d$ is minimal. The answer to the query is the sum of the lengths of these two shortest paths. The length of the path is equal to the sum of weights of edges in this path.

### Input

The first line contains two integers $n$ and $m$ $(4 \le n, m \le 10^5)$ — the number of vertices and edges in the graph respectively.

Each of the next $m$ lines contain three integers $v$, $u$, $w$ ($1 \le v, u \le n, v \neq u$, $1 \le w \le 10^9$) — this triple means that there is an edge between vertices $v$ and $u$ with weight $w$.

The next line contains a single integer $q$ $(0 \le q \le 10^5)$ — the number of queries.

The next $q$ lines contain the queries of two types:

* $0$ $v$ $u$ — this query means deleting an edge between $v$ and $u$ $(1 \le v, u \le n, v \neq u)$. It is guaranteed that such edge exists in the graph.
* $1$ $v$ $u$ $w$ — this query means adding an edge between vertices $v$ and $u$ with weight $w$ ($1 \le v, u \le n, v \neq u$, $1 \le w \le 10^9$). It is guaranteed that there was no such edge in the graph.

It is guaranteed that the initial graph does not contain multiple edges.

At the beginning and after each query, the graph doesn't need to be connected.

It is guaranteed that at each moment the number of edges will be at least $4$. It can be proven, that at each moment there exist some four vertices $a$, $b$, $c$, $d$ such that there exists a path between vertices $a$ and $b$, and there exists a path between vertices $c$ and $d$.

### Output

Print $q + 1$ integers — the minimal sum of lengths of shortest paths between chosen pairs of vertices before the queries and after each of them.

## Example

### Input


```text
6 6
1 3 6
4 3 1
1 4 1
2 6 4
2 4 2
5 4 3
4
1 2 5 2
0 1 4
0 3 4
1 6 1 3
```
### Output


```text
4
3
3
7
5
```
## Note

Before the queries you can choose vertices $(a, b) = (3, 2)$ and $(c, d) = (1, 4)$. The sum of lengths of two shortest paths is $3 + 1 = 4$.

After the first query you can choose vertices $(a, b) = (2, 5)$ and $(c, d) = (1, 4)$. The sum of lengths of two shortest paths is $2 + 1 = 3$.

After the second query you can choose vertices $(a, b) = (3, 4)$ and $(c, d) = (2, 5)$. The sum of lengths of two shortest paths is $1 + 2 = 3$.

After the third query, you can choose vertices $(a, b) = (2, 6)$ and $(c, d) = (4, 5)$. The sum of lengths of two shortest paths is $4 + 3 = 7$.

After the last query you can choose vertices $(a, b) = (1, 6)$ and $(c, d) = (2, 5)$. The sum of lengths of two shortest paths is $3 + 2 = 5$.



#### Tags 

#3100 #NOT OK #constructive_algorithms #data_structures #graphs #greedy #implementation #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_16.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
