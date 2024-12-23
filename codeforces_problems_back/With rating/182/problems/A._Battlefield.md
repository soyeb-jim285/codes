<h1 style='text-align: center;'> A. Battlefield</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya lagged behind at the University and got to the battlefield. Just joking! He's simply playing some computer game. The field is a flat platform with *n* trenches dug on it. The trenches are segments on a plane parallel to the coordinate axes. No two trenches intersect.

There is a huge enemy laser far away from Vasya. The laser charges for *a* seconds, and then shoots continuously for *b* seconds. Then, it charges for *a* seconds again. Then it shoots continuously for *b* seconds again and so on. Vasya knows numbers *a* and *b*. He also knows that while the laser is shooting, Vasya must be in the trench, but while the laser is charging, Vasya can safely move around the field. The main thing is to have time to hide in the trench before the shot. If Vasya reaches the trench exactly at the moment when the laser starts shooting, we believe that Vasya managed to hide. Coincidentally, the length of any trench in meters numerically does not exceed *b*.

Initially, Vasya is at point *A*. He needs to get to point *B*. Vasya moves at speed 1 meter per second in either direction. You can get in or out of the trench at any its point. Getting in or out of the trench takes no time. It is also possible to move in the trench, without leaving it.

What is the minimum time Vasya needs to get from point *A* to point *B*, if at the initial time the laser has just started charging? If Vasya cannot get from point *A* to point *B*, print -1. If Vasya reaches point *B* at the moment when the laser begins to shoot, it is believed that Vasya managed to reach point *B*.

## Input

The first line contains two space-separated integers: *a* and *b* (1 ≤ *a*, *b* ≤ 1000), — the duration of charging and the duration of shooting, in seconds.

The second line contains four space-separated integers: *A**x*, *A**y*, *B**x*, *B**y* ( - 104 ≤ *A**x*, *A**y*, *B**x*, *B**y* ≤ 104) — the coordinates of points *А* and *B*. It is guaranteed that points *A* and *B* do not belong to any trench.

The third line contains a single integer: *n* (1 ≤ *n* ≤ 1000), — the number of trenches. 

Each of the following *n* lines contains four space-separated integers: *x*1, *y*1, *x*2, *y*2 ( - 104 ≤ *x**i*, *y**i* ≤ 104) — the coordinates of ends of the corresponding trench.

All coordinates are given in meters. It is guaranteed that for any trench either *x*1 = *x*2, or *y*1 = *y*2. No two trenches intersect. The length of any trench in meters doesn't exceed *b* numerically.

## Output

If Vasya can get from point *A* to point *B*, print the minimum time he will need for it. Otherwise, print number -1.

The answer will be considered correct if the absolute or relative error does not exceed 10- 4

## Examples

## Input


```
2 4  
0 5 6 5  
3  
0 0 0 4  
1 1 4 1  
6 0 6 4  

```
## Output


```
19.0000000000  

```
## Input


```
5 10  
0 0 10 10  
1  
5 0 5 9  

```
## Output


```
-1  

```


#### tags 

#2200 #geometry #graphs #implementation #shortest_paths 