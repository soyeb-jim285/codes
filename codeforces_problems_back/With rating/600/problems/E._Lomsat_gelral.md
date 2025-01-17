<h1 style='text-align: center;'> E. Lomsat gelral</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree with root in vertex 1. Each vertex is coloured in some colour.

Let's call colour *c* dominating in the subtree of vertex *v* if there are no other colours that appear in the subtree of vertex *v* more times than colour *c*. So it's possible that two or more colours will be dominating in the subtree of some vertex.

The subtree of vertex *v* is the vertex *v* and all other vertices that contains vertex *v* in each path to the root.

For each vertex *v* find the sum of all dominating colours in the subtree of vertex *v*.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of vertices in the tree.

The second line contains *n* integers *c**i* (1 ≤ *c**i* ≤ *n*), *c**i* — the colour of the *i*-th vertex.

Each of the next *n* - 1 lines contains two integers *x**j*, *y**j* (1 ≤ *x**j*, *y**j* ≤ *n*) — the edge of the tree. The first vertex is the root of the tree.

## Output

Print *n* integers — the sums of dominating colours for each vertex.

## Examples

## Input


```
4  
1 2 3 4  
1 2  
2 3  
2 4  

```
## Output


```
10 9 3 4  

```
## Input


```
15  
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3  
1 2  
1 3  
1 4  
1 14  
1 15  
2 5  
2 6  
2 7  
3 8  
3 9  
3 10  
4 11  
4 12  
4 13  

```
## Output


```
6 5 4 3 2 3 3 1 1 3 2 2 1 2 3  

```


#### tags 

#2300 #data_structures #dfs_and_similar #dsu #trees 