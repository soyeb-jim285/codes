<h1 style='text-align: center;'> F. Divide Powers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a multiset of powers of two. More precisely, for each $i$ from $0$ to $n$ exclusive you have $cnt_i$ elements equal to $2^i$.

In one operation, you can choose any one element $2^l > 1$ and divide it into two elements $2^{l - 1}$.

You should perform $q$ queries. Each query has one of two types: 

* "$1$ $pos$ $val$" — assign $cnt_{pos} := val$;
* "$2$ $x$ $k$" — calculate the minimum number of operations you need to make at least $k$ elements with value lower or equal to $2^x$.

Note that all queries of the second type don't change the multiset; that is, you just calculate the minimum number of operations, you don't perform them.

### Input

The first line contains two integers $n$ and $q$ ($1 \le n \le 30$; $1 \le q \le 2 \cdot 10^5$) — the size of array $cnt$ and the number of queries.

The second line contains $n$ integers $cnt_0, cnt_1, \dots, cnt_{n - 1}$ ($0 \le cnt_i \le 10^6$).

Next $q$ lines contain queries: one per line. Each query has one of two types: 

* "$1$ $pos$ $val$" ($0 \le pos < n$; $0 \le val \le 10^6$);
* "$2$ $x$ $k$" ($0 \le x < n$; $1 \le k \le 10^{15}$).

It's guaranteed that there is at least one query of the second type.

### Output

For each query of the second type, print the minimum number of operations you need to make at least $k$ elements with a value lower or equal to $2^x$ or $-1$ if there is no way to do it.

## Example

### Input


```text
6 11
0 1 0 0 1 0
2 1 5
2 4 18
1 1 0
2 2 5
2 0 17
1 0 3
2 1 2
1 1 4
1 4 0
1 5 1
2 2 8
```
### Output


```text
4
16
4
-1
0
1
```


#### Tags 

#2900 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_98_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
