<h1 style='text-align: center;'> G. Colorful Tree Again</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

An edge-weighted tree of $n$ nodes is given with each edge colored in some color. Each node of this tree can be blocked or unblocked, all nodes are unblocked initially.

A simple path is a path in a graph that does not have repeating nodes. The length of a path is defined as the sum of weights of all edges on the path.

A path is good when it is a simple path consisting of edges of the same color $c$, all edges of color $c$ are on this path, and every node on the path is unblocked.

You need to operate $2$ kinds of queries: 

1. block a node,
2. unblock a node.

After each query, print the maximum length among all good paths. If there are no good paths, print $0$.

###### Input

The first line contains two integers $n$, $q$ ($1 \leq n,q \leq 2\cdot 10^5$) — the number of nodes and the number of queries.

Then $n-1$ lines follow, each containing four integers $u$, $v$, $w$ and $c$ ($1 \leq u,v,w,c \leq n$; $u \not = v$), denoting a weighted edge connecting node $u$ and node $v$ with weight $w$ and color $c$. It is guaranteed that these edges form a tree.

Then $q$ lines follow, each containing two integers $p$ and $x$ ($p = 0$ or $p = 1$, $1\leq x\leq n$), denoting a query: 

1. if $p = 0$, block the node $x$. It's guaranteed that it's not blocked at this time;
2. if $p = 1$, unblock the node $x$. It's guaranteed that it's blocked at this time.
###### Output

For each query, print the maximum length of a good path. If there are no good paths, print $0$.

## Examples

###### Input


```text
5 4
4 1 3 4
5 2 4 4
3 1 3 2
1 2 5 1
0 4
0 3
0 2
1 3
```
###### Output


```text
5
5
0
3
```
###### Input


```text
5 5
4 1 4 4
4 5 2 2
3 1 2 4
3 2 3 1
0 3
0 4
1 3
1 4
0 1
```
###### Output


```text
2
0
3
6
3
```
###### Input


```text
6 9
3 2 2 3
2 4 4 2
3 1 5 5
6 4 3 2
5 3 1 3
0 2
0 4
0 5
0 6
1 2
1 4
1 5
0 3
1 6
```
###### Output


```text
5
5
5
5
5
5
5
0
7
```
###### Input


```text
1 2
0 1
1 1
```
###### Output


```text
0
0
```


#### Tags 

#3000 #NOT OK #brute_force #data_structures #trees 

## Blogs
- [All Contest Problems](../TypeDB_Forces_2023_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [TypeDB Forces 2023 (en)](../blogs/TypeDB_Forces_2023_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
