<h1 style='text-align: center;'> E. Cakewalk</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A mouse encountered a nice big cake and decided to take a walk across it, eating the berries on top of the cake on its way. The cake is rectangular, neatly divided into squares; some of the squares have a berry in them, and some don't.

The mouse is in a bit of a hurry, though, so once she enters the cake from its northwest corner (the top left cell in the input data), she will only go east (right) or south (down), until she reaches the southeast corner (the bottom right cell). She will eat every berry in the squares she passes through, but not in the other squares.

The mouse tries to choose her path so as to maximize the number of berries consumed. However, her haste and hunger might be clouding her judgement, leading her to suboptimal decisions...

###### Input

The first line of input contains two integers $H$ and $W$ ($1 \le H, W \le 5$), separated by a space, — the height and the width of the cake.

The next $H$ lines contain a string of $W$ characters each, representing the squares of the cake in that row: '.' represents an empty square, and '*' represents a square with a berry.

###### Output

###### Output

 the number of berries the mouse will eat following her strategy.

## Examples

###### Input


```text
4 3
*..
.*.
..*
...
```
###### Output


```text
3
```
###### Input


```text
4 4
.*..
*...
...*
..*.
```
###### Output


```text
2
```
###### Input


```text
3 4
..**
*...
....
```
###### Output


```text
1
```
###### Input


```text
5 5
..*..
.....
**...
**...
**...
```
###### Output


```text
1
```


#### Tags 

#1800 #NOT OK #*special #greedy #implementation #shortest_paths 

## Blogs
- [All Contest Problems](../April_Fools_Day_Contest_2021.md)
- [Announcement](../blogs/Announcement.md)
- [tutorial (en)](../blogs/tutorial_(en).md)
