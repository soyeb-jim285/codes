<h1 style='text-align: center;'> F. Remove Bridges</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree, consisting of $n$ vertices, numbered from $1$ to $n$. Vertex $1$ is the root. Additionally, the root only has one child.

You are asked to add exactly $k$ edges to the tree (possibly, multiple edges and/or edges already existing in the tree).

Recall that a bridge is such an edge that, after you remove it, the number of connected components in the graph increases. So, initially, all edges of the tree are bridges.

After $k$ edges are added, some original edges of the tree are still bridges and some are not anymore. You want to satisfy two conditions: 

* for every bridge, all tree edges in the subtree of the lower vertex of that bridge should also be bridges;
* the number of bridges is as small as possible.

Solve the task for all values of $k$ from $1$ to $n - 1$ and output the smallest number of bridges.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 3 \cdot 10^5$) — the number of vertices of the tree.

Each of the next $n - 1$ lines contain two integers $v$ and $u$ ($1 \le v, u \le n$) — the description of the edges of the tree. It's guaranteed that the given edges form a valid tree.

Additional constraint on the input: the root (vertex $1$) has exactly one child.

The sum of $n$ over all testcases doesn't exceed $3 \cdot 10^5$.

## Output

For each testcase, print $n - 1$ integers. For each $k$ from $1$ to $n - 1$ print the smallest number of bridges that can be left after you add $k$ edges to the tree.

## Example

## Input


```

421 2124 105 1212 113 69 61 612 711 62 1110 910 881 22 32 43 53 64 74 851 22 33 44 5
```
## Output


```

0 
7 3 1 0 0 0 0 0 0 0 0 
4 1 0 0 0 0 0 
0 0 0 0 

```


#### tags 

#2800 #data_structures #dfs_and_similar #dp #greedy #sortings #trees 