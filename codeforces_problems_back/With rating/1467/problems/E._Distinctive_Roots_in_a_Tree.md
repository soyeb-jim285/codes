<h1 style='text-align: center;'> E. Distinctive Roots in a Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with $n$ vertices. Each vertex $i$ has a value $a_i$ associated with it.

Let us root the tree at some vertex $v$. The vertex $v$ is called a distinctive root if the following holds: in all paths that start at $v$ and end at some other node, all the values encountered are distinct. Two different paths may have values in common but a single path must have all distinct values.

Find the number of distinctive roots in the tree.

## Input

The first line of the input contains a single integer $n$ ($1 \le n \le 2\cdot10^5$) — the number of vertices in the tree.

The next line contains $n$ space-separated integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

The following $n-1$ lines each contain two space-separated integers $u$ and $v$ ($1 \le u$, $v \le n$), denoting an edge from $u$ to $v$.

It is guaranteed that the edges form a tree.

## Output

Print a single integer — the number of distinctive roots in the tree.

## Examples

## Input


```

5
2 5 1 1 4
1 2
1 3
2 4
2 5

```
## Output


```

3
```
## Input


```

5
2 1 1 1 4
1 2
1 3
2 4
2 5

```
## Output


```

0
```
## Note

In the first example, $1$, $2$ and $5$ are distinctive roots.



#### tags 

#2500 #data_structures #dfs_and_similar #dp #trees 