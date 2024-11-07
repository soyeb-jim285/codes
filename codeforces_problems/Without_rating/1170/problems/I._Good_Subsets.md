<h1 style='text-align: center;'> I. Good Subsets</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ segments on the $Ox$ axis. The $i$-th segment is given as a pair $l_i, r_i$, where $l_i$ is the position of the left end of the $i$-th segment and $r_i$ is the position of the right end of the $i$-th segment. Segments may intersect, overlap, or even coincide. A segment is a set of numbers (including floating-point numbers) lying between the segment ends or coinciding with them. Formally, the segment $[l, r]=\{x~|~x \in \Bbb{R},~l \le x \le r\}$.

Let the union of segments be the set of all axis points covered by the set of segments. Let's call a subset of the given segments good if its union equals the union of all $n$ segments.

Your task is to calculate the number of good subsets of the given $n$ segments. Since the answer may be very large, print it modulo $998244353$.

##### Input

The first line of the input contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of segments.

The next $n$ lines contain segments. The $i$-th segment is given as a pair $l_i, r_i$ ($1 \le l_i \le r_i \le 10^9$), where $l_i$ is the left border of the segment and $r_i$ is the right border of the segment. Segments may intersect, overlap, or even coincide.

##### Output

Print the number of good subsets of the given set of segments. Since the answer may be very large, print it modulo $998244353$.

## Examples

##### Input


```text
3
1 1
2 6
1 6
```
##### Output


```text
4
```
##### Input


```text
2
3 4
2 5
```
##### Output


```text
2
```
##### Input


```text
4
1 2
5 5
2 3
1 3
```
##### Output


```text
5
```


#### Tags 

#NOT OK #*special #dp 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_1.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Kotlin Heroes Editorial (en)](../blogs/Kotlin_Heroes_Editorial_(en).md)
