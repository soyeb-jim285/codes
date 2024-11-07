<h1 style='text-align: center;'> G. Just Add an Edge</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a directed acyclic graph with $n$ vertices and $m$ edges. For all edges $a \to b$ in the graph, $a < b$ holds.

You need to find the number of pairs of vertices $x$, $y$, such that $x > y$ and after adding the edge $x \to y$ to the graph, it has a Hamiltonian path. 

### Input

The first line of input contains one integer $t$ ($1 \leq t \leq 5$): the number of test cases.

The next lines contains the descriptions of the test cases.

In the first line you are given two integers $n$ and $m$ ($1 \leq n \leq 150\,000$, $0 \leq m \leq \min(150\,000, \frac{n(n-1)}{2})$): the number of vertices and edges in the graph. 

Each of the next $m$ lines contains two integers $a$, $b$ ($1 \leq a < b \leq n$), specifying an edge $a \to b$ in the graph. No edge $a \to b$ appears more than once.

### Output

For each test case, print one integer: the number of pairs of vertices $x$, $y$, $x > y$, such that after adding the edge $x \to y$ to the graph, it has a Hamiltonian path. 

## Example

### Input


```text
3
3 2
1 2
2 3
4 3
1 2
3 4
1 4
4 4
1 3
1 4
2 3
3 4
```
### Output


```text
3
1
4
```
## Note

In the first example, any edge $x \to y$ such that $x > y$ is valid, because there already is a path $1 \to 2 \to 3$.

In the second example only the edge $4 \to 1$ is valid. There is a path $3 \to 4 \to 1 \to 2$ if this edge is added.

In the third example you can add edges $2 \to 1$, $3 \to 1$, $4 \to 1$, $4 \to 2$.



#### Tags 

#3500 #NOT OK #dfs_and_similar #dp #graphs 

## Blogs
- [All Contest Problems](../Good_Bye_2021:_2022_is_NEAR.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
