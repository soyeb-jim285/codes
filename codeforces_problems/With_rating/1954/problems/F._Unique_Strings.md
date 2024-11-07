<h1 style='text-align: center;'> F. Unique Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's say that two strings $a$ and $b$ are equal if you can get the string $b$ by cyclically shifting string $a$. For example, the strings 0100110 and 1100100 are equal, while 1010 and 1100 are not.

You are given a binary string $s$ of length $n$. Its first $c$ characters are 1-s, and its last $n - c$ characters are 0-s.

In one operation, you can replace one 0 with 1.

Calculate the number of unique strings you can get using no more than $k$ operations. Since the answer may be too large, print it modulo $10^9 + 7$.

####### Input

The first and only line contains three integers $n$, $c$ and $k$ ($1 \le n \le 3000$; $1 \le c \le n$; $0 \le k \le n - c$) — the length of string $s$, the length of prefix of 1-s and the maximum number of operations.

####### Output

Print the single integer — the number of unique strings you can achieve performing no more than $k$ operations, modulo $10^9 + 7$.

## Examples

####### Input


```text
1 1 0
```
####### Output

```text

1

```
####### Input


```text
3 1 2
```
####### Output

```text

3

```
####### Input


```text
5 1 1
```
####### Output

```text

3

```
####### Input


```text
6 2 2
```
####### Output

```text

7

```
####### Input


```text
24 3 11
```
####### Output

```text

498062

```
## Note

In the first test case, the only possible string is 1.

In the second test case, the possible strings are: 100, 110, and 111. String 101 is equal to 110, so we don't count it.

In the third test case, the possible strings are: 10000, 11000, 10100. String 10010 is equal to 10100, and 10001 is equal to 11000.



#### Tags 

#3100 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_164_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
