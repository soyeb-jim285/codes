<h1 style='text-align: center;'> E. Mike and code of a permutation</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mike has discovered a new way to encode permutations. If he has a permutation *P* = [*p*1, *p*2, ..., *p**n*], he will encode it in the following way:

Denote by *A* = [*a*1, *a*2, ..., *a**n*] a sequence of length *n* which will represent the code of the permutation. For each *i* from 1 to *n* sequentially, he will choose the smallest unmarked *j* (1 ≤ *j* ≤ *n*) such that *p**i* < *p**j* and will assign to *a**i* the number *j* (in other words he performs *a**i* = *j*) and will mark *j*. If there is no such *j*, he'll assign to *a**i* the number  - 1 (he performs *a**i* =  - 1). 

Mike forgot his original permutation but he remembers its code. Your task is simple: find any permutation such that its code is the same as the code of Mike's original permutation.

You may assume that there will always be at least one valid permutation.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 500 000) — length of permutation.

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n* or *a**i* =  - 1) — the code of Mike's permutation.

You may assume that all positive values from *A* are different.

## Output

In first and only line print *n* numbers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — a permutation *P* which has the same code as the given one. ## Note

 that numbers in permutation are distinct.

## Examples

## Input


```
6  
2 -1 1 5 -1 4  

```
## Output


```
2 6 1 4 5 3  

```
## Input


```
8  
2 -1 4 -1 6 -1 8 -1  

```
## Output


```
1 8 2 7 3 6 4 5  

```
## Note

For the permutation from the first example:

*i* = 1, the smallest *j* is 2 because *p*2 = 6 > *p*1 = 2.

*i* = 2, there is no *j* because *p*2 = 6 is the greatest element in the permutation.

*i* = 3, the smallest *j* is 1 because *p*1 = 2 > *p*3 = 1.

*i* = 4, the smallest *j* is 5 (2 was already marked) because *p*5 = 5 > *p*4 = 4.

*i* = 5, there is no *j* because 2 is already marked.

*i* = 6, the smallest *j* is 4 because *p*4 = 4 > *p*6 = 3.



#### tags 

#3000 #constructive_algorithms #data_structures #graphs #sortings 