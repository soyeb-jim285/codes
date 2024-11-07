<h1 style='text-align: center;'> B. Alyona and a tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alyona has a tree with *n* vertices. The root of the tree is the vertex 1. In each vertex Alyona wrote an positive integer, in the vertex *i* she wrote *a**i*. Moreover, the girl wrote a positive integer to every edge of the tree (possibly, different integers on different edges).

Let's define *dist*(*v*, *u*) as the sum of the integers written on the edges of the simple path from *v* to *u*.

The vertex *v* controls the vertex *u* (*v* ≠ *u*) if and only if *u* is in the subtree of *v* and *dist*(*v*, *u*) ≤ *a**u*.

Alyona wants to settle in some vertex. In order to do this, she wants to know for each vertex *v* what is the number of vertices *u* such that *v* controls *u*.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 2·105).

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the integers written in the vertices.

The next (*n* - 1) lines contain two integers each. The *i*-th of these lines contains integers *p**i* and *w**i* (1 ≤ *p**i* ≤ *n*, 1 ≤ *w**i* ≤ 109) — the parent of the (*i* + 1)-th vertex in the tree and the number written on the edge between *p**i* and (*i* + 1).

It is guaranteed that the given graph is a tree.

## Output

Print *n* integers — the *i*-th of these numbers should be equal to the number of vertices that the *i*-th vertex controls.

## Examples

## Input


```
5  
2 5 1 4 6  
1 7  
1 1  
3 5  
3 6  

```
## Output


```
1 0 1 0 0  

```
## Input


```
5  
9 7 8 6 5  
1 1  
2 1  
3 1  
4 1  

```
## Output


```
4 3 2 1 0  

```
## Note

In the example test case the vertex 1 controls the vertex 3, the vertex 3 controls the vertex 5 (note that is doesn't mean the vertex 1 controls the vertex 5).



#### tags 

#1900 #binary_search #data_structures #dfs_and_similar #graphs #trees 