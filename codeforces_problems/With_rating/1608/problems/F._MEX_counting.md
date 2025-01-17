<h1 style='text-align: center;'> F. MEX counting</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array $c$ of nonnegative integers, $MEX(c)$ denotes the smallest nonnegative integer that doesn't appear in it. For example, $MEX([0, 1, 3]) = 2$, $MEX([42]) = 0$.

You are given integers $n, k$, and an array $[b_1, b_2, \ldots, b_n]$.

Find the number of arrays $[a_1, a_2, \ldots, a_n]$, for which the following conditions hold:

* $0 \le a_i \le n$ for each $i$ for each $i$ from $1$ to $n$.
* $|MEX([a_1, a_2, \ldots, a_i]) - b_i| \le k$ for each $i$ from $1$ to $n$.

As this number can be very big, output it modulo $998\,244\,353$.

####### Input

The first line of the input contains two integers $n, k$ ($1 \le n \le 2000$, $0 \le k \le 50$).

The second line of the input contains $n$ integers $b_1, b_2, \ldots, b_n$ ($-k \le b_i \le n+k$) — elements of the array $b$.

####### Output

####### Output

 a single integer — the number of arrays which satisfy the conditions from the statement, modulo $998\,244\,353$.

## Examples

####### Input


```text
4 0
0 0 0 0
```
####### Output


```text
256
```
####### Input


```text
4 1
0 0 0 0
```
####### Output


```text
431
```
####### Input


```text
4 1
0 0 1 1
```
####### Output


```text
509
```
####### Input


```text
5 2
0 0 2 2 0
```
####### Output


```text
6546
```
####### Input


```text
3 2
-2 0 4
```
####### Output


```text
11
```


#### Tags 

#3200 #NOT OK #combinatorics #dp #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_758_(Div.1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
