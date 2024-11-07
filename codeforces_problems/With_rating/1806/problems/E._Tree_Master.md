<h1 style='text-align: center;'> E. Tree Master</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a tree with $n$ weighted vertices labeled from $1$ to $n$ rooted at vertex $1$. The parent of vertex $i$ is $p_i$ and the weight of vertex $i$ is $a_i$. For convenience, define $p_1=0$.

For two vertices $x$ and $y$ of the same depth$^\dagger$, define $f(x,y)$ as follows: 

* Initialize $\mathrm{ans}=0$.
* While both $x$ and $y$ are not $0$:
	+ $\mathrm{ans}\leftarrow \mathrm{ans}+a_x\cdot a_y$;
	+ $x\leftarrow p_x$;
	+ $y\leftarrow p_y$.
* $f(x,y)$ is the value of $\mathrm{ans}$.

You will process $q$ queries. In the $i$-th query, you are given two integers $x_i$ and $y_i$ and you need to calculate $f(x_i,y_i)$.

$^\dagger$ The depth of vertex $v$ is the number of edges on the unique simple path from the root of the tree to vertex $v$. 

#### Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 10^5$; $1 \le q \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^5$).

The third line contains $n-1$ integers $p_2, \ldots, p_n$ ($1 \le p_i < i$).

Each of the next $q$ lines contains two integers $x_i$ and $y_i$ ($1\le x_i,y_i\le n$). It is guaranteed that $x_i$ and $y_i$ are of the same depth.

#### Output

#### Output

 $q$ lines, the $i$-th line contains a single integer, the value of $f(x_i,y_i)$.

## Examples

#### Input


```text
6 2
1 5 2 3 1 1
1 2 3 3 2
4 5
6 6
```
#### Output


```text
33
27
```
#### Input


```text
14 8
3 2 5 3 1 4 2 2 2 5 5 5 2 4
1 2 3 1 1 4 7 3 3 1 5 3 8
4 4
4 10
13 10
3 12
13 9
3 12
9 10
11 5
```
#### Output


```text
47
53
48
36
42
36
48
14
```
## Note

Consider the first example:

In the first query, the answer is $a_4\cdot a_5+a_3\cdot a_3+a_2\cdot a_2+a_1\cdot a_1=3+4+25+1=33$.

In the second query, the answer is $a_6\cdot a_6+a_2\cdot a_2+a_1\cdot a_1=1+25+1=27$.



#### Tags 

#2200 #NOT OK #brute_force #data_structures #dfs_and_similar #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_858_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
