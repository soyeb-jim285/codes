<h1 style='text-align: center;'> D. Dijkstra</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an unusual problem in an unusual contest, here is the announcement: [http://codeforces.com/blog/entry/73543](//codeforces.com/blog/entry/73543)

Find the distance between vertices $1$ and $n$ in an undirected weighted graph.

## Input

The first line contains two integers $n, m$ ($1 \leq n, m \leq 2 \cdot 10^5$) — the number of vertices and the number of edges.

Each of the next $m$ lines contain description of an edge $a_i~b_i~cost_i$ ($1 \leq a_i, b_i \leq n$, $1 \leq cost_i \leq 10^9$).

Loops and multiple edges? Hmm, why not?

## Output

Print one integer — the answer to the problem. If there is no path, print $-1$ instead.

## Example

## Input


```

3 3
1 2 5
2 3 1
1 3 7

```
## Output


```

6

```


#### tags 

