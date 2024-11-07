<h1 style='text-align: center;'> B. Diameter of Graph</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

CQXYM wants to create a connected undirected graph with $n$ nodes and $m$ edges, and the diameter of the graph must be strictly less than $k-1$. Also, CQXYM doesn't want a graph that contains self-loops or multiple edges (i.e. each edge connects two different vertices and between each pair of vertices there is at most one edge).

The diameter of a graph is the maximum distance between any two nodes.

The distance between two nodes is the minimum number of the edges on the path which endpoints are the two nodes.

CQXYM wonders whether it is possible to create such a graph.

## Input

The input consists of multiple test cases. 

The first line contains an integer $t (1 \leq t \leq 10^5)$ — the number of test cases. The description of the test cases follows.

Only one line of each test case contains three integers $n(1 \leq n \leq 10^9)$, $m$, $k$ $(0 \leq m,k \leq 10^9)$.

## Output

For each test case, print YES if it is possible to create the graph, or print NO if it is impossible. You can print each letter in any case (upper or lower).

## Example

## Input


```

5
1 0 3
4 5 3
4 6 3
5 4 1
2 1 1

```
## Output


```

YES
NO
YES
NO
NO

```
## Note

In the first test case, the graph's diameter equal to 0.

In the second test case, the graph's diameter can only be 2.

In the third test case, the graph's diameter can only be 1.



#### tags 

#1200 #constructive_algorithms #graphs #greedy #math 