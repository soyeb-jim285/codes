<h1 style='text-align: center;'> A. Find Divisible</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a range of positive integers from $l$ to $r$.

Find such a pair of integers $(x, y)$ that $l \le x, y \le r$, $x \ne y$ and $x$ divides $y$.

If there are multiple answers, print any of them.

You are also asked to answer $T$ independent queries.

### Input

The first line contains a single integer $T$ ($1 \le T \le 1000$) — the number of queries.

Each of the next $T$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le 998244353$) — inclusive borders of the range.

It is guaranteed that testset only includes queries, which have at least one suitable pair.

### Output

Print $T$ lines, each line should contain the answer — two integers $x$ and $y$ such that $l \le x, y \le r$, $x \ne y$ and $x$ divides $y$. The answer in the $i$-th line should correspond to the $i$-th query from the input.

If there are multiple answers, print any of them.

## Example

### Input


```text
3
1 10
3 14
1 10
```
### Output


```text
1 7
3 9
5 10
```


#### Tags 

#800 #NOT OK #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_57_(Rated_for_Div._2).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial (ru)](../blogs/Tutorial_(ru).md)
