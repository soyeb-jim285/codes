<h1 style='text-align: center;'> F. AND-permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an integer *N*, find two permutations:

1. Permutation *p* of numbers from 1 to *N* such that *p**i* ≠ *i* and *p**i* & *i* = 0 for all *i* = 1, 2, ..., *N*.
2. Permutation *q* of numbers from 1 to *N* such that *q**i* ≠ *i* and *q**i* & *i* ≠ 0 for all *i* = 1, 2, ..., *N*.

& is the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

## Input

The input consists of one line containing a single integer *N* (1 ≤ *N* ≤ 105).

## Output

For each subtask, if the required permutation doesn't exist, output a single line containing the word "NO"; otherwise output the word "YES" in the first line and *N* elements of the permutation, separated by spaces, in the second line. If there are several possible permutations in a subtask, output any of them.

## Examples

## Input


```
3  

```
## Output


```
NO  
NO  

```
## Input


```
6  

```
## Output


```
YES  
6 5 4 3 2 1   
YES  
3 6 2 5 1 4  

```


#### tags 

#2500 #constructive_algorithms 