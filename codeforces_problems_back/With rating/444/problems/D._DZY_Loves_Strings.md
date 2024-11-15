<h1 style='text-align: center;'> D. DZY Loves Strings</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

DZY loves strings, and he enjoys collecting them.

In China, many people like to use strings containing their names' initials, for example: xyz, jcvb, dzy, dyh.

Once DZY found a lucky string *s*. A lot of pairs of good friends came to DZY when they heard about the news. The first member of the *i*-th pair has name *a**i*, the second one has name *b**i*. Each pair wondered if there is a substring of the lucky string containing both of their names. If so, they want to find the one with minimum length, which can give them good luck and make their friendship last forever.

Please help DZY for each pair find the minimum length of the substring of *s* that contains both *a**i* and *b**i*, or point out that such substring doesn't exist.

A substring of *s* is a string *s**l**s**l* + 1... *s**r* for some integers *l*, *r* (1 ≤ *l* ≤ *r* ≤ |*s*|). The length of such the substring is (*r* - *l* + 1).

A string *p* contains some another string *q* if there is a substring of *p* equal to *q*.

## Input

The first line contains a string *s* (1 ≤ |*s*| ≤ 50000).

The second line contains a non-negative integer *q* (0 ≤ *q* ≤ 100000) — the number of pairs. Each of the next *q* lines describes a pair, the line contains two space-separated strings *a**i* and *b**i* (1 ≤ |*a**i*|, |*b**i*| ≤ 4).

It is guaranteed that all the strings only consist of lowercase English letters.

## Output

For each pair, print a line containing a single integer — the minimum length of the required substring. If there is no such substring, output -1.

## Examples

## Input


```
xudyhduxyz  
3  
xyz xyz  
dyh xyz  
dzy xyz  

```
## Output


```
3  
8  
-1  

```
## Input


```
abcabd  
3  
a c  
ab abc  
ab d  

```
## Output


```
2  
3  
3  

```
## Input


```
baabcabaaa  
2  
abca baa  
aa aba  

```
## Output


```
6  
4  

```
## Note

The shortest substrings in the first sample are: xyz, dyhduxyz.

The shortest substrings in the second sample are: ca, abc and abd.

The shortest substrings in the third sample are: baabca and abaa.



#### tags 

#2500 #binary_search #hashing #strings #two_pointers 