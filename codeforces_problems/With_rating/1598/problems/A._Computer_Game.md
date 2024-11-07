<h1 style='text-align: center;'> A. Computer Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a computer game. Now he wants to complete the first level of this game.

A level is a rectangular grid of $2$ rows and $n$ columns. Monocarp controls a character, which starts in cell $(1, 1)$ — at the intersection of the $1$-st row and the $1$-st column.

Monocarp's character can move from one cell to another in one step if the cells are adjacent by side and/or corner. Formally, it is possible to move from cell $(x_1, y_1)$ to cell $(x_2, y_2)$ in one step if $|x_1 - x_2| \le 1$ and $|y_1 - y_2| \le 1$. Obviously, it is prohibited to go outside the grid.

There are traps in some cells. If Monocarp's character finds himself in such a cell, he dies, and the game ends.

To complete a level, Monocarp's character should reach cell $(2, n)$ — at the intersection of row $2$ and column $n$.

Help Monocarp determine if it is possible to complete the level.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Then the test cases follow. Each test case consists of three lines.

The first line contains a single integer $n$ ($3 \le n \le 100$) — the number of columns.

The next two lines describe the level. The $i$-th of these lines describes the $i$-th line of the level — the line consists of the characters '0' and '1'. The character '0' corresponds to a safe cell, the character '1' corresponds to a trap cell.

Additional constraint on the input: cells $(1, 1)$ and $(2, n)$ are safe.

### Output

For each test case, output YES if it is possible to complete the level, and NO otherwise.

## Example

### Input


```text
4
3
000
000
4
0011
1100
4
0111
1110
6
010101
101010
```
### Output


```text
YES
YES
NO
YES
```
## Note

Consider the example from the statement.

In the first test case, one of the possible paths is $(1, 1) \rightarrow (2, 2) \rightarrow (2, 3)$.

In the second test case, one of the possible paths is $(1, 1) \rightarrow (1, 2) \rightarrow (2, 3) \rightarrow (2, 4)$.

In the fourth test case, one of the possible paths is $(1, 1) \rightarrow (2, 2) \rightarrow (1, 3) \rightarrow (2, 4) \rightarrow (1, 5) \rightarrow (2, 6)$.



#### Tags 

#800 #NOT OK #brute_force #dfs_and_similar #dp #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_115_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
