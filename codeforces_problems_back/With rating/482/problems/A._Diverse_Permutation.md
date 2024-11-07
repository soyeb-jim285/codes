<h1 style='text-align: center;'> A. Diverse Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Permutation *p* is an ordered set of integers *p*1,   *p*2,   ...,   *p**n*, consisting of *n* distinct positive integers not larger than *n*. We'll denote as *n* the length of permutation *p*1,   *p*2,   ...,   *p**n*.

Your task is to find such permutation *p* of length *n*, that the group of numbers |*p*1 - *p*2|, |*p*2 - *p*3|, ..., |*p**n* - 1 - *p**n*| has exactly *k* distinct elements.

## Input

The single line of the input contains two space-separated positive integers *n*, *k* (1 ≤ *k* < *n* ≤ 105).

## Output

Print *n* integers forming the permutation. If there are multiple answers, print any of them.

## Examples

## Input


```
3 2  

```
## Output


```
1 3 2  

```
## Input


```
3 1  

```
## Output


```
1 2 3  

```
## Input


```
5 2  

```
## Output


```
1 3 2 4 5  

```
## Note

By |*x*| we denote the absolute value of number *x*. 



#### tags 

#1200 #constructive_algorithms #greedy 