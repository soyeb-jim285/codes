<h1 style='text-align: center;'> C. On the Bench</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A year ago on the bench in public park Leha found an array of *n* numbers. Leha believes that permutation *p* is right if for all 1 ≤ *i* < *n* condition, that *a**p**i*·*a**p**i* + 1 is not perfect square, holds. Leha wants to find number of right permutations modulo 109 + 7.

## Input

First line of input data contains single integer *n* (1 ≤ *n* ≤ 300) — length of the array.

Next line contains *n* integers *a*1, *a*2, ... , *a**n* (1 ≤ *a**i* ≤ 109) — found array.

## Output

## Output

 single integer — number of right permutations modulo 109 + 7.

## Examples

## Input


```
3  
1 2 4  

```
## Output


```
2  

```
## Input


```
7  
5 2 4 2 4 1 1  

```
## Output


```
144  

```
## Note

For first example:

[1, 2, 4] — right permutation, because 2 and 8 are not perfect squares.

[1, 4, 2] — wrong permutation, because 4 is square of 2.

[2, 1, 4] — wrong permutation, because 4 is square of 2.

[2, 4, 1] — wrong permutation, because 4 is square of 2.

[4, 1, 2] — wrong permutation, because 4 is square of 2.

[4, 2, 1] — right permutation, because 8 and 2 are not perfect squares.



#### tags 

#2500 #combinatorics #dp 