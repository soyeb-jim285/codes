<h1 style='text-align: center;'> C. Ilya And The Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ilya is very fond of graphs, especially trees. During his last trip to the forest Ilya found a very interesting tree rooted at vertex 1. There is an integer number written on each vertex of the tree; the number written on vertex *i* is equal to *a**i*.

Ilya believes that the beauty of the vertex *x* is the greatest common divisor of all numbers written on the vertices on the path from the root to *x*, including this vertex itself. In addition, Ilya can change the number in one arbitrary vertex to 0 or leave all vertices unchanged. Now for each vertex Ilya wants to know the maximum possible beauty it can have.

For each vertex the answer must be considered independently.

The beauty of the root equals to number written on it.

## Input

First line contains one integer number *n* — the number of vertices in tree (1 ≤ *n* ≤ 2·105).

Next line contains *n* integer numbers *a**i* (1 ≤ *i* ≤ *n*, 1 ≤ *a**i* ≤ 2·105).

Each of next *n* - 1 lines contains two integer numbers *x* and *y* (1 ≤ *x*, *y* ≤ *n*, *x* ≠ *y*), which means that there is an edge (*x*, *y*) in the tree.

## Output

## Output

 *n* numbers separated by spaces, where *i*-th number equals to maximum possible beauty of vertex *i*.

## Examples

## Input


```
2  
6 2  
1 2  

```
## Output


```
6 6   

```
## Input


```
3  
6 2 3  
1 2  
1 3  

```
## Output


```
6 6 6   

```
## Input


```
1  
10  

```
## Output


```
10   

```


#### tags 

#2000 #dfs_and_similar #graphs #math #number_theory #trees 