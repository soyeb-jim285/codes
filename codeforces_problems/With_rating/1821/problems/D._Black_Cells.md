<h1 style='text-align: center;'> D. Black Cells</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing with a really long strip consisting of $10^{18}$ white cells, numbered from left to right as $0$, $1$, $2$ and so on. You are controlling a special pointer that is initially in cell $0$. Also, you have a "Shift" button you can press and hold.

In one move, you can do one of three actions: 

* move the pointer to the right (from cell $x$ to cell $x + 1$);
* press and hold the "Shift" button;
* release the "Shift" button: the moment you release "Shift", all cells that were visited while "Shift" was pressed are colored in black.

 (Of course, you can't press Shift if you already hold it. Similarly, you can't release Shift if you haven't pressed it.)Your goal is to color at least $k$ cells, but there is a restriction: you are given $n$ segments $[l_i, r_i]$ — you can color cells only inside these segments, i. e. you can color the cell $x$ if and only if $l_i \le x \le r_i$ for some $i$.

What is the minimum number of moves you need to make in order to color at least $k$ cells black?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$; $1 \le k \le 10^9$) — the number of segments and the desired number of black cells, respectively.

The second line contains $n$ integers $l_1, l_2, \dots, l_n$ ($1 \le l_1 < l_2 < \dots < l_n \le 10^9$), where $l_i$ is the left border of the $i$-th segment.

The third line contains $n$ integers $r_1, r_2, \dots, r_n$ ($1 \le r_i \le 10^9$; $l_i \le r_i < l_{i + 1} - 1$), where $r_i$ is the right border of the $i$-th segment.

Additional constraints on the input:

* every cell belongs to at most one segment;
* the sum of $n$ doesn't exceed $2 \cdot 10^5$.
### Output

For each test case, print the minimum number of moves to color at least $k$ cells black, or $-1$ if it's impossible.

## Example

### Input


```text
42 31 31 44 2010 13 16 1911 14 17 202 31 31 102 499 999999999100 1000000000
```
### Output

```text

8
-1
7
1000000004

```
## Note

In the first test case, one of the optimal sequences of operations is the following: 

1. Move right: pointer is moving into cell $1$;
2. Press Shift;
3. Release Shift: cell $1$ is colored black;
4. Move right: pointer is moving into cell $2$;
5. Move right: pointer is moving into cell $3$;
6. Press Shift;
7. Move right: pointer is moving into cell $4$;
8. Release Shift: cells $3$ and $4$ are colored in black.

 We've colored $3$ cells in $8$ moves.In the second test case, we can color at most $8$ cells, while we need $20$ cell to color.

In the third test case, one of the optimal sequences of operations is the following: 

1. Move right: pointer is moving into cell $1$;
2. Move right: pointer is moving into cell $2$;
3. Move right: pointer is moving into cell $3$;
4. Press Shift;
5. Move right: pointer is moving into cell $4$;
6. Move right: pointer is moving into cell $5$;
7. Release Shift: cells $3$, $4$ and $5$ are colored in black.

 We've colored $3$ cells in $7$ moves.

#### Tags 

#1900 #NOT OK #binary_search #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_147_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
