<h1 style='text-align: center;'> H. Points in triangle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a set of points on a plane with positive integer coordinates. Find a triangle of minimum area with vertices in points (0, 0), (*A*, 0) and (0, *B*) (*A* and *B* are unknown positive integers) that contains all the given points inside it (points on the edges count towards being inside).

## Input

The first line of the input contains an integer *N* (1 ≤ *N* ≤ 100) — the number of points. The following *N* lines contain pairs of numbers *X* and *Y* (1 ≤ *X*, *Y* ≤ 100) - the coordinates of the points. All points are distinct.

## Output

## Output

 one floating-point number — the minimal area of the triangle. The answer is considered to be correct if its absolute or relative error does not exceed 10- 4.

## Examples

## Input


```
2  
1 1  
1 3  

```
## Output


```
6.0  

```
## Input


```
2  
2 1  
1 2  

```
## Output


```
4.5  

```


#### tags 

#2100 #*special #geometry 