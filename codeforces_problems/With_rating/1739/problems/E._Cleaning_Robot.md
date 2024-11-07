<h1 style='text-align: center;'> E. Cleaning Robot</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider a hallway, which can be represented as the matrix with $2$ rows and $n$ columns. Let's denote the cell on the intersection of the $i$-th row and the $j$-th column as $(i, j)$. The distance between the cells $(i_1, j_1)$ and $(i_2, j_2)$ is $|i_1 - i_2| + |j_1 - j_2|$.

There is a cleaning robot in the cell $(1, 1)$. Some cells of the hallway are clean, other cells are dirty (the cell with the robot is clean). You want to clean the hallway, so you are going to launch the robot to do this.

After the robot is launched, it works as follows. While at least one cell is dirty, the robot chooses the closest (to its current cell) cell among those which are dirty, moves there and cleans it (so the cell is no longer dirty). After cleaning a cell, the robot again finds the closest dirty cell to its current cell, and so on. This process repeats until the whole hallway is clean.

However, there is a critical bug in the robot's program. If at some moment, there are multiple closest (to the robot's current position) dirty cells, the robot malfunctions.

You want to clean the hallway in such a way that the robot doesn't malfunction. Before launching the robot, you can clean some (possibly zero) of the dirty cells yourself. However, you don't want to do too much dirty work yourself while you have this nice, smart (yet buggy) robot to do this. 
## Note

 that you cannot make a clean cell dirty.

Calculate the maximum possible number of cells you can leave dirty before launching the robot, so that it doesn't malfunction.

######### Input

The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of columns in the hallway.

Then two lines follow, denoting the $1$-st and the $2$-nd row of the hallway. These lines contain $n$ characters each, where 0 denotes a clean cell and 1 denotes a dirty cell. The starting cell of the robot $(1, 1)$ is clean.

######### Output

Print one integer — the maximum possible number of cells you can leave dirty before launching the robot, so that it doesn't malfunction.

## Examples

######### Input


```text
2
01
11
```
######### Output


```text
2
```
######### Input


```text
2
01
01
```
######### Output


```text
2
```
######### Input


```text
4
0101
1011
```
######### Output


```text
4
```
######### Input


```text
4
0000
0000
```
######### Output


```text
0
```
######### Input


```text
5
00011
10101
```
######### Output


```text
4
```
######### Input


```text
6
011111
111111
```
######### Output


```text
8
```
######### Input


```text
10
0101001010
1010100110
```
######### Output


```text
6
```
## Note

In the first example, you can clean the cell $(1, 2)$, so the path of the robot is $(1, 1) \rightarrow (2, 1) \rightarrow (2, 2)$.

In the second example, you can leave the hallway as it is, so the path of the robot is $(1, 1) \rightarrow (1, 2) \rightarrow (2, 2)$.

In the third example, you can clean the cell $(1, 2)$, so the path of the robot is $(1, 1) \rightarrow (2, 1) \rightarrow (2, 3) \rightarrow (2, 4) \rightarrow (1, 4)$.

In the fourth example, the hallway is already clean. Maybe you have launched the robot earlier?



#### Tags 

#2400 #NOT OK #bitmasks #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_136_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
