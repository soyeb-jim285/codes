<h1 style='text-align: center;'> D. Isolation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Find the number of ways to divide an array $a$ of $n$ integers into any number of disjoint non-empty segments so that, in each segment, there exist at most $k$ distinct integers that appear exactly once.

Since the answer can be large, find it modulo $998\,244\,353$.

##### Input

The first line contains two space-separated integers $n$ and $k$ ($1 \leq k \leq n \leq 10^5$) — the number of elements in the array $a$ and the restriction from the statement.

The following line contains $n$ space-separated integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — elements of the array $a$.

##### Output

The first and only line contains the number of ways to divide an array $a$ modulo $998\,244\,353$.

## Examples

##### Input


```text
3 1
1 1 2
```
##### Output


```text
3
```
##### Input


```text
5 2
1 1 2 1 3
```
##### Output


```text
14
```
##### Input


```text
5 5
1 2 3 4 5
```
##### Output


```text
16
```
## Note

In the first sample, the three possible divisions are as follows.

* $[[1], [1], [2]]$
* $[[1, 1], [2]]$
* $[[1, 1, 2]]$

Division $[[1], [1, 2]]$ is not possible because two distinct integers appear exactly once in the second segment $[1, 2]$.



#### Tags 

#2900 #NOT OK #data_structures #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_542_[Alex_Lopashev_Thanks-Round]_(Div._1).md)
- [Codeforces Round #542 (en)](../blogs/Codeforces_Round_542_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
