<h1 style='text-align: center;'> D. Tourists</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A double tourist path, located at a park in Ultima Thule, is working by the following principle:

* We introduce the Cartesian coordinate system.
* At some points of time there are two tourists going (for a walk) from points ( - 1, 0) and (1, 0) simultaneously. The first one is walking from ( - 1, 0), the second one is walking from (1, 0).
* Both tourists in a pair move at the same speed 1 (distance unit per second), the first one moves along line *x* =  - 1, the second one moves along line *x* = 1, both of them are moving in the positive direction of the *Oy* axis.
* At some points of time walls appear. Wall (*l**i*, *r**i*) is a segment between points (0, *l**i*) and (0, *r**i*). Each wall appears immediately.

The Ultima Thule government wants to learn this for each pair of tourists that walk simultaneously: for how long (in seconds) will they not see each other? Two tourists don't see each other if the segment that connects their positions on the plane intersects at least one wall. Two segments intersect if they share at least one point. We assume that the segments' ends belong to the segments.

Help the government count the required time. Note that the walls can intersect (in any way) or coincide.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of pairs of tourists and the number of built walls. The next *m* lines contain three space-separated integers *l**i*, *r**i* and *t**i* each (0 ≤ *l**i* < *r**i* ≤ 109, 0 ≤ *t**i* ≤ 109) — the wall ends and the time it appeared. The last line contains *n* distinct space-separated strictly increasing integers *q*1, *q*2, ..., *q**n* (0 ≤ *q**i* ≤ 109) — the points of time when pairs of tourists walk.

All points of time are given in seconds.

## Output

For each pair of tourists print on a single line a single integer — the time in seconds when the two tourists from the corresponding pair won't see each other. Print the numbers in the order in which the they go in the input.

## Examples

## Input


```
2 2  
1 4 3  
3 6 5  
0 1  

```
## Output


```
2  
4  

```
## Input


```
3 3  
0 3 4  
0 1 2  
2 4 0  
1 3 4  

```
## Output


```
2  
4  
4  

```


#### tags 

#2600 #data_structures #sortings 