<h1 style='text-align: center;'> F. String Compression</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ivan wants to write a letter to his friend. The letter is a string *s* consisting of lowercase Latin letters.

Unfortunately, when Ivan started writing the letter, he realised that it is very long and writing the whole letter may take extremely long time. So he wants to write the compressed version of string *s* instead of the string itself.

The compressed version of string *s* is a sequence of strings *c*1, *s*1, *c*2, *s*2, ..., *c**k*, *s**k*, where *c**i* is the decimal representation of number *a**i* (without any leading zeroes) and *s**i* is some string consisting of lowercase Latin letters. If Ivan writes string *s*1 exactly *a*1 times, then string *s*2 exactly *a*2 times, and so on, the result will be string *s*.

The length of a compressed version is |*c*1| + |*s*1| + |*c*2| + |*s*2|... |*c**k*| + |*s**k*|. Among all compressed versions Ivan wants to choose a version such that its length is minimum possible. Help Ivan to determine minimum possible length.

## Input

The only line of input contains one string *s* consisting of lowercase Latin letters (1 ≤ |*s*| ≤ 8000).

## Output

## Output

 one integer number — the minimum possible length of a compressed version of *s*.

## Examples

## Input


```
aaaaaaaaaa  

```
## Output


```
3  

```
## Input


```
abcab  

```
## Output


```
6  

```
## Input


```
cczabababab  

```
## Output


```
7  

```
## Note

In the first example Ivan will choose this compressed version: *c*1 is 10, *s*1 is a.

In the second example Ivan will choose this compressed version: *c*1 is 1, *s*1 is abcab.

In the third example Ivan will choose this compressed version: *c*1 is 2, *s*1 is c, *c*2 is 1, *s*2 is z, *c*3 is 4, *s*3 is ab.



#### tags 

#2400 #dp #hashing #string_suffix_structures #strings 