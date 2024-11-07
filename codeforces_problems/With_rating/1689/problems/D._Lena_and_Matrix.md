<h1 style='text-align: center;'> D. Lena and Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lena is a beautiful girl who likes logical puzzles.

As a gift for her birthday, Lena got a matrix puzzle!

The matrix consists of $n$ rows and $m$ columns, and each cell is either black or white. The coordinates $(i,j)$ denote the cell which belongs to the $i$-th row and $j$-th column for every $1\leq i \leq n$ and $1\leq j \leq m$. To solve the puzzle, Lena has to choose a cell that minimizes the Manhattan distance to the farthest black cell from the chosen cell.

More formally, let there be $k \ge 1$ black cells in the matrix with coordinates $(x_i,y_i)$ for every $1\leq i \leq k$. Lena should choose a cell $(a,b)$ that minimizes $$\max_{i=1}^{k}(|a-x_i|+|b-y_i|).$$

As Lena has no skill, she asked you for help. Will you tell her the optimal cell to choose? 

### Input

There are several test cases in the input data. The first line contains a single integer $t$ ($1\leq t\leq 10\,000$) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains two integers $n$ and $m$ ($2\leq n,m \leq 1000$)  — the dimensions of the matrix. 

The following $n$ lines contain $m$ characters each, each character is either 'W' or 'B'. The $j$-th character in the $i$-th of these lines is 'W' if the cell $(i,j)$ is white, and 'B' if the cell $(i,j)$ is black. 

It is guaranteed that at least one black cell exists.

It is guaranteed that the sum of $n\cdot m$ does not exceed $10^6$.

### Output

For each test case, output the optimal cell $(a,b)$ to choose. If multiple answers exist, output any.

## Example

### Input


```text
5
3 2
BW
WW
WB
3 3
WWB
WBW
BWW
2 3
BBB
BBB
5 5
BWBWB
WBWBW
BWBWB
WBWBW
BWBWB
9 9
WWWWWWWWW
WWWWWWWWW
BWWWWWWWW
WWWWWWWWW
WWWWBWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWB
```
### Output


```text

2 1
2 2
1 2
3 3
6 5
```
## Note

In the first test case the two black cells have coordinates $(1,1)$ and $(3,2)$. The four optimal cells are $(1,2)$, $(2,1)$, $(2,2)$ and $(3,1)$. It can be shown that no other cell minimizes the maximum Manhattan distance to every black cell.

In the second test case it is optimal to choose the black cell $(2,2)$ with maximum Manhattan distance being $2$.



#### Tags 

#1900 #NOT OK #data_structures #dp #geometry #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_798_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
