<h1 style='text-align: center;'> E. AND-MEX Walk</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an undirected, connected graph with $n$ vertices and $m$ weighted edges. A walk from vertex $u$ to vertex $v$ is defined as a sequence of vertices $p_1,p_2,\ldots,p_k$ (which are not necessarily distinct) starting with $u$ and ending with $v$, such that $p_i$ and $p_{i+1}$ are connected by an edge for $1 \leq i < k$.

We define the length of a walk as follows: take the ordered sequence of edges and write down the weights on each of them in an array. Now, write down the bitwise AND of every nonempty prefix of this array. The length of the walk is the MEX of all these values.

More formally, let us have $[w_1,w_2,\ldots,w_{k-1}]$ where $w_i$ is the weight of the edge between $p_i$ and $p_{i+1}$. Then the length of the walk is given by $\mathrm{MEX}(\{w_1,\,w_1\\& w_2,\,\ldots,\,w_1\\& w_2\\& \ldots\\& w_{k-1}\})$, where $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

Now you must process $q$ queries of the form u v. For each query, find the minimum possible length of a walk from $u$ to $v$.

The MEX (minimum excluded) of a set is the smallest non-negative integer that does not belong to the set. For instance: 

* The MEX of $\{2,1\}$ is $0$, because $0$ does not belong to the set.
* The MEX of $\{3,1,0\}$ is $2$, because $0$ and $1$ belong to the set, but $2$ does not.
* The MEX of $\{0,3,1,2\}$ is $4$ because $0$, $1$, $2$ and $3$ belong to the set, but $4$ does not.
#### Input

The first line contains two integers $n$ and $m$ ($2 \leq n \leq 10^5$; $n-1 \leq m \leq \min{\left(\frac{n(n-1)}{2},10^5\right)}$).

Each of the next $m$ lines contains three integers $a$, $b$, and $w$ ($1 \leq a, b \leq n$, $a \neq b$; $0 \leq w < 2^{30}$) indicating an undirected edge between vertex $a$ and vertex $b$ with weight $w$. The input will not contain self-loops or duplicate edges, and the provided graph will be connected.

The next line contains a single integer $q$ ($1 \leq q \leq 10^5$).

Each of the next $q$ lines contains two integers $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$), the description of each query.

#### Output

For each query, print one line containing a single integer — the answer to the query.

## Examples

#### Input


```text
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
3
1 5
1 2
5 3
```
#### Output


```text
2
0
1
```
#### Input


```text
9 8
1 2 5
2 3 11
3 4 10
3 5 10
5 6 2
5 7 1
7 8 5
7 9 5
10
5 7
2 5
7 1
6 4
5 2
7 6
4 1
6 2
4 7
2 8
```
#### Output


```text
0
0
2
0
0
2
1
0
1
1
```
## Note

The following is an explanation of the first example.

 ![](images/55436d6a89ce2a462cfa055a8465441116efb2e2.png) The graph in the first example. Here is one possible walk for the first query:

$$1 \overset{5}{\rightarrow} 3 \overset{3}{\rightarrow} 2 \overset{1}{\rightarrow} 1 \overset{5}{\rightarrow} 3 \overset{1}{\rightarrow} 4 \overset{2}{\rightarrow} 5.$$

The array of weights is $w=[5,3,1,5,1,2]$. Now if we take the bitwise AND of every prefix of this array, we get the set $\{5,1,0\}$. The MEX of this set is $2$. We cannot get a walk with a smaller length (as defined in the statement).



#### Tags 

#2200 #NOT OK #bitmasks #brute_force #constructive_algorithms #dfs_and_similar #dsu #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_782_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
