<h1 style='text-align: center;'> E. Wavy numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A wavy number is such positive integer that for any digit of its decimal representation except for the first one and the last one following condition holds: the digit is either strictly larger than both its adjacent digits or strictly less than both its adjacent digits. For example, numbers 35270, 102, 747, 20 and 3 are wavy and numbers 123, 1000 and 2212 are not.

The task is to find the *k*-th smallest wavy number *r* that is divisible by *n* for the given integer values *n* and *k*.

You are to write a program that will find the value of *r* if it doesn't exceed 1014.

## Input

The only line of input contains two integers *n* and *k*, separated by a single space (1 ≤ *n*, *k* ≤ 1014). 

## Output

Your task is to output the only integer *r* — the answer to the given problem. If such number does not exist or it is larger than 1014, then print "-1" (minus one without the quotes) instead.

## Examples

## Input


```
123 4  

```
## Output


```
1845  

```
## Input


```
100 1  

```
## Output


```
-1  

```
## Input


```
97461 457  

```
## Output


```
1805270103  

```
## Note

The values of the first four wavy numbers that are divisible by *n* for the first sample are: 492, 615, 738 and 1845.



#### tags 

#2900 #brute_force #dfs_and_similar #meet-in-the-middle #sortings 