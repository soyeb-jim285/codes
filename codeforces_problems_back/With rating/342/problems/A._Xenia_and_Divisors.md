<h1 style='text-align: center;'> A. Xenia and Divisors</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Xenia the mathematician has a sequence consisting of *n* (*n* is divisible by 3) positive integers, each of them is at most 7. She wants to split the sequence into groups of three so that for each group of three *a*, *b*, *c* the following conditions held:

* *a* < *b* < *c*;
* *a* divides *b*, *b* divides *c*.

Naturally, Xenia wants each element of the sequence to belong to exactly one group of three. Thus, if the required partition exists, then it has ![](images/4de0f387b35d0865b1f96d528b2f1b06fb6f1903.png) groups of three.

Help Xenia, find the required partition or else say that it doesn't exist.

## Input

The first line contains integer *n* (3 ≤ *n* ≤ 99999) — the number of elements in the sequence. The next line contains *n* positive integers, each of them is at most 7.

It is guaranteed that *n* is divisible by 3.

## Output

If the required partition exists, print ![](images/4de0f387b35d0865b1f96d528b2f1b06fb6f1903.png) groups of three. Print each group as values of the elements it contains. You should print values in increasing order. Separate the groups and integers in groups by whitespaces. If there are multiple solutions, you can print any of them.

If there is no solution, print -1.

## Examples

## Input


```
6  
1 1 1 2 2 2  

```
## Output


```
-1  

```
## Input


```
6  
2 2 1 1 4 6  

```
## Output


```
1 2 4  
1 2 6  

```


#### tags 

#1200 #greedy #implementation 