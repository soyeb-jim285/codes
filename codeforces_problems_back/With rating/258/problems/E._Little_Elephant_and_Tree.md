<h1 style='text-align: center;'> E. Little Elephant and Tree</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant loves trees very much, he especially loves root trees.

He's got a tree consisting of *n* nodes (the nodes are numbered from 1 to *n*), with root at node number 1. Each node of the tree contains some list of numbers which initially is empty. 

The Little Elephant wants to apply *m* operations. On the *i*-th operation (1 ≤ *i* ≤ *m*) he first adds number *i* to lists of all nodes of a subtree with the root in node number *a**i*, and then he adds number *i* to lists of all nodes of the subtree with root in node *b**i*.

After applying all operations the Little Elephant wants to count for each node *i* number *c**i* — the number of integers *j* (1 ≤ *j* ≤ *n*; *j* ≠ *i*), such that the lists of the *i*-th and the *j*-th nodes contain at least one common number.

Help the Little Elephant, count numbers *c**i* for him.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of the tree nodes and the number of operations. 

Each of the following *n* - 1 lines contains two space-separated integers, *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*), that mean that there is an edge between nodes number *u**i* and *v**i*. 

Each of the following *m* lines contains two space-separated integers, *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*), that stand for the indexes of the nodes in the *i*-th operation.

It is guaranteed that the given graph is an undirected tree.

## Output

In a single line print *n* space-separated integers — *c*1, *c*2, ..., *c**n*.

## Examples

## Input


```
5 1  
1 2  
1 3  
3 5  
3 4  
2 3  

```
## Output


```
0 3 3 3 3 
```
## Input


```
11 3  
1 2  
2 3  
2 4  
1 5  
5 6  
5 7  
5 8  
6 9  
8 10  
8 11  
2 9  
3 6  
2 8  

```
## Output


```
0 6 7 6 0 2 0 5 4 5 5 
```


#### tags 

#2400 #data_structures #dfs_and_similar #trees 