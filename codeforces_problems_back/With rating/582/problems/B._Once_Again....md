<h1 style='text-align: center;'> B. Once Again...</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of positive integers *a*1, *a*2, ..., *a**n* × *T* of length *n* × *T*. We know that for any *i* > *n* it is true that *a**i* = *a**i* - *n*. Find the length of the longest non-decreasing sequence of the given array.

## Input

The first line contains two space-separated integers: *n*, *T* (1 ≤ *n* ≤ 100, 1 ≤ *T* ≤ 107). The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 300).

## Output

Print a single number — the length of a sought sequence.

## Examples

## Input


```
4 3  
3 1 4 2  

```
## Output


```
5  

```
## Note

The array given in the sample looks like that: 3, 1, 4, 2, 3, 1, 4, 2, 3, 1, 4, 2. The elements in bold form the largest non-decreasing subsequence. 



#### tags 

#1900 #constructive_algorithms #dp #matrices 