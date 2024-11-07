<h1 style='text-align: center;'> E. Star MST</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In this problem, we will consider complete undirected graphs consisting of $n$ vertices with weighted edges. The weight of each edge is an integer from $1$ to $k$.

An undirected graph is considered beautiful if the sum of weights of all edges incident to vertex $1$ is equal to the weight of MST in the graph. MST is the minimum spanning tree — a tree consisting of $n-1$ edges of the graph, which connects all $n$ vertices and has the minimum sum of weights among all such trees; the weight of MST is the sum of weights of all edges in it.

Calculate the number of complete beautiful graphs having exactly $n$ vertices and the weights of edges from $1$ to $k$. Since the answer might be large, print it modulo $998244353$.

## Input

The only line contains two integers $n$ and $k$ ($2 \le n \le 250$; $1 \le k \le 250$).

## Output

Print one integer — the number of complete beautiful graphs having exactly $n$ vertices and the weights of edges from $1$ to $k$. Since the answer might be large, print it modulo $998244353$.

## Examples

## Input


```

3 2

```
## Output


```

5

```
## Input


```

4 4

```
## Output


```

571

```
## Input


```

6 9

```
## Output


```

310640163

```
## Input


```

42 13

```
## Output


```

136246935

```


#### tags 

#2200 #combinatorics #dp #graph_matchings #math 