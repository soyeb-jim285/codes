<h1 style='text-align: center;'> A. Square and Rectangles</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* rectangles. The corners of rectangles have integer coordinates and their edges are parallel to the *Ox* and *Oy* axes. The rectangles may touch each other, but they do not overlap (that is, there are no points that belong to the interior of more than one rectangle). 

Your task is to determine if the rectangles form a square. In other words, determine if the set of points inside or on the border of at least one rectangle is precisely equal to the set of points inside or on the border of some square.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 5). Next *n* lines contain four integers each, describing a single rectangle: *x*1, *y*1, *x*2, *y*2 (0 ≤ *x*1 < *x*2 ≤ 31400, 0 ≤ *y*1 < *y*2 ≤ 31400) — *x*1 and *x*2 are *x*-coordinates of the left and right edges of the rectangle, and *y*1 and *y*2 are *y*-coordinates of the bottom and top edges of the rectangle. 

No two rectangles overlap (that is, there are no points that belong to the interior of more than one rectangle).

## Output

In a single line print "YES", if the given rectangles form a square, or "NO" otherwise.

## Examples

## Input


```
5  
0 0 2 3  
0 3 3 5  
2 0 5 2  
3 2 5 5  
2 2 3 3  

```
## Output


```
YES  

```
## Input


```
4  
0 0 2 3  
0 3 3 5  
2 0 5 2  
3 2 5 5  

```
## Output


```
NO  

```


#### tags 

#1500 #implementation 