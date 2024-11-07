<h1 style='text-align: center;'> D. Decinc Dividing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an array $a$ of $m$ integers $a_1, a_2, \ldots, a_m$ Decinc if $a$ can be made increasing by removing a decreasing subsequence (possibly empty) from it.

* For example, if $a = [3, 2, 4, 1, 5]$, we can remove the decreasing subsequence $[a_1, a_4]$ from $a$ and obtain $a = [2, 4, 5]$, which is increasing.

You are given a permutation $p$ of numbers from $1$ to $n$. Find the number of pairs of integers $(l, r)$ with $1 \le l \le r \le n$ such that $p[l \ldots r]$ (the subarray of $p$ from $l$ to $r$) is a Decinc array. 

##### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$)  — the size of $p$.

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$, all $p_i$ are distinct)  — elements of the permutation.

##### Output

##### Output

 the number of pairs of integers $(l, r)$ such that $p[l \ldots r]$ (the subarray of $p$ from $l$ to $r$) is a Decinc array. $(1 \le l \le r \le n)$

## Examples

##### Input


```text
3
2 3 1
```
##### Output


```text
6
```
##### Input


```text
6
4 5 2 6 1 3
```
##### Output


```text
19
```
##### Input


```text
10
7 10 1 8 3 9 2 4 6 5
```
##### Output


```text
39
```
## Note

In the first sample, all subarrays are Decinc.

In the second sample, all subarrays except $p[1 \ldots 6]$ and $p[2 \ldots 6]$ are Decinc.



#### Tags 

#2800 #NOT OK #brute_force #data_structures #divide_and_conquer #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_800_(Div._1).md)
- [Codeforces Round #800 (en)](../blogs/Codeforces_Round_800_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
