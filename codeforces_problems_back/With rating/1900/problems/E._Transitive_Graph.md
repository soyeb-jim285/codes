<h1 style='text-align: center;'> E. Transitive Graph</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a directed graph $G$ with $n$ vertices and $m$ edges between them.

Initially, graph $H$ is the same as graph $G$. Then you decided to perform the following actions: 

* If there exists a triple of vertices $a$, $b$, $c$ of $H$, such that there is an edge from $a$ to $b$ and an edge from $b$ to $c$, but there is no edge from $a$ to $c$, add an edge from $a$ to $c$.
* Repeat the previous step as long as there are such triples.

## Note

 that the number of edges in $H$ can be up to $n^2$ after performing the actions.

You also wrote some values on vertices of graph $H$. More precisely, vertex $i$ has the value of $a_i$ written on it.

Consider a simple path consisting of $k$ distinct vertices with indexes $v_1, v_2, \ldots, v_k$. The length of such a path is $k$. The value of that path is defined as $\sum_{i = 1}^k a_{v_i}$.

A simple path is considered the longest if there is no other simple path in the graph with greater length.

Among all the longest simple paths in $H$, find the one with the smallest value.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n,m \le 2 \cdot 10^5$) — the number of vertices and the number of edges.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the numbers written on the vertices of graph $H$.

The $i$-th of the next $m$ lines contains two integers $v_i$ and $u_i$ ($1 \le v_i, u_i \le n$) — meaning that there is an edge going from vertex $v_i$ to vertex $u_i$ in graph $G$. ## Note

 that edges are directed. Also note that the graph may have self-loops and multiple edges.

It is guaranteed that neither the sum of $n$ nor the sum of $m$ over all test cases exceeds $2 \cdot 10^5$.

## Output

For each test case, output two numbers — the length of the longest simple path in $H$ and the minimal possible value of such path.

## Example

## Input


```

35 62 2 4 1 31 21 32 43 44 55 27 7999999999 999999999 999999999 999999999 1000000000 999999999 10000000001 22 33 44 14 54 66 714 222 3 5 7 3 4 1 4 3 4 2 2 5 11 22 32 43 14 44 55 65 65 126 76 87 57 77 98 49 1110 911 1011 1012 1313 1414 12
```
## Output


```

5 12
6 5999999995
11 37

```
## Note

In the first test case, the longest path in both graphs is $1 \to 3 \to 4 \to 5 \to 2$. As the path includes all vertices, the minimal possible value of the longest path is the sum of values on all vertices, which is $12$.

In the second test case, the longest possible path is $1 \to 2 \to 3 \to 4 \to 6 \to 7$. As there are no longest paths with vertex $5$ in them, this path has the minimal possible value of $5\,999\,999\,995$.

In the third test case, it can be proven that there is no path longer than $11$ and that the value of the longest path cannot be less than $37$. Also, notice that the given graph has both self-loops and multiple edges.



#### tags 

#2100 #dfs_and_similar #dp #dsu #graphs #implementation 