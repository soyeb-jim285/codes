<h1 style='text-align: center;'> B. Scale</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tina has a square grid with $n$ rows and $n$ columns. Each cell in the grid is either $0$ or $1$. 

Tina wants to reduce the grid by a factor of $k$ ($k$ is a divisor of $n$). To do this, Tina splits the grid into $k \times k$ nonoverlapping blocks of cells such that every cell belongs to exactly one block.

Tina then replaces each block of cells with a single cell equal to the value of the cells in the block. It is guaranteed that every cell in the same block has the same value. 

For example, the following demonstration shows a grid being reduced by factor of $3$.

 Original grid 

| $0$ | $0$ | $0$ | $1$ | $1$ | $1$ |
| --- | --- | --- | --- | --- | --- |
| $0$ | $0$ | $0$ | $1$ | $1$ | $1$ |
| $0$ | $0$ | $0$ | $1$ | $1$ | $1$ |
| $1$ | $1$ | $1$ | $0$ | $0$ | $0$ |
| $1$ | $1$ | $1$ | $0$ | $0$ | $0$ |
| $1$ | $1$ | $1$ | $0$ | $0$ | $0$ |

  Reduced grid 

| $0$ | $1$ |
| --- | --- |
| $1$ | $0$ |

 Help Tina reduce the grid by a factor of $k$.

### Input

The first line contains $t$ ($1 \leq t \leq 100$) – the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \leq n \leq 1000$, $1 \le k \le n$, $k$ is a divisor of $n$) — the number of rows and columns of the grid, and the factor that Tina wants to reduce the grid by. 

Each of the following $n$ lines contain $n$ characters describing the cells of the grid. Each character is either $0$ or $1$. It is guaranteed every $k$ by $k$ block has the same value.

It is guaranteed the sum of $n$ over all test cases does not exceed $1000$.

### Output

For each test case, output the grid reduced by a factor of $k$ on a new line.

## Example

### Input


```text
44 400000000000000006 30001110001110001111110001110001110006 20011000011001111111111111100001100008 11111111111111111111111111111111111111111111111111111111111111111
```
### Output

```text

0
01
10
010
111
100
11111111
11111111
11111111
11111111
11111111
11111111
11111111
11111111

```


#### Tags 

#NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_962_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial 2 (en)](../blogs/Video_Tutorial_2_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
