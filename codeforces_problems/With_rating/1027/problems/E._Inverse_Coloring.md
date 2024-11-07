<h1 style='text-align: center;'> E. Inverse Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a square board, consisting of $n$ rows and $n$ columns. Each tile in it should be colored either white or black.

Let's call some coloring beautiful if each pair of adjacent rows are either the same or different in every position. The same condition should be held for the columns as well.

Let's call some coloring suitable if it is beautiful and there is no rectangle of the single color, consisting of at least $k$ tiles.

Your task is to count the number of suitable colorings of the board of the given size.

Since the answer can be very large, print it modulo $998244353$.

##### Input

A single line contains two integers $n$ and $k$ ($1 \le n \le 500$, $1 \le k \le n^2$) — the number of rows and columns of the board and the maximum number of tiles inside the rectangle of the single color, respectively.

##### Output

Print a single integer — the number of suitable colorings of the board of the given size modulo $998244353$.

## Examples

##### Input


```text
1 1  

```
##### Output


```text
0  

```
##### Input


```text
2 3  

```
##### Output


```text
6  

```
##### Input


```text
49 1808  

```
##### Output


```text
359087121  

```
## Note

Board of size $1 \times 1$ is either a single black tile or a single white tile. Both of them include a rectangle of a single color, consisting of $1$ tile.

Here are the beautiful colorings of a board of size $2 \times 2$ that don't include rectangles of a single color, consisting of at least $3$ tiles:

 ![](images/9fac296fd9c22445427c2b2ceff464b1301a1018.png) The rest of beautiful colorings of a board of size $2 \times 2$ are the following:

 ![](images/fcbfe601dd6e3a8487a9a1588282b8b2255b6bb0.png) 

#### Tags 

#2100 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_49_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
