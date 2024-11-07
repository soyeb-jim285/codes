<h1 style='text-align: center;'> E. Making Anti-Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$, consisting of lowercase English letters. In one operation, you are allowed to swap any two characters of the string $s$.

A string $s$ of length $n$ is called an anti-palindrome, if $s[i] \ne s[n - i + 1]$ for every $i$ ($1 \le i \le n$). For example, the strings "codeforces", "string" are anti-palindromes, but the strings "abacaba", "abc", "test" are not.

Determine the minimum number of operations required to make the string $s$ an anti-palindrome, or output $-1$, if this is not possible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

Each test case consists of two lines. The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the string $s$.

The second line contains the string $s$, consisting of $n$ lowercase English letters.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum number of operations required to make the string $s$ an anti-palindrome, or $-1$ if this is not possible.

## Example

### Input


```text
1010codeforces3abc10taarrrataa10dcbdbdcccc4wwww12cabbaccabaac10aadaaaaddc14aacdaaaacadcdc6abccba12dcbcaebacccd
```
### Output

```text

0
-1
1
1
-1
3
-1
2
2
2

```
## Note

In the first test case, the string "codeforces" is already an anti-palindrome, so the answer is $0$.

In the second test case, it can be shown that the string "abc" cannot be transformed into an anti-palindrome by performing the allowed operations, so the answer is $-1$.

In the third test case, it is enough to swap the second and the fifth characters of the string "taarrrataa", and the new string "trararataa" will be an anti-palindrome, so the answer is $1$.



#### Tags 

#1600 #NOT OK #greedy #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_867_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
