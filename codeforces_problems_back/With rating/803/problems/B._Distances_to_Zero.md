<h1 style='text-align: center;'> B. Distances to Zero</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given the array of integer numbers *a*0, *a*1, ..., *a**n* - 1. For each element find the distance to the nearest zero (to the element which equals to zero). There is at least one zero element in the given array.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 2·105) — length of the array *a*. The second line contains integer elements of the array separated by single spaces ( - 109 ≤ *a**i* ≤ 109).

## Output

Print the sequence *d*0, *d*1, ..., *d**n* - 1, where *d**i* is the difference of indices between *i* and nearest *j* such that *a**j* = 0. It is possible that *i* = *j*.

## Examples

## Input


```
9  
2 1 0 3 0 0 3 2 4  

```
## Output


```
2 1 0 1 0 0 1 2 3 
```
## Input


```
5  
0 1 2 3 4  

```
## Output


```
0 1 2 3 4 
```
## Input


```
7  
5 6 0 1 -2 3 4  

```
## Output


```
2 1 0 1 2 3 4 
```


#### tags 

#1200 #constructive_algorithms 