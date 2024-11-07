<h1 style='text-align: center;'> F. Robot on the Board 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The robot is located on a checkered rectangular board of size $n \times m$ ($n$ rows, $m$ columns). The rows in the board are numbered from $1$ to $n$ from top to bottom, and the columns — from $1$ to $m$ from left to right.

The robot is able to move from the current cell to one of the four cells adjacent by side.

Each cell has one of the symbols 'L', 'R', 'D' or 'U' written on it, indicating the direction in which the robot will move when it gets in that cell — left, right, down or up, respectively.

The robot can start its movement in any cell. He then moves to the adjacent square in the direction indicated on the current square in one move. 

* If the robot moves beyond the edge of the board, it falls and breaks.
* If the robot appears in the cell it already visited before, it breaks (it stops and doesn't move anymore).

Robot can choose any cell as the starting cell. Its goal is to make the maximum number of steps before it breaks or stops.

Determine from which square the robot should start its movement in order to execute as many commands as possible. A command is considered successfully completed if the robot has moved from the square on which that command was written (it does not matter whether to another square or beyond the edge of the board).

### Input

The first line contains an integer $t$ ($1 \le t \le 10000$) — the number of test cases in the test.

Each test case's description is preceded by a blank line. Next is a line that contains integers $n$ and $m$ ($1 \le n \le 2000$; $1 \le m \le 2000$) — the height and width of the board. This line followed by $n$ lines, the $i$-th of which describes the $i$-th line of the board. Each of them is exactly $m$ letters long and consists of symbols 'L', 'R', 'D' and 'U'.

It is guaranteed that the sum of sizes of all boards in the input does not exceed $4\cdot10^6$.

### Output

For each test case, output three integers $r$, $c$ and $d$ ($1 \le r \le n$; $1 \le c \le m$; $d \ge 0$), which denote that the robot should start moving from cell $(r, c)$ to make the maximum number of moves $d$. If there are several answers, output any of them.

## Example

### Input


```text
7

1 1
R

1 3
RRL

2 2
DL
RU

2 2
UD
RU

3 2
DL
UL
RU

4 4
RRRD
RUUD
URUD
ULLR

4 4
DDLU
RDDU
UUUU
RDLD
```
### Output


```text
1 1 1
1 1 3
1 1 4
2 1 3
3 1 5
4 3 12
1 1 4
```


#### Tags 

#2300 #NOT OK #brute_force #dfs_and_similar #graphs #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_753_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
