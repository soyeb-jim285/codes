<h1 style='text-align: center;'> D. Two Melodies</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice is a beginner composer and now she is ready to create another masterpiece. And not even the single one but two at the same time! 

Alice has a sheet with *n* notes written on it. She wants to take two such non-empty non-intersecting subsequences that both of them form a melody and sum of their lengths is maximal.

Subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

Subsequence forms a melody when each two adjacent notes either differs by 1 or are congruent modulo 7.

You should write a program which will calculate maximum sum of lengths of such two non-empty non-intersecting subsequences that both of them form a melody.

## Input

The first line contains one integer number *n* (2 ≤ *n* ≤ 5000).

The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105) — notes written on a sheet.

## Output

Print maximum sum of lengths of such two non-empty non-intersecting subsequences that both of them form a melody.

## Examples

## Input


```
4  
1 2 4 5  

```
## Output


```
4  

```
## Input


```
6  
62 22 60 61 48 49  

```
## Output


```
5  

```
## Note

In the first example subsequences [1, 2] and [4, 5] give length 4 in total.

In the second example subsequences [62, 48, 49] and [60, 61] give length 5 in total. If you choose subsequence [62, 61] in the first place then the second melody will have maximum length 2, that gives the result of 4, which is not maximal.



#### tags 

#2600 #dp #flows 