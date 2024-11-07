<h1 style='text-align: center;'> B. Cthulhu</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

...Once upon a time a man came to the sea. The sea was stormy and dark. The man started to call for the little mermaid to appear but alas, he only woke up Cthulhu...

Whereas on the other end of the world Pentagon is actively collecting information trying to predict the monster's behavior and preparing the secret super weapon. Due to high seismic activity and poor weather conditions the satellites haven't yet been able to make clear shots of the monster. The analysis of the first shot resulted in an undirected graph with *n* vertices and *m* edges. Now the world's best minds are about to determine whether this graph can be regarded as Cthulhu or not.

To add simplicity, let's suppose that Cthulhu looks from the space like some spherical body with tentacles attached to it. Formally, we shall regard as Cthulhu such an undirected graph that can be represented as a set of three or more rooted trees, whose roots are connected by a simple cycle.

It is guaranteed that the graph contains no multiple edges and self-loops.

 ![](images/4a1bd2a30a2185e611915f5c6321f74deead2a5c.png) ## Input

The first line contains two integers — the number of vertices *n* and the number of edges *m* of the graph (1 ≤ *n* ≤ 100, 0 ≤ *m* ≤ ![](images/b6fbba87a6e66854e5728f67cc384b75c4bcf131.png)).

Each of the following *m* lines contains a pair of integers *x* and *y*, that show that an edge exists between vertices *x* and *y* (1 ≤ *x*, *y* ≤ *n*, *x* ≠ *y*). For each pair of vertices there will be at most one edge between them, no edge connects a vertex to itself.

## Output

Print "NO", if the graph is not Cthulhu and "FHTAGN!" if it is.

## Examples

## Input


```
6 6  
6 3  
6 4  
5 1  
2 5  
1 4  
5 4  

```
## Output


```
FHTAGN!
```
## Input


```
6 5  
5 6  
4 6  
3 1  
5 1  
1 2  

```
## Output


```
NO
```
## Note

Let us denote as a simple cycle a set of *v* vertices that can be numbered so that the edges will only exist between vertices number 1 and 2, 2 and 3, ..., *v* - 1 and *v*, *v* and 1.

A tree is a connected undirected graph consisting of *n* vertices and *n* - 1 edges (*n* > 0).

A rooted tree is a tree where one vertex is selected to be the root.



#### tags 

#1500 #dfs_and_similar #dsu #graphs 