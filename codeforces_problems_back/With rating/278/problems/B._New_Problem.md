<h1 style='text-align: center;'> B. New Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Coming up with a new problem isn't as easy as many people think. Sometimes it is hard enough to name it. We'll consider a title original if it doesn't occur as a substring in any titles of recent Codeforces problems. 

You've got the titles of *n* last problems — the strings, consisting of lowercase English letters. Your task is to find the shortest original title for the new problem. If there are multiple such titles, choose the lexicographically minimum one. ## Note

, that title of the problem can't be an empty string.

A substring *s*[*l*... *r*] (1 ≤ *l* ≤ *r* ≤ |*s*|) of string *s* = *s*1*s*2... *s*|*s*| (where |*s*| is the length of string *s*) is string *s**l**s**l* + 1... *s**r*.

String *x* = *x*1*x*2... *x**p* is lexicographically smaller than string *y* = *y*1*y*2... *y**q*, if either *p* < *q* and *x*1 = *y*1, *x*2 = *y*2, ... , *x**p* = *y**p*, or there exists such number *r* (*r* < *p*, *r* < *q*), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1. The string characters are compared by their ASCII codes.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 30) — the number of titles you've got to consider. Then follow *n* problem titles, one per line. Each title only consists of lowercase English letters (specifically, it doesn't contain any spaces) and has the length from 1 to 20, inclusive.

## Output

Print a string, consisting of lowercase English letters — the lexicographically minimum shortest original title.

## Examples

## Input


```
5  
threehorses  
goodsubstrings  
secret  
primematrix  
beautifulyear  

```
## Output


```
j  

```
## Input


```
4  
aa  
bdefghijklmn  
opqrstuvwxyz  
c  

```
## Output


```
ab  

```
## Note

In the first sample the first 9 letters of the English alphabet (a, b, c, d, e, f, g, h, i) occur in the problem titles, so the answer is letter j.

In the second sample the titles contain 26 English letters, so the shortest original title cannot have length 1. Title aa occurs as a substring in the first title.



#### tags 

#1500 #brute_force #strings 