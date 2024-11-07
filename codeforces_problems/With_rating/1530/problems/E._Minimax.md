<h1 style='text-align: center;'> E. Minimax</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Prefix function of string $t = t_1 t_2 \ldots t_n$ and position $i$ in it is defined as the length $k$ of the longest proper (not equal to the whole substring) prefix of substring $t_1 t_2 \ldots t_i$ which is also a suffix of the same substring.

For example, for string $t = $ abacaba the values of the prefix function in positions $1, 2, \ldots, 7$ are equal to $[0, 0, 1, 0, 1, 2, 3]$.

Let $f(t)$ be equal to the maximum value of the prefix function of string $t$ over all its positions. For example, $f($abacaba$) = 3$.

You are given a string $s$. Reorder its characters arbitrarily to get a string $t$ (the number of occurrences of any character in strings $s$ and $t$ must be equal). The value of $f(t)$ must be minimized. Out of all options to minimize $f(t)$, choose the one where string $t$ is the lexicographically smallest.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The only line of each test case contains string $s$ ($1 \le |s| \le 10^5$) consisting of lowercase English letters.

It is guaranteed that the sum of lengths of $s$ over all test cases does not exceed $10^5$.

### Output

For each test case print a single string $t$.

The multisets of letters in strings $s$ and $t$ must be equal. The value of $f(t)$, the maximum of prefix functions in string $t$, must be as small as possible. String $t$ must be the lexicographically smallest string out of all strings satisfying the previous conditions.

## Example

### Input


```text
3
vkcup
abababa
zzzzzz
```
### Output


```text
ckpuv
aababab
zzzzzz
```
## Note

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds:

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

In the first test case, $f(t) = 0$ and the values of prefix function are $[0, 0, 0, 0, 0]$ for any permutation of letters. String ckpuv is the lexicographically smallest permutation of letters of string vkcup.

In the second test case, $f(t) = 1$ and the values of prefix function are $[0, 1, 0, 1, 0, 1, 0]$.

In the third test case, $f(t) = 5$ and the values of prefix function are $[0, 1, 2, 3, 4, 5]$.



#### Tags 

#2100 #NOT OK #constructive_algorithms #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_733_(Div._1_+_Div._2,_based_on_VK_Cup_2021_-_Elimination_(Engine)).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
