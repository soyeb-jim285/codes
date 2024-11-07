<h1 style='text-align: center;'> D. Two-Colored Dominoes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an $n\times m$ board divided into cells. There are also some dominoes on this board. Each domino covers two adjacent cells (that is, two cells that share a side), and no two dominoes overlap.

Piet thinks that this board is too boring and it needs to be painted. He will paint the cells of the dominoes black and white. He calls the painting beautiful if all of the following conditions hold:

* for each domino, one of its cells is painted white and the other is painted black;
* for each row, the number of black cells in this row equals the number of white cells in this row;
* for each column, the number of black cells in this column equals the number of white cells in this column.

## Note

 that the cells that are not covered by dominoes are not painted at all, they are counted as neither black nor white.

Help Piet produce a beautiful painting or tell that it is impossible.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2\le n, m\le 500$).

The next $n$ lines describe the tiling of the board, row by row from top to bottom. Each of these lines contains $m$ characters, describing the cells in the corresponding row from left to right. Each character is one of U, D, L, R, or ., meaning that the cell is covered with a top, bottom, left, right half of a domino or nothing, respectively. The tiling is guaranteed to be valid.

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $250\,000$.

### Output

For each test case, output a single integer $-1$ if a beautiful painting does not exist. Otherwise, print $n$ lines, each containing $m$ characters, describing the colors in the corresponding row of a beautiful painting. Every character corresponding to a cell not covered by a domino must be . (a dot), and all other characters must be B if the corresponding cell is black or W if it is white.

If there are multiple solutions, print any of them.

## Example

### Input


```text
34 6..LR..ULRU..DLRDUU..LRDD5 4.LR..UU.UDDUD..DLR..2 2....
```
### Output

```text

..WB..
WWBB..
BBWWWB
..BWBW
-1
..
..

```
## Note

In the first test case, the answer is illustrated below: 

 ![](images/da1745b7a1a29475483fe6b951c23b33470509eb.png) In the second test case, it is impossible to paint all cells the right way.



#### Tags 

#1400 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Pinely_Round_2_(Div._1_+_Div._2).md)
- [Pinely Round 2](../blogs/Pinely_Round_2.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
