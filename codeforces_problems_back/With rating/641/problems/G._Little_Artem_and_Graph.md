<h1 style='text-align: center;'> G. Little Artem and Graph</h1>

<h5 style='text-align: center;'>time limit per test: 12 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Artem is given a graph, constructed as follows: start with some *k*-clique, then add new vertices one by one, connecting them to *k* already existing vertices that form a *k*-clique.

Artem wants to count the number of spanning trees in this graph modulo 109 + 7.

## Input

First line of the input contains two integers *n* and *k* (1 ≤ *n* ≤ 10 000, 1 ≤ *k* ≤ *min*(*n*, 5)) — the total size of the graph and the size of the initial clique, respectively.

Next *n* - *k* lines describe *k* + 1-th, *k* + 2-th, ..., *i*-th, ..., *n*-th vertices by listing *k* distinct vertex indices 1 ≤ *a**ij* < *i* it is connected to. It is guaranteed that those vertices form a k-clique.

## Output

## Output

 a single integer — the number of spanning trees in the given graph modulo 109 + 7.

## Examples

## Input


```
3 2  
1 2  

```
## Output


```
3  

```
## Input


```
4 3  
1 2 3  

```
## Output


```
16  

```


#### tags 

#2300 