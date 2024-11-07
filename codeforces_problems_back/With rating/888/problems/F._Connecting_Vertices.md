<h1 style='text-align: center;'> F. Connecting Vertices</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* points marked on the plane. The points are situated in such a way that they form a regular polygon (marked points are its vertices, and they are numbered in counter-clockwise order). You can draw *n* - 1 segments, each connecting any two marked points, in such a way that all points have to be connected with each other (directly or indirectly).

But there are some restrictions. Firstly, some pairs of points cannot be connected directly and have to be connected undirectly. Secondly, the segments you draw must not intersect in any point apart from the marked points (that is, if any two segments intersect and their intersection is not a marked point, then the picture you have drawn is invalid).

How many ways are there to connect all vertices with *n* - 1 segments? Two ways are considered different iff there exist some pair of points such that a segment is drawn between them in the first way of connection, but it is not drawn between these points in the second one. Since the answer might be large, output it modulo 109 + 7.

## Input

The first line contains one number *n* (3 ≤ *n* ≤ 500) — the number of marked points.

Then *n* lines follow, each containing *n* elements. *a**i*, *j* (*j*-th element of line *i*) is equal to 1 iff you can connect points *i* and *j* directly (otherwise *a**i*, *j* = 0). It is guaranteed that for any pair of points *a**i*, *j* = *a**j*, *i*, and for any point *a**i*, *i* = 0.

## Output

Print the number of ways to connect points modulo 109 + 7.

## Examples

## Input


```
3  
0 0 1  
0 0 1  
1 1 0  

```
## Output


```
1  

```
## Input


```
4  
0 1 1 1  
1 0 1 1  
1 1 0 1  
1 1 1 0  

```
## Output


```
12  

```
## Input


```
3  
0 0 0  
0 0 1  
0 1 0  

```
## Output


```
0  

```


#### tags 

#2500 #dp #graphs 