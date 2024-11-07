<h1 style='text-align: center;'> F. Simultaneous Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a matrix, consisting of $n$ rows and $m$ columns.

You can perform two types of actions on it: 

* paint the entire column in blue;
* paint the entire row in red.

Note that you cannot choose which color to paint the row or column.

In one second, you can perform either one action or multiple actions at the same time. If you perform one action, it will be free. If you perform $k > 1$ actions at the same time, it will cost $k^2$ coins. When multiple actions are performed at the same time, for each cell affected by actions of both types, the color can be chosen independently.

You are asked to process $q$ queries. Before each query, all cells become colorless. Initially, there are no restrictions on the color of any cells. In the $i$-th query, a restriction of the following form is added: 

* $x_i~y_i~c_i$ — the cell in row $x_i$ in column $y_i$ should be painted in color $c_i$.

Thus, after $i$ queries, there are $i$ restrictions on the required colors of the matrix cells. After each query, output the minimum cost of painting the matrix according to the restrictions.

#### Input

The first line contains three integers $n, m$ and $q$ ($1 \le n, m, q \le 2 \cdot 10^5$) — the size of the matrix and the number of queries.

In the $i$-th of the next $q$ lines, two integers $x_i, y_i$ and a character $c_i$ ($1 \le x_i \le n$; $1 \le y_i \le m$; $c_i \in$ {'R', 'B'}, where 'R' means red, and 'B' means blue) — description of the $i$-th restriction. The cells in all queries are pairwise distinct.

#### Output

Print $q$ integers — after each query, output the minimum cost of painting the matrix according to the restrictions.

## Examples

#### Input


```text
2 2 41 1 R2 2 R1 2 B2 1 B
```
#### Output

```text

0
0
0
16

```
#### Input


```text
3 5 101 1 B2 5 B2 2 B2 3 R2 1 B3 2 R3 3 B1 2 R1 3 B3 1 B
```
#### Output

```text

0
0
0
0
0
0
16
16
25
25

```


#### Tags 

#3000 #NOT OK #dfs_and_similar #divide_and_conquer #graphs 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_167_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Tutorial #2](../blogs/Tutorial_2.md)
