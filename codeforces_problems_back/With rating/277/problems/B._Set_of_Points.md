<h1 style='text-align: center;'> B. Set of Points</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Convexity of a set of points on the plane is the size of the largest subset of points that form a convex polygon. Your task is to build a set of *n* points with the convexity of exactly *m*. Your set of points should not contain three points that lie on a straight line.

## Input

The single line contains two integers *n* and *m* (3 ≤ *m* ≤ 100, *m* ≤ *n* ≤ 2*m*).

## Output

If there is no solution, print "-1". Otherwise, print *n* pairs of integers — the coordinates of points of any set with the convexity of *m*. The coordinates shouldn't exceed 108 in their absolute value.

## Examples

## Input


```
4 3  

```
## Output


```
0 0  
3 0  
0 3  
1 1  

```
## Input


```
6 3  

```
## Output


```
-1  

```
## Input


```
6 6  

```
## Output


```
10 0  
-10 0  
10 1  
9 1  
9 -1  
0 -2  

```
## Input


```
7 4  

```
## Output


```
176166 6377  
709276 539564  
654734 174109  
910147 434207  
790497 366519  
606663 21061  
859328 886001  

```


#### tags 

#2300 #constructive_algorithms #geometry 