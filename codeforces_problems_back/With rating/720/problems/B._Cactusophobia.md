<h1 style='text-align: center;'> B. Cactusophobia</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tree is a connected undirected graph that has no cycles. Edge cactus is a connected undirected graph without loops and parallel edges, such that each edge belongs to at most one cycle.

Vasya has an edge cactus, each edge of this graph has some color.

Vasya would like to remove the minimal number of edges in such way that his cactus turned to a tree. Vasya wants to make it in such a way that there were edges of as many different colors in the resulting tree, as possible. Help him to find how many different colors can the resulting tree have.

## Input

The first line contains two integers: *n*, *m* (2 ≤ *n* ≤ 10 000) — the number of vertices and the number of edges in Vasya's graph, respectively.

The following *m* lines contain three integers each: *u*, *v*, *c* (1 ≤ *u*, *v* ≤ *n*, *u* ≠ *v*, 1 ≤ *c* ≤ *m*) — the numbers of vertices connected by the corresponding edge, and its color. It is guaranteed that the described graph is indeed an edge cactus.

## Output

## Output

 one integer: the maximal number of different colors that the resulting tree can have.

## Examples

## Input


```
4 4  
1 2 4  
2 3 1  
3 4 2  
4 2 3  

```
## Output


```
3  

```
## Input


```
7 9  
1 2 1  
2 3 4  
3 1 5  
1 4 5  
4 5 2  
5 1 6  
1 6 4  
6 7 6  
7 1 3  

```
## Output


```
6  

```


#### tags 

#2400 #dfs_and_similar #flows 