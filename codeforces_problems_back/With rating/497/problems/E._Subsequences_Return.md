<h1 style='text-align: center;'> E. Subsequences Return</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Assume that *s**k*(*n*) equals the sum of digits of number *n* in the *k*-based notation. For example, *s*2(5) = *s*2(1012) = 1 + 0 + 1 = 2, *s*3(14) = *s*3(1123) = 1 + 1 + 2 = 4.

The sequence of integers *a*0, ..., *a**n* - 1 is defined as ![](images/3d69672a1eeecefd43ff353cc9755741cf4b9b57.png). Your task is to calculate the number of distinct subsequences of sequence *a*0, ..., *a**n* - 1. Calculate the answer modulo 109 + 7.

Sequence *a*1, ..., *a**k* is called to be a subsequence of sequence *b*1, ..., *b**l*, if there is a sequence of indices 1 ≤ *i*1 < ... < *i**k* ≤ *l*, such that *a*1 = *b**i*1, ..., *a**k* = *b**i**k*. In particular, an empty sequence (i.e. the sequence consisting of zero elements) is a subsequence of any sequence.

## Input

The first line contains two space-separated numbers *n* and *k* (1 ≤ *n* ≤ 1018, 2 ≤ *k* ≤ 30).

## Output

In a single line print the answer to the problem modulo 109 + 7.

## Examples

## Input


```
4 2  

```
## Output


```
11  

```
## Input


```
7 7  

```
## Output


```
128  

```
## Note

In the first sample the sequence *a**i* looks as follows: (0, 1, 1, 0). All the possible subsequences are: 

(), (0), (0, 0), (0, 1), (0, 1, 0), (0, 1, 1), (0, 1, 1, 0), (1), (1, 0), (1, 1), (1, 1, 0).In the second sample the sequence *a**i* looks as follows: (0, 1, 2, 3, 4, 5, 6). The subsequences of this sequence are exactly all increasing sequences formed from numbers from 0 to 6. It is easy to see that there are 27 = 128 such sequences.



#### tags 

#2900 #dp #matrices 