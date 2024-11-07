<h1 style='text-align: center;'> E. Crazy Robot</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a grid, consisting of $n$ rows and $m$ columns. Each cell of the grid is either free or blocked. One of the free cells contains a lab. All the cells beyond the borders of the grid are also blocked.

A crazy robot has escaped from this lab. It is currently in some free cell of the grid. You can send one of the following commands to the robot: "move right", "move down", "move left" or "move up". Each command means moving to a neighbouring cell in the corresponding direction.

However, as the robot is crazy, it will do anything except following the command. Upon receiving a command, it will choose a direction such that it differs from the one in command and the cell in that direction is not blocked. If there is such a direction, then it will move to a neighbouring cell in that direction. Otherwise, it will do nothing.

We want to get the robot to the lab to get it fixed. For each free cell, determine if the robot can be forced to reach the lab starting in this cell. That is, after each step of the robot a command can be sent to a robot such that no matter what different directions the robot chooses, it will end up in a lab.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

The first line of each testcase contains two integers $n$ and $m$ ($1 \le n, m \le 10^6$; $n \cdot m \le 10^6$) — the number of rows and the number of columns in the grid.

The $i$-th of the next $n$ lines provides a description of the $i$-th row of the grid. It consists of $m$ elements of one of three types: 

* '.' — the cell is free;
* '#' — the cell is blocked;
* 'L' — the cell contains a lab.

The grid contains exactly one lab. The sum of $n \cdot m$ over all testcases doesn't exceed $10^6$.

### Output

For each testcase find the free cells that the robot can be forced to reach the lab from. Given the grid, replace the free cells (marked with a dot) with a plus sign ('+') for the cells that the robot can be forced to reach the lab from. Print the resulting grid.

## Example

### Input


```text
4
3 3
...
.L.
...
4 5
#....
..##L
...#.
.....
1 1
L
1 9
....L..#.
```
### Output


```text
...
.L.
...
#++++
..##L
...#+
...++
L
++++L++#.
```
## Note

In the first testcase there is no free cell that the robot can be forced to reach the lab from. Consider a corner cell. Given any direction, it will move to a neighbouring border grid that's not a corner. Now consider a non-corner free cell. No matter what direction you send to the robot, it can choose a different direction such that it ends up in a corner.

In the last testcase, you can keep sending the command that is opposite to the direction to the lab and the robot will have no choice other than move towards the lab.



#### Tags 

#2000 #NOT OK #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_118_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
