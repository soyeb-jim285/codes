<h1 style='text-align: center;'> D. Tree and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a rooted tree consisting of *n* vertices. Each vertex of the tree has some color. We will assume that the tree vertices are numbered by integers from 1 to *n*. Then we represent the color of vertex *v* as *c**v*. The tree root is a vertex with number 1.

In this problem you need to answer to *m* queries. Each query is described by two integers *v**j*, *k**j*. The answer to query *v**j*, *k**j* is the number of such colors of vertices *x*, that the subtree of vertex *v**j* contains at least *k**j* vertices of color *x*.

You can find the definition of a rooted tree by the following link: http://en.wikipedia.org/wiki/Tree_(graph_theory).

## Input

The first line contains two integers *n* and *m* (2 ≤ *n* ≤ 105; 1 ≤ *m* ≤ 105). The next line contains a sequence of integers *c*1, *c*2, ..., *c**n* (1 ≤ *c**i* ≤ 105). The next *n* - 1 lines contain the edges of the tree. The *i*-th line contains the numbers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *a**i* ≠ *b**i*) — the vertices connected by an edge of the tree.

Next *m* lines contain the queries. The *j*-th line contains two integers *v**j*, *k**j* (1 ≤ *v**j* ≤ *n*; 1 ≤ *k**j* ≤ 105).

## Output

Print *m* integers — the answers to the queries in the order the queries appear in the input.

## Examples

## Input


```
8 5  
1 2 2 3 3 2 3 3  
1 2  
1 5  
2 3  
2 4  
5 6  
5 7  
5 8  
1 2  
1 3  
1 4  
2 3  
5 3  

```
## Output


```
2  
2  
1  
0  
1  

```
## Input


```
4 1  
1 2 3 4  
1 2  
2 3  
3 4  
1 1  

```
## Output


```
4  

```
## Note

A subtree of vertex *v* in a rooted tree with root *r* is a set of vertices {*u* : *dist*(*r*, *v*) + *dist*(*v*, *u*) = *dist*(*r*, *u*)}. Where *dist*(*x*, *y*) is the length (in edges) of the shortest path between vertices *x* and *y*.



#### tags 

#2400 #data_structures #dfs_and_similar #trees 