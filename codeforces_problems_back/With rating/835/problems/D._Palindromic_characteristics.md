<h1 style='text-align: center;'> D. Palindromic characteristics</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Palindromic characteristics of string *s* with length |*s*| is a sequence of |*s*| integers, where *k*-th number is the total number of non-empty substrings of *s* which are *k*-palindromes.

A string is 1-palindrome if and only if it reads the same backward as forward.

A string is *k*-palindrome (*k* > 1) if and only if: 

1. Its left half equals to its right half.
2. Its left and right halfs are non-empty (*k* - 1)-palindromes.

The left half of string *t* is its prefix of length ⌊|*t*| / 2⌋, and right half — the suffix of the same length. ⌊|*t*| / 2⌋ denotes the length of string *t* divided by 2, rounded down.

## Note

 that each substring is counted as many times as it appears in the string. For example, in the string "aaa" the substring "a" appears 3 times.

## Input

The first line contains the string *s* (1 ≤ |*s*| ≤ 5000) consisting of lowercase English letters.

## Output

Print |*s*| integers — palindromic characteristics of string *s*.

## Examples

## Input


```
abba  

```
## Output


```
6 1 0 0   

```
## Input


```
abacaba  

```
## Output


```
12 4 1 0 0 0 0   

```
## Note

In the first example 1-palindromes are substring «a», «b», «b», «a», «bb», «abba», the substring «bb» is 2-palindrome. There are no 3- and 4-palindromes here.



#### tags 

#1900 #brute_force #dp #hashing #strings 