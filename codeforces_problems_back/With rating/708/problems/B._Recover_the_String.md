<h1 style='text-align: center;'> B. Recover the String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For each string *s* consisting of characters '0' and '1' one can define four integers *a*00, *a*01, *a*10 and *a*11, where *a**xy* is the number of subsequences of length 2 of the string *s* equal to the sequence {*x*, *y*}. 

In these problem you are given four integers *a*00, *a*01, *a*10, *a*11 and have to find any non-empty string *s* that matches them, or determine that there is no such string. One can prove that if at least one answer exists, there exists an answer of length no more than 1 000 000.

## Input

The only line of the input contains four non-negative integers *a*00, *a*01, *a*10 and *a*11. Each of them doesn't exceed 109.

## Output

If there exists a non-empty string that matches four integers from the input, print it in the only line of the output. Otherwise, print "Impossible". The length of your answer must not exceed 1 000 000.

## Examples

## Input


```
1 2 3 4  

```
## Output


```
Impossible  

```
## Input


```
1 2 2 1  

```
## Output


```
0110  

```


#### tags 

#1900 #constructive_algorithms #greedy #implementation #math 