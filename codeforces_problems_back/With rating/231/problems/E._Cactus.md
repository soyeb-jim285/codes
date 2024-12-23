<h1 style='text-align: center;'> E. Cactus</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A connected undirected graph is called a vertex cactus, if each vertex of this graph belongs to at most one simple cycle.

A simple cycle in a undirected graph is a sequence of distinct vertices *v*1, *v*2, ..., *v**t* (*t* > 2), such that for any *i* (1 ≤ *i* < *t*) exists an edge between vertices *v**i* and *v**i* + 1, and also exists an edge between vertices *v*1 and *v**t*.

A simple path in a undirected graph is a sequence of not necessarily distinct vertices *v*1, *v*2, ..., *v**t* (*t* > 0), such that for any *i* (1 ≤ *i* < *t*) exists an edge between vertices *v**i* and *v**i* + 1 and furthermore each edge occurs no more than once. We'll say that a simple path *v*1, *v*2, ..., *v**t* starts at vertex *v*1 and ends at vertex *v**t*.

You've got a graph consisting of *n* vertices and *m* edges, that is a vertex cactus. Also, you've got a list of *k* pairs of interesting vertices *x**i*, *y**i*, for which you want to know the following information — the number of distinct simple paths that start at vertex *x**i* and end at vertex *y**i*. We will consider two simple paths distinct if the sets of edges of the paths are distinct.

For each pair of interesting vertices count the number of distinct simple paths between them. As this number can be rather large, you should calculate it modulo 1000000007 (109 + 7). 

## Input

The first line contains two space-separated integers *n*, *m* (2 ≤ *n* ≤ 105; 1 ≤ *m* ≤ 105) — the number of vertices and edges in the graph, correspondingly. Next *m* lines contain the description of the edges: the *i*-th line contains two space-separated integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*) — the indexes of the vertices connected by the *i*-th edge.

The next line contains a single integer *k* (1 ≤ *k* ≤ 105) — the number of pairs of interesting vertices. Next *k* lines contain the list of pairs of interesting vertices: the *i*-th line contains two space-separated numbers *x**i*, *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*; *x**i* ≠ *y**i*) — the indexes of interesting vertices in the *i*-th pair.

It is guaranteed that the given graph is a vertex cactus. It is guaranteed that the graph contains no loops or multiple edges. Consider the graph vertices are numbered from 1 to *n*.

## Output

Print *k* lines: in the *i*-th line print a single integer — the number of distinct simple ways, starting at *x**i* and ending at *y**i*, modulo 1000000007 (109 + 7).

## Examples

## Input


```
10 11  
1 2  
2 3  
3 4  
1 4  
3 5  
5 6  
8 6  
8 7  
7 6  
7 9  
9 10  
6  
1 2  
3 5  
6 9  
9 2  
9 3  
9 10  

```
## Output


```
2  
2  
2  
4  
4  
1  

```


#### tags 

#2100 #data_structures #dfs_and_similar #dp #graphs #trees 