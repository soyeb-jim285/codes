<h1 style='text-align: center;'> A. The Closest Pair</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Currently Tiny is learning Computational Geometry. When trying to solve a problem called "The Closest Pair Of Points In The Plane", he found that a code which gave a wrong time complexity got Accepted instead of Time Limit Exceeded.

The problem is the follows. Given *n* points in the plane, find a pair of points between which the distance is minimized. Distance between (*x*1, *y*1) and (*x*2, *y*2) is ![](images/a0c6a684203590998776587e7f02c93ba5771038.png).

The pseudo code of the unexpected code is as follows:


```
  
input n  
for i from 1 to n  
    input the i-th point's coordinates into p[i]  
sort array p[] by increasing of x coordinate first and increasing of y coordinate second  
d=INF        //here INF is a number big enough  
tot=0  
for i from 1 to n  
    for j from (i+1) to n  
        ++tot  
        if (p[j].x-p[i].x>=d) then break    //notice that "break" is only to be  
                                            //out of the loop "for j"  
        d=min(d,distance(p[i],p[j]))  
output d  

```
Here, *tot* can be regarded as the running time of the code. Due to the fact that a computer can only run a limited number of operations per second, *tot* should not be more than *k* in order not to get Time Limit Exceeded.

You are a great hacker. Would you please help Tiny generate a test data and let the code get Time Limit Exceeded?

## Input

A single line which contains two space-separated integers *n* and *k* (2 ≤ *n* ≤ 2000, 1 ≤ *k* ≤ 109).

## Output

If there doesn't exist such a data which let the given code get TLE, print "no solution" (without quotes); else print *n* lines, and the *i*-th line contains two integers *x**i*, *y**i* (|*x**i*|, |*y**i*| ≤ 109) representing the coordinates of the *i*-th point.

The conditions below must be held:

* All the points must be distinct.
* |*x**i*|, |*y**i*| ≤ 109.
* After running the given code, the value of *tot* should be larger than *k*.
## Examples

## Input


```
4 3  

```
## Output


```
0 0  
0 1  
1 0  
1 1  

```
## Input


```
2 100  

```
## Output


```
no solution  

```


#### tags 

#1300 #constructive_algorithms #implementation 