<h1 style='text-align: center;'> C. Sereja and Brackets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sereja has a bracket sequence *s*1, *s*2, ..., *s**n*, or, in other words, a string *s* of length *n*, consisting of characters "(" and ")".

Sereja needs to answer *m* queries, each of them is described by two integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*). The answer to the *i*-th query is the length of the maximum correct bracket subsequence of sequence *s**l**i*, *s**l**i* + 1, ..., *s**r**i*. Help Sereja answer all queries.

You can find the definitions for a subsequence and a correct bracket sequence in the notes.

## Input

The first line contains a sequence of characters *s*1, *s*2, ..., *s**n* (1 ≤ *n* ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer *m* (1 ≤ *m* ≤ 105) — the number of queries. Each of the next *m* lines contains a pair of integers. The *i*-th line contains integers *l**i*, *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*) — the description of the *i*-th query.

## Output

Print the answer to each question on a single line. Print the answers in the order they go in the input.

## Examples

## Input


```
())(())(())(  
7  
1 1  
2 3  
1 2  
1 12  
8 12  
5 11  
2 10  

```
## Output


```
0  
0  
2  
10  
4  
6  
6  

```
## Note

A subsequence of length |*x*| of string *s* = *s*1*s*2... *s*|*s*| (where |*s*| is the length of string *s*) is string *x* = *s**k*1*s**k*2... *s**k*|*x*| (1 ≤ *k*1 < *k*2 < ... < *k*|*x*| ≤ |*s*|).

A correct bracket sequence is a bracket sequence that can be transformed into a correct aryphmetic expression by inserting characters "1" and "+" between the characters of the string. For example, bracket sequences "()()", "(())" are correct (the resulting expressions "(1)+(1)", "((1+1)+1)"), and ")(" and "(" are not.

For the third query required sequence will be «()».

For the fourth query required sequence will be «()(())(())».



#### tags 

#2000 #data_structures #schedules 