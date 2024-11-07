<h1 style='text-align: center;'> G. Greedy Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For some array $c$, let's denote a greedy subsequence as a sequence of indices $p_1$, $p_2$, ..., $p_l$ such that $1 \le p_1 < p_2 < \dots < p_l \le |c|$, and for each $i \in [1, l - 1]$, $p_{i + 1}$ is the minimum number such that $p_{i + 1} > p_i$ and $c[p_{i + 1}] > c[p_i]$.

You are given an array $a_1, a_2, \dots, a_n$. For each its subsegment of length $k$, calculate the length of its longest greedy subsequence.

#### Input

The first line contains two integers $n$ and $k$ ($1 \le k \le n \le 10^6$) — the length of array $a$ and the length of subsegments.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — array $a$.

#### Output

Print $n - k + 1$ integers — the maximum lengths of greedy subsequences of each subsegment having length $k$. The first number should correspond to subsegment $a[1..k]$, the second — to subsegment $a[2..k + 1]$, and so on.

## Examples

#### Input


```text
6 4
1 5 2 5 3 6
```
#### Output


```text
2 2 3 
```
#### Input


```text
7 6
4 5 2 5 3 6 6
```
#### Output


```text
3 3 
```
## Note

In the first example: 

* $[1, 5, 2, 5]$ — the longest greedy subsequences are $1, 2$ ($[c_1, c_2] = [1, 5]$) or $3, 4$ ($[c_3, c_4] = [2, 5]$).
* $[5, 2, 5, 3]$ — the sequence is $2, 3$ ($[c_2, c_3] = [2, 5]$).
* $[2, 5, 3, 6]$ — the sequence is $1, 2, 4$ ($[c_1, c_2, c_4] = [2, 5, 6]$).

In the second example: 

* $[4, 5, 2, 5, 3, 6]$ — the longest greedy subsequences are $1, 2, 6$ ($[c_1, c_2, c_6] = [4, 5, 6]$) or $3, 4, 6$ ($[c_3, c_4, c_6] = [2, 5, 6]$).
* $[5, 2, 5, 3, 6, 6]$ — the subsequence is $2, 3, 5$ ($[c_2, c_3, c_5] = [2, 5, 6]$).


#### Tags 

#2400 #NOT OK #data_structures #dp #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_61_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [T (en)](../blogs/T_(en).md)
