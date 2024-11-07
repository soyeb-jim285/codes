<h1 style='text-align: center;'> A. Chess Placing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a chessboard of size 1 × *n*. It is guaranteed that *n* is even. The chessboard is painted like this: "BWBW...BW".

Some cells of the board are occupied by the chess pieces. Each cell contains no more than one chess piece. It is known that the total number of pieces equals to ![](images/a64c1b2df604f8cfa9acf6716a3cc1424488361e.png).

In one step you can move one of the pieces one cell to the left or to the right. You cannot move pieces beyond the borders of the board. You also cannot move pieces to the cells that are already occupied.

Your task is to place all the pieces in the cells of the same color using the minimum number of moves (all the pieces must occupy only the black cells or only the white cells after all the moves are made).

#### Input

The first line of the input contains one integer *n* (2 ≤ *n* ≤ 100, *n* is even) — the size of the chessboard. 

The second line of the input contains ![](images/a64c1b2df604f8cfa9acf6716a3cc1424488361e.png) integer numbers ![](images/e2af9e0bc529157633221e52aefff46b28281af2.png) (1 ≤ *p**i* ≤ *n*) — initial positions of the pieces. It is guaranteed that all the positions are distinct.

#### Output

Print one integer — the minimum number of moves you have to make to place all the pieces in the cells of the same color.

## Examples

#### Input


```text
6  
1 2 6  

```
#### Output


```text
2  

```
#### Input


```text
10  
1 2 3 4 5  

```
#### Output


```text
10  

```
## Note

In the first example the only possible strategy is to move the piece at the position 6 to the position 5 and move the piece at the position 2 to the position 3. Notice that if you decide to place the pieces in the white cells the minimum number of moves will be 3.

In the second example the possible strategy is to move ![](images/e1e06f6a15cce30628c7a2360c4ffa57a8ba0ebd.png) in 4 moves, then ![](images/c84dfbe0c6a917b45fc3f69467c256c4ac460eeb.png) in 3 moves, ![](images/598731d81393332209d914cb0bbe97d8566c887d.png) in 2 moves and ![](images/29f71c065c3536e88b54429c734103ad3604f68b.png) in 1 move.



#### Tags 

#1100 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_44_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
