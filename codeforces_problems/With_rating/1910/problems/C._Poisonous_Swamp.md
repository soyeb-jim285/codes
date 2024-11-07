<h1 style='text-align: center;'> C. Poisonous Swamp</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The first location in the brand new critically acclaimed fantasy action RPG "Ancient Staff" is a poisonous swamp. The swamp has some lily pads growing in it. It can be represented as a $2 \times n$ grid ($2$ rows and $n$ columns), where each cell is either empty or has a lily pad in it.

There are exactly $n$ lily pads in a swamp — one in each column. A frog is sitting on top of every lily pad. In one move, every frog must jump to an adjacent by a side cell.

After the move, no frog can be outside the grid and no two frogs can share the same lily pad. Two frogs from adjacent cells can't jump towards each other (i.e. swap cells).

If a frog jumps to a lily pad, it survives. Otherwise, it falls into a poisonous swamp and gets devoured by an eldritch creature living on its bottom.

You can choose the direction each frogs jumps at. Determine the maximum number of frogs that can survive after one move.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of the testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of columns in a swamp grid.

Each of the following two lines contains a description of a row of a swamp — a string, consisting of exactly $n$ characters. Each character is either a dot ('.'), denoting a swamp cell, or an asterisk ('*'), denoting a lily pad with a frog.

In each column, there is exactly one dot and exactly one asterisk. The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print a single integer — the maximum number of frogs that can survive after one move, if you choose the direction each frogs jumps at.

## Example

### Input


```text
35*..**.**..1*.3...***
```
### Output

```text

2
0
2

```
## Note

The $i$-th frog is the frog on the lily pad in the $i$-th column.

In the first testcase: 

* the first frog can't survive because there's no adjacent lily pad;
* the second and the third frogs can jump right and up, respectively, — there's no way to save them both at the same time;
* the fourth and the fifth frogs can jump left and left, respectively, — there's no way to save them both at the same time; note, however, that the third and the fourth frogs will end up in the same cell in the swamp, which is not prohibited.


#### Tags 

#1600 #NOT OK #*special #*special #implementation #implementation 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_9_(Unrated,_T-Shirts_+_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
