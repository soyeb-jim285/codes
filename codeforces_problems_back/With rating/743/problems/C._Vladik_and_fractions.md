<h1 style='text-align: center;'> C. Vladik and fractions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vladik and Chloe decided to determine who of them is better at math. Vladik claimed that for any positive integer *n* he can represent fraction ![](images/c2954a9b673b8c8ecdb35e61f72ab6c1fa6069ad.png) as a sum of three distinct positive fractions in form ![](images/73b471e9aa68eb411c798a43effc25523c815c83.png).

Help Vladik with that, i.e for a given *n* find three distinct positive integers *x*, *y* and *z* such that ![](images/637d7258208fe971109fefd332c21093948eb758.png). Because Chloe can't check Vladik's answer if the numbers are large, he asks you to print numbers not exceeding 109.

If there is no such answer, print -1.

## Input

The single line contains single integer *n* (1 ≤ *n* ≤ 104).

## Output

If the answer exists, print 3 distinct numbers *x*, *y* and *z* (1 ≤ *x*, *y*, *z* ≤ 109, *x* ≠ *y*, *x* ≠ *z*, *y* ≠ *z*). Otherwise print -1.

If there are multiple answers, print any of them.

## Examples

## Input


```
3  

```
## Output


```
2 7 42  

```
## Input


```
7  

```
## Output


```
7 8 56  

```


#### tags 

#1500 #brute_force #constructive_algorithms #math #number_theory 