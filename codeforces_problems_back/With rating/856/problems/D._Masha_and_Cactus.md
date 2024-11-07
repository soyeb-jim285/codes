<h1 style='text-align: center;'> D. Masha and Cactus</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Masha is fond of cacti. When she was a little girl, she decided to plant a tree. Now Masha wants to make a nice cactus out of her tree.

Recall that tree is a connected undirected graph that has no cycles. Cactus is a connected undirected graph such that each vertex belongs to at most one cycle.

Masha has some additional edges that she can add to a tree. For each edge she knows which vertices it would connect and the beauty of this edge. Masha can add some of these edges to the graph if the resulting graph is a cactus. Beauty of the resulting cactus is sum of beauties of all added edges. 

Help Masha find out what maximum beauty of the resulting cactus she can achieve.

## Input

The first line of the input data contains two integers *n* and *m* — the number of vertices in a tree, and the number of additional edges available (3 ≤ *n* ≤ 2·105; 0 ≤ *m* ≤ 2·105).

Let us describe Masha's tree. It has a root at vertex 1. The second line contains *n* - 1 integers: *p*2, *p*3, ..., *p**n*, here *p**i* — is the parent of a vertex *i* — the first vertex on a path from the vertex *i* to the root of the tree (1 ≤ *p**i* < *i*).

The following *m* lines contain three integers *u**i*, *v**i* and *c**i* — pairs of vertices to be connected by the additional edges that Masha can add to the tree and beauty of edge (1 ≤ *u**i*, *v**i* ≤ *n*; *u**i* ≠ *v**i*; 1 ≤ *c**i* ≤ 104).

It is guaranteed that no additional edge coincides with the edge of the tree.

## Output

## Output

 one integer — the maximum beauty of a cactus Masha can achieve.

## Example

## Input


```
7 3  
1 1 2 2 3 3  
4 5 1  
6 7 1  
2 3 1  

```
## Output


```
2  

```


#### tags 

#2400 #dp #trees 