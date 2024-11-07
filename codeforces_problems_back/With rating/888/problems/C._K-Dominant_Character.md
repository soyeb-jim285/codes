<h1 style='text-align: center;'> C. K-Dominant Character</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string *s* consisting of lowercase Latin letters. Character *c* is called *k*-dominant iff each substring of *s* with length at least *k* contains this character *c*.

You have to find minimum *k* such that there exists at least one *k*-dominant character.

## Input

The first line contains string *s* consisting of lowercase Latin letters (1 ≤ |*s*| ≤ 100000).

## Output

Print one number — the minimum value of *k* such that there exists at least one *k*-dominant character.

## Examples

## Input


```
abacaba  

```
## Output


```
2  

```
## Input


```
zzzzz  

```
## Output


```
1  

```
## Input


```
abcde  

```
## Output


```
3  

```


#### tags 

#1400 #binary_search #implementation #two_pointers 