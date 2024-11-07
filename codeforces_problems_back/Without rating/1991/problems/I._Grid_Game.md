<h1 style='text-align: center;'> I. Grid Game</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

You are given a grid with $n$ rows and $m$ columns. You need to fill each cell with a unique integer from $1$ to $n \cdot m$.

After filling the grid, you will play a game on this grid against the interactor. Players take turns selecting one of the previously unselected cells from the grid, with the interactor going first.

On the first turn, the interactor can choose any cell from the grid. After that, any chosen cell must be orthogonally adjacent to at least one previously selected cell. Two cells are considered orthogonally adjacent if they share an edge. The game continues until all cells have been selected.

Your goal is to let the sum of numbers in the cells selected by you be strictly less than the sum of numbers in the cells selected by the interactor.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The only line of each test case contains two integers $n$ and $m$ ($4 \le n, m \le 10$) — the number of rows and columns in the grid.

## Interaction

First, output $n$ lines, each containing $m$ integers, representing the integers that you filled in the grid. Each integer from $1$ to $n \cdot m$ should appear exactly once.

Then, the game begins. The interactor and you take turns outputting coordinates to select a cell for $n \times m$ turns, with the interactor starting first.

On each player's (either you or the interactor) turn, the player will output two integers $i$ and $j$ ($1 \le i \le n$, $1 \le j \le m$), denoting that the player has selected the cell on the $i$-th row and $j$-th column. This cell should not have been selected in a previous round. Additionally, if it is not the first turn, the cell must be orthogonally adjacent to at least one previously selected cell.

If any of your outputs are invalid, the jury will output "-1" and you will receive a Wrong Answer verdict.

At the end of all $n \cdot m$ turns, if the sum of numbers in the cells selected by you is not strictly less than the sum of numbers in the cells selected by the interactor, the jury will output "-1" and you will receive a Wrong Answer verdict.

If your program has received a Wrong Answer verdict, it must terminate immediately. Otherwise, you may receive an arbitrary verdict because your solution might be reading from a closed stream.

After outputting, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

In this problem, hacks are disabled.

## Example

## Input


```

1
4 4




3 4

4 4

4 2

4 1

1 4

1 2

2 2

2 1


```
Output
```



2 3 4 10
12 6 11 15
5 13 16 8
9 7 1 14

2 4

4 3

3 3

3 1

1 3

1 1

2 3

3 2
```
## Note

## Note

 that this is an example game and does not necessarily represent the optimal strategy for both players.

First, we fill a $4 \times 4$ grid with unique integers from $1$ to $16$ in the following way:

 

| $2$ | $3$ | $4$ | $10$ |
| --- | --- | --- | --- |
| $12$ | $6$ | $11$ | $15$ |
| $5$ | $13$ | $16$ | $8$ |
| $9$ | $7$ | $1$ | $14$ |

 Next, the game begins.

1. The interactor first selects $(3, 4)$, which is the number $8$. For this selection, the interactor could choose any number. From the next selection onwards, each chosen number has to be adjacent to any previously selected number.
2. We select $(2, 4)$, which is the number $15$, adjacent to $(3, 4)$.
3. The interactor selects $(4, 4)$, which is the number $14$, adjacent to $(3, 4)$.
4. We select $(4, 3)$, which is the number $1$, adjacent to $(4, 4)$.
5. $\ldots$
6. This is continued until all numbers are selected.

In the end, the numbers we selected were $[15, 1, 16, 5, 4, 2, 11, 13]$, and the numbers selected by the interactor were $[8, 14, 7, 9, 10, 3, 6, 12]$. The sum of the numbers we selected is $67$, which is less than the sum of the numbers selected by the interactor $69$. Therefore, we have won this game.



#### tags 

#constructive_algorithms #games #greedy #interactive 