<h1 style='text-align: center;'> C. MAX-MEX Cut</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A binary string is a string that consists of characters $0$ and $1$. A bi-table is a table that has exactly two rows of equal length, each being a binary string.

Let $\operatorname{MEX}$ of a bi-table be the smallest digit among $0$, $1$, or $2$ that does not occur in the bi-table. For example, $\operatorname{MEX}$ for $\begin{bmatrix} 0011\\\ 1010 \end{bmatrix}$ is $2$, because $0$ and $1$ occur in the bi-table at least once. $\operatorname{MEX}$ for $\begin{bmatrix} 111\\\ 111 \end{bmatrix}$ is $0$, because $0$ and $2$ do not occur in the bi-table, and $0 < 2$.

You are given a bi-table with $n$ columns. You should cut it into any number of bi-tables (each consisting of consecutive columns) so that each column is in exactly one bi-table. It is possible to cut the bi-table into a single bi-table — the whole bi-table.

What is the maximal sum of $\operatorname{MEX}$ of all resulting bi-tables can be?

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first line of the description of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the number of columns in the bi-table.

Each of the next two lines contains a binary string of length $n$ — the rows of the bi-table.

It's guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print a single integer — the maximal sum of $\operatorname{MEX}$ of all bi-tables that it is possible to get by cutting the given bi-table optimally.

## Example

### Input


```text
4
7
0101000
1101100
5
01100
10101
2
01
01
6
000000
111111
```
### Output


```text
8
8
2
12
```
## Note

In the first test case you can cut the bi-table as follows:

* $\begin{bmatrix} 0\\\ 1 \end{bmatrix}$, its $\operatorname{MEX}$ is $2$.
* $\begin{bmatrix} 10\\\ 10 \end{bmatrix}$, its $\operatorname{MEX}$ is $2$.
* $\begin{bmatrix} 1\\\ 1 \end{bmatrix}$, its $\operatorname{MEX}$ is $0$.
* $\begin{bmatrix} 0\\\ 1 \end{bmatrix}$, its $\operatorname{MEX}$ is $2$.
* $\begin{bmatrix} 0\\\ 0 \end{bmatrix}$, its $\operatorname{MEX}$ is $1$.
* $\begin{bmatrix} 0\\\ 0 \end{bmatrix}$, its $\operatorname{MEX}$ is $1$.

The sum of $\operatorname{MEX}$ is $8$.



#### Tags 

#1000 #NOT OK #bitmasks #constructive_algorithms #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_16.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
