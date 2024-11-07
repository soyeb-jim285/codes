<h1 style='text-align: center;'> F. Vova Escapes the Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Following a world tour, Vova got himself trapped inside an $n \times m$ matrix. Rows of this matrix are numbered by integers from $1$ to $n$ from top to bottom, and the columns are numbered by integers from $1$ to $m$ from left to right. The cell $(i, j)$ is the cell on the intersection of row $i$ and column $j$ for $1 \leq i \leq n$ and $1 \leq j \leq m$.

Some cells of this matrix are blocked by obstacles, while all other cells are empty. Vova occupies one of the empty cells. It is guaranteed that cells $(1, 1)$, $(1, m)$, $(n, 1)$, $(n, m)$ (that is, corners of the matrix) are blocked.

Vova can move from one empty cell to another empty cell if they share a side. Vova can escape the matrix from any empty cell on the boundary of the matrix; these cells are called exits.

Vova defines the type of the matrix based on the number of exits he can use to escape the matrix: 

* The $1$-st type: matrices with no exits he can use to escape.
* The $2$-nd type: matrices with exactly one exit he can use to escape.
* The $3$-rd type: matrices with multiple (two or more) exits he can use to escape.

Before Vova starts moving, Misha can create more obstacles to block more cells. However, he cannot change the type of the matrix. What is the maximum number of cells Misha can block, so that the type of the matrix remains the same? Misha cannot block the cell Vova is currently standing on.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10\,000$). The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($3 \leq n,m \leq 1000$) — the dimensions of the matrix.

The next $n$ lines contain the description of the matrix: the $i$-th ($1 \le i \le n$) of them contains a string of length $m$, consisting of characters '.', '#', and 'V'. The $j$-th character of the $i$-th line describes the cell $(i, j)$ of the matrix. The dot '.' denotes an empty cell, the sharp '#' denotes a blocked cell, and the letter 'V' denotes an empty cell where Vova initially is.

It is guaranteed that the corners of the matrix are blocked (the first and the last characters of the first and the last lines of the matrix description are '#'). It is guaranteed that the letter 'V' appears in the matrix description exactly once.

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $1\,000\,000$.

## Output

For each test case, output a single integer — the maximum number of cells Misha may block.

## Example

## Input


```

84 4#..#..V.....#..#3 6#.#####....#####V#3 3####V####6 5#.####...####.##V..##.#####..#7 5######.V.##.#.##.#.##.#.##...##.#.#3 7#.....#.#####.#...V.#5 8####.####..V#..##...#..##...##.####.####5 5#...###.####V####.###...#
```
## Output


```

9
0
0
3
4
10
12
5

```
## Note

In the first test case, the matrix is of the $3$-rd type. Misha can create obstacles in all empty cells except the cells $(1, 3)$, $(2, 3)$, $(2, 4)$. There are $9$ such cells, and adding such obstacles does not change the type of the matrix.

In the second test case, the matrix is of the $3$-rd type. Blocking any cell changes the matrix type to the $2$-nd: one of the two exits will become unavailable for Vova. Thus, the answer is $0$.

In the third test case, the matrix is of the $1$-st type. No free cell exists (besides Vova's), so Misha cannot block any cell.

In the fourth test case, the matrix is of the $2$-nd type. Misha can create $3$ obstacles in cells $(5, 2)$, $(6, 3)$, $(6, 4)$ without changing the type of the matrix.

In the fifth test case, the matrix is of the $3$-rd type. Misha can create $4$ obstacles in cells $(2, 2)$, $(3, 2)$, $(4, 2)$, $(5, 2)$ or $4$ obstacles in cells $(2, 4)$, $(3, 4)$, $(4, 4)$, $(5, 4)$ without changing the type of the matrix.



#### tags 

#2600 #brute_force #dfs_and_similar #divide_and_conquer #shortest_paths 