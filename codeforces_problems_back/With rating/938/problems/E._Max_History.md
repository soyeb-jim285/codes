<h1 style='text-align: center;'> E. Max History</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *a* of length *n*. We define *f**a* the following way:

* Initially *f**a* = 0, *M* = 1;
* for every 2 ≤ *i* ≤ *n* if *a**M* < *a**i* then we set *f**a* = *f**a* + *a**M* and then set *M* = *i*.

Calculate the sum of *f**a* over all *n*! permutations of the array *a* modulo 109 + 7.

## Note

: two elements are considered different if their indices differ, so for every array *a* there are exactly *n*! permutations.

## Input

The first line contains integer *n* (1 ≤ *n* ≤  1 000 000) — the size of array *a*.

Second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤  *a**i* ≤  109).

## Output

Print the only integer, the sum of *f**a* over all *n*! permutations of the array *a* modulo 109 + 7.

## Examples

## Input


```
2  
1 3  

```
## Output


```
1
```
## Input


```
3  
1 1 2  

```
## Output


```
4
```
## Note

For the second example all the permutations are:

* *p* = [1, 2, 3] : *f**a* is equal to 1;
* *p* = [1, 3, 2] : *f**a* is equal to 1;
* *p* = [2, 1, 3] : *f**a* is equal to 1;
* *p* = [2, 3, 1] : *f**a* is equal to 1;
* *p* = [3, 1, 2] : *f**a* is equal to 0;
* *p* = [3, 2, 1] : *f**a* is equal to 0.

Where *p* is the array of the indices of initial array *a*. The sum of *f**a* is equal to 4.



#### tags 

#2300 #combinatorics #math 