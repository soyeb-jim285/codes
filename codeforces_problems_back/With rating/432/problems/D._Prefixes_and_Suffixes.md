<h1 style='text-align: center;'> D. Prefixes and Suffixes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a string *s* = *s*1*s*2...*s*|*s*|, where |*s*| is the length of string *s*, and *s**i* its *i*-th character. 

Let's introduce several definitions:

* A substring *s*[*i*..*j*] (1 ≤ *i* ≤ *j* ≤ |*s*|) of string *s* is string *s**i**s**i* + 1...*s**j*.
* The prefix of string *s* of length *l* (1 ≤ *l* ≤ |*s*|) is string *s*[1..*l*].
* The suffix of string *s* of length *l* (1 ≤ *l* ≤ |*s*|) is string *s*[|*s*| - *l* + 1..|*s*|].

Your task is, for any prefix of string *s* which matches a suffix of string *s*, print the number of times it occurs in string *s* as a substring.

## Input

The single line contains a sequence of characters *s*1*s*2...*s*|*s*| (1 ≤ |*s*| ≤ 105) — string *s*. The string only consists of uppercase English letters.

## Output

In the first line, print integer *k* (0 ≤ *k* ≤ |*s*|) — the number of prefixes that match a suffix of string *s*. Next print *k* lines, in each line print two integers *l**i* *c**i*. Numbers *l**i* *c**i* mean that the prefix of the length *l**i* matches the suffix of length *l**i* and occurs in string *s* as a substring *c**i* times. Print pairs *l**i* *c**i* in the order of increasing *l**i*.

## Examples

## Input


```
ABACABA  

```
## Output


```
3  
1 4  
3 2  
7 1  

```
## Input


```
AAA  

```
## Output


```
3  
1 3  
2 2  
3 1  

```


#### tags 

#2000 #dp #string_suffix_structures #strings #two_pointers 