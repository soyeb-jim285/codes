<h1 style='text-align: center;'> B. Eight Point Sets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gerald is very particular to eight point sets. He thinks that any decent eight point set must consist of all pairwise intersections of three distinct integer vertical straight lines and three distinct integer horizontal straight lines, except for the average of these nine points. In other words, there must be three integers *x*1, *x*2, *x*3 and three more integers *y*1, *y*2, *y*3, such that *x*1 < *x*2 < *x*3, *y*1 < *y*2 < *y*3 and the eight point set consists of all points (*x**i*, *y**j*) (1 ≤ *i*, *j* ≤ 3), except for point (*x*2, *y*2).

You have a set of eight points. Find out if Gerald can use this set?

## Input

The input consists of eight lines, the *i*-th line contains two space-separated integers *x**i* and *y**i* (0 ≤ *x**i*, *y**i* ≤ 106). You do not have any other conditions for these points.

## Output

In a single line print word "respectable", if the given set of points corresponds to Gerald's decency rules, and "ugly" otherwise.

## Examples

## Input


```
0 0  
0 1  
0 2  
1 0  
1 2  
2 0  
2 1  
2 2  

```
## Output


```
respectable  

```
## Input


```
0 0  
1 0  
2 0  
3 0  
4 0  
5 0  
6 0  
7 0  

```
## Output


```
ugly  

```
## Input


```
1 1  
1 2  
1 3  
2 1  
2 2  
2 3  
3 1  
3 2  

```
## Output


```
ugly  

```


#### tags 

#1400 #sortings 