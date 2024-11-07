<h1 style='text-align: center;'> D. Suspicious logarithms</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $f$($x$) be the floor of the binary logarithm of $x$. In other words, $f$($x$) is largest non-negative integer $y$, such that $2^y$ does not exceed $x$.

Let $g$($x$) be the floor of the logarithm of $x$ with base $f$($x$). In other words, $g$($x$) is the largest non-negative integer $z$, such that ${f(x)}^{z}$ does not exceed $x$.

You are given $q$ queries. The $i$-th query consists of two integers $l_i$ and $r_i$. The answer to the query is the sum of $g$($k$) across all integers $k$, such that $l_i \leq k \leq r_i$. Since the answers might be large, print them modulo ${10^9 + 7}$.

### Input

The first line contains a single integer $q$ — the number of queries ($1 \leq q \leq 10^5$).

The next $q$ lines each contain two integers $l_i$ and $r_i$ — the bounds of the $i$-th query ($4 \leq l_i \leq r_i \leq 10^{18}$). 

### Output

For each query, output the answer to the query modulo $10^9 + 7$.

## Example

### Input


```text
12
4 6
4 7
4 8
4 100000
179 1000000000000000000
57 179
4 201018959
7 201018960
729 50624
728 50624
728 50625
729 50625
```
### Output


```text
6
8
9
348641
41949982
246
1
0
149688
149690
149694
149692
```
## Note

The table below contains the values of the functions $f$($x$) and $g$($x$) for all $x$ such that $1 \leq x \leq 8$. 

 

| $x$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $f$ | $0$ | $1$ | $1$ | $2$ | $2$ | $2$ | $2$ | $3$ |
| $g$ | $-$ | $-$ | $-$ | $2$ | $2$ | $2$ | $2$ | $1$ |

 

#### Tags 

#1900 #NOT OK #binary_search #brute_force #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_907_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial](../blogs/Editorial.md)
