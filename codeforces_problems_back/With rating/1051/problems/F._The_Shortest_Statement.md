<h1 style='text-align: center;'> F. The Shortest Statement</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a weighed undirected connected graph, consisting of $n$ vertices and $m$ edges.

You should answer $q$ queries, the $i$-th query is to find the shortest distance between vertices $u_i$ and $v_i$.

## Input

The first line contains two integers $n$ and $m~(1 \le n, m \le 10^5, m - n \le 20)$ — the number of vertices and edges in the graph.

Next $m$ lines contain the edges: the $i$-th edge is a triple of integers $v_i, u_i, d_i~(1 \le u_i, v_i \le n, 1 \le d_i \le 10^9, u_i \neq v_i)$. This triple means that there is an edge between vertices $u_i$ and $v_i$ of weight $d_i$. It is guaranteed that graph contains no self-loops and multiple edges.

The next line contains a single integer $q~(1 \le q \le 10^5)$ — the number of queries.

Each of the next $q$ lines contains two integers $u_i$ and $v_i~(1 \le u_i, v_i \le n)$ — descriptions of the queries.

Pay attention to the restriction $m - n ~ \le ~ 20$.

## Output

Print $q$ lines.

The $i$-th line should contain the answer to the $i$-th query — the shortest distance between vertices $u_i$ and $v_i$.

## Examples

## Input


```
3 3  
1 2 3  
2 3 1  
3 1 5  
3  
1 2  
1 3  
2 3  

```
## Output


```
3  
4  
1  

```
## Input


```
8 13  
1 2 4  
2 3 6  
3 4 1  
4 5 12  
5 6 3  
6 7 8  
7 8 7  
1 4 1  
1 8 3  
2 6 9  
2 7 1  
4 6 3  
6 8 2  
8  
1 5  
1 7  
2 3  
2 8  
3 7  
3 4  
6 8  
7 8  

```
## Output


```
7  
5  
6  
7  
7  
1  
2  
7  

```


#### tags 

#2400 #graphs #shortest_paths #trees 