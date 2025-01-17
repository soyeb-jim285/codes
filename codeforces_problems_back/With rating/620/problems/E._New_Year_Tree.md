<h1 style='text-align: center;'> E. New Year Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The New Year holidays are over, but Resha doesn't want to throw away the New Year tree. He invited his best friends Kerim and Gural to help him to redecorate the New Year tree.

The New Year tree is an undirected tree with *n* vertices and root in the vertex 1.

You should process the queries of the two types:

1. Change the colours of all vertices in the subtree of the vertex *v* to the colour *c*.
2. Find the number of different colours in the subtree of the vertex *v*.
## Input

The first line contains two integers *n*, *m* (1 ≤ *n*, *m* ≤ 4·105) — the number of vertices in the tree and the number of the queries.

The second line contains *n* integers *c**i* (1 ≤ *c**i* ≤ 60) — the colour of the *i*-th vertex.

Each of the next *n* - 1 lines contains two integers *x**j*, *y**j* (1 ≤ *x**j*, *y**j* ≤ *n*) — the vertices of the *j*-th edge. It is guaranteed that you are given correct undirected tree.

The last *m* lines contains the description of the queries. Each description starts with the integer *t**k* (1 ≤ *t**k* ≤ 2) — the type of the *k*-th query. For the queries of the first type then follows two integers *v**k*, *c**k* (1 ≤ *v**k* ≤ *n*, 1 ≤ *c**k* ≤ 60) — the number of the vertex whose subtree will be recoloured with the colour *c**k*. For the queries of the second type then follows integer *v**k* (1 ≤ *v**k* ≤ *n*) — the number of the vertex for which subtree you should find the number of different colours.

## Output

For each query of the second type print the integer *a* — the number of different colours in the subtree of the vertex given in the query.

Each of the numbers should be printed on a separate line in order of query appearing in the input.

## Examples

## Input


```
7 10  
1 1 1 1 1 1 1  
1 2  
1 3  
1 4  
3 5  
3 6  
3 7  
1 3 2  
2 1  
1 4 3  
2 1  
1 2 5  
2 1  
1 6 4  
2 1  
2 2  
2 3  

```
## Output


```
2  
3  
4  
5  
1  
2  

```
## Input


```
23 30  
1 2 2 6 5 3 2 1 1 1 2 4 5 3 4 4 3 3 3 3 3 4 6  
1 2  
1 3  
1 4  
2 5  
2 6  
3 7  
3 8  
4 9  
4 10  
4 11  
6 12  
6 13  
7 14  
7 15  
7 16  
8 17  
8 18  
10 19  
10 20  
10 21  
11 22  
11 23  
2 1  
2 5  
2 6  
2 7  
2 8  
2 9  
2 10  
2 11  
2 4  
1 12 1  
1 13 1  
1 14 1  
1 15 1  
1 16 1  
1 17 1  
1 18 1  
1 19 1  
1 20 1  
1 21 1  
1 22 1  
1 23 1  
2 1  
2 5  
2 6  
2 7  
2 8  
2 9  
2 10  
2 11  
2 4  

```
## Output


```
6  
1  
3  
3  
2  
1  
2  
3  
5  
5  
1  
2  
2  
1  
1  
1  
2  
3  

```


#### tags 

#2100 #bitmasks #data_structures #trees 