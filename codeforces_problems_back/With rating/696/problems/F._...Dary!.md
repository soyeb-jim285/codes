<h1 style='text-align: center;'> F. ...Dary!</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Barney has finally found the one, a beautiful young lady named Lyanna. The problem is, Lyanna and Barney are trapped in Lord Loss' castle. This castle has shape of a convex polygon of *n* points. Like most of castles in Demonata worlds, this castle has no ceiling.

 ![](images/88095178099d86bf418c57f13017daa8ba8bedf2.png) Barney and Lyanna have an escape plan, but it requires some geometry knowledge, so they asked for your help.

Barney knows that demons are organized and move in lines. He and Lyanna want to wait for the appropriate time so they need to watch for the demons. Each of them wants to stay in a point inside the castle (possibly on edges or corners), also they may stay in the same position. They both want to pick a real number *r* and watch all points in the circles with radius *r* around each of them (these two circles may overlap).

 ![](images/1a468fb1dd5ab9c486f6da7d828cc77b47ba089a.png) We say that Barney and Lyanna are watching carefully if and only if for every edge of the polygon, at least one of them can see at least one point on the line this edge lies on, thus such point may not be on the edge but it should be on edge's line. Formally, each edge line should have at least one common point with at least one of two circles.

The greater *r* is, the more energy and focus they need. So they asked you to tell them the minimum value of *r* such that they can watch carefully.

## Input

The first line of input contains a single integer *n* (3 ≤ *n* ≤ 300) — the number of castle polygon vertices.

The next *n* lines describe the polygon vertices in counter-clockwise order. *i*-th of them contains two integers *x**i* and *y**i* (|*x**i*|, |*y**i*| ≤ 104) — the coordinates of *i*-th point of the castle. It is guaranteed that given points form a convex polygon, in particular, any three of them do not line on the same line.

## Output

In the first line print the single number *r* — minimum radius of guys' watching circles.

In the second line print the pair of coordinates of point where Barney should stay.

In the third line print the pair of coordinates of point where Lyanna should stay.

Points should lie inside the polygon.

Coordinates may not be integers. If there are multiple answers print any of them.

Your answer will be considered correct if its absolute or relative error doesn't exceed 10- 6.

## Examples

## Input


```
4  
-41 67  
-16 20  
25 25  
-36 85  

```
## Output


```
0  
-16 20  
-36 85  

```
## Input


```
7  
-7 54  
-5 31  
-2 17  
20 19  
32 23  
34 27  
26 57  

```
## Output


```
2.9342248  
32.019503 23.0390067  
-6.929116 54.006444  

```
## Note

In the first example guys can stay in opposite corners of the castle.



#### tags 

#3300 #binary_search #geometry #two_pointers 