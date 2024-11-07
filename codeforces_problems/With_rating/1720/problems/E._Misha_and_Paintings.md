<h1 style='text-align: center;'> E. Misha and Paintings</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Misha has a square $n \times n$ matrix, where the number in row $i$ and column $j$ is equal to $a_{i, j}$. Misha wants to modify the matrix to contain exactly $k$ distinct integers. To achieve this goal, Misha can perform the following operation zero or more times:

1. choose any square submatrix of the matrix (you choose $(x_1,y_1)$, $(x_2,y_2)$, such that $x_1 \leq x_2$, $y_1 \leq y_2$, $x_2 - x_1 = y_2 - y_1$, then submatrix is a set of cells with coordinates $(x, y)$, such that $x_1 \leq x \leq x_2$, $y_1 \leq y \leq y_2$),
2. choose an integer $k$, where $1 \leq k \leq n^2$,
3. replace all integers in the submatrix with $k$.

Please find the minimum number of operations that Misha needs to achieve his goal.

###### Input

The first input line contains two integers $n$ and $k$ ($1 \leq n \leq 500, 1 \leq k \leq n^2$)  — the size of the matrix and the desired amount of distinct elements in the matrix.

Then $n$ lines follows. The $i$-th of them contains $n$ integers $a_{i, 1}, a_{i, 2}, \ldots, a_{i, n}$ ($1 \leq a_{i,j} \leq n^2$) — the elements of the $i$-th row of the matrix.

###### Output

###### Output

 one integer — the minimum number of operations required.

## Examples

###### Input


```text
3 4
1 1 1
1 1 2
3 4 5
```
###### Output


```text
1
```
###### Input

```text

3 2
2 1 3
2 1 1
3 1 2

```
###### Output


```text
2
```
###### Input

```text

3 3
1 1 1
1 1 2
2 2 2

```
###### Output


```text
1
```
###### Input

```text

3 2
1 1 1
1 2 1
2 2 2

```
###### Output


```text

0
```
## Note

In the first test case the answer is $1$, because one can change the value in the bottom right corner of the matrix to $1$. The resulting matrix can be found below:

 

| 1 | 1 | 1 |
| --- | --- | --- |
| 1 | 1 | 2 |
| 3 | 4 | 1 |

 In the second test case the answer is $2$. First, one can change the entire matrix to contain only $1$s, and the change the value of any single cell to $2$. One of the possible resulting matrices is displayed below:

 

| 1 | 1 | 1 |
| --- | --- | --- |
| 1 | 1 | 1 |
| 1 | 1 | 2 |

 

#### Tags 

#2700 #NOT OK #constructive_algorithms #data_structures #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_815_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
