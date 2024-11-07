<h1 style='text-align: center;'> D. Rectangle Painting 1</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a square grid of size $n \times n$. Some cells are colored in black, all others are colored in white. In one operation you can select some rectangle and color all its cells in white. It costs $\max(h, w)$ to color a rectangle of size $h \times w$. You are to make all cells white for minimum total cost.

###### Input

The first line contains a single integer $n$ ($1 \leq n \leq 50$) — the size of the square grid.

Each of the next $n$ lines contains a string of length $n$, consisting of characters '.' and '#'. The $j$-th character of the $i$-th line is '#' if the cell with coordinates $(i, j)$ is black, otherwise it is white.

###### Output

Print a single integer — the minimum total cost to paint all cells in white.

## Examples

###### Input


```text
3
###
#.#
###
```
###### Output


```text
3
```
###### Input


```text
3
...
...
...
```
###### Output


```text
0
```
###### Input


```text
4
#...
....
....
#...
```
###### Output


```text
2
```
###### Input


```text
5
#...#
.#.#.
.....
.#...
#....
```
###### Output


```text
5
```
## Note

The examples and some of optimal solutions are shown on the pictures below.

 ![](images/3e301c8f13644d71a51706c0e91e8d944a1d4358.png) 

#### Tags 

#2300 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_576_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [E (en)](../blogs/E_(en).md)
