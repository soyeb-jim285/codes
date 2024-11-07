<h1 style='text-align: center;'> F. Tree nesting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two trees (connected undirected acyclic graphs) *S* and *T*.

Count the number of subtrees (connected subgraphs) of *S* that are isomorphic to tree *T*. Since this number can get quite large, output it modulo 109 + 7.

Two subtrees of tree *S* are considered different, if there exists a vertex in *S* that belongs to exactly one of them.

Tree *G* is called isomorphic to tree *H* if there exists a bijection *f* from the set of vertices of *G* to the set of vertices of *H* that has the following property: if there is an edge between vertices *A* and *B* in tree *G*, then there must be an edge between vertices *f*(*A*) and *f*(*B*) in tree *H*. And vice versa — if there is an edge between vertices *A* and *B* in tree *H*, there must be an edge between *f*- 1(*A*) and *f*- 1(*B*) in tree *G*.

## Input

The first line contains a single integer |*S*| (1 ≤ |*S*| ≤ 1000) — the number of vertices of tree *S*.

Next |*S*| - 1 lines contain two integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ |*S*|) and describe edges of tree *S*.

The next line contains a single integer |*T*| (1 ≤ |*T*| ≤ 12) — the number of vertices of tree *T*.

Next |*T*| - 1 lines contain two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ |*T*|) and describe edges of tree *T*.

## Output

On the first line output a single integer — the answer to the given task modulo 109 + 7.

## Examples

## Input


```
5  
1 2  
2 3  
3 4  
4 5  
3  
1 2  
2 3  

```
## Output


```
3  

```
## Input


```
3  
2 3  
3 1  
3  
1 2  
1 3  

```
## Output


```
1  

```
## Input


```
7  
1 2  
1 3  
1 4  
1 5  
1 6  
1 7  
4  
4 1  
4 2  
4 3  

```
## Output


```
20  

```
## Input


```
5  
1 2  
2 3  
3 4  
4 5  
4  
4 1  
4 2  
4 3  

```
## Output


```
0  

```


#### tags 

#2800 #combinatorics #graphs #trees 