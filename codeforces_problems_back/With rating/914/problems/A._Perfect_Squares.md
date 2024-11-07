<h1 style='text-align: center;'> A. Perfect Squares</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array *a*1, *a*2, ..., *a**n* of *n* integers, find the largest number in the array that is not a perfect square.

A number *x* is said to be a perfect square if there exists an integer *y* such that *x* = *y*2.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 1000) — the number of elements in the array.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* ( - 106 ≤ *a**i* ≤ 106) — the elements of the array.

It is guaranteed that at least one element of the array is not a perfect square.

## Output

Print the largest number in the array which is not a perfect square. It is guaranteed that an answer always exists.

## Examples

## Input


```
2  
4 2  

```
## Output


```
2  

```
## Input


```
8  
1 2 4 8 16 32 64 576  

```
## Output


```
32  

```
## Note

In the first sample case, 4 is a perfect square, so the largest number in the array that is not a perfect square is 2.



#### tags 

#900 #brute_force #implementation #math 