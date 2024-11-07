<h1 style='text-align: center;'> D. Balanced Ternary String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of exactly $n$ characters, and each character is either '0', '1' or '2'. Such strings are called ternary strings.

Your task is to replace minimum number of characters in this string with other characters to obtain a balanced ternary string (balanced ternary string is a ternary string such that the number of characters '0' in this string is equal to the number of characters '1', and the number of characters '1' (and '0' obviously) is equal to the number of characters '2').

Among all possible balanced ternary strings you have to obtain the lexicographically (alphabetically) smallest.

Note that you can neither remove characters from the string nor add characters to the string. Also note that you can replace the given characters only with characters '0', '1' and '2'.

It is guaranteed that the answer exists.

###### Input

The first line of the input contains one integer $n$ ($3 \le n \le 3 \cdot 10^5$, $n$ is divisible by $3$) — the number of characters in $s$.

The second line contains the string $s$ consisting of exactly $n$ characters '0', '1' and '2'.

###### Output

Print one string — the lexicographically (alphabetically) smallest balanced ternary string which can be obtained from the given one with minimum number of replacements.

Because $n$ is divisible by $3$ it is obvious that the answer exists. And it is obvious that there is only one possible answer.

## Examples

###### Input


```text
3
121
```
###### Output


```text
021
```
###### Input


```text
6
000000
```
###### Output


```text
001122
```
###### Input


```text
6
211200
```
###### Output


```text
211200
```
###### Input


```text
6
120110
```
###### Output


```text
120120
```


#### Tags 

#1500 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_531_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
