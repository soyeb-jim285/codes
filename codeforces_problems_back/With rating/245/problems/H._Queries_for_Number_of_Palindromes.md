<h1 style='text-align: center;'> H. Queries for Number of Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got a string *s* = *s*1*s*2... *s*|*s*| of length |*s*|, consisting of lowercase English letters. There also are *q* queries, each query is described by two integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ |*s*|). The answer to the query is the number of substrings of string *s*[*l**i*... *r**i*], which are palindromes.

String *s*[*l*... *r*] = *s**l**s**l* + 1... *s**r* (1 ≤ *l* ≤ *r* ≤ |*s*|) is a substring of string *s* = *s*1*s*2... *s*|*s*|.

String *t* is called a palindrome, if it reads the same from left to right and from right to left. Formally, if *t* = *t*1*t*2... *t*|*t*| = *t*|*t*|*t*|*t*| - 1... *t*1.

## Input

The first line contains string *s* (1 ≤ |*s*| ≤ 5000). The second line contains a single integer *q* (1 ≤ *q* ≤ 106) — the number of queries. Next *q* lines contain the queries. The *i*-th of these lines contains two space-separated integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ |*s*|) — the description of the *i*-th query.

It is guaranteed that the given string consists only of lowercase English letters.

## Output

Print *q* integers — the answers to the queries. Print the answers in the order, in which the queries are given in the input. Separate the printed numbers by whitespaces.

## Examples

## Input


```
caaaba  
5  
1 1  
1 4  
2 3  
4 6  
4 5  

```
## Output


```
1  
7  
3  
4  
2  

```
## Note

Consider the fourth query in the first test case. String *s*[4... 6] = «aba». Its palindrome substrings are: «a», «b», «a», «aba».



#### tags 

#1800 #dp #hashing #strings 