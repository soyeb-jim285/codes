<h1 style='text-align: center;'> E. Fib-tree</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $F_k$ denote the $k$-th term of Fibonacci sequence, defined as below:

* $F_0 = F_1 = 1$
* for any integer $n \geq 0$, $F_{n+2} = F_{n+1} + F_n$

You are given a tree with $n$ vertices. Recall that a tree is a connected undirected graph without cycles.

We call a tree a Fib-tree, if its number of vertices equals $F_k$ for some $k$, and at least one of the following conditions holds:

* The tree consists of only $1$ vertex;
* You can divide it into two Fib-trees by removing some edge of the tree.

Determine whether the given tree is a Fib-tree or not.

##### Input

The first line of the input contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of vertices in the tree.

Then $n-1$ lines follow, each of which contains two integers $u$ and $v$ ($1\leq u,v \leq n$, $u \neq v$), representing an edge between vertices $u$ and $v$. It's guaranteed that given edges form a tree.

##### Output

Print "YES" if the given tree is a Fib-tree, or "NO" otherwise.

You can print your answer in any case. For example, if the answer is "YES", then the output "Yes" or "yeS" will also be considered as correct answer.

## Examples

##### Input


```text
3
1 2
2 3
```
##### Output


```text
YES
```
##### Input


```text
5
1 2
1 3
1 4
1 5
```
##### Output


```text
NO
```
##### Input


```text
5
1 3
1 2
4 5
3 4
```
##### Output


```text
YES
```
## Note

In the first sample, we can cut the edge $(1, 2)$, and the tree will be split into $2$ trees of sizes $1$ and $2$ correspondently. Any tree of size $2$ is a Fib-tree, as it can be split into $2$ trees of size $1$.

In the second sample, no matter what edge we cut, the tree will be split into $2$ trees of sizes $1$ and $4$. As $4$ isn't $F_k$ for any $k$, it's not Fib-tree.

In the third sample, here is one possible order of cutting the edges so that all the trees in the process are Fib-trees: $(1, 3), (1, 2), (4, 5), (3, 4)$. 



#### Tags 

#2400 #NOT OK #brute_force #dfs_and_similar #divide_and_conquer #number_theory #trees 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_13.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
