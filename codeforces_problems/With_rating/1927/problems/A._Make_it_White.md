<h1 style='text-align: center;'> A. Make it White</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a horizontal strip of $n$ cells. Each cell is either white or black.

You can choose a continuous segment of cells once and paint them all white. After this action, all the black cells in this segment will become white, and the white ones will remain white.

What is the minimum length of the segment that needs to be painted white in order for all $n$ cells to become white?

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10$) — the length of the strip.

The second line of each test case contains a string $s$, consisting of $n$ characters, each of which is either 'W' or 'B'. The symbol 'W' denotes a white cell, and 'B' — a black one. It is guaranteed that at least one cell of the given strip is black.

### Output

For each test case, output a single number — the minimum length of a continuous segment of cells that needs to be painted white in order for the entire strip to become white.

## Example

### Input


```text
86WBBWBW1B2WB3BBW4BWWB6BWBWWB6WWBBWB9WBWBWWWBW
```
### Output

```text

4
1
1
2
4
6
4
7

```
## Note

In the first test case of the example for the strip "WBBWBW", the minimum length of the segment to be repainted white is $4$. It is necessary to repaint to white the segment from the $2$-nd to the $5$-th cell (the cells are numbered from $1$ from left to right).



#### Tags 

#800 #OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_923_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
