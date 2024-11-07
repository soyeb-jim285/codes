<h1 style='text-align: center;'> E. Great Grids</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An $n \times m$ grid of characters is called great if it satisfies these three conditions: 

* Each character is either 'A', 'B', or 'C'.
* Every $2 \times 2$ contiguous subgrid contains all three different letters.
* Any two cells that share a common edge contain different letters.

Let $(x,y)$ denote the cell in the $x$-th row from the top and $y$-th column from the left.

You want to construct a great grid that satisfies $k$ constraints. Each constraint consists of two cells, $(x_{i,1},y_{i,1})$ and $(x_{i,2},y_{i,2})$, that share exactly one corner. You want your great grid to have the same letter in cells $(x_{i,1},y_{i,1})$ and $(x_{i,2},y_{i,2})$.

Determine whether there exists a great grid satisfying all the constraints. 

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^3$). The description of the test cases follows.

The first line of each test case contains three integers, $n$, $m$, and $k$ ($2 \le n,m \le 2 \cdot 10^3$, $1 \le k \le 4 \cdot 10^3$).

Each of the next $k$ lines contains four integers, $x_{i,1}$, $y_{i,1}$, $x_{i,2}$, and $y_{i,2}$ ($1 \le x_{i,1} < x_{i,2} \le n$, $1 \le y_{i,1},y_{i,2} \le m$). It is guaranteed that either $(x_{i,2},y_{i,2}) = (x_{i,1}+1,y_{i,1}+1)$ or $(x_{i,2},y_{i,2}) = (x_{i,1}+1,y_{i,1}-1)$.

The pairs of cells are pairwise distinct, i.e. for all $1 \le i < j \le k$, it is not true that $x_{i,1} = x_{j,1}$, $y_{i,1} = y_{j,1}$, $x_{i,2} = x_{j,2}$, and $y_{i,2} = y_{j,2}$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^3$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $2 \cdot 10^3$.

It is guaranteed that the sum of $k$ over all test cases does not exceed $4 \cdot 10^3$.

### Output

For each test case, output "YES" if a great grid satisfying all the constraints exists and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
43 4 41 1 2 22 1 3 21 4 2 32 3 3 22 7 21 1 2 21 2 2 18 5 41 2 2 11 5 2 47 1 8 27 4 8 58 5 41 2 2 11 5 2 47 1 8 27 5 8 4
```
### Output

```text

YES
NO
YES
NO

```
## Note

In the first test case, the following great grid satisfies all the constraints: 

| B | A | B | C |
| --- | --- | --- | --- |
| C | B | C | A |
| A | C | A | B |



In the second test case, the two constraints imply that cells $(1,1)$ and $(2,2)$ have the same letter and cells $(1,2)$ and $(2,1)$ have the same letter, which makes it impossible for the only $2 \times 2$ subgrid to contain all three different letters.



#### Tags 

#2400 #NOT OK #2-sat #constructive_algorithms #dfs_and_similar #dsu #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_884_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
