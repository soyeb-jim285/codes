<h1 style='text-align: center;'> A. Shooshuns and Sequence </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day shooshuns found a sequence of *n* integers, written on a blackboard. The shooshuns can perform one operation with it, the operation consists of two steps:

1. Find the number that goes *k*-th in the current sequence and add the same number to the end of the sequence;
2. Delete the first number of the current sequence.

The shooshuns wonder after how many operations all numbers on the board will be the same and whether all numbers will ever be the same.

## Input

The first line contains two space-separated integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 105).

The second line contains *n* space-separated integers: *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105) — the sequence that the shooshuns found.

## Output

Print the minimum number of operations, required for all numbers on the blackboard to become the same. If it is impossible to achieve, print -1.

## Examples

## Input


```
3 2  
3 1 1  

```
## Output


```
1  

```
## Input


```
3 1  
3 1 1  

```
## Output


```
-1  

```
## Note

In the first test case after the first operation the blackboard will have sequence [1, 1, 1]. So, one operation is enough to make all numbers the same. Thus, the answer equals one.

In the second test case the sequence will never consist of the same numbers. It will always contain at least two distinct numbers 3 and 1. Thus, the answer equals -1.



#### tags 

#1200 #brute_force #implementation 