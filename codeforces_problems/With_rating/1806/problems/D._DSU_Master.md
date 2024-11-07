<h1 style='text-align: center;'> D. DSU Master</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an integer $n$ and an array $a$ of length $n-1$ whose elements are either $0$ or $1$.

Let us define the value of a permutation$^\dagger$ $p$ of length $m-1$ ($m \leq n$) by the following process.

Let $G$ be a graph of $m$ vertices labeled from $1$ to $m$ that does not contain any edges. For each $i$ from $1$ to $m-1$, perform the following operations: 

* define $u$ and $v$ as the (unique) vertices in the weakly connected components$^\ddagger$ containing vertices $p_i$ and $p_i+1$ respectively with only incoming edges$^{\dagger\dagger}$;
* in graph $G$, add a directed edge from vertex $v$ to $u$ if $a_{p_i}=0$, otherwise add a directed edge from vertex $u$ to $v$ (if $a_{p_i}=1$).

 
## Note

 that after each step, it can be proven that each weakly connected component of $G$ has a unique vertex with only incoming edges.Then, the value of $p$ is the number of incoming edges of vertex $1$ of $G$.

For each $k$ from $1$ to $n-1$, find the sum of values of all $k!$ permutations of length $k$. Since this value can be big, you are only required to compute this value under modulo $998\,244\,353$.

 ![](images/47e7961fd6fd7b8239751e7ef0adf6f246d1546f.png) Operations when $n=3$, $a=[0,1]$ and $p=[1,2]$ $^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

$^\ddagger$ The weakly connected components of a directed graph is the same as the components of the undirected version of the graph. Formally, for directed graph $G$, define a graph $H$ where for all edges $a \to b$ in $G$, you add an undirected edge $a \leftrightarrow b$ in $H$. Then the weakly connected components of $G$ are the components of $H$.

$^{\dagger\dagger}$ 
## Note

 that a vertex that has no edges is considered to have only incoming edges.

### Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2\le n\le 5 \cdot 10^5$).

The second line of each test case contains $n-1$ integers $a_1, a_2, \ldots, a_{n-1}$ ($a_i$ is $0$ or $1$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

### Output

For each test case, output $n-1$ integers in a line, the $i$-th integer should represent the answer when $k=i$, under modulo $998\,244\,353$.

## Example

### Input


```text
230 090 1 0 0 0 1 0 0
```
### Output

```text

1 3 
1 2 7 31 167 1002 7314 60612 

```
## Note

Consider the first test case.

When $k=1$, there is only $1$ permutation $p$.

* When $p=[1]$, we will add a single edge from vertex $2$ to $1$. Vertex $1$ will have $1$ incoming edge. So the value of $[1]$ is $1$.

Therefore when $k=1$, the answer is $1$.

When $k=2$, there are $2$ permutations $p$.

* When $p=[1,2]$, we will add an edge from vertex $2$ to $1$ and an edge from $3$ to $1$. Vertex $1$ will have $2$ incoming edges. So the value of $[1,2]$ is $2$.
* When $p=[2,1]$, we will add an edge from vertex $3$ to $2$ and an edge from $2$ to $1$. Vertex $1$ will have $1$ incoming edge. So the value of $[2,1]$ is $1$.

Therefore when $k=2$, the answer is $2+1=3$.



#### Tags 

#2500 #NOT OK #combinatorics #dp #dsu #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_858_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
