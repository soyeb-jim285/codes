<h1 style='text-align: center;'> C. Prime Number</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Simon has a prime number *x* and an array of non-negative integers *a*1, *a*2, ..., *a**n*.

Simon loves fractions very much. Today he wrote out number ![](images/0e5514847e09ee88944c28dc39e468fe8e103f70.png) on a piece of paper. After Simon led all fractions to a common denominator and summed them up, he got a fraction: ![](images/51780b9051ed8ac533fe055b34e1fb589b48815e.png), where number *t* equals *x**a*1 + *a*2 + ... + *a**n*. Now Simon wants to reduce the resulting fraction. 

Help him, find the greatest common divisor of numbers *s* and *t*. As GCD can be rather large, print it as a remainder after dividing it by number 1000000007 (109 + 7).

## Input

The first line contains two positive integers *n* and *x* (1 ≤ *n* ≤ 105, 2 ≤ *x* ≤ 109) — the size of the array and the prime number.

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a*1 ≤ *a*2 ≤ ... ≤ *a**n* ≤ 109). 

## Output

Print a single number — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
2 2  
2 2  

```
## Output


```
8  

```
## Input


```
3 3  
1 2 3  

```
## Output


```
27  

```
## Input


```
2 2  
29 29  

```
## Output


```
73741817  

```
## Input


```
4 5  
0 0 0 0  

```
## Output


```
1  

```
## Note

In the first sample ![](images/7745f7cc87c6c5f753e3414fad9baa3b1e3fea48.png). Thus, the answer to the problem is 8.

In the second sample, ![](images/acb3d7990f024100be499bcb59828fa6e23a867d.png). The answer to the problem is 27, as 351 = 13·27, 729 = 27·27.

In the third sample the answer to the problem is 1073741824 *mod* 1000000007 = 73741817.

In the fourth sample ![](images/05a5fca3fb4690369838ff6dfeda521c959aa937.png). Thus, the answer to the problem is 1.



#### tags 

#1900 #math #number_theory 