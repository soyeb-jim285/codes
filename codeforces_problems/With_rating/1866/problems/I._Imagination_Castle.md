<h1 style='text-align: center;'> I. Imagination Castle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Given a chessboard of size $N \times M$ ($N$ rows and $M$ columns). Each row is numbered from $1$ to $N$ from top to bottom and each column is numbered from $1$ to $M$ from left to right. The tile in row $r$ and column $c$ is denoted as $(r,c)$. There exists $K$ distinct special tiles on the chessboard with the $i$-th special tile being tile $(X_i,Y_i)$. It is guaranteed that tile $(1,1)$ is not a special tile.

A new chess piece has been invented, which is the castle. The castle moves similarly to a rook in regular chess, but slightly differently. In one move, a castle that is on some tile can only move to another tile in the same row or in the same column, but only in the right direction or the down direction. Formally, in one move, the castle on tile $(r,c)$ can only move to tile $(r',c')$ if and only if one of the following two conditions is satisfied: 

* $r'=r$ and $c'>c$.
* $c'=c$ and $r'>r$.

Chaneka and Bhinneka will play a game. In the beginning of the game, there is a castle in tile $(1,1)$. The two players will play alternatingly with Chaneka going first. In one turn, the player on that turn must move the castle following the movement rules of the castle.

If a player moves the castle to a special tile on her turn, then that player wins the game and the game ends. If on a turn, the castle cannot be moved, the player on that turn loses and the game ends.

Given the size of the board and the locations of each special tile. Determine the winner of this game if Chaneka and Bhinneka plays optimally.

#### Input

The first line contains three integers $N$, $M$, and $K$ ($1 \leq N,M \leq 2 \cdot 10^5$; $0 \leq K \leq \min(N \times M - 1, 2\cdot10^5)$) — the size of the chessboard and the number of special tiles.

The $i$-th of the next $K$ lines contains two integers $X_i$ and $Y_i$ ($1\leq X_i\leq N$; $1\leq Y_i\leq M$; $(X_i, Y_i) \neq (1,1)$) — the location of each special tile. The special tiles are pairwise distinct.

#### Output

#### Output

 Chaneka if Chaneka is the winner, output Bhinneka if Bhinneka is the winner.

## Examples

#### Input


```text
4 5 3
1 3
4 4
1 5
```
#### Output


```text
Chaneka
```
#### Input


```text
2 2 0
```
#### Output


```text
Bhinneka
```
## Note

In the first example, the following is an illustration of the chessboard in the beginning of the game.

 ![](images/79d24bd8ddccf79aeff668801c8cbaf6702a596e.png)

Chaneka can move the castle to special tile $(1,3)$ or $(1,5)$ directly on her first turn. Therefore, Chaneka is the winner.

In the second example, the following is an illustration of the chessboard in the beginning of the game.

 ![](images/a32630fbfbf586a6f7dcb0a15f5322477ba8cbdf.png)

Chaneka can only move the castle to tile $(1, 2)$ or $(2, 1)$ on her first turn. Whatever Chaneka does, Bhinneka will be able to directly move the castle to tile $(2, 2)$. After that, on Chaneka's turn, she cannot move the castle, so Chaneka loses. Therefore, Bhinneka is the winner.



#### Tags 

#2300 #NOT OK #dp #games #two_pointers 

## Blogs
- [All Contest Problems](../COMPFEST_15_-_Preliminary_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
