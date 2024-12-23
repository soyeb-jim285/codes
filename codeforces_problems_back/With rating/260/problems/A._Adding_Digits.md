<h1 style='text-align: center;'> A. Adding Digits</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has got two number: *a* and *b*. However, Vasya finds number *a* too short. So he decided to repeat the operation of lengthening number *a* *n* times.

One operation of lengthening a number means adding exactly one digit to the number (in the decimal notation) to the right provided that the resulting number is divisible by Vasya's number *b*. If it is impossible to obtain the number which is divisible by *b*, then the lengthening operation cannot be performed.

Your task is to help Vasya and print the number he can get after applying the lengthening operation to number *a* *n* times.

## Input

The first line contains three integers: *a*, *b*, *n* (1 ≤ *a*, *b*, *n* ≤ 105).

## Output

In a single line print the integer without leading zeros, which Vasya can get when he applies the lengthening operations to number *a* *n* times. If no such number exists, then print number -1. If there are multiple possible answers, print any of them.

## Examples

## Input


```
5 4 5  

```
## Output


```
524848  

```
## Input


```
12 11 1  

```
## Output


```
121  

```
## Input


```
260 150 10  

```
## Output


```
-1  

```


#### tags 

#1400 #implementation #math 