<h1 style='text-align: center;'> D. Manhattan Circle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a $n$ by $m$ grid consisting of '.' and '#' characters, there exists a whole manhattan circle on the grid. The top left corner of the grid has coordinates $(1,1)$, and the bottom right corner has coordinates $(n, m)$.

Point ($a, b$) belongs to the manhattan circle centered at ($h, k$) if $|h - a| + |k - b| < r$, where $r$ is a positive constant.

On the grid, the set of points that are part of the manhattan circle is marked as '#'. Find the coordinates of the center of the circle.

### Input

The first line contains $t$ ($1 \leq t \leq 1000$)  — the number of test cases.

The first line of each test case contains $n$ and $m$ ($1 \leq n \cdot m \leq 2 \cdot 10^5$) — the height and width of the grid, respectively. 

The next $n$ lines contains $m$ characters '.' or '#'. If the character is '#', then the point is part of the manhattan circle.

It is guaranteed the sum of $n \cdot m$ over all test cases does not exceed $2 \cdot 10^5$, and there is a whole manhattan circle on the grid.

### Output

For each test case, output the two integers, the coordinates of the center of the circle.

## Example

### Input


```text
65 5............#............5 5..#...###.#####.###...#..5 6.............#....###....#....1 1#5 6...#....###..#####..###....#..2 10.............#......
```
### Output

```text

3 3
3 3
4 2
1 1
3 4
2 4

```


#### Tags 

#900 #NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_952_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
