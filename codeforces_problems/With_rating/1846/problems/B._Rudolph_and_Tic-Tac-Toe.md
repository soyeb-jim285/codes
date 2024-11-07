<h1 style='text-align: center;'> B. Rudolph and Tic-Tac-Toe</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rudolph invented the game of tic-tac-toe for three players. It has classic rules, except for the third player who plays with pluses. Rudolf has a $3 \times 3$ field  — the result of the completed game. Each field cell contains either a cross, or a nought, or a plus sign, or nothing. The game is won by the player who makes a horizontal, vertical or diagonal row of $3$'s of their symbols.

Rudolph wants to find the result of the game. Either exactly one of the three players won or it ended in a draw. It is guaranteed that multiple players cannot win at the same time.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of three lines, each of which consists of three characters. The symbol can be one of four: "X" means a cross, "O" means a nought, "+" means a plus, "." means an empty cell.

### Output

For each test case, print the string "X" if the crosses won, "O" if the noughts won, "+" if the pluses won, "DRAW" if there was a draw.

## Example

### Input


```text
5+X+OXOOX.O+.+OXX+O.XOOX.+++O.+X.O+...++X.O+..
```
### Output

```text

X
O
+
DRAW
DRAW

```


#### Tags 

#800 #OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_883_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
