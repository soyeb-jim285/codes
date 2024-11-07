<h1 style='text-align: center;'> A. Letters Cyclic Shift</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a non-empty string *s* consisting of lowercase English letters. You have to pick exactly one non-empty substring of *s* and shift all its letters 'z' ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 'y' ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 'x' ![](images/005927f46ee43aed9953b17eaaafb44b804a158a.png) 'b' ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 'a' ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 'z'. In other words, each character is replaced with the previous character of English alphabet and 'a' is replaced with 'z'.

What is the lexicographically minimum string that can be obtained from *s* by performing this shift exactly once?

## Input

The only line of the input contains the string *s* (1 ≤ |*s*| ≤ 100 000) consisting of lowercase English letters.

## Output

Print the lexicographically minimum string that can be obtained from *s* by shifting letters of exactly one non-empty substring.

## Examples

## Input


```
codeforces  

```
## Output


```
bncdenqbdr  

```
## Input


```
abacaba  

```
## Output


```
aaacaba  

```
## Note

String *s* is lexicographically smaller than some other string *t* of the same length if there exists some 1 ≤ *i* ≤ |*s*|, such that *s*1 = *t*1, *s*2 = *t*2, ..., *s**i* - 1 = *t**i* - 1, and *s**i* < *t**i*.



#### tags 

#1200 #constructive_algorithms #greedy #implementation #strings 