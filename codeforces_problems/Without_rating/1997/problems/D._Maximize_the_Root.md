<h1 style='text-align: center;'> D. Maximize the Root</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree, consisting of $n$ vertices. The vertices in the tree are numbered from $1$ to $n$, and the root is the vertex $1$. The value $a_i$ is written at the $i$-th vertex.

You can perform the following operation any number of times (possibly zero): choose a vertex $v$ which has at least one child; increase $a_v$ by $1$; and decrease $a_u$ by $1$ for all vertices $u$ that are in the subtree of $v$ (except $v$ itself). However, after each operation, the values on all vertices should be non-negative.

Your task is to calculate the maximum possible value written at the root using the aforementioned operation.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of vertices in the tree.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 10^9$) — the initial values written at vertices.

The third line contains $n-1$ integers $p_2, p_3, \dots, p_n$ ($1 \le p_i \le n$), where $p_i$ is the parent of the $i$-th vertex in the tree. Vertex $1$ is the root.

Additional constraint on the input: the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the maximum possible value written at the root using the aforementioned operation.

## Example

### Input


```text
340 1 0 21 1 323 0152 5 3 9 63 1 5 2
```
### Output

```text

1
3
6

```
## Note

In the first test case, the following sequence of operations is possible:

* perform the operation on $v=3$, then the values on the vertices will be $[0, 1, 1, 1]$;
* perform the operation on $v=1$, then the values on the vertices will be $[1, 0, 0, 0]$.


#### Tags 

#NOT OK #binary_search #dfs_and_similar #dp #greedy #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_168_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
