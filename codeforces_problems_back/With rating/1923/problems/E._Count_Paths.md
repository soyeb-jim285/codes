<h1 style='text-align: center;'> E. Count Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tree, consisting of $n$ vertices, numbered from $1$ to $n$. Every vertex is colored in some color, denoted by an integer from $1$ to $n$.

A simple path of the tree is called beautiful if: 

* it consists of at least $2$ vertices;
* the first and the last vertices of the path have the same color;
* no other vertex on the path has the same color as the first vertex.

Count the number of the beautiful simple paths of the tree. Note that paths are considered undirected (i. e. the path from $x$ to $y$ is the same as the path from $y$ to $x$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of vertices in the tree.

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le n$) — the color of each vertex.

The $i$-th of the next $n - 1$ lines contains two integers $v_i$ and $u_i$ ($1 \le v_i, u_i \le n$; $v_i \neq u_i$) — the $i$-th edge of the tree.

The given edges form a valid tree. The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the number of the beautiful simple paths of the tree.

## Example

## Input


```

431 2 11 22 352 1 2 1 21 21 33 44 551 2 3 4 51 21 33 44 542 2 2 23 13 23 4
```
## Output


```

1
3
0
3

```


#### tags 

#2000 #data_structures #dfs_and_similar #dp #dsu #graphs #trees 