<h1 style='text-align: center;'> D. On Sum of Number of Inversions in Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation *p*. Calculate the total number of inversions in all permutations that lexicographically do not exceed the given one.

As this number can be very large, print it modulo 1000000007 (109 + 7).

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 106) — the length of the permutation. The second line contains *n* distinct integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*).

## Output

Print a single number — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
2  
2 1  

```
## Output


```
1  

```
## Input


```
3  
2 1 3  

```
## Output


```
2  

```
## Note

Permutation *p* of length *n* is the sequence that consists of *n* distinct integers, each of them is from 1 to *n*.

An inversion of permutation *p*1, *p*2, ..., *p**n* is a pair of indexes (*i*, *j*), such that *i* < *j* and *p**i* > *p**j*.

Permutation *a* do not exceed permutation *b* lexicographically, if either *a* = *b* or there exists such number *i*, for which the following logical condition fulfills: ![](images/ecb7310db358bbe288e686f1c88c3bb3da967725.png) AND (*a**i* < *b**i*).



#### tags 

#combinatorics #math 