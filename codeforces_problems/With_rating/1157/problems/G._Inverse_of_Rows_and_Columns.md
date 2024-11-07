<h1 style='text-align: center;'> G. Inverse of Rows and Columns</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary matrix $a$ of size $n \times m$. A binary matrix is a matrix where each element is either $0$ or $1$.

You may perform some (possibly zero) operations with this matrix. During each operation you can inverse the row of this matrix or a column of this matrix. Formally, inverting a row is changing all values in this row to the opposite ($0$ to $1$, $1$ to $0$). Inverting a column is changing all values in this column to the opposite.

Your task is to sort the initial matrix by some sequence of such operations. The matrix is considered sorted if the array $[a_{1, 1}, a_{1, 2}, \dots, a_{1, m}, a_{2, 1}, a_{2, 2}, \dots, a_{2, m}, \dots, a_{n, m - 1}, a_{n, m}]$ is sorted in non-descending order.

##### Input

The first line of the input contains two integers $n$ and $m$ ($1 \le n, m \le 200$) — the number of rows and the number of columns in the matrix.

The next $n$ lines contain $m$ integers each. The $j$-th element in the $i$-th line is $a_{i, j}$ ($0 \le a_{i, j} \le 1$) — the element of $a$ at position $(i, j)$.

##### Output

If it is impossible to obtain a sorted matrix, print "NO" in the first line.

Otherwise print "YES" in the first line. In the second line print a string $r$ of length $n$. The $i$-th character $r_i$ of this string should be '1' if the $i$-th row of the matrix is inverted and '0' otherwise. In the third line print a string $c$ of length $m$. The $j$-th character $c_j$ of this string should be '1' if the $j$-th column of the matrix is inverted and '0' otherwise. If there are multiple answers, you can print any.

## Examples

##### Input


```text
2 2
1 1
0 1
```
##### Output


```text
YES
00
10
```
##### Input


```text
3 4
0 0 0 1
0 0 0 0
1 1 1 1
```
##### Output


```text
YES
010
0000
```
##### Input


```text
3 3
0 0 0
1 0 1
1 1 0
```
##### Output


```text
NO
```


#### Tags 

#2200 #NOT OK #brute_force #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_555_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
