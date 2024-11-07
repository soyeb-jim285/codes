<h1 style='text-align: center;'> B. Palindrome</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a string *s*, determine if it contains any palindrome of length exactly 100 as a subsequence. If it has any, print any one of them. If it doesn't have any, print a palindrome that is a subsequence of *s* and is as long as possible.

## Input

The only line of the input contains one string *s* of length *n* (1 ≤ *n* ≤ 5·104) containing only lowercase English letters.

## Output

If *s* contains a palindrome of length exactly 100 as a subsequence, print any palindrome of length 100 which is a subsequence of *s*. If *s* doesn't contain any palindromes of length exactly 100, print a palindrome that is a subsequence of *s* and is as long as possible.

If there exists multiple answers, you are allowed to print any of them.

## Examples

## Input


```
bbbabcbbb  

```
## Output


```
bbbcbbb  

```
## Input


```
rquwmzexectvnbanemsmdufrg  

```
## Output


```
rumenanemur  

```
## Note

A subsequence of a string is a string that can be derived from it by deleting some characters without changing the order of the remaining characters. A palindrome is a string that reads the same forward or backward.



#### tags 

#1900 #constructive_algorithms #dp 