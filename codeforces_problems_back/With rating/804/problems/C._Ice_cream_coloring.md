<h1 style='text-align: center;'> C. Ice cream coloring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Isart and Modsart were trying to solve an interesting problem when suddenly Kasra arrived. Breathless, he asked: "Can you solve a problem I'm stuck at all day?"

We have a tree *T* with *n* vertices and *m* types of ice cream numerated from 1 to *m*. Each vertex *i* has a set of *s**i* types of ice cream. Vertices which have the *i*-th (1 ≤ *i* ≤ *m*) type of ice cream form a connected subgraph. We build a new graph *G* with *m* vertices. We put an edge between the *v*-th and the *u*-th (1 ≤ *u*, *v* ≤ *m*, *u* ≠ *v*) vertices in *G* if and only if there exists a vertex in *T* that has both the *v*-th and the *u*-th types of ice cream in its set. The problem is to paint the vertices of *G* with minimum possible number of colors in a way that no adjacent vertices have the same color.

Please note that we consider that empty set of vertices form a connected subgraph in this problem.

As usual, Modsart don't like to abandon the previous problem, so Isart wants you to solve the new problem.

## Input

The first line contains two integer *n* and *m* (1 ≤ *n*, *m* ≤ 3·105) — the number of vertices in *T* and the number of ice cream types.

*n* lines follow, the *i*-th of these lines contain single integer *s**i* (0 ≤ *s**i* ≤ 3·105) and then *s**i* distinct integers, each between 1 and *m* — the types of ice cream in the *i*-th vertex. The sum of *s**i* doesn't exceed 5·105.

*n* - 1 lines follow. Each of these lines describes an edge of the tree with two integers *u* and *v* (1 ≤ *u*, *v* ≤ *n*) — the indexes of connected by this edge vertices.

## Output

Print single integer *c* in the first line — the minimum number of colors to paint the vertices in graph *G*.

In the second line print *m* integers, the *i*-th of which should be the color of the *i*-th vertex. The colors should be between 1 and *c*. If there are some answers, print any of them.

## Examples

## Input


```
3 3  
1 1  
2 2 3  
1 2  
1 2  
2 3  

```
## Output


```
2  
1 1 2 
```
## Input


```
4 5  
0  
1 1  
1 3  
3 2 4 5  
2 1  
3 2  
4 3  

```
## Output


```
3  
1 1 1 2 3 
```
## Note

In the first example the first type of ice cream is present in the first vertex only, so we can color it in any color. The second and the third ice cream are both presented in the second vertex, so we should paint them in different colors.

In the second example the colors of the second, the fourth and the fifth ice cream should obviously be distinct.



#### tags 

#2200 #constructive_algorithms #dfs_and_similar #greedy 