<h1 style='text-align: center;'> C. Building Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Permutation *p* is an ordered set of integers *p*1,  *p*2,  ...,  *p**n*, consisting of *n* distinct positive integers, each of them doesn't exceed *n*. We'll denote the *i*-th element of permutation *p* as *p**i*. We'll call number *n* the size or the length of permutation *p*1,  *p*2,  ...,  *p**n*.

You have a sequence of integers *a*1, *a*2, ..., *a**n*. In one move, you are allowed to decrease or increase any number by one. Count the minimum number of moves, needed to build a permutation from this sequence.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 3·105) — the size of the sought permutation. The second line contains *n* integers *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109).

## Output

Print a single number — the minimum number of moves.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
2  
3 0  

```
## Output


```
2  

```
## Input


```
3  
-1 -1 2  

```
## Output


```
6  

```
## Note

In the first sample you should decrease the first number by one and then increase the second number by one. The resulting permutation is (2, 1).

In the second sample you need 6 moves to build permutation (1, 3, 2).



#### tags 

#1200 #greedy #implementation #sortings 