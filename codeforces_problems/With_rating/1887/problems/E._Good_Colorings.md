<h1 style='text-align: center;'> E. Good Colorings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice suggested Bob to play a game. Bob didn't like this idea, but he couldn't refuse Alice, so he asked you to write a program that would play instead of him.

The game starts with Alice taking out a grid sheet of size $n \times n$, the cells of which are initially not colored. After that she colors some $2n$ cells with colors $1,2,\ldots, 2n$, respectively, and informs Bob about these cells.

In one move, Bob can point to a cell that has not been colored yet and ask Alice to color that cell. Alice colors that cell with one of the $2n$ colors of her choice, informing Bob of the chosen color. Bob can make no more than $10$ moves, after which he needs to find a good set of four cells.

A set of four cells is considered good if the following conditions are met:

* All the cells in the set are colored;
* No two cells in the set are colored with the same color;
* The centers of the cells form a rectangle with sides parallel to the grid lines.
### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 200$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 1000$) — the size of the grid.

The $i$-th of the following $2n$ lines contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$) — the coordinates of the cell colored with the $i$-th color.

It is guaranteed that all coordinates $(x_i, y_i)$ are pairwise distinct for the same test case.

After reading the input data for each test case, continue the interaction as described below.

## Interaction

You can make no more than $10$ moves. To make a move, output "? $x$ $y$" ($1 \leq x,y \leq n$). In response to this, the jury's program will output a single integer from $1$ to $2n$ — the color of cell $(x,y)$.

After all moves (it is not necessary to make all $10$ moves and it is not necessary to make at least one move), output a string in the format "! $x_1$ $x_2$ $y_1$ $y_2$" ($1 \leq x_1, x_2, y_1, y_2 \leq n, x_1 \ne x_2, y_1 \ne y_2$). If cells $(x_1, y_1)$, $(x_1, y_2)$, $(x_2, y_1)$, $(x_2, y_2)$ are colored with different colors, the jury's program will output "OK". After that, proceed to the next test case or terminate the program if there are no more test cases left.

Otherwise, if any of the specified cells are colored with the same color or one of the cells is not colored yet, the jury's program will output "ERROR". In this case, your program should immediately terminate its execution to receive the Wrong Answer verdict. Otherwise, you may receive an arbitrary verdict.

After each move or answer, do not forget to output the end of line and flush the output. Otherwise, you will get the Idleness limit exceeded verdict.

To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

## Note

 that the interactor is adaptive, meaning that the color Alice will use to color the cells during Bob's moves is not fixed in advance.

Hacks

You cannot use hacks in this problem.

## Example

### Input


```text
2
3
1 2
1 3
2 1
2 3
3 1
3 2

1

OK
3
1 1
1 2
1 3
2 1
2 2
2 3

OK
```
#Output
```text









? 1 1

! 1 2 1 3








! 1 2 1 2
```
## Note

In the first test case:

 ![](images/e12a5a1ac9b6f655a5b86fa130b6094da5300a1c.png) In the second test case, cells with coordinates $(1, 1), (1, 2), (2, 1), (2, 2)$ are initially colored by Alice in different colors.



#### Tags 

#3100 #NOT OK #binary_search #constructive_algorithms #graphs #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_905_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
