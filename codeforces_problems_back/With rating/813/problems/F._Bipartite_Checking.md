<h1 style='text-align: center;'> F. Bipartite Checking</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected graph consisting of *n* vertices. Initially there are no edges in the graph. Also you are given *q* queries, each query either adds one undirected edge to the graph or removes it. After each query you have to check if the resulting graph is bipartite (that is, you can paint all vertices of the graph into two colors so that there is no edge connecting two vertices of the same color).

## Input

The first line contains two integers *n* and *q* (2 ≤ *n*, *q* ≤ 100000).

Then *q* lines follow. *i*th line contains two numbers *x**i* and *y**i* (1 ≤ *x**i* < *y**i* ≤ *n*). These numbers describe *i*th query: if there is an edge between vertices *x**i* and *y**i*, then remove it, otherwise add it.

## Output

Print *q* lines. *i*th line must contain YES if the graph is bipartite after *i*th query, and NO otherwise.

## Example

## Input


```
3 5  
2 3  
1 3  
1 2  
1 2  
1 2  

```
## Output


```
YES  
YES  
NO  
YES  
NO  

```


#### tags 

#2500 #data_structures #dsu #graphs 