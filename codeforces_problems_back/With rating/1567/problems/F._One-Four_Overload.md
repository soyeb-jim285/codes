<h1 style='text-align: center;'> F. One-Four Overload</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has an empty grid with $n$ rows and $m$ columns. Some of the cells are marked, and no marked cells are adjacent to the edge of the grid. (Two squares are adjacent if they share a side.) 

Alice wants to fill each cell with a number such that the following statements are true: 

* every unmarked cell contains either the number $1$ or $4$;
* every marked cell contains the sum of the numbers in all unmarked cells adjacent to it (if a marked cell is not adjacent to any unmarked cell, this sum is $0$);
* every marked cell contains a multiple of $5$.

 Alice couldn't figure it out, so she asks Bob to help her. Help Bob find any such grid, or state that no such grid exists.## Input

The first line of input contains two integers $n$ and $m$ ($1 \leq n, m \leq 500$) — the number of rows and the number of columns in the grid, respectively.

Then $n$ lines follow, each containing $m$ characters. Each of these characters is either '.' or 'X' — an unmarked and a marked cell, respectively. No marked cells are adjacent to the edge of the grid.

## Output

## Output

 "'NO" if no suitable grid exists. Otherwise, output "'YES"'. Then output $n$ lines of $m$ space-separated integers — the integers in the grid.

## Examples

## Input


```

5 5
.....
.XXX.
.X.X.
.XXX.
.....

```
## Output


```

YES
4 1 4 4 1
4 5 5 5 1
4 5 1 5 4
1 5 5 5 4
1 4 4 1 4

```
## Input


```

5 5
.....
.XXX.
.XXX.
.XXX.
.....

```
## Output


```

NO

```
## Input


```

3 2
..
..
..

```
## Output


```

YES
4 1
4 1
1 4

```
## Input


```

9 9
.........
.XXXXX.X.
.X...X...
.X.XXXXX.
.X.X.X.X.
.X.XXX.X.
.X.....X.
.XXXXXXX.
.........

```
## Output


```

YES
4 4 4 1 4 1 4 1 4
1 5 5 5 5 5 4 10 1
4 5 1 4 1 5 4 4 4
4 5 1 5 5 0 5 5 1
4 5 1 5 4 5 1 5 4
4 5 1 5 5 5 4 5 1
1 5 4 4 1 1 4 5 1
4 5 5 5 5 5 5 5 4
1 1 1 1 4 4 1 1 4

```
## Note

It can be shown that no such grid exists for the second test.



#### tags 

#2700 #2-sat #constructive_algorithms #dfs_and_similar #dsu #graphs #implementation 