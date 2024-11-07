<h1 style='text-align: center;'> G. Antifibonacci Cut</h1>

<h5 style='text-align: center;'>time limit per test: 12 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 4 megabytes</h5>

Note that the memory limit is unusual.

Let's define the sequence of Fibonacci strings as follows: $f_0$ is 0, $f_1$ is 1, $f_i$ is $f_{i-1} + f_{i-2}$ for $i>1$ ($+$ denotes the concatenation of two strings). So, for example, $f_2$ is 10, $f_3$ is 101, $f_4$ is 10110.

For a given string $s$, let's define $g(s)$ as the number of ways to cut it into several (any number, possibly even just one) strings such that none of these strings are Fibonacci strings. For example, if $s$ is 10110101, $g(s) = 3$ since there are three ways to cut it:

* 101101 $+$ 01;
* 1011 $+$ 0101;
* 1011 $+$ 01 $+$ 01.

You are given a sequence of strings $s_1, s_2, \dots, s_n$. Calculate $g(s_1), g(s_1 + s_2), \dots, g(s_1 + s_2 + \ldots + s_n)$. Since these values can be huge, print them modulo $998244353$.

##### Input

The first line of the input contains one integer $n$ ($1 \le n \le 3 \cdot 10^3$).

Then, $n$ lines follow. The $i$-th line contains the string $s_i$ ($1 \le |s_i| \le 10^3$), consisting of characters 0 and/or 1.

##### Output

Print $n$ integers, where the $i$-th integer is $g(s_1 + s_2 + \ldots + s_i) \bmod 998244353$.

## Examples

##### Input


```text
1
10110101
```
##### Output


```text
3
```
##### Input


```text
3
1111
1
0
```
##### Output


```text
2
3
3
```
##### Input


```text
6
10110101
100100001110
0000001100010001
1111
1001010100101010101001
000100000010101111
```
##### Output


```text
3
561
1466229
9887505
972227653
52128355
```


#### Tags 

#3000 #NOT OK #bitmasks #combinatorics #constructive_algorithms #data_structures #dp #hashing #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_137_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
