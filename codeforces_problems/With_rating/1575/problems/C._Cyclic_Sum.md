<h1 style='text-align: center;'> C. Cyclic Sum</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Denote a cyclic sequence of size $n$ as an array $s$ such that $s_n$ is adjacent to $s_1$. The segment $s[r, l]$ where $l < r$ is the concatenation of $s[r, n]$ and $s[1, l]$.

You are given an array $a$ consisting of $n$ integers. Define $b$ as the cyclic sequence obtained from concatenating $m$ copies of $a$. 
## Note

 that $b$ has size $n \cdot m$.

You are given an integer $k$ where $k = 1$ or $k$ is a prime number. Find the number of different segments in $b$ where the sum of elements in the segment is divisible by $k$.

Two segments are considered different if the set of indices of the segments are different. For example, when $n = 3$ and $m = 2$, the set of indices for segment $s[2, 5]$ is $\{2, 3, 4, 5\}$, and for segment $s[5, 2]$ is $\{5, 6, 1, 2\}$. In particular, the segments $s[1, 6], s[2,1], \ldots, s[6, 5]$ are considered as the same segment.

##### Output

 the answer modulo $10^9 + 7$.

##### Input

The first line contains three integers $n$, $m$, and $k$ ($1 \leq n, m, k \leq 2 \cdot 10^5$, $k = 1$ or $k$ is a prime number).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 2 \cdot 10^5$).

##### Output

##### Output

 an integer denoting the number of different segments in $b$ where the sum of elements in the segment is divisible by $k$, modulo $10^9 + 7$.

## Examples

##### Input


```text
5 1 5
1 2 3 4 3
```
##### Output


```text
4
```
##### Input


```text
5 1 5
1 2 3 4 5
```
##### Output


```text
5
```
##### Input


```text
5 4 5
1 2 3 4 5
```
##### Output


```text
125
```
## Note

In the first example, all valid segments are $[1,4]$, $[2, 3]$, $[3, 5]$, and $[4, 2]$.

In the second example, one of the valid segments is $[1, 5]$.



#### Tags 

#3000 #NOT OK #data_structures #fft #number_theory 

## Blogs
- [All Contest Problems](../COMPFEST_13_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [COMPFEST 13 — Editorial (en)](../blogs/COMPFEST_13_—_Editorial_(en).md)
