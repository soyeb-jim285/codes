<h1 style='text-align: center;'> C. Gargari and Bishops</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gargari is jealous that his friend Caisa won the game from the previous problem. He wants to prove that he is a genius.

He has a *n* × *n* chessboard. Each cell of the chessboard has a number written on it. Gargari wants to place two bishops on the chessboard in such a way that there is no cell that is attacked by both of them. Consider a cell with number *x* written on it, if this cell is attacked by one of the bishops Gargari will get *x* dollars for it. Tell Gargari, how to place bishops on the chessboard to get maximum amount of money.

We assume a cell is attacked by a bishop, if the cell is located on the same diagonal with the bishop (the cell, where the bishop is, also considered attacked by it).

## Input

The first line contains a single integer *n* (2 ≤ *n* ≤ 2000). Each of the next *n* lines contains *n* integers *a**ij* (0 ≤ *a**ij* ≤ 109) — description of the chessboard.

## Output

On the first line print the maximal number of dollars Gargari will get. On the next line print four integers: *x*1, *y*1, *x*2, *y*2 (1 ≤ *x*1, *y*1, *x*2, *y*2 ≤ *n*), where *x**i* is the number of the row where the *i*-th bishop should be placed, *y**i* is the number of the column where the *i*-th bishop should be placed. Consider rows are numbered from 1 to *n* from top to bottom, and columns are numbered from 1 to *n* from left to right.

If there are several optimal solutions, you can print any of them.

## Examples

## Input


```
4  
1 1 1 1  
2 1 1 0  
1 1 1 0  
1 0 0 1  

```
## Output


```
12  
2 2 3 2  

```


#### tags 

#1900 #greedy #hashing #implementation 