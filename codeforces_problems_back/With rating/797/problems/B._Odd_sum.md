<h1 style='text-align: center;'> B. Odd sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given sequence *a*1, *a*2, ..., *a**n* of integer numbers of length *n*. Your task is to find such subsequence that its sum is odd and maximum among all such subsequences. It's guaranteed that given sequence contains subsequence with odd sum.

Subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

You should write a program which finds sum of the best subsequence.

## Input

The first line contains integer number *n* (1 ≤ *n* ≤ 105).

The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* ( - 104 ≤ *a**i* ≤ 104). The sequence contains at least one subsequence with odd sum.

## Output

Print sum of resulting subseqeuence.

## Examples

## Input


```
4  
-2 2 -3 1  

```
## Output


```
3  

```
## Input


```
3  
2 -5 -3  

```
## Output


```
-1  

```
## Note

In the first example sum of the second and the fourth elements is 3.



#### tags 

#1400 #dp #greedy #implementation 