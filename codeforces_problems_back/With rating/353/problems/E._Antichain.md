<h1 style='text-align: center;'> E. Antichain</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a directed acyclic graph *G*, consisting of *n* vertexes, numbered from 0 to *n* - 1. The graph contains *n* edges numbered from 0 to *n* - 1. An edge with number *i* connects vertexes *i* and (*i* + 1) *mod* *n*, and it can be directed in either direction (from *i* to (*i* + 1) *mod* *n*, or vise versa).

Operation *x* *mod* *y* means taking the remainder after dividing number *x* by number *y*.

Let's call two vertexes *u* and *v* in graph *G* comparable if the graph contains a path either from *u* to *v* or from *v* to *u*. We'll assume that an antichain is a set of vertexes of graph *G*, where any two distinct vertexes are not comparable. The size of an antichain is the number of vertexes in the corresponding set. An antichain is maximum if the graph doesn't have antichains of a larger size.

Your task is to find the size of the maximum antichain in graph *G*.

## Input

The first line contains the sequence of characters *s*0*s*1... *s**n* - 1 (2 ≤ *n* ≤ 106), consisting of numbers zero and one. The length of the line (number *n*) corresponds to the number of vertexes and edges in graph *G*. If character *s**i* (*i* ≥ 0) equals 0, then the edge between vertexes *i* and (*i* + 1) *mod* *n* is directed from the *i*-th vertex to the (*i* + 1) *mod* *n*-th one, otherwise — to the opposite point.

It is guaranteed that the given graph is acyclic.

## Output

Print a single integer — the size of the maximum antichain of graph *G*.

## Examples

## Input


```
001  

```
## Output


```
1  

```
## Input


```
110010  

```
## Output


```
3  

```
## Note

Consider the first test sample. The graph's *G* edges are: 0 → 1, 1 → 2, 0 → 2. We can choose the set of vertexes [0] as the maximum antichain. We cannot choose an antichain of larger size.



#### tags 

#2200 #dp #graph_matchings #greedy 