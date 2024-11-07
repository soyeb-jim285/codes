<h1 style='text-align: center;'> C. Peaceful Rooks</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a $n \times n$ chessboard. Rows and columns of the board are numbered from $1$ to $n$. Cell $(x, y)$ lies on the intersection of column number $x$ and row number $y$.

Rook is a chess piece, that can in one turn move any number of cells vertically or horizontally. There are $m$ rooks ($m < n$) placed on the chessboard in such a way that no pair of rooks attack each other. I.e. there are no pair of rooks that share a row or a column.

In one turn you can move one of the rooks any number of cells vertically or horizontally. Additionally, it shouldn't be attacked by any other rook after movement. What is the minimum number of moves required to place all the rooks on the main diagonal?

The main diagonal of the chessboard is all the cells $(i, i)$, where $1 \le i \le n$.

## Input

The first line contains the number of test cases $t$ ($1 \leq t \leq 10^3$). Description of the $t$ test cases follows.

The first line of each test case contains two integers $n$ and $m$ — size of the chessboard and the number of rooks ($2 \leq n \leq 10^5$, $1 \leq m < n$). Each of the next $m$ lines contains two integers $x_i$ and $y_i$ — positions of rooks, $i$-th rook is placed in the cell $(x_i, y_i)$ ($1 \leq x_i, y_i \leq n$). It's guaranteed that no two rooks attack each other in the initial placement.

The sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each of $t$ test cases print a single integer — the minimum number of moves required to place all the rooks on the main diagonal.

It can be proved that this is always possible.

## Example

## Input


```

4
3 1
2 3
3 2
2 1
1 2
5 3
2 3
3 1
1 2
5 4
4 5
5 1
2 2
3 3

```
## Output


```

1
3
4
2

```
## Note

Possible moves for the first three test cases:

1. $(2, 3) \to (2, 2)$
2. $(2, 1) \to (2, 3)$, $(1, 2) \to (1, 1)$, $(2, 3) \to (2, 2)$
3. $(2, 3) \to (2, 4)$, $(2, 4) \to (4, 4)$, $(3, 1) \to (3, 3)$, $(1, 2) \to (1, 1)$


#### tags 

#1700 #dfs_and_similar #dsu #graphs 