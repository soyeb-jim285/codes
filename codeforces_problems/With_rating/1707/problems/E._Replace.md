<h1 style='text-align: center;'> E. Replace</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an integer array $a_1,\ldots, a_n$, where $1\le a_i \le n$ for all $i$.

There's a "replace" function $f$ which takes a pair of integers $(l, r)$, where $l \le r$, as input and outputs the pair $$f\big( (l, r) \big)=\left(\min\{a_l,a_{l+1},\ldots,a_r\},\, \max\{a_l,a_{l+1},\ldots,a_r\}\right).$$

Consider repeated calls of this function. That is, from a starting pair $(l, r)$ we get $f\big((l, r)\big)$, then $f\big(f\big((l, r)\big)\big)$, then $f\big(f\big(f\big((l, r)\big)\big)\big)$, and so on.

Now you need to answer $q$ queries. For the $i$-th query you have two integers $l_i$ and $r_i$ ($1\le l_i\le r_i\le n$). You must answer the minimum number of times you must apply the "replace" function to the pair $(l_i,r_i)$ to get $(1, n)$, or report that it is impossible.

##### Input

The first line contains two positive integers $n$, $q$ ($1\le n,q\le 10^5$) — the length of the sequence $a$ and the number of the queries.

The second line contains $n$ positive integers $a_1,a_2,\ldots,a_n$ ($1\le a_i\le n$) — the sequence $a$.

Each line of the following $q$ lines contains two integers $l_i$, $r_i$ ($1\le l_i\le r_i\le n$) — the queries.

##### Output

For each query, output the required number of times, or $-1$ if it is impossible.

## Examples

##### Input


```text
5 6
2 5 4 1 3
4 4
1 5
1 4
3 5
4 5
2 3
```
##### Output


```text
-1
0
1
2
3
4
```
##### Input


```text
6 3
2 3 4 6 1 2
5 6
2 5
2 3
```
##### Output


```text
5
1
3
```
##### Input


```text
5 3
3 2 2 4 1
2 5
1 3
1 5
```
##### Output


```text
-1
-1
0
```
## Note

In the first example, $n=5$ and $a=[2,5,4,1,3]$.

For the first query: $(4,4)\to(1,1)\to(2,2)\to(5,5)\to(3,3)\to(4,4)\to\ldots$, so it's impossible to get $(1,5)$.

For the second query, you already have $(1,5)$.

For the third query: $(1,4)\to(1,5)$.

For the fourth query: $(3,5)\to(1,4)\to(1,5)$.

For the fifth query: $(4,5)\to(1,3)\to(2,5)\to(1,5)$.

For the sixth query: $(2,3)\to(4,5)\to(1,3)\to(2,5)\to(1,5)$.



#### Tags 

#3500 #NOT OK #binary_search #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_808_(Div._1).md)
- [Codeforces Round #808 (en)](../blogs/Codeforces_Round_808_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
