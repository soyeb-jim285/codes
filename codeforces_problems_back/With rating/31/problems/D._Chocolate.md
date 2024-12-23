<h1 style='text-align: center;'> D. Chocolate</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob has a rectangular chocolate bar of the size *W* × *H*. He introduced a cartesian coordinate system so that the point (0, 0) corresponds to the lower-left corner of the bar, and the point (*W*, *H*) corresponds to the upper-right corner. Bob decided to split the bar into pieces by breaking it. Each break is a segment parallel to one of the coordinate axes, which connects the edges of the bar. More formally, each break goes along the line *x* = *x**c* or *y* = *y**c*, where *x**c* and *y**c* are integers. It should divide one part of the bar into two non-empty parts. After Bob breaks some part into two parts, he breaks the resulting parts separately and independently from each other. Also he doesn't move the parts of the bar. Bob made *n* breaks and wrote them down in his notebook in arbitrary order. At the end he got *n* + 1 parts. Now he wants to calculate their areas. Bob is lazy, so he asks you to do this task.

## Input

The first line contains 3 integers *W*, *H* and *n* (1 ≤ *W*, *H*, *n* ≤ 100) — width of the bar, height of the bar and amount of breaks. Each of the following *n* lines contains four integers *x**i*, 1, *y**i*, 1, *x**i*, 2, *y**i*, 2 — coordinates of the endpoints of the *i*-th break (0 ≤ *x**i*, 1 ≤ *x**i*, 2 ≤ *W*, 0 ≤ *y**i*, 1 ≤ *y**i*, 2 ≤ *H*, or *x**i*, 1 = *x**i*, 2, or *y**i*, 1 = *y**i*, 2). Breaks are given in arbitrary order.

It is guaranteed that the set of breaks is correct, i.e. there is some order of the given breaks that each next break divides exactly one part of the bar into two non-empty parts.

## Output

## Output

 *n* + 1 numbers — areas of the resulting parts in the increasing order.

## Examples

## Input


```
2 2 2  
1 0 1 2  
0 1 1 1  

```
## Output


```
1 1 2 
```
## Input


```
2 2 3  
1 0 1 2  
0 1 1 1  
1 1 2 1  

```
## Output


```
1 1 1 1 
```
## Input


```
2 4 2  
0 1 2 1  
0 3 2 3  

```
## Output


```
2 2 4 
```


#### tags 

#2000 #dfs_and_similar #implementation 