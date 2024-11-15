<h1 style='text-align: center;'> E. ELCA</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a root tree containing *n* vertexes. Let's number the tree vertexes with integers from 1 to *n*. The tree root is in the vertex 1.

Each vertex (except fot the tree root) *v* has a direct ancestor *p**v*. Also each vertex *v* has its integer value *s**v*. 

Your task is to perform following queries:

* P *v* *u* (*u* ≠ *v*). If *u* isn't in subtree of *v*, you must perform the assignment *p**v* = *u*. Otherwise you must perform assignment *p**u* = *v*. ## Note

 that after this query the graph continues to be a tree consisting of *n* vertexes.
* V *v* *t*. Perform assignment *s**v* = *t*.

Your task is following. Before starting performing queries and after each query you have to calculate expected value written on the lowest common ancestor of two equiprobably selected vertices *i* and *j*. Here lowest common ancestor of *i* and *j* is the deepest vertex that lies on the both of the path from the root to vertex *i* and the path from the root to vertex *j*. Please note that the vertices *i* and *j* can be the same (in this case their lowest common ancestor coincides with them).

## Input

The first line of the input contains integer *n* (2 ≤ *n* ≤ 5·104) — the number of the tree vertexes. 

The second line contains *n* - 1 integer *p*2, *p*3, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the description of the tree edges. It is guaranteed that those numbers form a tree.

The third line contains *n* integers — *s*1, *s*2, ... *s**n* (0 ≤ *s**i* ≤ 106) — the values written on each vertex of the tree.

The next line contains integer *q* (1 ≤ *q* ≤ 5·104) — the number of queries. Each of the following *q* lines contains the description of the query in the format described in the statement. It is guaranteed that query arguments *u* and *v* lie between 1 and *n*. It is guaranteed that argument *t* in the queries of type V meets limits 0 ≤ *t* ≤ 106.

## Output

Print *q* + 1 number — the corresponding expected values. Your answer will be considered correct if its absolute or relative error doesn't exceed 10- 9.

## Examples

## Input


```
5  
1 2 2 1  
1 2 3 4 5  
5  
P 3 4  
P 4 5  
V 2 3  
P 5 2  
P 1 4  

```
## Output


```
1.640000000  
1.800000000  
2.280000000  
2.320000000  
2.800000000  
1.840000000  

```
## Note

## Note

 that in the query P *v* *u* if *u* lies in subtree of *v* you must perform assignment *p**u* = *v*. An example of such case is the last query in the sample.



#### tags 

#3200 #data_structures #trees 