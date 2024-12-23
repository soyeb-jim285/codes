<h1 style='text-align: center;'> D. Palindrome pairs</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a non-empty string *s* consisting of lowercase letters. Find the number of pairs of non-overlapping palindromic substrings of this string.

In a more formal way, you have to find the quantity of tuples (*a*, *b*, *x*, *y*) such that 1 ≤ *a* ≤ *b* < *x* ≤ *y* ≤ |*s*| and substrings *s*[*a*... *b*], *s*[*x*... *y*] are palindromes.

A palindrome is a string that can be read the same way from left to right and from right to left. For example, "abacaba", "z", "abba" are palindromes.

A substring *s*[*i*... *j*] (1 ≤ *i* ≤ *j* ≤ |*s*|) of string *s* = *s*1*s*2... *s*|*s*| is a string *s**i**s**i* + 1... *s**j*. For example, substring *s*[2...4] of string *s* = "abacaba" equals "bac".

## Input

The first line of input contains a non-empty string *s* which consists of lowercase letters ('a'...'z'), *s* contains at most 2000 characters.

## Output

## Output

 a single number — the quantity of pairs of non-overlapping palindromic substrings of *s*.

Please do not use the %lld format specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d format specifier.

## Examples

## Input


```
aa  

```
## Output


```
1  

```
## Input


```
aaa  

```
## Output


```
5  

```
## Input


```
abacaba  

```
## Output


```
36  

```


#### tags 

#1500 #*special #brute_force #dp #strings 