<h1 style='text-align: center;'> H. Submatrices</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given matrix $s$ that contains $n$ rows and $m$ columns. Each element of a matrix is one of the $5$ first Latin letters (in upper case).

For each $k$ ($1 \le k \le 5$) calculate the number of submatrices that contain exactly $k$ different letters. Recall that a submatrix of matrix $s$ is a matrix that can be obtained from $s$ after removing several (possibly zero) first rows, several (possibly zero) last rows, several (possibly zero) first columns, and several (possibly zero) last columns. If some submatrix can be obtained from $s$ in two or more ways, you have to count this submatrix the corresponding number of times.

##### Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 800$).

Then $n$ lines follow, each containing the string $s_i$ ($|s_i| = m$) — $i$-th row of the matrix. 

##### Output

For each $k$ ($1 \le k \le 5$) print one integer — the number of submatrices that contain exactly $k$ different letters.

## Examples

##### Input


```text
2 3
ABB
ABA
```
##### Output


```text
9 9 0 0 0 
```
##### Input

```text

6 6
EDCECE
EDDCEB
ACCECC
BAEEDC
DDDDEC
DDAEAD

```
##### Output


```text
56 94 131 103 57 
```
##### Input

```text

3 10
AEAAEEEEEC
CEEAAEEEEE
CEEEEAACAA

```
##### Output


```text

78 153 99 0 0 
```


#### Tags 

#NOT OK #*special #bitmasks #data_structures #dp 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_7.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
