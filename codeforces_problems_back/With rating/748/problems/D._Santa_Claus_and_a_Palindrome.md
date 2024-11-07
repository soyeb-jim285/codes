<h1 style='text-align: center;'> D. Santa Claus and a Palindrome</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Santa Claus likes palindromes very much. There was his birthday recently. *k* of his friends came to him to congratulate him, and each of them presented to him a string *s**i* having the same length *n*. We denote the beauty of the *i*-th string by *a**i*. It can happen that *a**i* is negative — that means that Santa doesn't find this string beautiful at all.

Santa Claus is crazy about palindromes. He is thinking about the following question: what is the maximum possible total beauty of a palindrome which can be obtained by concatenating some (possibly all) of the strings he has? Each present can be used at most once. ## Note

 that all strings have the same length *n*.

Recall that a palindrome is a string that doesn't change after one reverses it.

Since the empty string is a palindrome too, the answer can't be negative. Even if all *a**i*'s are negative, Santa can obtain the empty string.

## Input

The first line contains two positive integers *k* and *n* divided by space and denoting the number of Santa friends and the length of every string they've presented, respectively (1 ≤ *k*, *n* ≤ 100 000; *n*·*k*  ≤ 100 000).

*k* lines follow. The *i*-th of them contains the string *s**i* and its beauty *a**i* ( - 10 000 ≤ *a**i* ≤ 10 000). The string consists of *n* lowercase English letters, and its beauty is integer. Some of strings may coincide. Also, equal strings can have different beauties.

## Output

In the only line print the required maximum possible beauty.

## Examples

## Input


```
7 3  
abb 2  
aaa -3  
bba -1  
zyz -4  
abb 5  
aaa 7  
xyx 4  

```
## Output


```
12  

```
## Input


```
3 1  
a 1  
a 2  
a 3  

```
## Output


```
6  

```
## Input


```
2 5  
abcde 10000  
abcde 10000  

```
## Output


```
0  

```
## Note

In the first example Santa can obtain abbaaaxyxaaabba by concatenating strings 5, 2, 7, 6 and 3 (in this order).



#### tags 

#2100 #constructive_algorithms #data_structures #greedy 