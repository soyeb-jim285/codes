<h1 style='text-align: center;'> F. Uniformly Branched Trees</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A tree is a connected graph without cycles.

Two trees, consisting of *n* vertices each, are called isomorphic if there exists a permutation *p*: {1, ..., *n*} → {1, ..., *n*} such that the edge (*u*, *v*) is present in the first tree if and only if the edge (*p**u*, *p**v*) is present in the second tree.

Vertex of the tree is called internal if its degree is greater than or equal to two.

Count the number of different non-isomorphic trees, consisting of *n* vertices, such that the degree of each internal vertex is exactly *d*. Print the answer over the given prime modulo *mod*.

## Input

The single line of the input contains three integers *n*, *d* and *mod* (1 ≤ *n* ≤ 1000, 2 ≤ *d* ≤ 10, 108 ≤ *mod* ≤ 109)  — the number of vertices in the tree, the degree of internal vertices and the prime modulo.

## Output

Print the number of trees over the modulo *mod*.

## Examples

## Input


```
5 2 433416647  

```
## Output


```
1  

```
## Input


```
10 3 409693891  

```
## Output


```
2  

```
## Input


```
65 4 177545087  

```
## Output


```
910726  

```


#### tags 

#2700 #combinatorics #dp #trees 