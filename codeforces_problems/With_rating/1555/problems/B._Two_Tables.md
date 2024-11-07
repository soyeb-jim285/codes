<h1 style='text-align: center;'> B. Two Tables</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an axis-aligned rectangle room with width $W$ and height $H$, so the lower left corner is in point $(0, 0)$ and the upper right corner is in $(W, H)$.

There is a rectangular table standing in this room. The sides of the table are parallel to the walls, the lower left corner is in $(x_1, y_1)$, and the upper right corner in $(x_2, y_2)$.

You want to place another rectangular table in this room with width $w$ and height $h$ with the width of the table parallel to the width of the room.

The problem is that sometimes there is not enough space to place the second table without intersecting with the first one (there are no problems with tables touching, though).

You can't rotate any of the tables, but you can move the first table inside the room. 

 ![](images/e637afe49454e6722bfe68e77148b651b24048bc.png) 
## Example

 of how you may move the first table. What is the minimum distance you should move the first table to free enough space for the second one?

### Input

The first line contains the single integer $t$ ($1 \le t \le 5000$) — the number of the test cases.

The first line of each test case contains two integers $W$ and $H$ ($1 \le W, H \le 10^8$) — the width and the height of the room.

The second line contains four integers $x_1$, $y_1$, $x_2$ and $y_2$ ($0 \le x_1 < x_2 \le W$; $0 \le y_1 < y_2 \le H$) — the coordinates of the corners of the first table.

The third line contains two integers $w$ and $h$ ($1 \le w \le W$; $1 \le h \le H$) — the width and the height of the second table.

### Output

For each test case, print the minimum distance you should move the first table, or $-1$ if there is no way to free enough space for the second table.

Your answer will be considered correct if its absolute or relative error doesn't exceed $10^{-6}$.

## Example

### Input


```text
5
8 5
2 1 7 4
4 2
5 4
2 2 5 4
3 3
1 8
0 3 1 6
1 5
8 1
3 0 6 1
5 1
8 10
4 5 7 8
8 5
```
### Output


```text
1.000000000
-1
2.000000000
2.000000000
0.000000000
```
## Note

The configuration of the first test case is shown in the picture. But the movement of the first table is not optimal. One of the optimal movement, for example, is to move the table by $(0, -1)$, so the lower left corner will move from $(2, 1)$ to $(2, 0)$. Then you can place the second table at $(0, 3)-(4, 5)$.

In the second test case, there is no way to fit both tables in the room without intersecting.

In the third test case, you can move the first table by $(0, 2)$, so the lower left corner will move from $(0, 3)$ to $(0, 5)$.



#### Tags 

#1300 #NOT OK #brute_force 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_112_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
