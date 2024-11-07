<h1 style='text-align: center;'> I. Inverse Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider the following problem.

You are given a string $s$, consisting of $n$ lowercase Latin letters, and an integer $k$ ($n$ is not divisible by $k$). Each letter is one of the first $c$ letters of the alphabet.

You apply the following operation until the length of the string is less than $k$: choose a contiguous substring of the string of length exactly $k$, remove it from the string and glue the resulting parts together without changing the order.

Let the resulting string of length smaller than $k$ be $t$. What is lexicographically smallest string $t$ that can obtained?

You are asked the inverse of this problem. Given two integers $n$ and $k$ ($n$ is not divisible by $k$) and a string $t$, consisting of ($n \bmod k$) lowercase Latin letters, count the number of strings $s$ that produce $t$ as the lexicographically smallest solution.

Print that number modulo $998\,244\,353$.

###### Input

The first line contains three integers $n, k$ and $c$ ($1 \le n \le 10^6$; $2 \le k \le 10^6$; $1 \le c \le 26$; $n$ is not divisible by $k$) — the length of string $s$, the length of the substring that is being removed and the number of first letters from the alphabet.

The second line contains string $t$, consisting of exactly ($n \bmod k$) lowercase Latin letters. Each letter is one of the first $c$ letters of the alphabet.

###### Output

Print a single integer — the number of strings $s$ that produce $t$ as the lexicographically smallest solution.

## Examples

###### Input


```text
3 2 2
a
```
###### Output


```text
6
```
###### Input


```text
5 3 3
bc
```
###### Output


```text
15
```
###### Input


```text
34 12 26
codeforces
```
###### Output


```text
988024123
```
###### Input


```text
5 3 1
aa
```
###### Output


```text
1
```
## Note

The strings $s$ in the first example: "aaa", "aab", "aba", "abb", "baa", "bba".

The strings $s$ in the second example: "bcabc", "bcacc", "bcbbc", "bcbcc", "bccbc", "bcccc", "caabc", "cabbc", "cacbc", "cbabc", "cbbbc", "cbcbc", "ccabc", "ccbbc", "cccbc".



#### Tags 

#2700 #NOT OK #*special #combinatorics #dp 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_9_(Unrated,_T-Shirts_+_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
