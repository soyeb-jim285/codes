<h1 style='text-align: center;'> G. MST with Matching</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an undirected connected graph on $n$ vertices. Each edge of this graph has a weight; the weight of the edge connecting vertices $i$ and $j$ is $w_{i,j}$ (or $w_{i,j} = 0$ if there is no edge between $i$ and $j$). All weights are positive integers.

You are also given a positive integer $c$.

You have to build a spanning tree of this graph; i. e. choose exactly $(n-1)$ edges of this graph in such a way that every vertex can be reached from every other vertex by traversing some of the chosen edges. The cost of the spanning tree is the sum of two values:

* the sum of weights of all chosen edges;
* the maximum matching in the spanning tree (i. e. the maximum size of a set of edges such that they all belong to the chosen spanning tree, and no vertex has more than one incident edge in this set), multiplied by the given integer $c$.

Find any spanning tree with the minimum cost. Since the graph is connected, there exists at least one spanning tree.

## Input

The first line contains two integers $n$ and $c$ ($2 \le n \le 20$; $1 \le c \le 10^6$).

Then $n$ lines follow. The $i$-th of them contains $n$ integers $w_{i,1}, w_{i,2}, \dots, w_{i,n}$ ($0 \le w_{i,j} \le 10^6$), where $w_{i,j}$ denotes the weight of the edge between $i$ and $j$ (or $w_{i,j} = 0$ if there is no such edge).

Additional constraints on the input:

* for every $i \in [1, n]$, $w_{i,i} = 0$;
* for every pair of integers $(i, j)$ such that $i \in [1, n]$ and $j \in [1, n]$, $w_{i,j} = w_{j,i}$;
* the given graph is connected.
## Output

Print one integer — the minimum cost of a spanning tree of the given graph.

## Examples

## Input


```

4 100 1 8 01 0 1 08 1 0 20 0 2 0
```
## Output


```

21

```
## Input


```

4 50 1 8 01 0 1 08 1 0 20 0 2 0
```
## Output


```

14

```
## Note

In the first example, the minimum cost spanning tree consists of edges $(1, 3)$, $(2, 3)$ and $(3, 4)$. The maximum matching for it is $1$.

In the second example, the minimum cost spanning tree consists of edges $(1, 2)$, $(2, 3)$ and $(3, 4)$. The maximum matching for it is $2$.



#### tags 

#3100 #bitmasks #brute_force #dsu #graph_matchings #trees 