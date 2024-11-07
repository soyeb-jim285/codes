<h1 style='text-align: center;'> J. Pawns</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an infinite chessboard, divided into cells. The cell $(x, y)$ is the cell on the intersection of the $x_i$-th row and $y_i$-th column. $n$ black pawns are placed on the board, the $i$-th black pawn occupies the cell $(x_i, y_i)$.

You want to capture all black pawns. In order to do so, you may perform the following actions:

* place a white pawn into any empty cell (any cell having integer coordinates can be chosen, as long as it doesn't contain any pawns);
* make a move with one of the white pawns according to the chess rules.

Recall that when you make a move with a white pawn in the cell $(x, y)$, the chess rules allow you to choose exactly one of these actions: 

* if there is a black pawn in the cell $(x + 1, y - 1)$, you can capture it — the black pawn is removed from the board, and the white pawn moves to $(x + 1, y - 1)$;
* if there is a black pawn in the cell $(x + 1, y + 1)$, you can capture it — the black pawn is removed from the board, and the white pawn moves to $(x + 1, y + 1)$;
* if the cell $(x + 1, y)$ is empty, you can move the white pawn to that cell.

You may perform any finite sequence of actions (placing white pawns and moving them). You want to capture all of the black pawns, and it can be shown that it is always possible; and you want to do it placing as few white pawns as possible.

What is the minimum number of white pawns you have to place to capture all $n$ black pawns?

##### Input

The first line contains one integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the number of black pawns.

Then $n$ lines follow. The $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le 5 \cdot 10^5$) denoting a black pawn in the cell $(x_i, y_i)$. No cell is occupied by two or more black pawns.

##### Output

Print one integer — the minimum number of white pawns you have to place to capture all $n$ black pawns.

## Examples

##### Input


```text
3
1 1
5 1
2 2
```
##### Output


```text
1
```
##### Input


```text
3
3 2
1 3
1 1
```
##### Output


```text
2
```
##### Input


```text
2
1 1
2 2
```
##### Output


```text
1
```


#### Tags 

#NOT OK #*special 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_7.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
