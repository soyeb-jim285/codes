<h1 style='text-align: center;'> E. Fill the Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a square matrix, consisting of $n$ rows and $n$ columns of cells, both numbered from $1$ to $n$. The cells are colored white or black. Cells from $1$ to $a_i$ are black, and cells from $a_i+1$ to $n$ are white, in the $i$-th column.

You want to place $m$ integers in the matrix, from $1$ to $m$. There are two rules: 

* each cell should contain at most one integer;
* black cells should not contain integers.

The beauty of the matrix is the number of such $j$ that $j+1$ is written in the same row, in the next column as $j$ (in the neighbouring cell to the right).

What's the maximum possible beauty of the matrix?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the size of the matrix.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le n$) — the number of black cells in each column.

The third line contains a single integer $m$ ($0 \le m \le \sum \limits_{i=1}^n n - a_i$) — the number of integers you have to write in the matrix. Note that this number might not fit into a 32-bit integer data type.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print a single integer — the maximum beauty of the matrix after you write all $m$ integers in it. Note that there are no more integers than the white cells, so the answer always exists.

## Example

### Input


```text
630 0 0942 0 3 1542 0 3 1642 0 3 110100 2 2 1 5 10 3 4 1 120110
```
### Output

```text

6
3
4
4
16
0

```


#### Tags 

#2200 #NOT OK #data_structures #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_150_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
