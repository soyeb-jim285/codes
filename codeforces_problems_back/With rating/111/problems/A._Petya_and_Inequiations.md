<h1 style='text-align: center;'> A. Petya and Inequiations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Petya loves inequations. Help him find *n* positive integers *a*1, *a*2, ..., *a**n*, such that the following two conditions are satisfied:

* *a*12 + *a*22 + ... + *a**n*2 ≥ *x*
* *a*1 + *a*2 + ... + *a**n* ≤ *y*
## Input

The first line contains three space-separated integers *n*, *x* and *y* (1 ≤ *n* ≤ 105, 1 ≤ *x* ≤ 1012, 1 ≤ *y* ≤ 106).

Please do not use the %lld specificator to read or write 64-bit integers in С++. It is recommended to use cin, cout streams or the %I64d specificator.

## Output

Print *n* positive integers that satisfy the conditions, one integer per line. If such numbers do not exist, print a single number "-1". If there are several solutions, print any of them.

## Examples

## Input


```
5 15 15  

```
## Output


```
4  
4  
1  
1  
2  

```
## Input


```
2 3 2  

```
## Output


```
-1  

```
## Input


```
1 99 11  

```
## Output


```
11  

```


#### tags 

#1400 #greedy 