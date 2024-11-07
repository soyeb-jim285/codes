<h1 style='text-align: center;'> D. Degree Set</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence of *n* positive integers *d*1, *d*2, ..., *d**n* (*d*1 < *d*2 < ... < *d**n*). Your task is to construct an undirected graph such that:

* there are exactly *d**n* + 1 vertices;
* there are no self-loops;
* there are no multiple edges;
* there are no more than 106 edges;
* its degree set is equal to *d*.

Vertices should be numbered 1 through (*d**n* + 1).

Degree sequence is an array *a* with length equal to the number of vertices in a graph such that *a**i* is the number of vertices adjacent to *i*-th vertex.

Degree set is a sorted in increasing order sequence of all distinct values from the degree sequence.

It is guaranteed that there exists such a graph that all the conditions hold, and it contains no more than 106 edges.

Print the resulting graph.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 300) — the size of the degree set.

The second line contains *n* integers *d*1, *d*2, ..., *d**n* (1 ≤ *d**i* ≤ 1000, *d*1 < *d*2 < ... < *d**n*) — the degree set.

## Output

In the first line print one integer *m* (1 ≤ *m* ≤ 106) — the number of edges in the resulting graph. It is guaranteed that there exists such a graph that all the conditions hold and it contains no more than 106 edges.

Each of the next *m* lines should contain two integers *v**i* and *u**i* (1 ≤ *v**i*, *u**i* ≤ *d**n* + 1) — the description of the *i*-th edge.

## Examples

## Input


```
3  
2 3 4  

```
## Output


```
8  
3 1  
4 2  
4 5  
2 5  
5 1  
3 2  
2 1  
5 3  

```
## Input


```
3  
1 2 3  

```
## Output


```
4  
1 2  
1 3  
1 4  
2 3  

```


#### tags 

#2500 #constructive_algorithms #graphs #implementation 