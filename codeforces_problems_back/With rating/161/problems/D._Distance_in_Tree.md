<h1 style='text-align: center;'> D. Distance in Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A tree is a connected graph that doesn't contain any cycles.

The distance between two vertices of a tree is the length (in edges) of the shortest path between these vertices.

You are given a tree with *n* vertices and a positive number *k*. Find the number of distinct pairs of the vertices which have a distance of exactly *k* between them. ## Note

 that pairs (*v*, *u*) and (*u*, *v*) are considered to be the same pair.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 50000, 1 ≤ *k* ≤ 500) — the number of vertices and the required distance between the vertices.

Next *n* - 1 lines describe the edges as "*a**i* *b**i*" (without the quotes) (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*), where *a**i* and *b**i* are the vertices connected by the *i*-th edge. All given edges are different.

## Output

Print a single integer — the number of distinct pairs of the tree's vertices which have a distance of exactly *k* between them.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
5 2  
1 2  
2 3  
3 4  
2 5  

```
## Output


```
4  

```
## Input


```
5 3  
1 2  
2 3  
3 4  
4 5  

```
## Output


```
2  

```
## Note

In the first sample the pairs of vertexes at distance 2 from each other are (1, 3), (1, 5), (3, 5) and (2, 4).



#### tags 

#1800 #dfs_and_similar #dp #trees 