<h1 style='text-align: center;'> C. Minimum Modular</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have been given *n* distinct integers *a*1, *a*2, ..., *a**n*. You can remove at most *k* of them. Find the minimum modular *m* (*m* > 0), so that for every pair of the remaining integers (*a**i*, *a**j*), the following unequality holds: ![](images/99207b6fd2ae3166568533e27b232fe26273b32c.png).

## Input

The first line contains two integers *n* and *k* (1  ≤ *n*  ≤ 5000, 0 ≤ *k* ≤ 4), which we have mentioned above. 

The second line contains *n* distinct integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 106).

## Output

Print a single positive integer — the minimum *m*.

## Examples

## Input


```
7 0  
0 2 3 6 7 12 18  

```
## Output


```
13  

```
## Input


```
7 1  
0 2 3 6 7 12 18  

```
## Output


```
7  

```


#### tags 

#2400 #brute_force #graphs #math #number_theory 