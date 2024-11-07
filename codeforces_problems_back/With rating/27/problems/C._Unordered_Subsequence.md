<h1 style='text-align: center;'> C. Unordered Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The sequence is called ordered if it is non-decreasing or non-increasing. For example, sequnces [3, 1, 1, 0] and [1, 2, 3, 100] are ordered, but the sequence [1, 3, 3, 1] is not. You are given a sequence of numbers. You are to find it's shortest subsequence which is not ordered.

A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.

## Input

The first line of the input contains one integer *n* (1 ≤ *n* ≤ 105). The second line contains *n* space-separated integers — the given sequence. All numbers in this sequence do not exceed 106 by absolute value.

## Output

If the given sequence does not contain any unordered subsequences, output 0. Otherwise, output the length *k* of the shortest such subsequence. Then output *k* integers from the range [1..*n*] — indexes of the elements of this subsequence. If there are several solutions, output any of them.

## Examples

## Input


```
5  
67 499 600 42 23  

```
## Output


```
3  
1 3 5  

```
## Input


```
3  
1 2 3  

```
## Output


```
0  

```
## Input


```
3  
2 3 1  

```
## Output


```
3  
1 2 3  

```


#### tags 

#1900 #constructive_algorithms #greedy 