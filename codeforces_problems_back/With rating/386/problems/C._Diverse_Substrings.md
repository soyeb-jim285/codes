<h1 style='text-align: center;'> C. Diverse Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

String diversity is the number of symbols that occur in the string at least once. Diversity of *s* will be denoted by *d*(*s*). For example , *d*("aaa")=1, *d*("abacaba")=3.

Given a string *s*, consisting of lowercase Latin letters. Consider all its substrings. Obviously, any substring diversity is a number from 1 to *d*(*s*). Find statistics about substrings diversity: for each *k* from 1 to *d*(*s*), find how many substrings of *s* has a diversity of exactly *k*.

## Input

The input consists of a single line containing *s*. It contains only lowercase Latin letters, the length of *s* is from 1 to 3·105.

## Output

Print to the first line the value *d*(*s*). Print sequence *t*1, *t*2, ..., *t**d*(*s*) to the following lines, where *t**i* is the number of substrings of *s* having diversity of exactly *i*.

## Examples

## Input


```
abca  

```
## Output


```
3  
4  
3  
3  

```
## Input


```
aabacaabbad  

```
## Output


```
4  
14  
19  
28  
5  

```
## Note

Consider the first example.

We denote by *s*(*i*, *j*) a substring of "abca" with the indices in the segment [*i*, *j*].

* *s*(1, 1) =  "a", *d*("a") = 1
* *s*(2, 2) =  "b", *d*("b") = 1
* *s*(3, 3) =  "c", *d*("c") = 1
* *s*(4, 4) =  "a", *d*("a") = 1
* *s*(1, 2) =  "ab", *d*("ab") = 2
* *s*(2, 3) =  "bc", *d*("bc") = 2
* *s*(3, 4) =  "ca", *d*("ca") = 2
* *s*(1, 3) =  "abc", *d*("abc") = 3
* *s*(2, 4) =  "bca", *d*("bca") = 3
* *s*(1, 4) =  "abca", *d*("abca") = 3

Total number of substring with diversity 1 is 4, with diversity 2 equals 3, 3 diversity is 3.



#### tags 

#2000 #dp #strings #two_pointers 