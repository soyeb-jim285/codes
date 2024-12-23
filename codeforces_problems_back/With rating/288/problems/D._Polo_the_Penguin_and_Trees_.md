<h1 style='text-align: center;'> D. Polo the Penguin and Trees </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little penguin Polo has got a tree — a non-directed connected acyclic graph, containing *n* nodes and *n* - 1 edges. We will consider the tree nodes numbered by integers from 1 to *n*.

Today Polo wonders, how to find the number of pairs of paths that don't have common nodes. More formally, he should find the number of groups of four integers *a*, *b*, *c* and *d* such that:

* 1 ≤ *a* < *b* ≤ *n*;
* 1 ≤ *c* < *d* ≤ *n*;
* there's no such node that lies on both the shortest path from node *a* to node *b* and from node *c* to node *d*.

The shortest path betweem two nodes is the path that is shortest in the number of edges.

Help Polo solve this problem.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 80000) — the number of tree nodes. Each of the following *n* - 1 lines contains a pair of integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*; *u**i* ≠ *v**i*) — the *i*-th edge of the tree.

It is guaranteed that the given graph is a tree.

## Output

In a single line print a single integer — the answer to the problem.

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is recommended to use the cin, cout streams or the %I64d specificator.

## Examples

## Input


```
4  
1 2  
2 3  
3 4  

```
## Output


```
2  

```


#### tags 

#2400 #combinatorics #dfs_and_similar #trees 