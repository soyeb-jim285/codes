<h1 style='text-align: center;'> D. Colorful Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got an undirected graph, consisting of *n* vertices and *m* edges. We will consider the graph's vertices numbered with integers from 1 to *n*. Each vertex of the graph has a color. The color of the *i*-th vertex is an integer *c**i*.

Let's consider all vertices of the graph, that are painted some color *k*. Let's denote a set of such as *V*(*k*). Let's denote the value of the neighbouring color diversity for color *k* as the cardinality of the set *Q*(*k*) = {*c**u* :  *c**u* ≠ *k* and there is vertex *v* belonging to set *V*(*k*) such that nodes *v* and *u* are connected by an edge of the graph}.

Your task is to find such color *k*, which makes the cardinality of set *Q*(*k*) maximum. In other words, you want to find the color that has the most diverse neighbours. Please note, that you want to find such color *k*, that the graph has at least one vertex with such color.

## Input

The first line contains two space-separated integers *n*, *m* (1 ≤ *n*, *m* ≤ 105) — the number of vertices end edges of the graph, correspondingly. The second line contains a sequence of integers *c*1, *c*2, ..., *c**n* (1 ≤ *c**i* ≤ 105) — the colors of the graph vertices. The numbers on the line are separated by spaces.

Next *m* lines contain the description of the edges: the *i*-th line contains two space-separated integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *a**i* ≠ *b**i*) — the numbers of the vertices, connected by the *i*-th edge. 

It is guaranteed that the given graph has no self-loops or multiple edges.

## Output

Print the number of the color which has the set of neighbours with the maximum cardinality. It there are multiple optimal colors, print the color with the minimum number. Please note, that you want to find such color, that the graph has at least one vertex with such color.

## Examples

## Input


```
6 6  
1 1 2 3 5 8  
1 2  
3 2  
1 4  
4 3  
4 5  
4 6  

```
## Output


```
3  

```
## Input


```
5 6  
4 2 5 2 4  
1 2  
2 3  
3 1  
5 3  
5 4  
3 4  

```
## Output


```
2  

```


#### tags 

#1600 #brute_force #dfs_and_similar #graphs 