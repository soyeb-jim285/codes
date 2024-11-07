<h1 style='text-align: center;'> D. Weighting a Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a connected undirected graph with *n* vertices and *m* edges. The vertices are enumerated from 1 to *n*. 

You are given *n* integers *c*1, *c*2, ..., *c**n*, each of them is between  - *n* and *n*, inclusive. It is also guaranteed that the parity of *c**v* equals the parity of degree of vertex *v*. The degree of a vertex is the number of edges connected to it.

You are to write a weight between  - 2·*n*2 and 2·*n*2 (inclusive) on each edge in such a way, that for each vertex *v* the sum of weights on edges connected to this vertex is equal to *c**v*, or determine that this is impossible.

## Input

The first line contains two integers *n* and *m* (2 ≤ *n* ≤ 105, *n* - 1 ≤ *m* ≤ 105) — the number of vertices and the number of edges.

The next line contains *n* integers *c*1, *c*2, ..., *c**n* ( - *n* ≤ *c**i* ≤ *n*), where *c**i* is the required sum of weights of edges connected to vertex *i*. It is guaranteed that the parity of *c**i* equals the parity of degree of vertex *i*.

The next *m* lines describe edges of the graph. The *i*-th of these lines contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *a**i* ≠ *b**i*), meaning that the *i*-th edge connects vertices *a**i* and *b**i*.

It is guaranteed that the given graph is connected and does not contain loops and multiple edges.

## Output

If there is no solution, print "NO".

Otherwise print "YES" and then *m* lines, the *i*-th of them is the weight of the *i*-th edge *w**i* ( - 2·*n*2 ≤ *w**i* ≤ 2·*n*2).

## Examples

## Input


```
3 3  
2 2 2  
1 2  
2 3  
1 3  

```
## Output


```
YES  
1  
1  
1  

```
## Input


```
4 3  
-1 0 2 1  
1 2  
2 3  
3 4  

```
## Output


```
YES  
-1  
1  
1  

```
## Input


```
6 6  
3 5 5 5 1 5  
1 4  
3 2  
4 3  
4 5  
3 5  
5 6  

```
## Output


```
YES  
3  
5  
3  
-1  
-3  
5  

```
## Input


```
4 4  
4 4 2 4  
1 2  
2 3  
3 4  
4 1  

```
## Output


```
NO
```


#### tags 

#2700 #constructive_algorithms #dfs_and_similar #graphs 