<h1 style='text-align: center;'> D. Regular Bridge</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An undirected graph is called *k*-regular, if the degrees of all its vertices are equal *k*. An edge of a connected graph is called a bridge, if after removing it the graph is being split into two connected components.

Build a connected undirected *k*-regular graph containing at least one bridge, or else state that such graph doesn't exist.

## Input

The single line of the input contains integer *k* (1 ≤ *k* ≤ 100) — the required degree of the vertices of the regular graph.

## Output

Print "NO" (without quotes), if such graph doesn't exist. 

Otherwise, print "YES" in the first line and the description of any suitable graph in the next lines.

The description of the made graph must start with numbers *n* and *m* — the number of vertices and edges respectively. 

Each of the next *m* lines must contain two integers, *a* and *b* (1 ≤ *a*, *b* ≤ *n*, *a* ≠ *b*), that mean that there is an edge connecting the vertices *a* and *b*. A graph shouldn't contain multiple edges and edges that lead from a vertex to itself. A graph must be connected, the degrees of all vertices of the graph must be equal *k*. At least one edge of the graph must be a bridge. You can print the edges of the graph in any order. You can print the ends of each edge in any order.

The constructed graph must contain at most 106 vertices and 106 edges (it is guaranteed that if at least one graph that meets the requirements exists, then there also exists the graph with at most 106 vertices and at most 106 edges). 

## Examples

## Input


```
1  

```
## Output


```
YES  
2 1  
1 2  

```
## Note

In the sample from the statement there is a suitable graph consisting of two vertices, connected by a single edge.



#### tags 

#1900 #constructive_algorithms #graphs #implementation 