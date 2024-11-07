<h1 style='text-align: center;'> G. Removal Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a simple undirected graph, consisting of $n$ vertices and $m$ edges. The vertices are numbered from $1$ to $n$. The $i$-th vertex has a value $a_i$ written on it.

You will be removing vertices from that graph. You are allowed to remove vertex $i$ only if its degree is equal to $a_i$. When a vertex is removed, all edges incident to it are also removed, thus, decreasing the degree of adjacent non-removed vertices.

A valid sequence of removals is a permutation $p_1, p_2, \dots, p_n$ $(1 \le p_i \le n)$ such that the $i$-th vertex to be removed is $p_i$, and every removal is allowed.

A pair $(x, y)$ of vertices is nice if there exist two valid sequences of removals such that $x$ is removed before $y$ in one of them and $y$ is removed before $x$ in the other one.

Count the number of nice pairs $(x, y)$ such that $x < y$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains two integers $n$ and $m$ ($1 \le n \le 10^5$; $0 \le m \le \min(10^5, \frac{n \cdot (n - 1)}{2})$) — the number of vertices and the number of edges of the graph.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le n - 1$) — the degree requirements for each removal.

Each of the next $m$ lines contains two integers $v$ and $u$ ($1 \le v, u \le n$; $v \neq u$) — the description of an edge.

The graph doesn't contain any self-loops or multiple edges.

The sum of $n$ over all testcases doesn't exceed $10^5$. The sum of $m$ over all testcases doesn't exceed $10^5$.

Additional constraint on the input: there always exists at least one valid sequence of removals.

## Output

For each testcase, print a single integer — the number of nice pairs of vertices.

## Example

## Input


```

43 21 0 12 31 23 31 2 01 22 31 35 63 0 2 1 01 24 14 23 42 35 11 00
```
## Output


```

1
0
4
0

```


#### tags 

#2700 #bitmasks #dfs_and_similar #graphs 