<h1 style='text-align: center;'> C. Remembering Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have multiset of *n* strings of the same length, consisting of lowercase English letters. We will say that those strings are easy to remember if for each string there is some position *i* and some letter *c* of the English alphabet, such that this string is the only string in the multiset that has letter *c* in position *i*.

For example, a multiset of strings {"abc", "aba", "adc", "ada"} are not easy to remember. And multiset {"abc", "ada", "ssa"} is easy to remember because: 

* the first string is the only string that has character *c* in position 3;
* the second string is the only string that has character *d* in position 2;
* the third string is the only string that has character *s* in position 2.

You want to change your multiset a little so that it is easy to remember. For *a**ij* coins, you can change character in the *j*-th position of the *i*-th string into any other lowercase letter of the English alphabet. Find what is the minimum sum you should pay in order to make the multiset of strings easy to remember.

## Input

The first line contains two integers *n*, *m* (1 ≤ *n*, *m* ≤ 20) — the number of strings in the multiset and the length of the strings respectively. Next *n* lines contain the strings of the multiset, consisting only of lowercase English letters, each string's length is *m*.

Next *n* lines contain *m* integers each, the *i*-th of them contains integers *a**i*1, *a**i*2, ..., *a**im* (0 ≤ *a**ij* ≤ 106).

## Output

Print a single number — the answer to the problem.

## Examples

## Input


```
4 5  
abcde  
abcde  
abcde  
abcde  
1 1 1 1 1  
1 1 1 1 1  
1 1 1 1 1  
1 1 1 1 1  

```
## Output


```
3  

```
## Input


```
4 3  
abc  
aba  
adc  
ada  
10 10 10  
10 1 10  
10 10 10  
10 1 10  

```
## Output


```
2  

```
## Input


```
3 3  
abc  
ada  
ssa  
1 1 1  
1 1 1  
1 1 1  

```
## Output


```
0  

```


#### tags 

#2500 #bitmasks #dp 