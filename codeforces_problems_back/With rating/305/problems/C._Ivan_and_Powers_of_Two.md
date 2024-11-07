<h1 style='text-align: center;'> C. Ivan and Powers of Two</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan has got an array of *n* non-negative integers *a*1, *a*2, ..., *a**n*. Ivan knows that the array is sorted in the non-decreasing order. 

Ivan wrote out integers 2*a*1, 2*a*2, ..., 2*a**n* on a piece of paper. Now he wonders, what minimum number of integers of form 2*b* (*b* ≥ 0) need to be added to the piece of paper so that the sum of all integers written on the paper equalled 2*v* - 1 for some integer *v* (*v* ≥ 0). 

Help Ivan, find the required quantity of numbers.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105). The second input line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 2·109). It is guaranteed that *a*1 ≤ *a*2 ≤ ... ≤ *a**n*.

## Output

Print a single integer — the answer to the problem.

## Examples

## Input


```
4  
0 1 1 1  

```
## Output


```
0  

```
## Input


```
1  
3  

```
## Output


```
3  

```
## Note

In the first sample you do not need to add anything, the sum of numbers already equals 23 - 1 = 7.

In the second sample you need to add numbers 20, 21, 22.



#### tags 

#1600 #greedy #implementation 