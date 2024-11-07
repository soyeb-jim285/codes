<h1 style='text-align: center;'> C. Sort</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $a$ and $b$ of length $n$. Then, you are (forced against your will) to answer $q$ queries.

For each query, you are given a range bounded by $l$ and $r$. In one operation, you can choose an integer $i$ ($l \leq i \leq r$) and set $a_i = x$ where $x$ is any character you desire. 
### Output

 the minimum number of operations you must perform such that $\texttt{sorted(a[l..r])} = \texttt{sorted(b[l..r])}$. The operations you perform on one query does not affect other queries.

For an arbitrary string $c$, $\texttt{sorted(c[l..r])}$ denotes the substring consisting of characters $c_l, c_{l+1}, ... , c_r$ sorted in lexicographical order.

### Input

The first line contains $t$ ($1 \leq t \leq 1000$) – the number of test cases.

The first line of each test case contains two integers $n$ and $q$ ($1 \leq n, q \leq 2 \cdot 10^5$) – the length of both strings and the number of queries.

The following line contains $a$ of length $n$. It is guaranteed $a$ only contains lowercase latin letters.

The following line contains $b$ of length $n$. It is guaranteed $b$ only contains lowercase latin letters.

The following $q$ lines contain two integers $l$ and $r$ ($1 \leq l \leq r \leq n$) – the range of the query.

It is guaranteed the sum of $n$ and $q$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each query, output an integer, the minimum number of operations you need to perform in a new line.

## Example

### Input


```text
35 3abcdeedcba1 51 43 34 2zzdeazbe1 31 46 3uwuwuwwuwuwu2 41 31 6
```
### Output

```text

0
1
0
2
2
1
1
0

```
## Note

For the first query, $\texttt{sorted(a[1..5])} =$ abcde and $\texttt{sorted(b[1..5])} =$ abcde, so no operations are necessary.

For the second query, you need to set $a_1 = $ e. Then, $\texttt{sorted(a[1..4])} = \texttt{sorted(b[1..4])} = $ bcde.



#### Tags 

#NOT OK #dp #greedy #sortings #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_962_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial 2 (en)](../blogs/Video_Tutorial_2_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
