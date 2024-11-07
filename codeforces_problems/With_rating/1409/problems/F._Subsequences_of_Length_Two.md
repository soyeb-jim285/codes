<h1 style='text-align: center;'> F. Subsequences of Length Two</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$ consisting of lowercase Latin letters. The length of $t$ is $2$ (i.e. this string consists only of two characters).

In one move, you can choose any character of $s$ and replace it with any lowercase Latin letter. More formally, you choose some $i$ and replace $s_i$ (the character at the position $i$) with some character from 'a' to 'z'.

You want to do no more than $k$ replacements in such a way that maximizes the number of occurrences of $t$ in $s$ as a subsequence.

Recall that a subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.

###### Input

The first line of the input contains two integers $n$ and $k$ ($2 \le n \le 200$; $0 \le k \le n$) — the length of $s$ and the maximum number of moves you can make. The second line of the input contains the string $s$ consisting of $n$ lowercase Latin letters. The third line of the input contains the string $t$ consisting of two lowercase Latin letters.

###### Output

Print one integer — the maximum possible number of occurrences of $t$ in $s$ as a subsequence if you replace no more than $k$ characters in $s$ optimally.

## Examples

###### Input


```text
4 2
bbaa
ab
```
###### Output


```text
3
```
###### Input


```text
7 3
asddsaf
sd
```
###### Output


```text
10
```
###### Input


```text
15 6
qwertyhgfdsazxc
qa
```
###### Output


```text
16
```
###### Input


```text
7 2
abacaba
aa
```
###### Output


```text
15
```
## Note

In the first example, you can obtain the string "abab" replacing $s_1$ with 'a' and $s_4$ with 'b'. Then the answer is $3$.

In the second example, you can obtain the string "ssddsdd" and get the answer $10$.

In the fourth example, you can obtain the string "aaacaaa" and get the answer $15$.



#### Tags 

#2100 #NOT OK #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_667_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
