<h1 style='text-align: center;'> F. Large Graph</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Given an array $a$ of length $n$. Let's construct a square matrix $b$ of size $n \times n$, in which the $i$-th row contains the array $a$ cyclically shifted to the right by $(i - 1)$. For example, for the array $a = [3, 4, 5]$, the obtained matrix is

$$b = \begin{bmatrix} 3 & 4 & 5 \\\ 5 & 3 & 4 \\\ 4 & 5 & 3 \end{bmatrix}$$

Let's construct the following graph:

* The graph contains $n^2$ vertices, each of which corresponds to one of the elements of the matrix. Let's denote the vertex corresponding to the element $b_{i, j}$ as $(i, j)$.
* We will draw an edge between vertices $(i_1, j_1)$ and $(i_2, j_2)$ if $|i_1 - i_2| + |j_1 - j_2| \le k$ and $\gcd(b_{i_1, j_1}, b_{i_2, j_2}) > 1$, where $\gcd(x, y)$ denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$.

Your task is to calculate the number of connected components$^{\dagger}$ in the obtained graph.

$^{\dagger}$A connected component of a graph is a set of vertices in which any vertex is reachable from any other via edges, and adding any other vertex to the set violates this rule.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 10^6$, $2 \le k \le 2 \cdot 10^6$) — the length of the array and the parameter $k$. 

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

## Output

For each test case, output a single integer — the number of connected components in the obtained graph.

## Example

## Input


```

63 33 4 53 33 4 93 23 4 92 22 85 38 27 5 4 34 102 2 2 2
```
## Output


```

3
2
3
1
4
1

```
## Note

In the first test case, the matrix $b$ is given in the statement. The first connected component contains the vertices $(1, 1)$, $(2, 2)$, and $(3, 3)$. The second connected component contains the vertices $(1, 2)$, $(2, 3)$, and $(3, 1)$. The third connected component contains the vertices $(1, 3)$, $(2, 1)$, and $(3, 2)$. Thus, the graph has $3$ connected components.

In the second test case, the following matrix is obtained:

$$b = \begin{bmatrix} 3 & 4 & 9 \\\ 9 & 3 & 4 \\\ 4 & 9 & 3 \end{bmatrix}$$

The first connected component contains all vertices corresponding to elements with values $3$ and $9$. The second connected component contains all vertices corresponding to elements with the value $4$.

In the fourth test case, all vertices are in one connected component.



#### tags 

#2400 #data_structures #dfs_and_similar #dsu #graphs #number_theory #two_pointers 