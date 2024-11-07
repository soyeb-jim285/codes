<h1 style='text-align: center;'> D. Recover a functional graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Functional graph is a directed graph in which all vertices have outdegree equal to 1. Loops are allowed.

Some vertices of a functional graph lay on a cycle. From the others we can come to a cycle by making a finite number of steps along the edges (we consider only finite functional graphs in this problem).

Let's compute two values for each vertex. *precycle**i* is the amount of edges we should pass to get to a vertex which is a part of some cycle (zero, if *i* itself lies on a cycle), *cycle**i* is the length of the cycle we get to.

You are given the information about these values for some functional graph. For each vertex you know the values *precycle**i* and *cycle**i*, however, instead of some values there can be the question mark. It means that these values are unknown.

Build any functional graph that suits the description or determine that there is no such graph.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 300) — the number of vertices in the graph.

Each of the next *n* lines contain two integers — *precycle**i* (0 ≤ *precycle**i* ≤ *n* - 1) and *cycle**i* (1 ≤ *cycle**i* ≤ *n*). There could be question marks instead of some of these values.

## Output

In case there is no solution, print -1.

Otherwise, print *n* integers. *i*-th of them is the number of vertex to which the edge form the *i*-th vertex go.

The vertices should be in the same order as they go in input data.

If there are multiple solutions, print any of them.

## Examples

## Input


```
3  
0 3  
0 3  
? ?  

```
## Output


```
2 3 1   

```
## Input


```
5  
3 2  
? ?  
? ?  
? ?  
? ?  

```
## Output


```
5 3 2 2 4   

```
## Input


```
8  
? 3  
? ?  
0 2  
0 2  
0 3  
0 3  
0 3  
3 3  

```
## Output


```
5 1 4 3 6 7 5 2   

```
## Input


```
1  
? ?  

```
## Output


```
1   

```
## Input


```
6  
0 3  
0 3  
0 3  
0 3  
0 3  
0 3  

```
## Output


```
2 3 1 5 6 4   

```
## Input


```
2  
1 1  
1 1  

```
## Output


```
-1  

```


#### tags 

#3400 #graph_matchings 