<h1 style='text-align: center;'> E. Misha and LCP on Tree</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Misha has a tree with characters written on the vertices. He can choose two vertices *s* and *t* of this tree and write down characters of vertices lying on a path from *s* to *t*. We'll say that such string corresponds to pair (*s*, *t*).

Misha has *m* queries of type: you are given 4 vertices *a*, *b*, *c*, *d*; you need to find the largest common prefix of the strings that correspond to pairs (*a*, *b*) and (*c*, *d*). Your task is to help him.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 300 000) — the number of vertices in the tree.

Next follows a line consisting of *n* small English letters. The *i*-th character of the string corresponds to the character written on the *i*-th vertex. 

Next *n* - 1 lines contain information about edges. An edge is defined by a pair of integers *u*, *v* (1 ≤ *u*, *v* ≤ *n*, *u* ≠ *v*), separated by spaces.

The next line contains integer *m* (1 ≤ *m* ≤ 1 000 000) — the number of queries.

Next *m* lines contain information about queries. A query is defined by four integers *a*, *b*, *c*, *d* (1 ≤ *a*, *b*, *c*, *d* ≤ *n*), separated by spaces.

## Output

For each query print the length of the largest common prefix on a separate line.

## Examples

## Input


```
6  
bbbabb  
2 1  
3 2  
4 3  
5 2  
6 5  
6  
2 5 3 1  
1 5 2 3  
5 6 5 6  
6 3 4 1  
6 2 3 4  
2 2 4 5  

```
## Output


```
2  
2  
2  
0  
1  
0  

```


#### tags 

#3000 #binary_search #dfs_and_similar #hashing #string_suffix_structures #trees 