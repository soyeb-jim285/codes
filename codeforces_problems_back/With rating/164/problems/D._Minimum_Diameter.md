<h1 style='text-align: center;'> D. Minimum Diameter</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* points on the plane. You need to delete exactly *k* of them (*k* < *n*) so that the diameter of the set of the remaining *n* - *k* points were as small as possible. The diameter of a set of points is the maximum pairwise distance between the points of the set. The diameter of a one point set equals zero.

## Input

The first input line contains a pair of integers *n*, *k* (2 ≤ *n* ≤ 1000, 1 ≤ *k* ≤ 30, *k* < *n*) — the numbers of points on the plane and the number of points to delete, correspondingly.

Next *n* lines describe the points, one per line. Each description consists of a pair of integers *x**i*, *y**i* (0 ≤ *x**i*, *y**i* ≤ 32000) — the coordinates of the *i*-th point. The given points can coincide.

## Output

Print *k* different space-separated integers from 1 to *n* — the numbers of points to delete. The points are numbered in the order, in which they are given in the input from 1 to *n*. You can print the numbers in any order. If there are multiple solutions, print any of them.

## Examples

## Input


```
5 2  
1 2  
0 0  
2 2  
1 1  
3 3  

```
## Output


```
5 2
```
## Input


```
4 1  
0 0  
0 0  
1 1  
1 1  

```
## Output


```
3
```


#### tags 

#3100 #binary_search #brute_force 