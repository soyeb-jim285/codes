<h1 style='text-align: center;'> D. Black and White Tree</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The board has got a painted tree graph, consisting of *n* nodes. Let us remind you that a non-directed graph is called a tree if it is connected and doesn't contain any cycles.

Each node of the graph is painted black or white in such a manner that there aren't two nodes of the same color, connected by an edge. Each edge contains its value written on it as a non-negative integer.

A bad boy Vasya came up to the board and wrote number *s**v* near each node *v* — the sum of values of all edges that are incident to this node. Then Vasya removed the edges and their values from the board.

Your task is to restore the original tree by the node colors and numbers *s**v*.

## Input

The first line of the input contains a single integer *n* (2 ≤ *n* ≤ 105) — the number of nodes in the tree. Next *n* lines contain pairs of space-separated integers *c**i*, *s**i* (0 ≤ *c**i* ≤ 1, 0 ≤ *s**i* ≤ 109), where *c**i* stands for the color of the *i*-th vertex (0 is for white, 1 is for black), and *s**i* represents the sum of values of the edges that are incident to the *i*-th vertex of the tree that is painted on the board.

## Output

Print the description of *n* - 1 edges of the tree graph. Each description is a group of three integers *v**i*, *u**i*, *w**i* (1 ≤ *v**i*, *u**i* ≤ *n*, *v**i* ≠ *u**i*, 0 ≤ *w**i* ≤ 109), where *v**i* and *u**i* — are the numbers of the nodes that are connected by the *i*-th edge, and *w**i* is its value. Note that the following condition must fulfill *c**v**i* ≠ *c**u**i*.

It is guaranteed that for any input data there exists at least one graph that meets these data. If there are multiple solutions, print any of them. You are allowed to print the edges in any order. As you print the numbers, separate them with spaces.

## Examples

## Input


```
3  
1 3  
1 2  
0 5  

```
## Output


```
3 1 3  
3 2 2  

```
## Input


```
6  
1 0  
0 3  
1 8  
0 2  
0 3  
0 0  

```
## Output


```
2 3 3  
5 3 3  
4 3 2  
1 6 0  
2 1 0  

```


#### tags 

#2100 #constructive_algorithms #dsu #graphs #greedy #trees 