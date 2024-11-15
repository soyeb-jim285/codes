<h1 style='text-align: center;'> E. Very simple problem</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a convex polygon. Count, please, the number of triangles that contain a given point in the plane and their vertices are the vertices of the polygon. It is guaranteed, that the point doesn't lie on the sides and the diagonals of the polygon.

## Input

The first line contains integer *n* — the number of vertices of the polygon (3 ≤ *n* ≤ 100000). The polygon description is following: *n* lines containing coordinates of the vertices in clockwise order (integer *x* and *y* not greater than 109 by absolute value). It is guaranteed that the given polygon is nondegenerate and convex (no three points lie on the same line).

The next line contains integer *t* (1 ≤ *t* ≤ 20) — the number of points which you should count the answer for. It is followed by *t* lines with coordinates of the points (integer *x* and *y* not greater than 109 by absolute value).

## Output

The output should contain *t* integer numbers, each on a separate line, where *i*-th number is the answer for the *i*-th point.

Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cin (also you may use %I64d).

## Examples

## Input


```
4  
5 0  
0 0  
0 5  
5 5  
1  
1 3  

```
## Output


```
2  

```
## Input


```
3  
0 0  
0 5  
5 0  
2  
1 1  
10 10  

```
## Output


```
1  
0  

```
## Input


```
5  
7 6  
6 3  
4 1  
1 2  
2 4  
4  
3 3  
2 3  
5 5  
4 2  

```
## Output


```
5  
3  
3  
4  

```


#### tags 

#2500 #geometry #two_pointers 