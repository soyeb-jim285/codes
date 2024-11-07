<h1 style='text-align: center;'> B. z-sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A student of *z*-school found a kind of sorting called *z*-sort. The array *a* with *n* elements are *z*-sorted if two conditions hold:

1. *a**i* ≥ *a**i* - 1 for all even *i*,
2. *a**i* ≤ *a**i* - 1 for all odd *i* > 1.

For example the arrays [1,2,1,2] and [1,1,1,1] are *z*-sorted while the array [1,2,3,4] isn’t *z*-sorted.

Can you make the array *z*-sorted?

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 1000) — the number of elements in the array *a*.

The second line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 109) — the elements of the array *a*.

## Output

If it's possible to make the array *a* *z*-sorted print *n* space separated integers *a**i* — the elements after *z*-sort. Otherwise print the only word "Impossible".

## Examples

## Input


```
4  
1 2 2 1  

```
## Output


```
1 2 1 2  

```
## Input


```
5  
1 3 2 2 5  

```
## Output


```
1 5 2 3 2  

```


#### tags 

#1000 #sortings 