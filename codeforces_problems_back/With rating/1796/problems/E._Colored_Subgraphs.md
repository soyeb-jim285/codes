<h1 style='text-align: center;'> E. Colored Subgraphs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has a tree, consisting of $n$ vertices.

He is going to select some vertex $r$ and perform the following operations on each vertex $v$ from $1$ to $n$: 

* set $d_v$ equal to the distance from $v$ to $r$ (the number of edges on the shortest path);
* color $v$ some color.

A nice coloring satisfies two conditions: 

* for each pair of vertices of the same color $(v, u)$, there exists a path from $v$ to $u$ that only visits vertices of the same color;
* for each pair of vertices of the same color $(v, u)$, $d_v \neq d_u$.

Note that Monocarp can choose any amount of different colors he wants to use.

For each used color, he then counts the number of vertices of this color. The cost of the tree is the minimum of these numbers.

What can be the maximum cost of the tree?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of vertices in the tree.

Each of the next $n-1$ lines contains two integers $v$ and $u$ ($1 \le v, u \le n$) — the description of an edge.

The given edges form a tree. The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase print a single integer — the maximum possible cost of the tree.

## Example

## Input


```

441 22 33 451 21 31 41 531 33 273 22 57 53 11 61 4
```
## Output


```

4
1
3
3

```


#### tags 

#2500 #dfs_and_similar #dp #games #greedy #trees 