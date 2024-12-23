<h1 style='text-align: center;'> E. Caisa and Tree</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Caisa is now at home and his son has a simple task for him.

Given a rooted tree with *n* vertices, numbered from 1 to *n* (vertex 1 is the root). Each vertex of the tree has a value. You should answer *q* queries. Each query is one of the following:

* Format of the query is "1 *v*". Let's write out the sequence of vertices along the path from the root to vertex *v*: *u*1, *u*2, ..., *u**k* (*u*1 = 1; *u**k* = *v*). You need to output such a vertex *u**i* that *gcd*(*value* *of* *u**i*, *value* *of* *v*) > 1 and *i* < *k*. If there are several possible vertices *u**i* pick the one with maximum value of *i*. If there is no such vertex output -1.
* Format of the query is "2 *v* *w*". You must change the value of vertex *v* to *w*.

You are given all the queries, help Caisa to solve the problem.

## Input

The first line contains two space-separated integers *n*, *q* (1 ≤ *n*, *q* ≤ 105). 

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 2·106), where *a**i* represent the value of node *i*.

Each of the next *n* - 1 lines contains two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*; *x**i* ≠ *y**i*), denoting the edge of the tree between vertices *x**i* and *y**i*.

Each of the next *q* lines contains a query in the format that is given above. For each query the following inequalities hold: 1 ≤ *v* ≤ *n* and 1 ≤ *w* ≤ 2·106. ## Note

 that: there are no more than 50 queries that changes the value of a vertex.

## Output

For each query of the first type output the result of the query.

## Examples

## Input


```
4 6  
10 8 4 3  
1 2  
2 3  
3 4  
1 1  
1 2  
1 3  
1 4  
2 1 9  
1 4  

```
## Output


```
-1  
1  
2  
-1  
1  

```
## Note

*gcd*(*x*, *y*) is greatest common divisor of two integers *x* and *y*.



#### tags 

#2100 #brute_force #dfs_and_similar #math #number_theory #trees 