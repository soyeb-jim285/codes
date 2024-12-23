<h1 style='text-align: center;'> A. LLPS</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This problem's actual name, "Lexicographically Largest Palindromic Subsequence" is too long to fit into the page headline.

You are given string *s* consisting of lowercase English letters only. Find its lexicographically largest palindromic subsequence.

We'll call a non-empty string *s*[*p*1*p*2... *p**k*] = *s**p*1*s**p*2... *s**p**k* (1  ≤  *p*1 < *p*2 < ... < *p**k*  ≤  |*s*|) a subsequence of string *s* = *s*1*s*2... *s*|*s*|, where |*s*| is the length of string *s*. For example, strings "abcb", "b" and "abacaba" are subsequences of string "abacaba".

String *x* = *x*1*x*2... *x*|*x*| is lexicographically larger than string *y* = *y*1*y*2... *y*|*y*| if either |*x*| > |*y*| and *x*1 = *y*1, *x*2 = *y*2, ..., *x*|*y*| = *y*|*y*|, or there exists such number *r* (*r* < |*x*|, *r* < |*y*|) that *x*1 = *y*1, *x*2 = *y*2, ..., *x**r* = *y**r* and *x**r*  +  1 > *y**r*  +  1. Characters in the strings are compared according to their ASCII codes. For example, string "ranger" is lexicographically larger than string "racecar" and string "poster" is lexicographically larger than string "post".

String *s* = *s*1*s*2... *s*|*s*| is a palindrome if it matches string *rev*(*s*) = *s*|*s*|*s*|*s*| - 1... *s*1. In other words, a string is a palindrome if it reads the same way from left to right and from right to left. For example, palindromic strings are "racecar", "refer" and "z".

## Input

The only input line contains a non-empty string *s* consisting of lowercase English letters only. Its length does not exceed 10.

## Output

Print the lexicographically largest palindromic subsequence of string *s*.

## Examples

## Input


```
radar  

```
## Output


```
rr  

```
## Input


```
bowwowwow  

```
## Output


```
wwwww  

```
## Input


```
codeforces  

```
## Output


```
s  

```
## Input


```
mississipp  

```
## Output


```
ssss  

```
## Note

Among all distinct subsequences of string "radar" the following ones are palindromes: "a", "d", "r", "aa", "rr", "ada", "rar", "rdr", "raar" and "radar". The lexicographically largest of them is "rr".



#### tags 

#800 #binary_search #bitmasks #brute_force #greedy #implementation #strings 