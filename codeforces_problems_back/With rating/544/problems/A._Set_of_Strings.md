<h1 style='text-align: center;'> A. Set of Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string *q*. A sequence of *k* strings *s*1, *s*2, ..., *s**k* is called beautiful, if the concatenation of these strings is string *q* (formally, *s*1 + *s*2 + ... + *s**k* = *q*) and the first characters of these strings are distinct.

Find any beautiful sequence of strings or determine that the beautiful sequence doesn't exist.

## Input

The first line contains a positive integer *k* (1 ≤ *k* ≤ 26) — the number of strings that should be in a beautiful sequence. 

The second line contains string *q*, consisting of lowercase Latin letters. The length of the string is within range from 1 to 100, inclusive.

## Output

If such sequence doesn't exist, then print in a single line "NO" (without the quotes). Otherwise, print in the first line "YES" (without the quotes) and in the next *k* lines print the beautiful sequence of strings *s*1, *s*2, ..., *s**k*.

If there are multiple possible answers, print any of them.

## Examples

## Input


```
1  
abca  

```
## Output


```
YES  
abca  

```
## Input


```
2  
aaacas  

```
## Output


```
YES  
aaa  
cas  

```
## Input


```
4  
abc  

```
## Output


```
NO  

```
## Note

In the second sample there are two possible answers: {"*aaaca*", "*s*"} and {"*aaa*", "*cas*"}.



#### tags 

#1100 #implementation #strings 