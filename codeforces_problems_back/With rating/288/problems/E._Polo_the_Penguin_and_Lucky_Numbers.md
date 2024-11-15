<h1 style='text-align: center;'> E. Polo the Penguin and Lucky Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Everybody knows that lucky numbers are positive integers that contain only lucky digits 4 and 7 in their decimal representation. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Polo the Penguin have two positive integers *l* and *r* (*l* < *r*), both of them are lucky numbers. Moreover, their lengths (that is, the number of digits in the decimal representation without the leading zeroes) are equal to each other.

Let's assume that *n* is the number of distinct lucky numbers, each of them cannot be greater than *r* or less than *l*, and *a**i* is the *i*-th (in increasing order) number of them. Find *a*1·*a*2 + *a*2·*a*3 + ... + *a**n* - 1·*a**n*. As the answer can be rather large, print the remainder after dividing it by 1000000007 (109 + 7).

## Input

The first line contains a positive integer *l*, and the second line contains a positive integer *r* (1 ≤ *l* < *r* ≤ 10100000). The numbers are given without any leading zeroes.

It is guaranteed that the lengths of the given numbers are equal to each other and that both of them are lucky numbers.

## Output

In the single line print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
4  
7  

```
## Output


```
28  

```
## Input


```
474  
777  

```
## Output


```
2316330  

```


#### tags 

#2800 #dp #implementation #math 