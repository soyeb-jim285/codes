<h1 style='text-align: center;'> F. Tricolor Triangles</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a simple undirected graph with $n$ vertices and $m$ edges. Edge $i$ is colored in the color $c_i$, which is either $1$, $2$, or $3$, or left uncolored (in this case, $c_i = -1$).

You need to color all of the uncolored edges in such a way that for any three pairwise adjacent vertices $1 \leq a < b < c \leq n$, the colors of the edges $a \leftrightarrow b$, $b \leftrightarrow c$, and $a \leftrightarrow c$ are either pairwise different, or all equal. In case no such coloring exists, you need to determine that.

### Input

The first line of input contains one integer $t$ ($1 \leq t \leq 10$): the number of test cases.

The following lines contain the description of the test cases.

In the first line you are given two integers $n$ and $m$ ($3 \leq n \leq 64$, $0 \leq m \leq \min(256, \frac{n(n-1)}{2})$): the number of vertices and edges in the graph.

Each of the next $m$ lines contains three integers $a_i$, $b_i$, and $c_i$ ($1 \leq a_i, b_i \leq n$, $a_i \ne b_i$, $c_i$ is either $-1$, $1$, $2$, or $3$), denoting an edge between $a_i$ and $b_i$ with color $c_i$. It is guaranteed that no two edges share the same endpoints.

### Output

For each test case, print $m$ integers $d_1, d_2, \ldots, d_m$, where $d_i$ is the color of the $i$-th edge in your final coloring. If there is no valid way to finish the coloring, print $-1$.

## Example

### Input


```text
4
3 3
1 2 1
2 3 2
3 1 -1
3 3
1 2 1
2 3 1
3 1 -1
4 4
1 2 -1
2 3 -1
3 4 -1
4 1 -1
3 3
1 2 1
2 3 1
3 1 2
```
### Output


```text
1 2 3 
1 1 1 
1 2 2 3 
-1
```


#### Tags 

#2900 #NOT OK #brute_force #graphs #math #matrices 

## Blogs
- [All Contest Problems](../Good_Bye_2021:_2022_is_NEAR.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
