<h1 style='text-align: center;'> C. Prairie Partition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It can be shown that any positive integer *x* can be uniquely represented as *x* = 1 + 2 + 4 + ... + 2*k* - 1 + *r*, where *k* and *r* are integers, *k* ≥ 0, 0 < *r* ≤ 2*k*. Let's call that representation prairie partition of *x*.

For example, the prairie partitions of 12, 17, 7 and 1 are: 

 12 = 1 + 2 + 4 + 5,17 = 1 + 2 + 4 + 8 + 2,

7 = 1 + 2 + 4,

1 = 1. 

Alice took a sequence of positive integers (possibly with repeating elements), replaced every element with the sequence of summands in its prairie partition, arranged the resulting numbers in non-decreasing order and gave them to Borys. Now Borys wonders how many elements Alice's original sequence could contain. Find all possible options!

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105) — the number of numbers given from Alice to Borys.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1012; *a*1 ≤ *a*2 ≤ ... ≤ *a**n*) — the numbers given from Alice to Borys.

## Output

## Output

, in increasing order, all possible values of *m* such that there exists a sequence of positive integers of length *m* such that if you replace every element with the summands in its prairie partition and arrange the resulting numbers in non-decreasing order, you will get the sequence given in the input.

If there are no such values of *m*, output a single integer -1.

## Examples

## Input


```
8  
1 1 2 2 3 4 5 8  

```
## Output


```
2   

```
## Input


```
6  
1 1 1 2 2 2  

```
## Output


```
2 3   

```
## Input


```
5  
1 2 4 4 4  

```
## Output


```
-1  

```
## Note

In the first example, Alice could get the input sequence from [6, 20] as the original sequence.

In the second example, Alice's original sequence could be either [4, 5] or [3, 3, 3].



#### tags 

#2200 #binary_search #constructive_algorithms #greedy #math 