<h1 style='text-align: center;'> D. Polyline</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are three points marked on the coordinate plane. The goal is to make a simple polyline, without self-intersections and self-touches, such that it passes through all these points. Also, the polyline must consist of only segments parallel to the coordinate axes. You are to find the minimum number of segments this polyline may consist of.

## Input

Each of the three lines of the input contains two integers. The *i*-th line contains integers *x**i* and *y**i* ( - 109 ≤ *x**i*, *y**i* ≤ 109) — the coordinates of the *i*-th point. It is guaranteed that all points are distinct.

## Output

Print a single number — the minimum possible number of segments of the polyline.

## Examples

## Input


```
1 -1  
1 1  
1 2  

```
## Output


```
1  

```
## Input


```
-1 -1  
-1 3  
4 3  

```
## Output


```
2  

```
## Input


```
1 1  
2 3  
3 2  

```
## Output


```
3  

```
## Note

The variant of the polyline in the first sample: ![](images/b41b4dad8437bd7a69f6ab01eaedf010b82ba7b8.png) The variant of the polyline in the second sample: ![](images/7410d2247b3381e5b27422609f90ff027e071812.png) The variant of the polyline in the third sample: ![](images/3a5018422eb982f0a2a9bd7f1fd7ab23777a0813.png)



#### tags 

#1700 #constructive_algorithms #implementation 