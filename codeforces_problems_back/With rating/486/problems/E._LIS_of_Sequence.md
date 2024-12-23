<h1 style='text-align: center;'> E. LIS of Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The next "Data Structures and Algorithms" lesson will be about Longest Increasing Subsequence (LIS for short) of a sequence. For better understanding, Nam decided to learn it a few days before the lesson.

Nam created a sequence *a* consisting of *n* (1 ≤ *n* ≤ 105) elements *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105). A subsequence *a**i*1, *a**i*2, ..., *a**i**k* where 1 ≤ *i*1 < *i*2 < ... < *i**k* ≤ *n* is called increasing if *a**i*1 < *a**i*2 < *a**i*3 < ... < *a**i**k*. An increasing subsequence is called longest if it has maximum length among all increasing subsequences. 

Nam realizes that a sequence may have several longest increasing subsequences. Hence, he divides all indexes *i* (1 ≤ *i* ≤ *n*), into three groups:

1. group of all *i* such that *a**i* belongs to no longest increasing subsequences.
2. group of all *i* such that *a**i* belongs to at least one but not every longest increasing subsequence.
3. group of all *i* such that *a**i* belongs to every longest increasing subsequence.

Since the number of longest increasing subsequences of *a* may be very large, categorizing process is very difficult. Your task is to help him finish this job.

## Input

The first line contains the single integer *n* (1 ≤ *n* ≤ 105) denoting the number of elements of sequence *a*.

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105).

## Output

Print a string consisting of *n* characters. *i*-th character should be '1', '2' or '3' depending on which group among listed above index *i* belongs to.

## Examples

## Input


```
1  
4  

```
## Output


```
3  

```
## Input


```
4  
1 3 2 5  

```
## Output


```
3223  

```
## Input


```
4  
1 5 2 3  

```
## Output


```
3133  

```
## Note

In the second sample, sequence *a* consists of 4 elements: {*a*1, *a*2, *a*3, *a*4} = {1, 3, 2, 5}. Sequence *a* has exactly 2 longest increasing subsequences of length 3, they are {*a*1, *a*2, *a*4} = {1, 3, 5} and {*a*1, *a*3, *a*4} = {1, 2, 5}.

In the third sample, sequence *a* consists of 4 elements: {*a*1, *a*2, *a*3, *a*4} = {1, 5, 2, 3}. Sequence *a* have exactly 1 longest increasing subsequence of length 3, that is {*a*1, *a*3, *a*4} = {1, 2, 3}.



#### tags 

#2200 #data_structures #dp #greedy #hashing #math 