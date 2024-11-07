<h1 style='text-align: center;'> E. PolandBall and White-Red graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

PolandBall has an undirected simple graph consisting of *n* vertices. Unfortunately, it has no edges. The graph is very sad because of that. PolandBall wanted to make it happier, adding some red edges. Then, he will add white edges in every remaining place. Therefore, the final graph will be a clique in two colors: white and red. 

Colorfulness of the graph is a value *min*(*d**r*, *d**w*), where *d**r* is the diameter of the red subgraph and *d**w* is the diameter of white subgraph. The diameter of a graph is a largest value *d* such that shortest path between some pair of vertices in it is equal to *d*. If the graph is not connected, we consider its diameter to be -1.

PolandBall wants the final graph to be as neat as possible. He wants the final colorfulness to be equal to *k*. Can you help him and find any graph which satisfies PolandBall's requests?

## Input

The only one input line contains two integers *n* and *k* (2 ≤ *n* ≤ 1000, 1 ≤ *k* ≤ 1000), representing graph's size and sought colorfulness.

## Output

If it's impossible to find a suitable graph, print -1.

Otherwise, you can output any graph which fulfills PolandBall's requirements. First, output *m* — the number of red edges in your graph. Then, you should output *m* lines, each containing two integers *a**i* and *b**i*, (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*) which means that there is an undirected red edge between vertices *a**i* and *b**i*. Every red edge should be printed exactly once, you can print the edges and the vertices of every edge in arbitrary order.

Remember that PolandBall's graph should remain simple, so no loops or multiple edges are allowed.

## Examples

## Input


```
4 1  

```
## Output


```
-1  

```
## Input


```
5 2  

```
## Output


```
4  
1 2  
2 3  
3 4  
4 5  

```
## Note

In the first sample case, no graph can fulfill PolandBall's requirements.

In the second sample case, red graph is a path from 1 to 5. Its diameter is 4. However, white graph has diameter 2, because it consists of edges 1-3, 1-4, 1-5, 2-4, 2-5, 3-5.



#### tags 

#2400 #constructive_algorithms #graphs #shortest_paths 