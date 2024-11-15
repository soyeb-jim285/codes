<h1 style='text-align: center;'> F. TorCoder</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A boy named Leo doesn't miss a single TorCoder contest round. On the last TorCoder round number 100666 Leo stumbled over the following problem. He was given a string *s*, consisting of *n* lowercase English letters, and *m* queries. Each query is characterised by a pair of integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*). 

We'll consider the letters in the string numbered from 1 to *n* from left to right, that is, *s* = *s*1*s*2... *s**n*. 

After each query he must swap letters with indexes from *l**i* to *r**i* inclusive in string *s* so as to make substring (*l**i*, *r**i*) a palindrome. If there are multiple such letter permutations, you should choose the one where string (*l**i*, *r**i*) will be lexicographically minimum. If no such permutation exists, you should ignore the query (that is, not change string *s*).

Everybody knows that on TorCoder rounds input line and array size limits never exceed 60, so Leo solved this problem easily. Your task is to solve the problem on a little bit larger limits. Given string *s* and *m* queries, print the string that results after applying all *m* queries to string *s*.

## Input

The first input line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the string length and the number of the queries.

The second line contains string *s*, consisting of *n* lowercase Latin letters.

Each of the next *m* lines contains a pair of integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*) — a query to apply to the string. 

## Output

In a single line print the result of applying *m* queries to string *s*. Print the queries in the order in which they are given in the input.

## Examples

## Input


```
7 2  
aabcbaa  
1 3  
5 7  

```
## Output


```
abacaba  

```
## Input


```
3 2  
abc  
1 2  
2 3  

```
## Output


```
abc  

```
## Note

A substring (*l**i*, *r**i*) 1 ≤ *l**i* ≤ *r**i* ≤ *n*) of string *s* = *s*1*s*2... *s**n* of length *n* is a sequence of characters *s**l**i**s**l**i* + 1...*s**r**i*.

A string is a palindrome, if it reads the same from left to right and from right to left.

String *x*1*x*2... *x**p* is lexicographically smaller than string *y*1*y*2... *y**q*, if either *p* < *q* and *x*1 = *y*1, *x*2 = *y*2, ... , *x**p* = *y**p*, or exists such number *r* (*r* < *p*, *r* < *q*), that *x*1 = *y*1, *x*2 = *y*2, ... , *x**r* = *y**r* and *x**r* + 1 < *y**r* + 1.



#### tags 

#2600 #data_structures 