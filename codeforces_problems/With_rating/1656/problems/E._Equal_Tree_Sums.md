<h1 style='text-align: center;'> E. Equal Tree Sums</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an undirected unrooted tree, i.e. a connected undirected graph without cycles.

You must assign a nonzero integer weight to each vertex so that the following is satisfied: if any vertex of the tree is removed, then each of the remaining connected components has the same sum of weights in its vertices.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 10^5$) — the number of vertices of the tree.

The next $n-1$ lines of each case contain each two integers $u, v$ ($1 \leq u,v \leq n$) denoting that there is an edge between vertices $u$ and $v$. It is guaranteed that the given edges form a tree.

The sum of $n$ for all test cases is at most $10^5$.

### Output

For each test case, you must output one line with $n$ space separated integers $a_1, a_2, \ldots, a_n$, where $a_i$ is the weight assigned to vertex $i$. The weights must satisfy $-10^5 \leq a_i \leq 10^5$ and $a_i \neq 0$.

It can be shown that there always exists a solution satisfying these constraints. If there are multiple possible solutions, output any of them.

## Example

### Input


```text
2
5
1 2
1 3
3 4
3 5
3
1 2
1 3
```
### Output


```text
-3 5 1 2 2
1 1 1
```
## Note

In the first case, when removing vertex $1$ all remaining connected components have sum $5$ and when removing vertex $3$ all remaining connected components have sum $2$. When removing other vertices, there is only one remaining connected component so all remaining connected components have the same sum.



#### Tags 

#2200 #NOT OK #constructive_algorithms #dfs_and_similar #math #trees 

## Blogs
- [All Contest Problems](../CodeTON_Round_1_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
