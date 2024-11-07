<h1 style='text-align: center;'> D. Almost Acyclic Graph</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) consisting of *n* vertices and *m* edges (each edge is directed, so it can be traversed in only one direction). You are allowed to remove at most one edge from it.

Can you make this graph [acyclic](https://en.wikipedia.org/wiki/Directed_acyclic_graph) by removing at most one edge from it? A directed graph is called acyclic iff it doesn't contain any cycle (a non-empty path that starts and ends in the same vertex).

## Input

The first line contains two integers *n* and *m* (2 ≤ *n* ≤ 500, 1 ≤ *m* ≤ *min*(*n*(*n* - 1), 100000)) — the number of vertices and the number of edges, respectively.

Then *m* lines follow. Each line contains two integers *u* and *v* denoting a directed edge going from vertex *u* to vertex *v* (1 ≤ *u*, *v* ≤ *n*, *u* ≠ *v*). Each ordered pair (*u*, *v*) is listed at most once (there is at most one directed edge from *u* to *v*).

## Output

If it is possible to make this graph acyclic by removing at most one edge, print YES. Otherwise, print NO.

## Examples

## Input


```
3 4  
1 2  
2 3  
3 2  
3 1  

```
## Output


```
YES  

```
## Input


```
5 6  
1 2  
2 3  
3 2  
3 1  
2 1  
4 5  

```
## Output


```
NO  

```
## Note

In the first example you can remove edge ![](images/29f71c065c3536e88b54429c734103ad3604f68b.png), and the graph becomes acyclic.

In the second example you have to remove at least two edges (for example, ![](images/420322fe5fba4eb3e3eba6886a2edb31f15762ce.png) and ![](images/29f71c065c3536e88b54429c734103ad3604f68b.png)) in order to make the graph acyclic.



#### tags 

#2200 #dfs_and_similar #graphs 