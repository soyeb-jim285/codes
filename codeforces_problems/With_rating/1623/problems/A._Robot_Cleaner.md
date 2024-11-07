<h1 style='text-align: center;'> A. Robot Cleaner</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A robot cleaner is placed on the floor of a rectangle room, surrounded by walls. The floor consists of $n$ rows and $m$ columns. The rows of the floor are numbered from $1$ to $n$ from top to bottom, and columns of the floor are numbered from $1$ to $m$ from left to right. The cell on the intersection of the $r$-th row and the $c$-th column is denoted as $(r,c)$. The initial position of the robot is $(r_b, c_b)$.

In one second, the robot moves by $dr$ rows and $dc$ columns, that is, after one second, the robot moves from the cell $(r, c)$ to $(r + dr, c + dc)$. Initially $dr = 1$, $dc = 1$. If there is a vertical wall (the left or the right walls) in the movement direction, $dc$ is reflected before the movement, so the new value of $dc$ is $-dc$. And if there is a horizontal wall (the upper or lower walls), $dr$ is reflected before the movement, so the new value of $dr$ is $-dr$.

Each second (including the moment before the robot starts moving), the robot cleans every cell lying in the same row or the same column as its position. There is only one dirty cell at $(r_d, c_d)$. The job of the robot is to clean that dirty cell.

 ![](images/3a0c942b8d905097abe13526d377911fc3e3f3fa.png) Illustration for the first example. The blue arc is the robot. The red star is the target dirty cell. Each second the robot cleans a row and a column, denoted by yellow stripes. Given the floor size $n$ and $m$, the robot's initial position $(r_b, c_b)$ and the dirty cell's position $(r_d, c_d)$, find the time for the robot to do its job.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

A test case consists of only one line, containing six integers $n$, $m$, $r_b$, $c_b$, $r_d$, and $c_d$ ($1 \le n, m \le 100$, $1 \le r_b, r_d \le n$, $1 \le c_b, c_d \le m$) — the sizes of the room, the initial position of the robot and the position of the dirt cell.

### Output

For each test case, print an integer — the time for the robot to clean the dirty cell. We can show that the robot always cleans the dirty cell eventually.

## Example

### Input


```text
5
10 10 6 1 2 8
10 10 9 9 1 1
9 8 5 6 2 1
6 9 2 2 5 8
2 2 1 1 2 1
```
### Output


```text
7
10
9
3
0
```
## Note

In the first example, the floor has the size of $10\times 10$. The initial position of the robot is $(6, 1)$ and the position of the dirty cell is $(2, 8)$. See the illustration of this example in the problem statement.

In the second example, the floor is the same, but the initial position of the robot is now $(9, 9)$, and the position of the dirty cell is $(1, 1)$. In this example, the robot went straight to the dirty cell and clean it. 

 ![](images/a10529aa44799540a984e17ba71ebcba84d6d151.png) In the third example, the floor has the size $9 \times 8$. The initial position of the robot is $(5, 6)$, and the position of the dirty cell is $(2, 1)$. 

 ![](images/16a71bf4954abc73a778fbab1a99d594b4630114.png) In the fourth example, the floor has the size $6 \times 9$. The initial position of the robot is $(2, 2)$ and the position of the dirty cell is $(5, 8)$. 

 ![](images/9c982bcf1b1183e35433ff946101ae129635ed9d.png) In the last example, the robot was already standing in the same column as the dirty cell, so it can clean the cell right away. 

 ![](images/9482250e04383ce58d89f7499687aa49285ad8e6.png) 

#### Tags 

#800 #NOT OK #brute_force #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_763_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
