<h1 style='text-align: center;'> E. Short Code</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady's code contains $n$ variables. Each variable has a unique name consisting of lowercase English letters only. One day Arkady decided to shorten his code.

He wants to replace each variable name with its non-empty prefix so that these new names are still unique (however, a new name of some variable can coincide with some old name of another or same variable). Among such possibilities he wants to find the way with the smallest possible total length of the new names.

A string $a$ is a prefix of a string $b$ if you can delete some (possibly none) characters from the end of $b$ and obtain $a$.

Please find this minimum possible total length of new names.

## Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$) — the number of variables.

The next $n$ lines contain variable names, one per line. Each name is non-empty and contains only lowercase English letters. The total length of these strings is not greater than $10^5$. The variable names are distinct.

## Output

Print a single integer — the minimum possible total length of new variable names.

## Examples

## Input


```
3  
codeforces  
codehorses  
code  

```
## Output


```
6  

```
## Input


```
5  
abba  
abb  
ab  
aa  
aacada  

```
## Output


```
11  

```
## Input


```
3  
telegram  
digital  
resistance  

```
## Output


```
3  

```
## Note

In the first example one of the best options is to shorten the names in the given order as "cod", "co", "c".

In the second example we can shorten the last name to "aac" and the first name to "a" without changing the other names.



#### tags 

#2200 #data_structures #dp #greedy #strings #trees 