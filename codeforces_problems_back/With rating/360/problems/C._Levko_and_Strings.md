<h1 style='text-align: center;'> C. Levko and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Levko loves strings of length *n*, consisting of lowercase English letters, very much. He has one such string *s*. For each string *t* of length *n*, Levko defines its beauty relative to *s* as the number of pairs of indexes *i*, *j* (1 ≤ *i* ≤ *j* ≤ *n*), such that substring *t*[*i*..*j*] is lexicographically larger than substring *s*[*i*..*j*].

The boy wondered how many strings *t* are there, such that their beauty relative to *s* equals exactly *k*. Help him, find the remainder after division this number by 1000000007 (109 + 7).

A substring *s*[*i*..*j*] of string *s* = *s*1*s*2... *s**n* is string *s**i**s**i*  +  1... *s**j*.

String *x*  =  *x*1*x*2... *x**p* is lexicographically larger than string *y*  =  *y*1*y*2... *y**p*, if there is such number *r* (*r* < *p*), that *x*1  =  *y*1,  *x*2  =  *y*2,  ... ,  *x**r*  =  *y**r* and *x**r*  +  1 > *y**r*  +  1. The string characters are compared by their ASCII codes.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 2000, 0 ≤ *k* ≤ 2000).

The second line contains a non-empty string *s* of length *n*. String *s* consists only of lowercase English letters. 

## Output

Print a single number — the answer to the problem modulo 1000000007 (109 + 7).

## Examples

## Input


```
2 2  
yz  

```
## Output


```
26  

```
## Input


```
2 3  
yx  

```
## Output


```
2  

```
## Input


```
4 7  
abcd  

```
## Output


```
21962  

```


#### tags 

#2500 #combinatorics #dp 