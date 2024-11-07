<h1 style='text-align: center;'> A. Slightly Decreasing Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Permutation *p* is an ordered set of integers *p*1,  *p*2,  ...,  *p**n*, consisting of *n* distinct positive integers, each of them doesn't exceed *n*. We'll denote the *i*-th element of permutation *p* as *p**i*. We'll call number *n* the size or the length of permutation *p*1,  *p*2,  ...,  *p**n*.

The decreasing coefficient of permutation *p*1, *p*2, ..., *p**n* is the number of such *i* (1 ≤ *i* < *n*), that *p**i* > *p**i* + 1.

You have numbers *n* and *k*. Your task is to print the permutation of length *n* with decreasing coefficient *k*.

## Input

The single line contains two space-separated integers: *n*, *k* (1 ≤ *n* ≤ 105, 0 ≤ *k* < *n*) — the permutation length and the decreasing coefficient.

## Output

In a single line print *n* space-separated integers: *p*1, *p*2, ..., *p**n* — the permutation of length *n* with decreasing coefficient *k*. 

If there are several permutations that meet this condition, print any of them. It is guaranteed that the permutation with the sought parameters exists.

## Examples

## Input


```
5 2  

```
## Output


```
1 5 2 4 3  

```
## Input


```
3 0  

```
## Output


```
1 2 3  

```
## Input


```
3 2  

```
## Output


```
3 2 1  

```


#### tags 

#1100 #greedy #implementation 