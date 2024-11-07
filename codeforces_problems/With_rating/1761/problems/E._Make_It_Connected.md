<h1 style='text-align: center;'> E. Make It Connected</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a simple undirected graph consisting of $n$ vertices. The graph doesn't contain self-loops, there is at most one edge between each pair of vertices. Your task is simple: make the graph connected.

You can do the following operation any number of times (possibly zero):

* Choose a vertex $u$ arbitrarily.
* For each vertex $v$ satisfying $v\ne u$ in the graph individually, if $v$ is adjacent to $u$, remove the edge between $u$ and $v$, otherwise add an edge between $u$ and $v$.

Find the minimum number of operations required to make the graph connected. Also, find any sequence of operations with the minimum length that makes the graph connected.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1\leq t\leq 800$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2\leq n\leq 4000$) — the number of vertices in the graph.

Then $n$ lines follow. The $i$-th row contains a binary string $s_i$ of length $n$, where $s_{i,j}$ is '1' if there is an edge between vertex $i$ and $j$ initially, otherwise $s_{i,j}$ is '0'.

It is guaranteed that $s_{i,i}$ is always '0' and $s_{i,j}=s_{j,i}$ for $1\leq i,j\leq n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $4000$.

### Output

For each test case, in the first line, output an integer $m$  — the minimum number of operations required.

If $m$ is greater than zero, then print an extra line consisting of $m$ integers — the vertices chosen in the operations in your solution. If there are multiple solutions with the minimum number of operations, print any.

## Example

### Input


```text
430111001003000001010401001000000100106001100000011100100101000010001010010
```
### Output

```text

0
1
1
2
3 4 
3
2 5 6 

```
## Note

In the first test case, the graph is connected at the beginning, so the answer is $0$.

In the second test case, if we do the operation with vertex $1$, we will get the following graph represented by an adjacency matrix:

$$ \begin{bmatrix} 0&1&1\\\ 1&0&1\\\ 1&1&0 \end{bmatrix} $$

It's obvious that the graph above is connected.

In the third test case, if we do the operation with vertex $3$ and $4$, we will get the following graph represented by an adjacency matrix:

$$ \begin{bmatrix} 0&1&1&1\\\ 1&0&1&1\\\ 1&1&0&1\\\ 1&1&1&0 \end{bmatrix} $$

It's obvious that the graph above is connected, and it can be proven that we can't perform less than $2$ operations to make the graph connected.



#### Tags 

#2400 #NOT OK #binary_search #brute_force #constructive_algorithms #dsu #graphs #greedy #matrices #trees #two_pointers 

## Blogs
- [All Contest Problems](../Pinely_Round_1_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
