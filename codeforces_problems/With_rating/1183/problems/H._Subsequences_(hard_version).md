<h1 style='text-align: center;'> H. Subsequences (hard version)</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The only difference between the easy and the hard versions is constraints.

A subsequence is a string that can be derived from another string by deleting some or no symbols without changing the order of the remaining symbols. Characters to be deleted are not required to go successively, there can be any gaps between them. For example, for the string "abaca" the following strings are subsequences: "abaca", "aba", "aaa", "a" and "" (empty string). But the following strings are not subsequences: "aabaca", "cb" and "bcaa".

You are given a string $s$ consisting of $n$ lowercase Latin letters.

In one move you can take any subsequence $t$ of the given string and add it to the set $S$. The set $S$ can't contain duplicates. This move costs $n - |t|$, where $|t|$ is the length of the added subsequence (i.e. the price equals to the number of the deleted characters).

Your task is to find out the minimum possible total cost to obtain a set $S$ of size $k$ or report that it is impossible to do so.

###### Input

The first line of the input contains two integers $n$ and $k$ ($1 \le n \le 100, 1 \le k \le 10^{12}$) — the length of the string and the size of the set, correspondingly.

The second line of the input contains a string $s$ consisting of $n$ lowercase Latin letters.

###### Output

Print one integer — if it is impossible to obtain the set $S$ of size $k$, print -1. Otherwise, print the minimum possible total cost to do it.

## Examples

###### Input


```text
4 5
asdf
```
###### Output


```text
4
```
###### Input


```text
5 6
aaaaa
```
###### Output


```text
15
```
###### Input


```text
5 7
aaaaa
```
###### Output


```text
-1
```
###### Input


```text
10 100
ajihiushda
```
###### Output


```text
233
```
## Note

In the first example we can generate $S$ = { "asdf", "asd", "adf", "asf", "sdf" }. The cost of the first element in $S$ is $0$ and the cost of the others is $1$. So the total cost of $S$ is $4$.



#### Tags 

#1900 #NOT OK #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_570_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
