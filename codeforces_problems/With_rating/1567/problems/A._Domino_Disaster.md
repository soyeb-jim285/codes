<h1 style='text-align: center;'> A. Domino Disaster</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has a grid with $2$ rows and $n$ columns. She fully covers the grid using $n$ dominoes of size $1 \times 2$ — Alice may place them vertically or horizontally, and each cell should be covered by exactly one domino.

Now, she decided to show one row of the grid to Bob. Help Bob and figure out what the other row of the grid looks like!

### Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 5000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 100$) — the width of the grid.

The second line of each test case contains a string $s$ consisting of $n$ characters, each of which is either L, R, U, or D, representing the left, right, top, or bottom half of a domino, respectively (see notes for better understanding). This string represents one of the rows of the grid. 

Additional constraint on the input: each input corresponds to at least one valid tiling.

### Output

For each test case, output one string — the other row of the grid, using the same format as the input string. If there are multiple answers, print any.

## Example

### Input


```text
4
1
U
2
LR
5
LRDLR
6
UUUUUU
```
### Output


```text
D
LR
LRULR
DDDDDD
```
## Note

In the first test case, Alice shows Bob the top row, the whole grid may look like: 

 ![](images/74fd27dee13c8d73f41b62ff63fec2b1fe6b2ce2.png) In the second test case, Alice shows Bob the bottom row, the whole grid may look like: 

 ![](images/a9de3377acd81e9b5573b797681868590ce31db2.png) In the third test case, Alice shows Bob the bottom row, the whole grid may look like: 

 ![](images/6f3e66bec16f74f442ff67d2eb5ae41b794bc6be.png) In the fourth test case, Alice shows Bob the top row, the whole grid may look like: 

 ![](images/1f8f48c39f103d5d8faa2832085cf8d075705bff.png) 

#### Tags 

#800 #NOT OK #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_742_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
