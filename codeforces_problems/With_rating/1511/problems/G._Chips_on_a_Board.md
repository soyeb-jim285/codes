<h1 style='text-align: center;'> G. Chips on a Board</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Alice and Bob have a rectangular board consisting of $n$ rows and $m$ columns. Each row contains exactly one chip.

Alice and Bob play the following game. They choose two integers $l$ and $r$ such that $1 \le l \le r \le m$ and cut the board in such a way that only the part of it between column $l$ and column $r$ (inclusive) remains. So, all columns to the left of column $l$ and all columns to the right of column $r$ no longer belong to the board.

After cutting the board, they move chips on the remaining part of the board (the part from column $l$ to column $r$). They make alternating moves, and the player which cannot make a move loses the game. The first move is made by Alice, the second — by Bob, the third — by Alice, and so on. During their move, the player must choose one of the chips from the board and move it any positive number of cells to the left (so, if the chip was in column $i$, it can move to any column $j < i$, and the chips in the leftmost column cannot be chosen).

Alice and Bob have $q$ pairs of numbers $L_i$ and $R_i$. For each such pair, they want to determine who will be the winner of the game if $l = L_i$ and $r = R_i$. Note that these games should be considered independently (they don't affect the state of the board for the next games), and both Alice and Bob play optimally.

### Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the number of rows and columns on the board, respectively.

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le m$), where $c_i$ is the index of the column where the chip in the $i$-th row is located (so, the chip in the $i$-th row is in the $c_i$-th column).

The third line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Then $q$ lines follow, the $i$-th of them contains two integers $L_i$ and $R_i$ ($1 \le L_i \le R_i \le m$).

### Output

Print a string of $q$ characters. The $i$-th character should be A if Alice wins the game with $l = L_i$ and $r = R_i$, or B if Bob wins it.

## Example

### Input


```text
8 10
1 3 3 7 4 2 6 9
7
2 3
1 3
1 4
1 10
5 10
8 10
9 10
```
### Output


```text

BAAAAAB
```


#### Tags 

#2700 #NOT OK #bitmasks #brute_force #data_structures #dp #games #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_107_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
