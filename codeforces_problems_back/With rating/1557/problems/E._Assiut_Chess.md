<h1 style='text-align: center;'> E. Assiut Chess</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

ICPC Assiut Community decided to hold a unique chess contest, and you were chosen to control a queen and hunt down the hidden king, while a member of ICPC Assiut Community controls this king.

You compete on an $8\times8$ chessboard, the rows are numerated from top to bottom, and the columns are numerated left to right, and the cell in row $x$ and column $y$ is denoted as $(x, y)$.

In one turn you can move the queen to any of the squares on the same horizontal line, vertical line, or any of the diagonals. For example, if the queen was on square ($4$, $5$), you can move to ($q_1$, $5$), ($4$, $q_1$), ($q_1$, $9-q_1$), or ($q_2$, $q_2+1$) where ($1 \le q_1 \le 8$, $q_1 \ne 4$, $1 \le q_2 \le 7$, $q_2 \ne 4$). ## Note

 that the queen cannot stay on its current cell. 

 ![](images/5e4bc8c949899239c929fbdda140cde07899f590.png) In one turn, the king can move "Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", or "Up-Right" such that he doesn't get out of the board. The king cannot move into a cell that is on the same row, column or diagonal with the queen (including the position of the queen itself). For example, if the king was on square ($4$, $5$), he can move to ($4+k_1$, $5+k_2$) where ($-1 \le k_1,k_2 \le 1$, $(k_1, k_2) \ne (0, 0)$). 

 ![](images/54c5bd15b305dbc63040afd3cb06a99eafda6987.png) At the start of the game, you should place the queen at any location on the board, and this is done once per game. After that the king is secretly placed at any cell different from the queen's location. You do not know the position of the king. Then, the king and the queen take turns with the king moving first. The king moves to one of the possible directions ("Right", "Down", "Up-Left", etc.), and you are only given the direction it moves to. After that, you should move your queen by declaring the square to which your queen will move. The game follows like this until you win the game or run out of moves.

You win if the king has no valid moves. You lose if after $130$ moves of the queen the king still has valid moves.

## Input

The first line contains a single integer $t$ ($1 \le t \le 60$) — the number of test cases.

## Interaction

In each test case, you should print the queen's starting cell immediately. If you placed the queen at the king's cell, you will win immediately.

After that, you may make at most $130$ moves. Each move is made in the format $x$ $y$, where $x$ and $y$ are two integers ($1 \leq x,y \leq 8$) that denote the new row and column of the queen respectively. Your move should be a valid queen move.

After the initial queen placement and after each move you will receive a string $s$ that represents the direction of the king's move. It will be one of the following: "Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right", or "Done" if you win the game. You should consider "Done" as the end of each test case.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

If at any point you make an invalid query or try to make more than $130$ queries for each test case, the game will terminate immediately and you will receive a Wrong Answer verdict.

## Example

## Input


```

1
Left
Right
Done
```
Output
```

7 5
7 6
7 7
```
## Note

In the example, the hidden king was at $(8, 8)$ at the start. The game follows like this:

 ![](images/99f3092f4355895434543a63ed44c8a3a403df9f.png)  ![](images/e7a9d1db3b81b31c5ded75dbd41669e3686de370.png) 

#### tags 

#2800 #brute_force #constructive_algorithms #interactive 