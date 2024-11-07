<h1 style='text-align: center;'> F. Erasing Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string *s*, initially consisting of *n* lowercase Latin letters. After that, you perform *k* operations with it, where ![](images/c9622f3cdf5f8480656b83e566988d23d6c716b5.png). During *i*-th operation you must erase some substring of length exactly 2*i* - 1 from *s*.

Print the lexicographically minimal string you may obtain after performing *k* such operations.

## Input

The only line contains one string *s* consisting of *n* lowercase Latin letters (1 ≤ *n* ≤ 5000).

## Output

Print the lexicographically minimal string you may obtain after performing *k* operations.

## Examples

## Input


```
adcbca  

```
## Output


```
aba  

```
## Input


```
abacabadabacaba  

```
## Output


```
aabacaba  

```
## Note

Possible operations in examples:

1. adcbca ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) adcba ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) aba;
2. abacabadabacaba ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) abcabadabacaba ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) aabadabacaba ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) aabacaba.


#### tags 

#2700 #bitmasks #dp #greedy 