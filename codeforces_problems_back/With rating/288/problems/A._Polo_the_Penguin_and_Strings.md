<h1 style='text-align: center;'> A. Polo the Penguin and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little penguin Polo adores strings. But most of all he adores strings of length *n*.

One day he wanted to find a string that meets the following conditions:

1. The string consists of *n* lowercase English letters (that is, the string's length equals *n*), exactly *k* of these letters are distinct.
2. No two neighbouring letters of a string coincide; that is, if we represent a string as *s* = *s*1*s*2... *s**n*, then the following inequality holds, *s**i* ≠ *s**i* + 1(1 ≤ *i* < *n*).
3. Among all strings that meet points 1 and 2, the required string is lexicographically smallest.

Help him find such string or state that such string doesn't exist.

String *x* = *x*1*x*2... *x**p* is lexicographically less than string *y* = *y*1*y*2... *y**q*, if either *p* < *q* and *x*1 = *y*1, *x*2 = *y*2, ... , *x**p* = *y**p*, or there is such number *r* (*r* < *p*, *r* < *q*), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1. The characters of the strings are compared by their ASCII codes.

## Input

A single line contains two positive integers *n* and *k* (1 ≤ *n* ≤ 106, 1 ≤ *k* ≤ 26) — the string's length and the number of distinct letters.

## Output

In a single line print the required string. If there isn't such string, print "-1" (without the quotes).

## Examples

## Input


```
7 4  

```
## Output


```
ababacd  

```
## Input


```
4 7  

```
## Output


```
-1  

```


#### tags 

#1300 #greedy 