<h1 style='text-align: center;'> C. Omkar and Determination</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The problem statement looms below, filling you with determination.

Consider a grid in which some cells are empty and some cells are filled. Call a cell in this grid exitable if, starting at that cell, you can exit the grid by moving up and left through only empty cells. This includes the cell itself, so all filled in cells are not exitable. 
## Note

 that you can exit the grid from any leftmost empty cell (cell in the first column) by going left, and from any topmost empty cell (cell in the first row) by going up.

Let's call a grid determinable if, given only which cells are exitable, we can exactly determine which cells are filled in and which aren't.

You are given a grid $a$ of dimensions $n \times m$ , i. e. a grid with $n$ rows and $m$ columns. You need to answer $q$ queries ($1 \leq q \leq 2 \cdot 10^5$). Each query gives two integers $x_1, x_2$ ($1 \leq x_1 \leq x_2 \leq m$) and asks whether the subgrid of $a$ consisting of the columns $x_1, x_1 + 1, \ldots, x_2 - 1, x_2$ is determinable.

### Input

The first line contains two integers $n, m$ ($1 \leq n, m \leq 10^6$, $nm \leq 10^6$)  — the dimensions of the grid $a$.

$n$ lines follow. The $y$-th line contains $m$ characters, the $x$-th of which is 'X' if the cell on the intersection of the the $y$-th row and $x$-th column is filled and "." if it is empty.

The next line contains a single integer $q$ ($1 \leq q \leq 2 \cdot 10^5$)  — the number of queries.

$q$ lines follow. Each line contains two integers $x_1$ and $x_2$ ($1 \leq x_1 \leq x_2 \leq m$), representing a query asking whether the subgrid of $a$ containing the columns $x_1, x_1 + 1, \ldots, x_2 - 1, x_2$ is determinable.

### Output

For each query, output one line containing "YES" if the subgrid specified by the query is determinable and "NO" otherwise. The output is case insensitive (so "yEs" and "No" will also be accepted).

## Example

### Input


```text
4 5
..XXX
...X.
...X.
...X.
5
1 3
3 3
4 5
5 5
1 5
```
### Output


```text
YES
YES
NO
YES
NO
```
## Note

For each query of the example, the corresponding subgrid is displayed twice below: first in its input format, then with each cell marked as "E" if it is exitable and "N" otherwise.

For the first query: 


```text
  
..X EEN  
... EEE  
... EEE  
... EEE  

```

```text
  
  

```
For the second query: 


```text
  
X N  
. E  
. E  
. E  

```
## Note

 that you can exit the grid by going left from any leftmost cell (or up from any topmost cell); you do not need to reach the top left corner cell to exit the grid.


```text
  
  

```
For the third query: 


```text
  
XX NN  
X. NN  
X. NN  
X. NN  

```
This subgrid cannot be determined only from whether each cell is exitable, because the below grid produces the above "exitability grid" as well: 


```text
  
XX  
XX  
XX  
XX  

```

```text
  
  

```
For the fourth query: 


```text
  
X N  
. E  
. E  
. E  

```

```text
  
  

```
For the fifth query: 


```text
  
..XXX EENNN  
...X. EEENN  
...X. EEENN  
...X. EEENN  

```
This query is simply the entire grid. It cannot be determined only from whether each cell is exitable because the below grid produces the above "exitability grid" as well: 


```text
  
..XXX  
...XX  
...XX  
...XX  

```


#### Tags 

#1700 #NOT OK #data_structures #dp 

## Blogs
- [All Contest Problems](../Technocup_2022_-_Elimination_Round_1.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
