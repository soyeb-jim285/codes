<h1 style='text-align: center;'> A.  Déjà Vu</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A palindrome is a string that reads the same backward as forward. For example, the strings "z", "aaa", "aba", and "abccba" are palindromes, but "codeforces" and "ab" are not. You hate palindromes because they give you déjà vu.

There is a string $s$. You must insert exactly one character 'a' somewhere in $s$. If it is possible to create a string that is not a palindrome, you should find one example. Otherwise, you should report that it is impossible.

For example, suppose $s=$ "cbabc". By inserting an 'a', you can create "acbabc", "cababc", "cbaabc", "cbabac", or "cbabca". However "cbaabc" is a palindrome, so you must output one of the other options.

### Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases.

The only line of each test case contains a string $s$ consisting of lowercase English letters.

The total length of all strings does not exceed $3\cdot 10^5$.

### Output

For each test case, if there is no solution, output "NO".

Otherwise, output "YES" followed by your constructed string of length $|s|+1$ on the next line. If there are multiple solutions, you may print any.

You can print each letter of "YES" and "NO" in any case (upper or lower).

## Example

### Input


```text
6
cbabc
ab
zza
ba
a
nutforajaroftuna
```
### Output


```text
YES
cbabac
YES
aab
YES
zaza
YES
baa
NO
YES
nutforajarofatuna
```
## Note

The first test case is described in the statement.

In the second test case, we can make either "aab" or "aba". But "aba" is a palindrome, so "aab" is the only correct answer.

In the third test case, "zaza" and "zzaa" are correct answers, but not "azza".

In the fourth test case, "baa" is the only correct answer.

In the fifth test case, we can only make "aa", which is a palindrome. So the answer is "NO".

In the sixth test case, "anutforajaroftuna" is a palindrome, but inserting 'a' elsewhere is valid.



#### Tags 

#800 #NOT OK #constructive_algorithms #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_712_(Div._2).md)
- [Codeforces Round #712 (en)](../blogs/Codeforces_Round_712_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
