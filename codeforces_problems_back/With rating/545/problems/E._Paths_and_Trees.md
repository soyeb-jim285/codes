<h1 style='text-align: center;'> E. Paths and Trees</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little girl Susie accidentally found her elder brother's notebook. She has many things to do, more important than solving problems, but she found this problem too interesting, so she wanted to know its solution and decided to ask you about it. So, the problem statement is as follows.

Let's assume that we are given a connected weighted undirected graph *G* = (*V*, *E*) (here *V* is the set of vertices, *E* is the set of edges). The shortest-path tree from vertex *u* is such graph *G*1 = (*V*, *E*1) that is a tree with the set of edges *E*1 that is the subset of the set of edges of the initial graph *E*, and the lengths of the shortest paths from *u* to any vertex to *G* and to *G*1 are the same. 

You are given a connected weighted undirected graph *G* and vertex *u*. Your task is to find the shortest-path tree of the given graph from vertex *u*, the total weight of whose edges is minimum possible.

## Input

The first line contains two numbers, *n* and *m* (1 ≤ *n* ≤ 3·105, 0 ≤ *m* ≤ 3·105) — the number of vertices and edges of the graph, respectively.

Next *m* lines contain three integers each, representing an edge — *u**i*, *v**i*, *w**i* — the numbers of vertices connected by an edge and the weight of the edge (*u**i* ≠ *v**i*, 1 ≤ *w**i* ≤ 109). It is guaranteed that graph is connected and that there is no more than one edge between any pair of vertices.

The last line of the input contains integer *u* (1 ≤ *u* ≤ *n*) — the number of the start vertex.

## Output

In the first line print the minimum total weight of the edges of the tree.

In the next line print the indices of the edges that are included in the tree, separated by spaces. The edges are numbered starting from 1 in the order they follow in the input. You may print the numbers of the edges in any order.

If there are multiple answers, print any of them.

## Examples

## Input


```
3 3  
1 2 1  
2 3 1  
1 3 2  
3  

```
## Output


```
2  
1 2   

```
## Input


```
4 4  
1 2 1  
2 3 1  
3 4 1  
4 1 2  
4  

```
## Output


```
4  
2 3 4   

```
## Note

In the first sample there are two possible shortest path trees:

* with edges 1 – 3 and 2 – 3 (the total weight is 3);
* with edges 1 – 2 and 2 – 3 (the total weight is 2);

And, for example, a tree with edges 1 – 2 and 1 – 3 won't be a shortest path tree for vertex 3, because the distance from vertex 3 to vertex 2 in this tree equals 3, and in the original graph it is 1.



#### tags 

#2000 #graphs #greedy #shortest_paths 