<h1 style='text-align: center;'> G. Painting Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers, each integer is from $1$ to $n$, all of them are pairwise distinct. You have to paint them red and blue (each integer should have exactly one color).

The cost of painting is the number of pairs $(x, y)$ such that $y \bmod x = 0$, $y$ is red and $x$ is blue.

For each $k \in [1, n]$, calculate the maximum cost of painting if exactly $k$ integers should have a red color.

##### Input

The first line contains one integer $n$ ($2 \le n \le 10^5$).

##### Output

For each $k \in [1,n]$ print one integer — the maximum cost of painting, if exactly $k$ integers should be red.

## Examples

##### Input


```text
6
```
##### Output


```text
3 5 6 6 5 0
```
##### Input


```text
2
```
##### Output


```text
1 0
```
##### Input


```text
11
```
##### Output


```text
3 6 9 11 12 13 14 14 13 10 0
```


#### Tags 

#2500 #NOT OK #*special #data_structures #greedy #number_theory 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_6.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
