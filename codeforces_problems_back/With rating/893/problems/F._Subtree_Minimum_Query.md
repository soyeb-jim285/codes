<h1 style='text-align: center;'> F. Subtree Minimum Query</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a rooted tree consisting of *n* vertices. Each vertex has a number written on it; number *a**i* is written on vertex *i*.

Let's denote *d*(*i*, *j*) as the distance between vertices *i* and *j* in the tree (that is, the number of edges in the shortest path from *i* to *j*). Also let's denote the *k*-blocked subtree of vertex *x* as the set of vertices *y* such that both these conditions are met:

* *x* is an ancestor of *y* (every vertex is an ancestor of itself);
* *d*(*x*, *y*) ≤ *k*.

You are given *m* queries to the tree. *i*-th query is represented by two numbers *x**i* and *k**i*, and the answer to this query is the minimum value of *a**j* among such vertices *j* such that *j* belongs to *k**i*-blocked subtree of *x**i*.

Write a program that would process these queries quickly!

Note that the queries are given in a modified way.

## Input

The first line contains two integers *n* and *r* (1 ≤ *r* ≤ *n* ≤ 100000) — the number of vertices in the tree and the index of the root, respectively.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the numbers written on the vertices.

Then *n* - 1 lines follow, each containing two integers *x* and *y* (1 ≤ *x*, *y* ≤ *n*) and representing an edge between vertices *x* and *y*. It is guaranteed that these edges form a tree.

Next line contains one integer *m* (1 ≤ *m* ≤ 106) — the number of queries to process.

Then *m* lines follow, *i*-th line containing two numbers *p**i* and *q**i*, which can be used to restore *i*-th query (1 ≤ *p**i*, *q**i* ≤ *n*).

*i*-th query can be restored as follows:

Let *last* be the answer for previous query (or 0 if *i* = 1). Then *x**i* = ((*p**i* + *last*) *mod* *n*) + 1, and *k**i* = (*q**i* + *last*) *mod* *n*.

## Output

Print *m* integers. *i*-th of them has to be equal to the answer to *i*-th query.

## Example

## Input


```
5 2  
1 3 2 3 5  
2 3  
5 1  
3 4  
4 1  
2  
1 2  
2 3  

```
## Output


```
2  
5  

```


#### tags 

#2300 #data_structures #trees 