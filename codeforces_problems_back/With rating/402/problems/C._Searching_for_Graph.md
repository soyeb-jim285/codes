<h1 style='text-align: center;'> C. Searching for Graph</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an undirected graph of *n* vertices *p*-interesting, if the following conditions fulfill: 

* the graph contains exactly 2*n* + *p* edges;
* the graph doesn't contain self-loops and multiple edges;
* for any integer *k* (1 ≤ *k* ≤ *n*), any subgraph consisting of *k* vertices contains at most 2*k* + *p* edges.

A subgraph of a graph is some set of the graph vertices and some set of the graph edges. At that, the set of edges must meet the condition: both ends of each edge from the set must belong to the chosen set of vertices. 

Your task is to find a *p*-interesting graph consisting of *n* vertices.

## Input

The first line contains a single integer *t* (1 ≤ *t* ≤ 5) — the number of tests in the input. Next *t* lines each contains two space-separated integers: *n*, *p* (5 ≤ *n* ≤ 24; *p* ≥ 0; ![](images/cb77925daa60ed3fa4319d6dab40a46c2e1f67c9.png)) — the number of vertices in the graph and the interest value for the appropriate test. 

It is guaranteed that the required graph exists.

## Output

For each of the *t* tests print 2*n* + *p* lines containing the description of the edges of a *p*-interesting graph: the *i*-th line must contain two space-separated integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *a**i* ≠ *b**i*) — two vertices, connected by an edge in the resulting graph. Consider the graph vertices numbered with integers from 1 to *n*. 

Print the answers to the tests in the order the tests occur in the input. If there are multiple solutions, you can print any of them.

## Examples

## Input


```
1  
6 0  

```
## Output


```
1 2  
1 3  
1 4  
1 5  
1 6  
2 3  
2 4  
2 5  
2 6  
3 4  
3 5  
3 6  

```


#### tags 

#1500 #brute_force #constructive_algorithms #graphs 