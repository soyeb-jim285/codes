<h1 style='text-align: center;'> E. Boring Segments</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ segments on a number line, numbered from $1$ to $n$. The $i$-th segments covers all integer points from $l_i$ to $r_i$ and has a value $w_i$.

You are asked to select a subset of these segments (possibly, all of them). Once the subset is selected, it's possible to travel between two integer points if there exists a selected segment that covers both of them. A subset is good if it's possible to reach point $m$ starting from point $1$ in arbitrary number of moves.

The cost of the subset is the difference between the maximum and the minimum values of segments in it. Find the minimum cost of a good subset.

In every test there exists at least one good subset.

#### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 3 \cdot 10^5$; $2 \le m \le 10^6$) — the number of segments and the number of integer points.

Each of the next $n$ lines contains three integers $l_i$, $r_i$ and $w_i$ ($1 \le l_i < r_i \le m$; $1 \le w_i \le 10^6$) — the description of the $i$-th segment.

In every test there exists at least one good subset.

#### Output

Print a single integer — the minimum cost of a good subset.

## Examples

#### Input


```text
5 12
1 5 5
3 4 10
4 10 6
11 12 5
10 12 3
```
#### Output


```text
3
```
#### Input


```text
1 10
1 10 23
```
#### Output


```text
0
```


#### Tags 

#2100 #NOT OK #data_structures #sortings #trees #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_112_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
