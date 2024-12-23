<h1 style='text-align: center;'> F. Yin Yang</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rectangular grid with $n$ rows and $m$ columns. $n$ and $m$ are divisible by $4$. Some of the cells are already colored black or white. It is guaranteed that no two colored cells share a corner or an edge.

Color the remaining cells in a way that both the black and the white cells becomes orthogonally connected or determine that it is impossible.

Consider a graph, where the black cells are the nodes. Two nodes are adjacent if the corresponding cells share an edge. If the described graph is connected, the black cells are orthogonally connected. Same for white cells.

### Input

The input consists of multiple test cases. The first line of the input contains a single integer $t$ ($1 \le t \le 4000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$, $m$ ($8 \le n, m \le 500$, $n$ and $m$ are divisible by $4$) — the number of rows and columns.

Each of the next $n$ lines contains $m$ characters. Each character is either 'B', 'W' or '.', representing black, white or empty cell respectively. Two colored (black or white) cell does not share a corner or an edge.

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $250\,000$.

### Output

For each testcase print "NO" if there is no solution, otherwise print "YES" and a grid with the same format. If there are multiple solutions, you can print any.

## Example

### Input


```text
4
8 8
.W.W....
.....B.W
.W.W....
.....W.W
B.B.....
....B.B.
B.W.....
....B.B.
8 8
B.W..B.W
........
W.B..W.B
........
........
B.W..B.W
........
W.B..W.B
8 12
W.B.........
....B...B.W.
B.B.........
....B...B.B.
.B..........
........B...
.W..B.B...W.
............
16 16
.W............W.
...W..W..W.W....
.B...........B.W
....W....W......
W......B....W.W.
..W.......B.....
....W...W....B.W
.W....W....W....
...B...........W
W.....W...W..B..
..W.W...W......B
............W...
.W.B...B.B....B.
.....W.....W....
..W......W...W..
W...W..W...W...W
```
### Output


```text
YES
BWWWWWWW
BWBBBBBW
BWBWWWBW
BWBWBWBW
BWBWBWBW
BWBBBWBW
BWWWWWBW
BBBBBBBW
NO
YES
WWBBBBBBBBBB
BWWWBBBBBBWB
BBBWBBBWWWWB
BBBWBBBWBBBB
BBBWBBBWBBBB
BBBWWWWWBBBB
BWWWBBBWWWWB
BBBBBBBBBBBB
YES
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WBBBBBBBBBBBBBWW
WBBBWBWWWWBWWBWW
WBBWWBBBWWBWWBWW
WBWWWBWWWWBWWBWW
WBBWWBBBWWBWWBWW
WWBWWWWWWWWWWWWW
WWBBBBBBBBBBBBWW
WBBBWWWBWWWBWBWW
WWWBWBBBWBBBWBBB
WWWBWBWWWWWBWWBW
WWWBWBBBWBBBWWBW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
```
## Note

Solution for test case 1: 

 ![](images/832f369f6fdfcf2be9467a0001f2a7668593b2bd.png) Test case 2: one can see that the black and the white part can't be connected in the same time. So the answer is "NO". 



#### Tags 

#3500 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_783_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
