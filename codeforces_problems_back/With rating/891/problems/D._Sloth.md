<h1 style='text-align: center;'> D. Sloth</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sloth is bad, mkay? So we decided to prepare a problem to punish lazy guys.

You are given a tree, you should count the number of ways to remove an edge from it and then add an edge to it such that the final graph is a tree and has a perfect matching. Two ways of this operation are considered different if their removed edges or their added edges aren't the same. The removed edge and the added edge can be equal.

A perfect matching is a subset of edges such that each vertex is an endpoint of exactly one of these edges.

## Input

The first line contains *n* (2 ≤ *n* ≤ 5·105) — the number of vertices.

Each of the next *n* - 1 lines contains two integers *a* and *b* (1 ≤ *a*, *b* ≤ *n*) — the endpoints of one edge. It's guaranteed that the graph is a tree.

## Output

## Output

 a single integer — the answer to the problem.

## Examples

## Input


```
4  
1 2  
2 3  
3 4  

```
## Output


```
8  

```
## Input


```
5  
1 2  
2 3  
3 4  
3 5  

```
## Output


```
0  

```
## Input


```
8  
1 2  
2 3  
3 4  
1 5  
5 6  
6 7  
1 8  

```
## Output


```
22  

```
## Note

In first sample, there are 8 ways:

* edge between 2 and 3 turns to edge between 1 and 3,
* edge between 2 and 3 turns to edge between 1 and 4,
* edge between 2 and 3 turns to edge between 2 and 3,
* edge between 2 and 3 turns to edge between 2 and 4,
* edge between 1 and 2 turns to edge between 1 and 2,
* edge between 1 and 2 turns to edge between 1 and 4,
* edge between 3 and 4 turns to edge between 1 and 4,
* edge between 3 and 4 turns to edge between 3 and 4.


#### tags 

#3100 #dfs_and_similar #dp #graph_matchings #trees 