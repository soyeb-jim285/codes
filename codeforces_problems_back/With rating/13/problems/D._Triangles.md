<h1 style='text-align: center;'> D. Triangles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Little Petya likes to draw. He drew *N* red and *M* blue points on the plane in such a way that no three points lie on the same line. Now he wonders what is the number of distinct triangles with vertices in red points which do not contain any blue point inside.

## Input

The first line contains two non-negative integer numbers *N* and *M* (0 ≤ *N* ≤ 500, 0 ≤ *M* ≤ 500) — the number of red and blue points respectively. The following *N* lines contain two integer numbers each — coordinates of red points. The following *M* lines contain two integer numbers each — coordinates of blue points. All coordinates do not exceed 109 by absolute value.

## Output

## Output

 one integer — the number of distinct triangles with vertices in red points which do not contain any blue point inside.

## Examples

## Input


```
4 1  
0 0  
10 0  
10 10  
5 4  
2 1  

```
## Output


```
2  

```
## Input


```
5 5  
5 10  
6 1  
8 6  
-6 -7  
7 -1  
5 -1  
10 -4  
-10 -8  
-10 5  
-2 -8  

```
## Output


```
7  

```


#### tags 

#2600 #dp #geometry 