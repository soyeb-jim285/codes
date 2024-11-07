<h1 style='text-align: center;'> G. Cross Xor</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a grid with $r$ rows and $c$ columns, where the square on the $i$-th row and $j$-th column has an integer $a_{i, j}$ written on it. Initially, all elements are set to $0$. We are allowed to do the following operation:

* Choose indices $1 \le i \le r$ and $1 \le j \le c$, then replace all values on the same row or column as $(i, j)$ with the value xor $1$. In other words, for all $a_{x, y}$ where $x=i$ or $y=j$ or both, replace $a_{x, y}$ with $a_{x, y}$ xor $1$.

You want to form grid $b$ by doing the above operations a finite number of times. However, some elements of $b$ are missing and are replaced with '?' instead.

Let $k$ be the number of '?' characters. Among all the $2^k$ ways of filling up the grid $b$ by replacing each '?' with '0' or '1', count the number of grids, that can be formed by doing the above operation a finite number of times, starting from the grid filled with $0$. As this number can be large, output it modulo $998244353$.

###### Input

The first line contains two integers $r$ and $c$ ($1 \le r, c \le 2000$)  — the number of rows and columns of the grid respectively.

The $i$-th of the next $r$ lines contain $c$ characters $b_{i, 1}, b_{i, 2}, \ldots, b_{i, c}$ ($b_{i, j} \in \{0, 1, ?\}$).

###### Output

Print a single integer representing the number of ways to fill up grid $b$ modulo $998244353$.

## Examples

###### Input


```text
3 3
?10
1??
010
```
###### Output


```text
1
```
###### Input


```text
2 3
000
001
```
###### Output


```text
0
```
###### Input


```text
1 1
?
```
###### Output


```text
2
```
###### Input


```text
6 9
1101011?0
001101?00
101000110
001011010
0101?01??
00?1000?0
```
###### Output


```text
8
```
## Note

In the first test case, the only way to fill in the $\texttt{?}$s is to fill it in as such:

 

| 0 | 1 | 0 |
| --- | --- | --- |
| 1 | 1 | 1 |
| 0 | 1 | 0 |

 This can be accomplished by doing a single operation by choosing $(i,j)=(2,2)$.

In the second test case, it can be shown that there is no sequence of operations that can produce that grid.



#### Tags 

#3200 #NOT OK #constructive_algorithms #graphs #math #matrices 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_20.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
