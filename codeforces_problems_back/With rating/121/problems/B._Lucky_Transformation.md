<h1 style='text-align: center;'> B. Lucky Transformation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya has a number consisting of *n* digits without leading zeroes. He represented it as an array of digits without leading zeroes. Let's call it *d*. The numeration starts with 1, starting from the most significant digit. Petya wants to perform the following operation *k* times: find the minimum *x* (1 ≤ *x* < *n*) such that *d**x* = 4 and *d**x* + 1 = 7, if *x* is odd, then to assign *d**x* = *d**x* + 1 = 4, otherwise to assign *d**x* = *d**x* + 1 = 7. ## Note

 that if no *x* was found, then the operation counts as completed and the array doesn't change at all.

You are given the initial number as an array of digits and the number *k*. Help Petya find the result of completing *k* operations.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 105, 0 ≤ *k* ≤ 109) — the number of digits in the number and the number of completed operations. The second line contains *n* digits without spaces representing the array of digits *d*, starting with *d*1. It is guaranteed that the first digit of the number does not equal zero.

## Output

In the single line print the result without spaces — the number after the *k* operations are fulfilled.

## Examples

## Input


```
7 4  
4727447  

```
## Output


```
4427477  

```
## Input


```
4 2  
4478  

```
## Output


```
4478  

```
## Note

In the first sample the number changes in the following sequence: 4727447 → 4427447 → 4427477 → 4427447 → 4427477.

In the second sample: 4478 → 4778 → 4478.



#### tags 

#1500 #strings 