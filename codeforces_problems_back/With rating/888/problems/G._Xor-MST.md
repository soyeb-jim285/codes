<h1 style='text-align: center;'> G. Xor-MST</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a complete undirected graph with *n* vertices. A number *a**i* is assigned to each vertex, and the weight of an edge between vertices *i* and *j* is equal to *a**i* *xor* *a**j*.

Calculate the weight of the minimum spanning tree in this graph.

## Input

The first line contains *n* (1 ≤ *n* ≤ 200000) — the number of vertices in the graph.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* < 230) — the numbers assigned to the vertices.

## Output

Print one number — the weight of the minimum spanning tree in the graph.

## Examples

## Input


```
5  
1 2 3 4 5  

```
## Output


```
8  

```
## Input


```
4  
1 2 3 4  

```
## Output


```
8  

```


#### tags 

#2300 #bitmasks #constructive_algorithms #data_structures 