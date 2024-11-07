<h1 style='text-align: center;'> C. Maximum splitting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given several queries. In the *i*-th query you are given a single positive integer *n**i*. You are to represent *n**i* as a sum of maximum possible number of composite summands and print this maximum number, or print -1, if there are no such splittings.

An integer greater than 1 is composite, if it is not prime, i.e. if it has positive divisors not equal to 1 and the integer itself.

## Input

The first line contains single integer *q* (1 ≤ *q* ≤ 105) — the number of queries.

*q* lines follow. The (*i* + 1)-th line contains single integer *n**i* (1 ≤ *n**i* ≤ 109) — the *i*-th query.

## Output

For each query print the maximum possible number of summands in a valid splitting to composite summands, or -1, if there are no such splittings.

## Examples

## Input


```
1  
12  

```
## Output


```
3  

```
## Input


```
2  
6  
8  

```
## Output


```
1  
2  

```
## Input


```
3  
1  
2  
3  

```
## Output


```
-1  
-1  
-1  

```
## Note

12 = 4 + 4 + 4 = 4 + 8 = 6 + 6 = 12, but the first splitting has the maximum possible number of summands.

8 = 4 + 4, 6 can't be split into several composite summands.

1, 2, 3 are less than any composite number, so they do not have valid splittings.



#### tags 

#1300 #dp #greedy #math #number_theory 