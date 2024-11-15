<h1 style='text-align: center;'> E. Cutting the Line</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a non-empty line *s* and an integer *k*. The following operation is performed with this line exactly once:

* A line is split into at most *k* non-empty substrings, i.e. string *s* is represented as a concatenation of a set of strings *s* = *t*1 + *t*2 + ... + *t**m*, 1 ≤ *m* ≤ *k*.
* Some of strings *t**i* are replaced by strings *t**i**r*, that is, their record from right to left.
* The lines are concatenated back in the same order, we get string *s*' = *t*'1*t*'2... *t*'*m*, where *t*'*i* equals *t**i* or *t**i**r*.

Your task is to determine the lexicographically smallest string that could be the result of applying the given operation to the string *s*.

## Input

The first line of the input contains string *s* (1 ≤ |*s*| ≤ 5 000 000), consisting of lowercase English letters. The second line contains integer *k* (1 ≤ *k* ≤ |*s*|) — the maximum number of parts in the partition.

## Output

In the single line print the lexicographically minimum string *s*' which can be obtained as a result of performing the described operation. 

## Examples

## Input


```
aba  
2  

```
## Output


```
aab  

```
## Input


```
aaaabacaba  
2  

```
## Output


```
aaaaabacab  

```
## Input


```
bababa  
1  

```
## Output


```
ababab  

```
## Input


```
abacabadabacaba  
4  

```
## Output


```
aababacabacabad  

```


#### tags 

#3100 #string_suffix_structures #strings 