<h1 style='text-align: center;'> C. Column Swapping</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a grid with $n$ rows and $m$ columns, where each cell has a positive integer written on it. Let's call a grid good, if in each row the sequence of numbers is sorted in a non-decreasing order. It means, that for each $1 \le i \le n$ and $2 \le j \le m$ the following holds: $a_{i,j} \ge a_{i, j-1}$.

You have to to do the following operation exactly once: choose two columns with indexes $i$ and $j$ (not necessarily different), $1 \le i, j \le m$, and swap them.

You are asked to determine whether it is possible to make the grid good after the swap and, if it is, find the columns that need to be swapped.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the number of rows and columns respectively.

Each of the next $n$ rows contains $m$ integers, $j$-th element of $i$-th row is $a_{i,j}$ ($1 \le a_{i,j} \le 10^9$) — the number written in the $j$-th cell of the $i$-th row.

It's guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

If after the swap it is impossible to get a good grid, output $-1$.

In the other case output $2$ integers — the indices of the columns that should be swapped to get a good grid.

If there are multiple solutions, print any.

## Example

### Input


```text
52 31 2 31 1 12 24 12 32 22 11 12 36 2 15 4 32 112
```
### Output

```text

1 1
-1
1 2
1 3
1 1

```
## Note

In the first test case the grid is initially good, so we can, for example, swap the first column with itself.

In the second test case it is impossible to make the grid good.

In the third test case it is needed to swap the first and the second column, then the grid becomes good.



#### Tags 

#1400 #NOT OK #brute_force #constructive_algorithms #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_792_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
