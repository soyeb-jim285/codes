<h1 style='text-align: center;'> C. Corners</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a matrix consisting of $n$ rows and $m$ columns. Each cell of this matrix contains $0$ or $1$.

Let's call a square of size $2 \times 2$ without one corner cell an L-shape figure. In one operation you can take one L-shape figure, with at least one cell containing $1$ and replace all numbers in it with zeroes.

Find the maximum number of operations that you can do with the given matrix.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 500$) — the number of test cases. Then follow the descriptions of each test case.

The first line of each test case contains two integers $n$ and $m$ ($2 \leq n, m \leq 500$) — the size of the matrix.

Each of the following $n$ lines contains a binary string of length $m$ — the description of the matrix.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases does not exceed $1000$.

### Output

For each test case output the maximum number of operations you can do with the given matrix.

## Example

### Input


```text
44 31011110111103 41110011101112 200002 21111
```
### Output

```text

8
9
0
2

```
## Note

In the first testcase one of the optimal sequences of operations is the following (bold font shows l-shape figure on which operation was performed): 

* Matrix before any operation was performed:  

| 1 | 0 | 1 |
| --- | --- | --- |
| 1 | 1 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 0 |
* Matrix after $1$ operation was performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 0 |
* Matrix after $2$ operations were performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 1 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 1 | 0 |
* Matrix after $3$ operations were performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 1 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 1 | 0 |
* Matrix after $4$ operations were performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 1 | 0 |
* Matrix after $5$ operations were performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
* Matrix after $6$ operations were performed:  

| 1 | 0 | 0 |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 0 | 0 |
| 1 | 0 | 0 |
* Matrix after $7$ operations were performed:  

| 0 | 0 | 0 |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 0 | 0 |
| 1 | 0 | 0 |
* Matrix after $8$ operations were performed:  

| 0 | 0 | 0 |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 0 | 0 |
| 0 | 0 | 0 |

In the third testcase from the sample we can not perform any operation because the matrix doesn't contain any ones.

In the fourth testcase it does not matter which L-shape figure we pick in our first operation. We will always be left with single one. So we will perform $2$ operations.



#### Tags 

#1200 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_815_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
