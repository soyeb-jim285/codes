<h1 style='text-align: center;'> B. Restoration of the Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let *A* = {*a*1, *a*2, ..., *a**n*} be any permutation of the first *n* natural numbers {1, 2, ..., *n*}. You are given a positive integer *k* and another sequence *B* = {*b*1, *b*2, ..., *b**n*}, where *b**i* is the number of elements *a**j* in *A* to the left of the element *a**t* = *i* such that *a**j* ≥ (*i* + *k*).

For example, if *n* = 5, a possible *A* is {5, 1, 4, 2, 3}. For *k* = 2, *B* is given by {1, 2, 1, 0, 0}. But if *k* = 3, then *B* = {1, 1, 0, 0, 0}.

For two sequences *X* = {*x*1, *x*2, ..., *x**n*} and *Y* = {*y*1, *y*2, ..., *y**n*}, let *i*-th elements be the first elements such that *x**i* ≠ *y**i*. If *x**i* < *y**i*, then *X* is lexicographically smaller than *Y*, while if *x**i* > *y**i*, then *X* is lexicographically greater than *Y*.

Given *n*, *k* and *B*, you need to determine the lexicographically smallest *A*.

## Input

The first line contains two space separated integers *n* and *k* (1 ≤ *n* ≤ 1000, 1 ≤ *k* ≤ *n*). On the second line are *n* integers specifying the values of *B* = {*b*1, *b*2, ..., *b**n*}.

## Output

Print on a single line *n* integers of *A* = {*a*1, *a*2, ..., *a**n*} such that *A* is lexicographically minimal. It is guaranteed that the solution exists.

## Examples

## Input


```
5 2  
1 2 1 0 0  

```
## Output


```
4 1 5 2 3 
```
## Input


```
4 2  
1 0 0 0  

```
## Output


```
2 3 1 4 
```


#### tags 

#1800 #greedy 