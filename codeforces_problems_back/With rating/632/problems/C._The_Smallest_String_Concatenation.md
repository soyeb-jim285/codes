<h1 style='text-align: center;'> C. The Smallest String Concatenation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given a list of *n* strings *a*1, *a*2, ..., *a**n*. You'd like to concatenate them together in some order such that the resulting string would be lexicographically smallest.

Given the list of strings, output the lexicographically smallest concatenation.

## Input

The first line contains integer *n* — the number of strings (1 ≤ *n* ≤ 5·104).

Each of the next *n* lines contains one string *a**i* (1 ≤ |*a**i*| ≤ 50) consisting of only lowercase English letters. The sum of string lengths will not exceed 5·104.

## Output

Print the only string *a* — the lexicographically smallest string concatenation.

## Examples

## Input


```
4  
abba  
abacaba  
bcd  
er  

```
## Output


```
abacabaabbabcder  

```
## Input


```
5  
x  
xx  
xxa  
xxaa  
xxaaa  

```
## Output


```
xxaaaxxaaxxaxxx  

```
## Input


```
3  
c  
cb  
cba  

```
## Output


```
cbacbc  

```


#### tags 

#1700 #sortings #strings 