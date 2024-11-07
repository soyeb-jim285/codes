<h1 style='text-align: center;'> F. Escape Through Leaf</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with *n* nodes (numbered from 1 to *n*) rooted at node 1. Also, each node has two values associated with it. The values for *i*-th node are *a**i* and *b**i*.

You can jump from a node to any node in its subtree. The cost of one jump from node *x* to node *y* is the product of *a**x* and *b**y*. The total cost of a path formed by one or more jumps is sum of costs of individual jumps. For every node, calculate the minimum total cost to reach any leaf from that node. Pay attention, that root can never be leaf, even if it has degree 1.

## Note

 that you cannot jump from a node to itself.

## Input

The first line of input contains an integer *n* (2 ≤ *n* ≤ 105) — the number of nodes in the tree.

The second line contains *n* space-separated integers *a*1,  *a*2,  ...,  *a**n*( - 105  ≤  *a**i*  ≤  105).

The third line contains *n* space-separated integers *b*1,  *b*2,  ...,  *b**n*( - 105  ≤  *b**i*  ≤  105).

Next *n*  -  1 lines contains two space-separated integers *u**i* and *v**i* (1 ≤ *u**i*,  *v**i* ≤  *n*) describing edge between nodes *u**i* and *v**i* in the tree.

## Output

## Output

 *n* space-separated integers, *i*-th of which denotes the minimum cost of a path from node *i* to reach any leaf.

## Examples

## Input


```
3  
2 10 -1  
7 -7 5  
2 3  
2 1  

```
## Output


```
10 50 0 
```
## Input


```
4  
5 -10 5 7  
-8 -80 -3 -10  
2 1  
2 4  
1 3  

```
## Output


```
-300 100 0 0 
```
## Note

In the first example, node 3 is already a leaf, so the cost is 0. For node 2, jump to node 3 with cost *a*2 × *b*3 = 50. For node 1, jump directly to node 3 with cost *a*1 × *b*3 = 10.

In the second example, node 3 and node 4 are leaves, so the cost is 0. For node 2, jump to node 4 with cost *a*2 × *b*4 = 100. For node 1, jump to node 2 with cost *a*1 × *b*2 =  - 400 followed by a jump from 2 to 4 with cost *a*2 × *b*4 = 100.



#### tags 

#2700 #data_structures #dp #geometry 