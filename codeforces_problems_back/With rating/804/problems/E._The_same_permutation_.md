<h1 style='text-align: center;'> E. The same permutation </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Seyyed and MoJaK are friends of Sajjad. Sajjad likes a permutation. Seyyed wants to change the permutation in a way that Sajjad won't like it. Seyyed thinks more swaps yield more probability to do that, so he makes MoJaK to perform a swap between every pair of positions (*i*, *j*), where *i* < *j*, exactly once. MoJaK doesn't like to upset Sajjad.

Given the permutation, determine whether it is possible to swap all pairs of positions so that the permutation stays the same. If it is possible find how to do that. 

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 1000) — the size of the permutation.

As the permutation is not important, you can consider *a**i* = *i*, where the permutation is *a*1, *a*2, ..., *a**n*.

## Output

If it is not possible to swap all pairs of positions so that the permutation stays the same, print "NO",

Otherwise print "YES", then print ![](images/66a19249b26d808e85ea349b8b84dee8a2090e0c.png) lines: the *i*-th of these lines should contain two integers *a* and *b* (*a* < *b*) — the positions where the *i*-th swap is performed.

## Examples

## Input


```
3  

```
## Output


```
NO  

```
## Input


```
1  

```
## Output


```
YES  

```


#### tags 

#3100 #constructive_algorithms 