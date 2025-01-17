<h1 style='text-align: center;'> A. Substring and Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Polycarpus got hold of two non-empty strings *s* and *t*, consisting of lowercase Latin letters. Polycarpus is quite good with strings, so he immediately wondered, how many different pairs of "*x* *y*" are there, such that *x* is a substring of string *s*, *y* is a subsequence of string *t*, and the content of *x* and *y* is the same. Two pairs are considered different, if they contain different substrings of string *s* or different subsequences of string *t*. Read the whole statement to understand the definition of different substrings and subsequences.

The length of string *s* is the number of characters in it. If we denote the length of the string *s* as |*s*|, we can write the string as *s* = *s*1*s*2... *s*|*s*|.

A substring of *s* is a non-empty string *x* = *s*[*a*... *b*] = *s**a**s**a* + 1... *s**b* (1 ≤ *a* ≤ *b* ≤ |*s*|). For example, "code" and "force" are substrings or "codeforces", while "coders" is not. Two substrings *s*[*a*... *b*] and *s*[*c*... *d*] are considered to be different if *a* ≠ *c* or *b* ≠ *d*. For example, if *s*="codeforces", *s*[2...2] and *s*[6...6] are different, though their content is the same.

A subsequence of *s* is a non-empty string *y* = *s*[*p*1*p*2... *p*|*y*|] = *s**p*1*s**p*2... *s**p*|*y*| (1 ≤ *p*1 < *p*2 < ... < *p*|*y*| ≤ |*s*|). For example, "coders" is a subsequence of "codeforces". Two subsequences *u* = *s*[*p*1*p*2... *p*|*u*|] and *v* = *s*[*q*1*q*2... *q*|*v*|] are considered different if the sequences *p* and *q* are different.

## Input

The input consists of two lines. The first of them contains *s* (1 ≤ |*s*| ≤ 5000), and the second one contains *t* (1 ≤ |*t*| ≤ 5000). Both strings consist of lowercase Latin letters.

## Output

Print a single number — the number of different pairs "*x* *y*" such that *x* is a substring of string *s*, *y* is a subsequence of string *t*, and the content of *x* and *y* is the same. As the answer can be rather large, print it modulo 1000000007 (109 + 7).

## Examples

## Input


```
aa  
aa  

```
## Output


```
5  

```
## Input


```
codeforces  
forceofcode  

```
## Output


```
60  

```
## Note

Let's write down all pairs "*x* *y*" that form the answer in the first sample: "*s*[1...1] *t*[1]", "*s*[2...2] *t*[1]", "*s*[1...1] *t*[2]","*s*[2...2] *t*[2]", "*s*[1...2] *t*[1 2]".



#### tags 

#1700 #dp 