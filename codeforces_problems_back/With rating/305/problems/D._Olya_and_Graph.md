<h1 style='text-align: center;'> D. Olya and Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Olya has got a directed non-weighted graph, consisting of *n* vertexes and *m* edges. We will consider that the graph vertexes are indexed from 1 to *n* in some manner. Then for any graph edge that goes from vertex *v* to vertex *u* the following inequation holds: *v* < *u*.

Now Olya wonders, how many ways there are to add an arbitrary (possibly zero) number of edges to the graph so as the following conditions were met:

1. You can reach vertexes number *i* + 1, *i* + 2, ..., *n* from any vertex number *i* (*i* < *n*).
2. For any graph edge going from vertex *v* to vertex *u* the following inequation fulfills: *v* < *u*.
3. There is at most one edge between any two vertexes.
4. The shortest distance between the pair of vertexes *i*, *j* (*i* < *j*), for which *j* - *i* ≤ *k* holds, equals *j* - *i* edges.
5. The shortest distance between the pair of vertexes *i*, *j* (*i* < *j*), for which *j* - *i* > *k* holds, equals either *j* - *i* or *j* - *i* - *k* edges.

 We will consider two ways distinct, if there is the pair of vertexes *i*, *j* (*i* < *j*), such that first resulting graph has an edge from *i* to *j* and the second one doesn't have it.

Help Olya. As the required number of ways can be rather large, print it modulo 1000000007 (109 + 7).

## Input

The first line contains three space-separated integers *n*, *m*, *k* (2 ≤ *n* ≤ 106, 0 ≤ *m* ≤ 105, 1 ≤ *k* ≤ 106).

The next *m* lines contain the description of the edges of the initial graph. The *i*-th line contains a pair of space-separated integers *u**i*, *v**i* (1 ≤ *u**i* < *v**i* ≤ *n*) — the numbers of vertexes that have a directed edge from *u**i* to *v**i* between them. 

It is guaranteed that any pair of vertexes *u**i*, *v**i* has at most one edge between them. It also is guaranteed that the graph edges are given in the order of non-decreasing *u**i*. If there are multiple edges going from vertex *u**i*, then it is guaranteed that these edges are given in the order of increasing *v**i*.

## Output

Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
7 8 2  
1 2  
2 3  
3 4  
3 6  
4 5  
4 7  
5 6  
6 7  

```
## Output


```
2  

```
## Input


```
7 0 2  

```
## Output


```
12  

```
## Input


```
7 2 1  
1 3  
3 5  

```
## Output


```
0  

```
## Note

In the first sample there are two ways: the first way is not to add anything, the second way is to add a single edge from vertex 2 to vertex 5.



#### tags 

#2200 #combinatorics #math 