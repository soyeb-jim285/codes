<h1 style='text-align: center;'> G. Xor-matic Number of the Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected graph, constisting of *n* vertices and *m* edges. Each edge of the graph has some non-negative integer written on it.

Let's call a triple (*u*, *v*, *s*) interesting, if 1 ≤ *u* < *v* ≤ *n* and there is a path (possibly non-simple, i.e. it can visit the same vertices and edges multiple times) between vertices *u* and *v* such that xor of all numbers written on the edges of this path is equal to *s*. When we compute the value s for some path, each edge is counted in xor as many times, as it appear on this path. It's not hard to prove that there are finite number of such triples.

Calculate the sum over modulo 109 + 7 of the values of *s* over all interesting triples.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n* ≤ 100 000, 0 ≤ *m* ≤ 200 000) — numbers of vertices and edges in the given graph.

The follow *m* lines contain three integers *u**i*, *v**i* and *t**i* (1 ≤ *u**i*, *v**i* ≤ *n*, 0 ≤ *t**i* ≤ 1018, *u**i* ≠ *v**i*) — vertices connected by the edge and integer written on it. It is guaranteed that graph doesn't contain self-loops and multiple edges.

## Output

Print the single integer, equal to the described sum over modulo 109 + 7.

## Examples

## Input


```
4 4  
1 2 1  
1 3 2  
2 3 3  
3 4 1  

```
## Output


```
12  

```
## Input


```
4 4  
1 2 1  
2 3 2  
3 4 4  
4 1 8  

```
## Output


```
90  

```
## Input


```
8 6  
1 2 2  
2 3 1  
2 4 4  
4 5 5  
4 6 3  
7 8 5  

```
## Output


```
62  

```
## Note

In the first example the are 6 interesting triples: 

1. (1, 2, 1)
2. (1, 3, 2)
3. (1, 4, 3)
4. (2, 3, 3)
5. (2, 4, 2)
6. (3, 4, 1)

 The sum is equal to 1 + 2 + 3 + 3 + 2 + 1 = 12.In the second example the are 12 interesting triples: 

1. (1, 2, 1)
2. (2, 3, 2)
3. (1, 3, 3)
4. (3, 4, 4)
5. (2, 4, 6)
6. (1, 4, 7)
7. (1, 4, 8)
8. (2, 4, 9)
9. (3, 4, 11)
10. (1, 3, 12)
11. (2, 3, 13)
12. (1, 2, 14)

 The sum is equal to 1 + 2 + 3 + 4 + 6 + 7 + 8 + 9 + 11 + 12 + 13 + 14 = 90.

#### tags 

#2600 #bitmasks #graphs #math #number_theory #trees 