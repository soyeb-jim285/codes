<h1 style='text-align: center;'> D. Cross Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a sheet of paper that can be represented with a grid of size $n \times m$: $n$ rows and $m$ columns of cells. All cells are colored in white initially.

$q$ operations have been applied to the sheet. The $i$-th of them can be described as follows: 

* $x_i$ $y_i$ — choose one of $k$ non-white colors and color the entire row $x_i$ and the entire column $y_i$ in it. The new color is applied to each cell, regardless of whether the cell was colored before the operation.

The sheet after applying all $q$ operations is called a coloring. Two colorings are different if there exists at least one cell that is colored in different colors.

How many different colorings are there? Print the number modulo $998\,244\,353$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of the testcase contains four integers $n, m, k$ and $q$ ($1 \le n, m, k, q \le 2 \cdot 10^5$) — the size of the sheet, the number of non-white colors and the number of operations.

The $i$-th of the following $q$ lines contains a description of the $i$-th operation — two integers $x_i$ and $y_i$ ($1 \le x_i \le n$; $1 \le y_i \le m$) — the row and the column the operation is applied to.

The sum of $q$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print a single integer — the number of different colorings modulo $998\,244\,353$.

## Example

### Input


```text
21 1 3 21 11 12 2 2 32 11 12 2
```
### Output

```text

3
4

```


#### Tags 

#1700 #NOT OK #data_structures #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_123_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
