<h1 style='text-align: center;'> F. Beautiful Tree</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Lunchbox has a tree of size $n$ rooted at node $1$. Each node is then assigned a value. Lunchbox considers the tree to be beautiful if each value is distinct and ranges from $1$ to $n$. In addition, a beautiful tree must also satisfy $m$ requirements of $2$ types:

* "1 a b c" — The node with the smallest value on the path between nodes $a$ and $b$ must be located at $c$.
* "2 a b c" — The node with the largest value on the path between nodes $a$ and $b$ must be located at $c$.

Now, you must assign values to each node such that the resulting tree is beautiful. If it is impossible to do so, output $-1$.

## Input

The first line contains two integers $n$ and $m$ ($2 \le n, m \le 2 \cdot 10^5$).

The next $n - 1$ lines contain two integers $u$ and $v$ ($1 \le u, v \le n, u \ne v$) — denoting an edge between nodes $u$ and $v$. It is guaranteed that the given edges form a tree.

The next $m$ lines each contain four integers $t$, $a$, $b$, and $c$ ($t \in \{1,2\}$, $1 \le a, b, c \le n$). It is guaranteed that node $c$ is on the path between nodes $a$ and $b$.

## Output

If it is impossible to assign values such that the tree is beautiful, output $-1$. Otherwise, output $n$ integers, the $i$-th of which denotes the value of node $i$.

## Examples

## Input


```

7 5
1 2
1 3
1 4
3 5
4 6
3 7
1 6 5 1
2 6 7 3
1 2 7 1
1 7 5 7
2 4 2 2

```
## Output


```

1 6 7 5 3 4 2 

```
## Input


```

2 2
1 2
1 1 2 1
1 1 2 2

```
## Output


```

-1

```


#### tags 

#2800 #data_structures #dfs_and_similar #graphs #implementation #trees 