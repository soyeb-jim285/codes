<h1 style='text-align: center;'> C. Secret</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Greatest Secret Ever consists of *n* words, indexed by positive integers from 1 to *n*. The secret needs dividing between *k* Keepers (let's index them by positive integers from 1 to *k*), the *i*-th Keeper gets a non-empty set of words with numbers from the set *U**i* = (*u**i*, 1, *u**i*, 2, ..., *u**i*, |*U**i*|). Here and below we'll presuppose that the set elements are written in the increasing order.

We'll say that the secret is safe if the following conditions are hold:

* for any two indexes *i*, *j* (1 ≤ *i* < *j* ≤ *k*) the intersection of sets *U**i* and *U**j* is an empty set;
* the union of sets *U*1, *U*2, ..., *U**k* is set (1, 2, ..., *n*);
* in each set *U**i*, its elements *u**i*, 1, *u**i*, 2, ..., *u**i*, |*U**i*| do not form an arithmetic progression (in particular, |*U**i*| ≥ 3 should hold).

Let us remind you that the elements of set (*u*1, *u*2, ..., *u**s*) form an arithmetic progression if there is such number *d*, that for all *i* (1 ≤ *i* < *s*) fulfills *u**i* + *d* = *u**i* + 1. For example, the elements of sets (5), (1, 10) and (1, 5, 9) form arithmetic progressions and the elements of sets (1, 2, 4) and (3, 6, 8) don't.

Your task is to find any partition of the set of words into subsets *U*1, *U*2, ..., *U**k* so that the secret is safe. Otherwise indicate that there's no such partition.

## Input

The input consists of a single line which contains two integers *n* and *k* (2 ≤ *k* ≤ *n* ≤ 106) — the number of words in the secret and the number of the Keepers. The numbers are separated by a single space.

## Output

If there is no way to keep the secret safe, print a single integer "-1" (without the quotes). Otherwise, print *n* integers, the *i*-th of them representing the number of the Keeper who's got the *i*-th word of the secret.

If there are multiple solutions, print any of them.

## Examples

## Input


```
11 3  

```
## Output


```
3 1 2 1 1 2 3 2 2 3 1  

```
## Input


```
5 2  

```
## Output


```
-1  

```


#### tags 

#1500 #constructive_algorithms #implementation 