<h1 style='text-align: center;'> F. Words on Tree</h1>

<h5 style='text-align: center;'>time limit per test: 9 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a tree consisting of $n$ vertices, and $q$ triples $(x_i, y_i, s_i)$, where $x_i$ and $y_i$ are integers from $1$ to $n$, and $s_i$ is a string with length equal to the number of vertices on the simple path from $x_i$ to $y_i$.

You want to write a lowercase Latin letter on each vertex in such a way that, for each of $q$ given triples, at least one of the following conditions holds:

* if you write out the letters on the vertices on the simple path from $x_i$ to $y_i$ in the order they appear on this path, you get the string $s_i$;
* if you write out the letters on the vertices on the simple path from $y_i$ to $x_i$ in the order they appear on this path, you get the string $s_i$.

Find any possible way to write a letter on each vertex to meet these constraints, or report that it is impossible.

###### Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 4 \cdot 10^5$; $1 \le q \le 4 \cdot 10^5$) — the number of vertices in the tree and the number of triples, respectively.

Then $n - 1$ lines follow; the $i$-th of them contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$; $u_i \ne v_i$) — the endpoints of the $i$-th edge. These edges form a tree.

Then $q$ lines follow; the $j$-th of them contains two integers $x_j$ and $y_j$, and a string $s_j$ consisting of lowercase Latin letters. The length of $s_j$ is equal to the number of vertices on the simple path between $x_j$ and $y_j$.

Additional constraint on the input: $\sum \limits_{j=1}^{q} |s_j| \le 4 \cdot 10^5$.

###### Output

If there is no way to meet the conditions on all triples, print NO. Otherwise, print YES in the first line, and a string of $n$ lowercase Latin letters in the second line; the $i$-th character of the string should be the letter you write on the $i$-th vertex. If there are multiple answers, print any of them.

## Examples

###### Input


```text
3 2
2 3
2 1
2 1 ab
2 3 bc
```
###### Output


```text
YES
abc
```
###### Input

```text

3 2
2 3
2 1
2 1 ab
2 3 cd

```
###### Output


```text
NO
```
###### Input


```text
10 10
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 2 ab
1 3 ab
1 4 ab
1 5 ab
1 6 ab
1 7 ab
1 8 ab
1 9 ab
1 10 ab
10 2 aba
```
###### Output


```text
YES
baaaaaaaaa
```
###### Input

```text

10 10
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 2 ab
1 3 ab
1 4 aa
1 5 ab
1 6 ab
1 7 ab
1 8 ab
1 9 ab
1 10 ab
10 2 aba

```
###### Output


```text
NO
```


#### Tags 

#2600 #NOT OK #2-sat #dfs_and_similar #dsu #graphs #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_125_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
