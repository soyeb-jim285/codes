<h1 style='text-align: center;'> A. Pashmak and Garden</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pashmak has fallen in love with an attractive girl called Parmida since one year ago...

Today, Pashmak set up a meeting with his partner in a romantic garden. Unfortunately, Pashmak has forgotten where the garden is. But he remembers that the garden looks like a square with sides parallel to the coordinate axes. He also remembers that there is exactly one tree on each vertex of the square. Now, Pashmak knows the position of only two of the trees. Help him to find the position of two remaining ones.

## Input

The first line contains four space-separated *x*1, *y*1, *x*2, *y*2 ( - 100 ≤ *x*1, *y*1, *x*2, *y*2 ≤ 100) integers, where *x*1 and *y*1 are coordinates of the first tree and *x*2 and *y*2 are coordinates of the second tree. It's guaranteed that the given points are distinct.

## Output

If there is no solution to the problem, print -1. Otherwise print four space-separated integers *x*3, *y*3, *x*4, *y*4 that correspond to the coordinates of the two other trees. If there are several solutions you can output any of them. 

Note that *x*3, *y*3, *x*4, *y*4 must be in the range ( - 1000 ≤ *x*3, *y*3, *x*4, *y*4 ≤ 1000).

## Examples

## Input


```
0 0 0 1  

```
## Output


```
1 0 1 1  

```
## Input


```
0 0 1 1  

```
## Output


```
0 1 1 0  

```
## Input


```
0 0 1 2  

```
## Output


```
-1  

```


#### tags 

#1200 #implementation 