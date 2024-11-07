<h1 style='text-align: center;'> E. Positions in Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Permutation *p* is an ordered set of integers *p*1,  *p*2,  ...,  *p**n*, consisting of *n* distinct positive integers, each of them doesn't exceed *n*. We'll denote the *i*-th element of permutation *p* as *p**i*. We'll call number *n* the size or the length of permutation *p*1,  *p*2,  ...,  *p**n*.

We'll call position *i* (1 ≤ *i* ≤ *n*) in permutation *p*1, *p*2, ..., *p**n* good, if |*p*[*i*] - *i*| = 1. Count the number of permutations of size *n* with exactly *k* good positions. Print the answer modulo 1000000007 (109 + 7).

## Input

The single line contains two space-separated integers *n* and *k* (1 ≤ *n* ≤ 1000, 0 ≤ *k* ≤ *n*).

## Output

Print the number of permutations of length *n* with exactly *k* good positions modulo 1000000007 (109 + 7).

## Examples

## Input


```
1 0  

```
## Output


```
1  

```
## Input


```
2 1  

```
## Output


```
0  

```
## Input


```
3 2  

```
## Output


```
4  

```
## Input


```
4 1  

```
## Output


```
6  

```
## Input


```
7 4  

```
## Output


```
328  

```
## Note

The only permutation of size 1 has 0 good positions.

Permutation (1, 2) has 0 good positions, and permutation (2, 1) has 2 positions.

Permutations of size 3:

1. (1, 2, 3) — 0 positions
2. ![](images/eacaee9ed78760263daaea6c99f00e6bed9f63f4.png) — 2 positions
3. ![](images/343aae148f8c6b48690f76a6df180f876ed28a70.png) — 2 positions
4. ![](images/9a68a5e5de70440f14a7d6b51e01c4c2073157ea.png) — 2 positions
5. ![](images/d3fc11bb6a53a29b6b096f9567b8cbdca17addba.png) — 2 positions
6. (3, 2, 1) — 0 positions


#### tags 

#2600 #combinatorics #dp #math 