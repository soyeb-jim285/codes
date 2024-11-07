<h1 style='text-align: center;'> F. Useful Edges</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a weighted undirected graph on $n$ vertices along with $q$ triples $(u, v, l)$, where in each triple $u$ and $v$ are vertices and $l$ is a positive integer. An edge $e$ is called useful if there is at least one triple $(u, v, l)$ and a path (not necessarily simple) with the following properties:

* $u$ and $v$ are the endpoints of this path,
* $e$ is one of the edges of this path,
* the sum of weights of all edges on this path doesn't exceed $l$.

Please print the number of useful edges in this graph.

## Input

The first line contains two integers $n$ and $m$ ($2\leq n\leq 600$, $0\leq m\leq \frac{n(n-1)}2$). 

Each of the following $m$ lines contains three integers $u$, $v$ and $w$ ($1\leq u, v\leq n$, $u\neq v$, $1\leq w\leq 10^9$), denoting an edge connecting vertices $u$ and $v$ and having a weight $w$.

The following line contains the only integer $q$ ($1\leq q\leq \frac{n(n-1)}2$) denoting the number of triples.

Each of the following $q$ lines contains three integers $u$, $v$ and $l$ ($1\leq u, v\leq n$, $u\neq v$, $1\leq l\leq 10^9$) denoting a triple $(u, v, l)$.

It's guaranteed that: 

* the graph doesn't contain loops or multiple edges;
* all pairs $(u, v)$ in the triples are also different.
## Output

Print a single integer denoting the number of useful edges in the graph.

## Examples

## Input


```

4 6
1 2 1
2 3 1
3 4 1
1 3 3
2 4 3
1 4 5
1
1 4 4

```
## Output


```

5

```
## Input


```

4 2
1 2 10
3 4 10
6
1 2 11
1 3 11
1 4 11
2 3 11
2 4 11
3 4 9

```
## Output


```

1

```
## Input


```

3 2
1 2 1
2 3 2
1
1 2 5

```
## Output


```

2

```
## Note

In the first example each edge is useful, except the one of weight $5$.

In the second example only edge between $1$ and $2$ is useful, because it belongs to the path $1-2$, and $10 \leq 11$. The edge between $3$ and $4$, on the other hand, is not useful.

In the third example both edges are useful, for there is a path $1-2-3-2$ of length exactly $5$. Please note that the path may pass through a vertex more than once.



#### tags 

#2400 #graphs #shortest_paths 