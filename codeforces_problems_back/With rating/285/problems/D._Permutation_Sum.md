<h1 style='text-align: center;'> D. Permutation Sum</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Permutation *p* is an ordered set of integers *p*1,  *p*2,  ...,  *p**n*, consisting of *n* distinct positive integers, each of them doesn't exceed *n*. We'll denote the *i*-th element of permutation *p* as *p**i*. We'll call number *n* the size or the length of permutation *p*1,  *p*2,  ...,  *p**n*.

Petya decided to introduce the sum operation on the set of permutations of length *n*. Let's assume that we are given two permutations of length *n*: *a*1, *a*2, ..., *a**n* and *b*1, *b*2, ..., *b**n*. Petya calls the sum of permutations *a* and *b* such permutation *c* of length *n*, where *c**i* = ((*a**i* - 1 + *b**i* - 1) *mod* *n*) + 1 (1 ≤ *i* ≤ *n*).

Operation ![](images/1d533a6df05afe2c303e325bb11b740c58acf6da.png) means taking the remainder after dividing number *x* by number *y*.

Obviously, not for all permutations *a* and *b* exists permutation *c* that is sum of *a* and *b*. That's why Petya got sad and asked you to do the following: given *n*, count the number of such pairs of permutations *a* and *b* of length *n*, that exists permutation *c* that is sum of *a* and *b*. The pair of permutations *x*, *y* (*x* ≠ *y*) and the pair of permutations *y*, *x* are considered distinct pairs.

As the answer can be rather large, print the remainder after dividing it by 1000000007 (109 + 7).

## Input

The single line contains integer *n* (1 ≤ *n* ≤ 16).

## Output

In the single line print a single non-negative integer — the number of such pairs of permutations *a* and *b*, that exists permutation *c* that is sum of *a* and *b*, modulo 1000000007 (109 + 7).

## Examples

## Input


```
3  

```
## Output


```
18  

```
## Input


```
5  

```
## Output


```
1800  

```


#### tags 

#1900 #bitmasks #combinatorics #dp #implementation #meet-in-the-middle 