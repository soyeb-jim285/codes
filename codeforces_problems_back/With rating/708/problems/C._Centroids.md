<h1 style='text-align: center;'> C. Centroids</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Tree is a connected acyclic graph. Suppose you are given a tree consisting of *n* vertices. The vertex of this tree is called centroid if the size of each connected component that appears if this vertex is removed from the tree doesn't exceed ![](images/a64c1b2df604f8cfa9acf6716a3cc1424488361e.png).

You are given a tree of size *n* and can perform no more than one edge replacement. Edge replacement is the operation of removing one edge from the tree (without deleting incident vertices) and inserting one new edge (without adding new vertices) in such a way that the graph remains a tree. For each vertex you have to determine if it's possible to make it centroid by performing no more than one edge replacement.

## Input

The first line of the input contains an integer *n* (2 ≤ *n* ≤ 400 000) — the number of vertices in the tree. Each of the next *n* - 1 lines contains a pair of vertex indices *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*) — endpoints of the corresponding edge.

## Output

Print *n* integers. The *i*-th of them should be equal to 1 if the *i*-th vertex can be made centroid by replacing no more than one edge, and should be equal to 0 otherwise.

## Examples

## Input


```
3  
1 2  
2 3  

```
## Output


```
1 1 1   

```
## Input


```
5  
1 2  
1 3  
1 4  
1 5  

```
## Output


```
1 0 0 0 0   

```
## Note

In the first sample each vertex can be made a centroid. For example, in order to turn vertex 1 to centroid one have to replace the edge (2, 3) with the edge (1, 3).



#### tags 

#2300 #data_structures #dfs_and_similar #dp #graphs #greedy #trees 