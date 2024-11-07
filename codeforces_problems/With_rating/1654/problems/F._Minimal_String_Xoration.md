<h1 style='text-align: center;'> F. Minimal String Xoration</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an integer $n$ and a string $s$ consisting of $2^n$ lowercase letters of the English alphabet. The characters of the string $s$ are $s_0s_1s_2\cdots s_{2^n-1}$.

A string $t$ of length $2^n$ (whose characters are denoted by $t_0t_1t_2\cdots t_{2^n-1}$) is a xoration of $s$ if there exists an integer $j$ ($0\le j \leq 2^n-1$) such that, for each $0 \leq i \leq 2^n-1$, $t_i = s_{i \oplus j}$ (where $\oplus$ denotes the operation [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR)).

Find the lexicographically minimal xoration of $s$.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

 
####### Input

The first line contains a single integer $n$ ($1 \le n \le 18$).

The second line contains a string $s$ consisting of $2^n$ lowercase letters of the English alphabet.

####### Output

Print a single line containing the lexicographically minimal xoration of $s$.

## Examples

####### Input


```text
2
acba
```
####### Output


```text
abca
```
####### Input


```text
3
bcbaaabb
```
####### Output


```text
aabbbcba
```
####### Input


```text
4
bdbcbccdbdbaaccd
```
####### Output


```text
abdbdccacbdbdccb
```
####### Input


```text
5
ccfcffccccccffcfcfccfffffcccccff
```
####### Output


```text
cccccffffcccccffccfcffcccccfffff
```
####### Input


```text
1
zz
```
####### Output


```text
zz
```
## Note

In the first test, the lexicographically minimal xoration $t$ of $s =$"acba" is "abca". It's a xoration because, for $j = 3$, 

* $t_0 = s_{0 \oplus j} = s_3 =$ "a";
* $t_1 = s_{1 \oplus j} = s_2 =$ "b";
* $t_2 = s_{2 \oplus j} = s_1 =$ "c";
* $t_3 = s_{3 \oplus j} = s_0 =$ "a".

 There isn't any xoration of $s$ lexicographically smaller than "abca".In the second test, the minimal string xoration corresponds to choosing $j = 4$ in the definition of xoration.

In the third test, the minimal string xoration corresponds to choosing $j = 11$ in the definition of xoration.

In the fourth test, the minimal string xoration corresponds to choosing $j = 10$ in the definition of xoration.

In the fifth test, the minimal string xoration corresponds to choosing either $j = 0$ or $j = 1$ in the definition of xoration.



#### Tags 

#2800 #NOT OK #bitmasks #data_structures #divide_and_conquer #greedy #hashing #sortings #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_778_(Div._1_+_Div._2,_based_on_Technocup_2022_Final_Round).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
