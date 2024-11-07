<h1 style='text-align: center;'> D. Rearrange</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Koa the Koala has a matrix $A$ of $n$ rows and $m$ columns. Elements of this matrix are distinct integers from $1$ to $n \cdot m$ (each number from $1$ to $n \cdot m$ appears exactly once in the matrix).

For any matrix $M$ of $n$ rows and $m$ columns let's define the following:

* The $i$-th row of $M$ is defined as $R_i(M) = [ M_{i1}, M_{i2}, \ldots, M_{im} ]$ for all $i$ ($1 \le i \le n$).
* The $j$-th column of $M$ is defined as $C_j(M) = [ M_{1j}, M_{2j}, \ldots, M_{nj} ]$ for all $j$ ($1 \le j \le m$).

Koa defines $S(A) = (X, Y)$ as the spectrum of $A$, where $X$ is the set of the maximum values in rows of $A$ and $Y$ is the set of the maximum values in columns of $A$.

More formally:

* $X = \{ \max(R_1(A)), \max(R_2(A)), \ldots, \max(R_n(A)) \}$
* $Y = \{ \max(C_1(A)), \max(C_2(A)), \ldots, \max(C_m(A)) \}$

Koa asks you to find some matrix $A'$ of $n$ rows and $m$ columns, such that each number from $1$ to $n \cdot m$ appears exactly once in the matrix, and the following conditions hold:

* $S(A') = S(A)$
* $R_i(A')$ is bitonic for all $i$ ($1 \le i \le n$)
* $C_j(A')$ is bitonic for all $j$ ($1 \le j \le m$)

 An array $t$ ($t_1, t_2, \ldots, t_k$) is called bitonic if it first increases and then decreases. More formally: $t$ is bitonic if there exists some position $p$ ($1 \le p \le k$) such that: $t_1 < t_2 < \ldots < t_p > t_{p+1} > \ldots > t_k$.

Help Koa to find such matrix or to determine that it doesn't exist.

##### Input

The first line of the input contains two integers $n$ and $m$ ($1 \le n, m \le 250$)  — the number of rows and columns of $A$.

Each of the ollowing $n$ lines contains $m$ integers. The $j$-th integer in the $i$-th line denotes element $A_{ij}$ ($1 \le A_{ij} \le n \cdot m$) of matrix $A$. It is guaranteed that every number from $1$ to $n \cdot m$ appears exactly once among elements of the matrix.

##### Output

If such matrix doesn't exist, print $-1$ on a single line.

Otherwise, the output must consist of $n$ lines, each one consisting of $m$ space separated integers  — a description of $A'$.

The $j$-th number in the $i$-th line represents the element $A'_{ij}$.

Every integer from $1$ to $n \cdot m$ should appear exactly once in $A'$, every row and column in $A'$ must be bitonic and $S(A) = S(A')$ must hold.

If there are many answers print any.

## Examples

##### Input


```text
3 3
3 5 6
1 7 9
4 8 2
```
##### Output


```text
9 5 1
7 8 2
3 6 4
```
##### Input


```text
2 2
4 1
3 2
```
##### Output


```text
4 1
3 2
```
##### Input


```text
3 4
12 10 8 6
3 4 5 7
2 11 9 1
```
##### Output


```text
12 8 6 1
10 11 9 2
3 4 5 7
```
## Note

Let's analyze the first sample:

For matrix $A$ we have:

+ Rows:
	- $R_1(A) = [3, 5, 6]; \max(R_1(A)) = 6$
	- $R_2(A) = [1, 7, 9]; \max(R_2(A)) = 9$
	- $R_3(A) = [4, 8, 2]; \max(R_3(A)) = 8$
+ Columns:
	- $C_1(A) = [3, 1, 4]; \max(C_1(A)) = 4$
	- $C_2(A) = [5, 7, 8]; \max(C_2(A)) = 8$
	- $C_3(A) = [6, 9, 2]; \max(C_3(A)) = 9$

 

* $X = \{ \max(R_1(A)), \max(R_2(A)), \max(R_3(A)) \} = \{ 6, 9, 8 \}$
* $Y = \{ \max(C_1(A)), \max(C_2(A)), \max(C_3(A)) \} = \{ 4, 8, 9 \}$
* So $S(A) = (X, Y) = (\{ 6, 9, 8 \}, \{ 4, 8, 9 \})$

For matrix $A'$ we have:

+ Rows:
	- $R_1(A') = [9, 5, 1]; \max(R_1(A')) = 9$
	- $R_2(A') = [7, 8, 2]; \max(R_2(A')) = 8$
	- $R_3(A') = [3, 6, 4]; \max(R_3(A')) = 6$
+ Columns:
	- $C_1(A') = [9, 7, 3]; \max(C_1(A')) = 9$
	- $C_2(A') = [5, 8, 6]; \max(C_2(A')) = 8$
	- $C_3(A') = [1, 2, 4]; \max(C_3(A')) = 4$

 

* 
## Note

 that each of this arrays are bitonic.
* $X = \{ \max(R_1(A')), \max(R_2(A')), \max(R_3(A')) \} = \{ 9, 8, 6 \}$
* $Y = \{ \max(C_1(A')), \max(C_2(A')), \max(C_3(A')) \} = \{ 9, 8, 4 \}$
* So $S(A') = (X, Y) = (\{ 9, 8, 6 \}, \{ 9, 8, 4 \})$


#### Tags 

#2800 #NOT OK #brute_force #constructive_algorithms #graphs #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_659_(Div._1).md)
- [Codeforces Round #659 (en)](../blogs/Codeforces_Round_659_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
