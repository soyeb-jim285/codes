<h1 style='text-align: center;'> D. Pair of Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Simon has an array *a*1, *a*2, ..., *a**n*, consisting of *n* positive integers. Today Simon asked you to find a pair of integers *l*, *r* (1 ≤ *l* ≤ *r* ≤ *n*), such that the following conditions hold:

1. there is integer *j* (*l* ≤ *j* ≤ *r*), such that all integers *a**l*, *a**l* + 1, ..., *a**r* are divisible by *a**j*;
2. value *r* - *l* takes the maximum value among all pairs for which condition 1 is true;

Help Simon, find the required pair of numbers (*l*, *r*). If there are multiple required pairs find all of them.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 3·105).

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 106).

## Output

Print two integers in the first line — the number of required pairs and the maximum value of *r* - *l*. On the following line print all *l* values from optimal pairs in increasing order.

## Examples

## Input


```
5  
4 6 9 3 6  

```
## Output


```
1 3  
2   

```
## Input


```
5  
1 3 5 7 9  

```
## Output


```
1 4  
1   

```
## Input


```
5  
2 3 5 7 11  

```
## Output


```
5 0  
1 2 3 4 5   

```
## Note

In the first sample the pair of numbers is right, as numbers 6, 9, 3 are divisible by 3.

In the second sample all numbers are divisible by number 1.

In the third sample all numbers are prime, so conditions 1 and 2 are true only for pairs of numbers (1, 1), (2, 2), (3, 3), (4, 4), (5, 5).



#### tags 

#2000 #binary_search #brute_force #data_structures #math #two_pointers 