<h1 style='text-align: center;'> D. Triangle Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an undirected graph consisting of $n$ vertices and $n$ edges, where $n$ is divisible by $6$. Each edge has a weight, which is a positive (greater than zero) integer.

The graph has the following structure: it is split into $\frac{n}{3}$ triples of vertices, the first triple consisting of vertices $1, 2, 3$, the second triple consisting of vertices $4, 5, 6$, and so on. Every pair of vertices from the same triple is connected by an edge. There are no edges between vertices from different triples.

You have to paint the vertices of this graph into two colors, red and blue. Each vertex should have exactly one color, there should be exactly $\frac{n}{2}$ red vertices and $\frac{n}{2}$ blue vertices. The coloring is called valid if it meets these constraints.

The weight of the coloring is the sum of weights of edges connecting two vertices with different colors.

Let $W$ be the maximum possible weight of a valid coloring. Calculate the number of valid colorings with weight $W$, and print it modulo $998244353$.

## Input

The first line contains one integer $n$ ($6 \le n \le 3 \cdot 10^5$, $n$ is divisible by $6$).

The second line contains $n$ integers $w_1, w_2, \dots, w_n$ ($1 \le w_i \le 1000$) — the weights of the edges. Edge $1$ connects vertices $1$ and $2$, edge $2$ connects vertices $1$ and $3$, edge $3$ connects vertices $2$ and $3$, edge $4$ connects vertices $4$ and $5$, edge $5$ connects vertices $4$ and $6$, edge $6$ connects vertices $5$ and $6$, and so on.

## Output

Print one integer — the number of valid colorings with maximum possible weight, taken modulo $998244353$.

## Examples

## Input


```

12
1 3 3 7 8 5 2 2 2 2 4 2

```
## Output


```

36

```
## Input


```

6
4 2 6 6 6 4

```
## Output


```

2

```
## Note

The following picture describes the graph from the first example test.

 ![](images/56fc24895819318d9cb93e0b212b2a1bf75a558d.png) The maximum possible weight of a valid coloring of this graph is $31$.



#### tags 

#1600 #combinatorics #math 