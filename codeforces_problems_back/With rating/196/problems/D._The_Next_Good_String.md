<h1 style='text-align: center;'> D. The Next Good String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In problems on strings one often has to find a string with some particular properties. The problem authors were reluctant to waste time on thinking of a name for some string so they called it good. A string is good if it doesn't have palindrome substrings longer than or equal to *d*. 

You are given string *s*, consisting only of lowercase English letters. Find a good string *t* with length |*s*|, consisting of lowercase English letters, which is lexicographically larger than *s*. Of all such strings string *t* must be lexicographically minimum.

We will call a non-empty string *s*[*a* ... *b*] = *s**a**s**a* + 1... *s**b* (1 ≤ *a* ≤ *b* ≤ |*s*|) a substring of string *s* = *s*1*s*2... *s*|*s*|.

A non-empty string *s* = *s*1*s*2... *s**n* is called a palindrome if for all *i* from 1 to *n* the following fulfills: *s**i* = *s**n* - *i* + 1. In other words, palindrome read the same in both directions.

String *x* = *x*1*x*2... *x*|*x*| is lexicographically larger than string *y* = *y*1*y*2... *y*|*y*|, if either |*x*| > |*y*| and *x*1 = *y*1, *x*2 = *y*2, ... , *x*|*y*| = *y*|*y*|, or there exists such number *r* (*r* < |*x*|, *r* < |*y*|), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 > *y**r* + 1. Characters in such strings are compared like their ASCII codes.

## Input

The first line contains integer *d* (1 ≤ *d* ≤ |*s*|).

The second line contains a non-empty string *s*, its length is no more than 4·105 characters. The string consists of lowercase English letters.

## Output

Print the good string that lexicographically follows *s*, has the same length and consists of only lowercase English letters. If such string does not exist, print "Impossible" (without the quotes).

## Examples

## Input


```
3  
aaaaaaa  

```
## Output


```
aabbcaa  

```
## Input


```
3  
zzyzzzz  

```
## Output


```
Impossible  

```
## Input


```
4  
abbabbbabbb  

```
## Output


```
abbbcaaabab  

```


#### tags 

#2800 #data_structures #greedy #hashing #strings 