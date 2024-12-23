<h1 style='text-align: center;'> A. Lexicographically Maximum Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got string *s*, consisting of only lowercase English letters. Find its lexicographically maximum subsequence.

We'll call a non-empty string *s*[*p*1*p*2... *p**k*] = *s**p*1*s**p*2... *s**p**k*(1 ≤ *p*1 < *p*2 < ... < *p**k* ≤ |*s*|) a subsequence of string *s* = *s*1*s*2... *s*|*s*|.

String *x* = *x*1*x*2... *x*|*x*| is lexicographically larger than string *y* = *y*1*y*2... *y*|*y*|, if either |*x*| > |*y*| and *x*1 = *y*1, *x*2 = *y*2, ... , *x*|*y*| = *y*|*y*|, or exists such number *r* (*r* < |*x*|, *r* < |*y*|), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 > *y**r* + 1. Characters in lines are compared like their ASCII codes.

## Input

The single line contains a non-empty string *s*, consisting only of lowercase English letters. The string's length doesn't exceed 105.

## Output

Print the lexicographically maximum subsequence of string *s*.

## Examples

## Input


```
ababba  

```
## Output


```
bbba  

```
## Input


```
abbcbccacbbcbaaba  

```
## Output


```
cccccbba  

```
## Note

Let's look at samples and see what the sought subsequences look like (they are marked with uppercase bold letters).

The first sample: aBaBBA

The second sample: abbCbCCaCbbCBaaBA



#### tags 

#1100 #greedy #strings 