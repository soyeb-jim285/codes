<h1 style='text-align: center;'> C. Given Length and Sum of Digits...</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a positive integer *m* and a non-negative integer *s*. Your task is to find the smallest and the largest of the numbers that have length *m* and sum of digits *s*. The required numbers should be non-negative integers written in the decimal base without leading zeroes.

## Input

The single line of the input contains a pair of integers *m*, *s* (1 ≤ *m* ≤ 100, 0 ≤ *s* ≤ 900) — the length and the sum of the digits of the required numbers.

## Output

In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1" (without the quotes).

## Examples

## Input


```
2 15  

```
## Output


```
69 96  

```
## Input


```
3 0  

```
## Output


```
-1 -1  

```


#### tags 

#1400 #dp #greedy #implementation 