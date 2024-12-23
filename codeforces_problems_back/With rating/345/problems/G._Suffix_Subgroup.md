<h1 style='text-align: center;'> G. Suffix Subgroup</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a group of *n* strings: *s*1, *s*2, ..., *s**n*.

You should find a subgroup *s**i*1, *s**i*2, ..., *s**i**k* (1 ≤ *i*1 < *i*2 < ... < *i**k* ≤ *n*) of the group. The following two conditions must hold:

* there exists a string *t* such, that each string from found subgroup is its suffix;
* the number of strings in the found subgroup is as large as possible.

Your task is to print the number of strings in the found subgroup.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 105) — the number of strings in the group. Each of the next *n* lines contains a string. The *i*-th line contains non-empty string *s**i*.

Each string consists only from lowercase Latin letters. The sum of all strings *s**i* doesn't exceed 105.

## Output

## Output

 a single integer — the number of strings in the found subgroup.

## Examples

## Input


```
6  
bb  
bb  
b  
aaa  
aa  
z  

```
## Output


```
3  

```
## Note

Look at the test sample. The required subgroup is *s*1, *s*2, *s*3.



#### tags 

#2200 #*special #strings 