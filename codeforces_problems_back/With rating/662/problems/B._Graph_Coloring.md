<h1 style='text-align: center;'> B. Graph Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected graph that consists of *n* vertices and *m* edges. Initially, each edge is colored either red or blue. Each turn a player picks a single vertex and switches the color of all edges incident to it. That is, all red edges with an endpoint in this vertex change the color to blue, while all blue edges with an endpoint in this vertex change the color to red.

Find the minimum possible number of moves required to make the colors of all edges equal.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 100 000) — the number of vertices and edges, respectively.

The following *m* lines provide the description of the edges, as the *i*-th of them contains two integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*) — the indices of the vertices connected by the *i*-th edge, and a character *c**i* (![](images/32f568a12a1c75e03b845a946cd2491cace9d61c.png)) providing the initial color of this edge. If *c**i* equals 'R', then this edge is initially colored red. Otherwise, *c**i* is equal to 'B' and this edge is initially colored blue. It's guaranteed that there are no self-loops and multiple edges.

## Output

If there is no way to make the colors of all edges equal output  - 1 in the only line of the output. Otherwise first output *k* — the minimum number of moves required to achieve the goal, then output *k* integers *a*1, *a*2, ..., *a**k*, where *a**i* is equal to the index of the vertex that should be used at the *i*-th move.

If there are multiple optimal sequences of moves, output any of them.

## Examples

## Input


```
3 3  
1 2 B  
3 1 R  
3 2 B  

```
## Output


```
1  
2   

```
## Input


```
6 5  
1 3 R  
2 3 R  
3 4 B  
4 5 R  
4 6 R  

```
## Output


```
2  
3 4   

```
## Input


```
4 5  
1 2 R  
1 3 R  
2 3 B  
3 4 B  
1 4 B  

```
## Output


```
-1  

```


#### tags 

#2200 #dfs_and_similar #graphs 