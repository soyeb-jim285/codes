<h1 style='text-align: center;'> B. Diverging Directions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a directed weighted graph with *n* nodes and 2*n* - 2 edges. The nodes are labeled from 1 to *n*, while the edges are labeled from 1 to 2*n* - 2. The graph's edges can be split into two parts.

* The first *n* - 1 edges will form a rooted spanning tree, with node 1 as the root. All these edges will point away from the root.
* The last *n* - 1 edges will be from node *i* to node 1, for all 2 ≤ *i* ≤ *n*.

You are given *q* queries. There are two types of queries

* 1 *i* *w*: Change the weight of the *i*-th edge to *w*
* 2 *u* *v*: Print the length of the shortest path between nodes *u* to *v*

Given these queries, print the shortest path lengths.

## Input

The first line of input will contain two integers *n*, *q* (2 ≤ *n*, *q* ≤ 200 000), the number of nodes, and the number of queries, respectively.

The next 2*n* - 2 integers will contain 3 integers *a**i*, *b**i*, *c**i*, denoting a directed edge from node *a**i* to node *b**i* with weight *c**i*.

The first *n* - 1 of these lines will describe a rooted spanning tree pointing away from node 1, while the last *n* - 1 of these lines will have *b**i* = 1.

More specifically, 

* The edges (*a*1, *b*1), (*a*2, *b*2), ... (*a**n* - 1, *b**n* - 1) will describe a rooted spanning tree pointing away from node 1.
* *b**j* = 1 for *n* ≤ *j* ≤ 2*n* - 2.
* *a**n*, *a**n* + 1, ..., *a*2*n* - 2 will be distinct and between 2 and *n*.

The next *q* lines will contain 3 integers, describing a query in the format described in the statement.

All edge weights will be between 1 and 106.

## Output

For each type 2 query, print the length of the shortest path in its own line.

## Example

## Input


```
5 9  
1 3 1  
3 2 2  
1 4 3  
3 5 4  
5 1 5  
3 1 6  
2 1 7  
4 1 8  
2 1 1  
2 1 3  
2 3 5  
2 5 2  
1 1 100  
2 1 3  
1 8 30  
2 4 2  
2 2 4  

```
## Output


```
0  
1  
4  
8  
100  
132  
10  

```


#### tags 

#2100 #data_structures #dfs_and_similar #trees 