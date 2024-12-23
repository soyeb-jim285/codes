<h1 style='text-align: center;'> A. Perfect Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A permutation is a sequence of integers *p*1, *p*2, ..., *p**n*, consisting of *n* distinct positive integers, each of them doesn't exceed *n*. Let's denote the *i*-th element of permutation *p* as *p**i*. We'll call number *n* the size of permutation *p*1, *p*2, ..., *p**n*.

Nickolas adores permutations. He likes some permutations more than the others. He calls such permutations perfect. A perfect permutation is such permutation *p* that for any *i* (1 ≤ *i* ≤ *n*) (*n* is the permutation size) the following equations hold *p**p**i* = *i* and *p**i* ≠ *i*. Nickolas asks you to print any perfect permutation of size *n* for the given *n*.

## Input

A single line contains a single integer *n* (1 ≤ *n* ≤ 100) — the permutation size.

## Output

If a perfect permutation of size *n* doesn't exist, print a single integer -1. Otherwise print *n* distinct integers from 1 to *n*, *p*1, *p*2, ..., *p**n* — permutation *p*, that is perfect. Separate printed numbers by whitespaces.

## Examples

## Input


```
1  

```
## Output


```
-1  

```
## Input


```
2  

```
## Output


```
2 1   

```
## Input


```
4  

```
## Output


```
2 1 4 3   

```


#### tags 

#800 #implementation #math 