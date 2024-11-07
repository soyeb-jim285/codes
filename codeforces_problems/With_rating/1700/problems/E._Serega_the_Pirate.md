<h1 style='text-align: center;'> E. Serega the Pirate</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little pirate Serega robbed a ship with puzzles of different kinds. Among all kinds, he liked only one, the hardest.

A puzzle is a table of $n$ rows and $m$ columns, whose cells contain each number from $1$ to $n \cdot m$ exactly once.

To solve a puzzle, you have to find a sequence of cells in the table, such that any two consecutive cells are adjacent by the side in the table. The sequence can have arbitrary length and should visit each cell one or more times. For a cell containing the number $i$, denote the position of the first occurrence of this cell in the sequence as $t_i$. The sequence solves the puzzle, if $t_1 < t_2 < \dots < t_{nm}$. In other words, the cell with number $x$ should be first visited before the cell with number $x + 1$ for each $x$.

Let's call a puzzle solvable, if there exists at least one suitable sequence.

In one move Serega can choose two arbitrary cells in the table (not necessarily adjacent by the side) and swap their numbers. He would like to know the minimum number of moves to make his puzzle solvable, but he is too impatient. Thus, please tell if the minimum number of moves is $0$, $1$, or at least $2$. In the case, where $1$ move is required, please also find the number of suitable cell pairs to swap.

##### Input

In the first line there are two whole positive numbers $n, m$ ($1 \leq n\cdot m \leq 400\,000$) — table dimensions.

In the next $n$ lines there are $m$ integer numbers $a_{i1}, a_{i2}, \dots, a_{im}$ ($1 \le a_{ij} \le nm$). 

It is guaranteed that every number from $1$ to $nm$ occurs exactly once in the table.

##### Output

Let $a$ be the minimum number of moves to make the puzzle solvable.

If $a = 0$, print $0$.

If $a = 1$, print $1$ and the number of valid swaps.

If $a \ge 2$, print $2$. 

## Examples

##### Input


```text
3 3
2 1 3
6 7 4
9 8 5
```
##### Output


```text
0
```
##### Input


```text
2 3
1 6 4
3 2 5
```
##### Output


```text
1 3
```
##### Input


```text
1 6
1 6 5 4 3 2
```
##### Output


```text
2
```
## Note

In the first example the sequence $(1, 2), (1, 1), (1, 2), (1, 3), (2, 3), (3, 3)$, $(2, 3), (1, 3), (1, 2), (1, 1), (2, 1), (2, 2), (3, 2), (3, 1)$ solves the puzzle, so the answer is $0$.

The puzzle in the second example can't be solved, but it's solvable after any of three swaps of cells with values $(1, 5), (1, 6), (2, 6)$. 

The puzzle from the third example requires at least two swaps, so the answer is $2$.



#### Tags 

#2600 #NOT OK #brute_force #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_802_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
