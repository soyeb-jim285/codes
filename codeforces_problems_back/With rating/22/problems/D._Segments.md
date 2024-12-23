<h1 style='text-align: center;'> D. Segments</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* segments on the Ox-axis. You can drive a nail in any integer point on the Ox-axis line nail so, that all segments containing this point, are considered nailed down. If the nail passes through endpoint of some segment, this segment is considered to be nailed too. What is the smallest number of nails needed to nail all the segments down?

## Input

The first line of the input contains single integer number *n* (1 ≤ *n* ≤ 1000) — amount of segments. Following *n* lines contain descriptions of the segments. Each description is a pair of integer numbers — endpoints coordinates. All the coordinates don't exceed 10000 by absolute value. Segments can degenarate to points.

## Output

The first line should contain one integer number — the smallest number of nails needed to nail all the segments down. The second line should contain coordinates of driven nails separated by space in any order. If the answer is not unique, output any.

## Examples

## Input


```
2  
0 2  
2 5  

```
## Output


```
1  
2 
```
## Input


```
5  
0 3  
4 2  
4 8  
8 10  
7 7  

```
## Output


```
3  
7 10 3  

```


#### tags 

#1900 #greedy #sortings 