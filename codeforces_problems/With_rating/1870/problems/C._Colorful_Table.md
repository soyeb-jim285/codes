<h1 style='text-align: center;'> C. Colorful Table</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $k$. You are also given an array of integers $a_1, a_2, \ldots, a_n$ of size $n$. It is known that for all $1 \leq i \leq n$, $1 \leq a_i \leq k$.

Define a two-dimensional array $b$ of size $n \times n$ as follows: $b_{i, j} = \min(a_i, a_j)$. Represent array $b$ as a square, where the upper left cell is $b_{1, 1}$, rows are numbered from top to bottom from $1$ to $n$, and columns are numbered from left to right from $1$ to $n$. Let the color of a cell be the number written in it (for a cell with coordinates $(i, j)$, this is $b_{i, j}$).

For each color from $1$ to $k$, find the smallest rectangle in the array $b$ containing all cells of this color. 
### Output

 the sum of width and height of this rectangle.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \leq n, k \leq 10^5$) — the size of array $a$ and the number of colors.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq k$) — the array $a$.

It is guaranteed that the sum of the values of $n$ and $k$ over all test cases does not exceed $10^5$.

### Output

For each test case, output $k$ numbers: the sums of width and height of the smallest rectangle containing all cells of a color, for each color from $1$ to $k$.

## Example

### Input


```text
52 11 12 21 23 53 2 44 21 2 1 25 31 2 3 2 1
```
### Output

```text

4 
4 2 
0 6 6 2 0 
8 6 
10 6 2 

```
## Note

In the first test case, the entire array $b$ consists of color $1$, so the smallest rectangle for color $1$ has a size of $2 \times 2$, and the sum of its sides is $4$.

In the second test case, the array $b$ looks like this:



| 1 | 1 |
| --- | --- |
| 1 | 2 |



One of the corner cells has color $2$, and the other three cells have color $1$. Therefore, the smallest rectangle for color $1$ has a size of $2 \times 2$, and for color $2$ it is $1 \times 1$.

In the last test case, the array $b$ looks like this:



| 1 | 1 | 1 | 1 | 1 |
| --- | --- | --- | --- | --- |
| 1 | 2 | 2 | 2 | 1 |
| 1 | 2 | 3 | 2 | 1 |
| 1 | 2 | 2 | 2 | 1 |
| 1 | 1 | 1 | 1 | 1 |





#### Tags 

#1300 #NOT OK #binary_search #data_structures #dp #implementation #math #two_pointers 

## Blogs
- [All Contest Problems](../CodeTON_Round_6_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
