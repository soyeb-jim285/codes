<h1 style='text-align: center;'> F. Yet Another Substring Reverse</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting only of first $20$ lowercase Latin letters ('a', 'b', ..., 't').

Recall that the substring $s[l; r]$ of the string $s$ is the string $s_l s_{l + 1} \dots s_r$. For example, the substrings of "codeforces" are "code", "force", "f", "for", but not "coder" and "top".

You can perform the following operation no more than once: choose some substring $s[l; r]$ and reverse it (i.e. the string $s_l s_{l + 1} \dots s_r$ becomes $s_r s_{r - 1} \dots s_l$).

Your goal is to maximize the length of the maximum substring of $s$ consisting of distinct (i.e. unique) characters.

The string consists of distinct characters if no character in this string appears more than once. For example, strings "abcde", "arctg" and "minecraft" consist of distinct characters but strings "codeforces", "abacaba" do not consist of distinct characters.

###### Input

The only line of the input contains one string $s$ consisting of no more than $10^6$ characters 'a', 'b', ..., 't' (first $20$ lowercase Latin letters).

###### Output

Print one integer — the maximum possible length of the maximum substring of $s$ consisting of distinct characters after reversing no more than one its substring.

## Examples

###### Input


```text
abacaba
```
###### Output


```text
3
```
###### Input


```text
abcdecdf
```
###### Output


```text
6
```
###### Input


```text
aabbcc
```
###### Output


```text
3
```
###### Input


```text
abcdeefc
```
###### Output


```text
6
```


#### Tags 

#2200 #NOT OK #bitmasks #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_590_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
