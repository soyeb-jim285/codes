<h1 style='text-align: center;'> C. Maximal GCD</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given positive integer number *n*. You should create such strictly increasing sequence of *k* positive numbers *a*1, *a*2, ..., *a**k*, that their sum is equal to *n* and greatest common divisor is maximal.

Greatest common divisor of sequence is maximum of such numbers that every element of sequence is divisible by them.

If there is no possible sequence then output -1.

## Input

The first line consists of two numbers *n* and *k* (1 ≤ *n*, *k* ≤ 1010).

## Output

If the answer exists then output *k* numbers — resulting sequence. Otherwise output -1. If there are multiple answers, print any of them.

## Examples

## Input


```
6 3  

```
## Output


```
1 2 3  

```
## Input


```
8 2  

```
## Output


```
2 6  

```
## Input


```
5 3  

```
## Output


```
-1  

```


#### tags 

#1900 #constructive_algorithms #greedy #math 