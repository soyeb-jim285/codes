<h1 style='text-align: center;'> B. Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* *k*-digit integers. You have to rearrange the digits in the integers so that the difference between the largest and the smallest number was minimum. Digits should be rearranged by the same rule in all integers.

## Input

The first line contains integers *n* and *k* — the number and digit capacity of numbers correspondingly (1 ≤ *n*, *k* ≤ 8). Next *n* lines contain *k*-digit positive integers. Leading zeroes are allowed both in the initial integers and the integers resulting from the rearranging of digits.

## Output

Print a single number: the minimally possible difference between the largest and the smallest number after the digits are rearranged in all integers by the same rule.

## Examples

## Input


```
6 4  
5237  
2753  
7523  
5723  
5327  
2537  

```
## Output


```
2700  

```
## Input


```
3 3  
010  
909  
012  

```
## Output


```
3  

```
## Input


```
7 5  
50808  
36603  
37198  
44911  
29994  
42543  
50156  

```
## Output


```
20522  

```
## Note

In the first sample, if we rearrange the digits in numbers as (3,1,4,2), then the 2-nd and the 4-th numbers will equal 5237 and 2537 correspondingly (they will be maximum and minimum for such order of digits).

In the second sample, if we swap the second digits and the first ones, we get integers 100, 99 and 102.



#### tags 

#1400 #brute_force #combinatorics #implementation 