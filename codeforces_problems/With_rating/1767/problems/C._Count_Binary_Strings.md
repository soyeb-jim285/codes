<h1 style='text-align: center;'> C. Count Binary Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an integer $n$. You have to calculate the number of binary (consisting of characters 0 and/or 1) strings $s$ meeting the following constraints.

For every pair of integers $(i, j)$ such that $1 \le i \le j \le n$, an integer $a_{i,j}$ is given. It imposes the following constraint on the string $s_i s_{i+1} s_{i+2} \dots s_j$:

* if $a_{i,j} = 1$, all characters in $s_i s_{i+1} s_{i+2} \dots s_j$ should be the same;
* if $a_{i,j} = 2$, there should be at least two different characters in $s_i s_{i+1} s_{i+2} \dots s_j$;
* if $a_{i,j} = 0$, there are no additional constraints on the string $s_i s_{i+1} s_{i+2} \dots s_j$.

Count the number of binary strings $s$ of length $n$ meeting the aforementioned constraints. Since the answer can be large, print it modulo $998244353$.

###### Input

The first line contains one integer $n$ ($2 \le n \le 100$).

Then $n$ lines follow. The $i$-th of them contains $n-i+1$ integers $a_{i,i}, a_{i,i+1}, a_{i,i+2}, \dots, a_{i,n}$ ($0 \le a_{i,j} \le 2$).

###### Output

Print one integer — the number of strings meeting the constraints, taken modulo $998244353$.

## Examples

###### Input


```text
3
1 0 2
1 0
1
```
###### Output


```text
6
```
###### Input


```text
3
1 1 2
1 0
1
```
###### Output


```text
2
```
###### Input


```text
3
1 2 1
1 0
1
```
###### Output


```text
0
```
###### Input


```text
3
2 0 2
0 1
1
```
###### Output


```text
0
```
## Note

In the first example, the strings meeting the constraints are 001, 010, 011, 100, 101, 110.

In the second example, the strings meeting the constraints are 001, 110.



#### Tags 

#2100 #NOT OK #data_structures #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_140_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
