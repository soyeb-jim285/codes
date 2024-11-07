<h1 style='text-align: center;'> A. LuoTianyi and the Palindrome String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

LuoTianyi gives you a palindrome$^{\dagger}$ string $s$, and she wants you to find out the length of the longest non-empty subsequence$^{\ddagger}$ of $s$ which is not a palindrome string. If there is no such subsequence, output $-1$ instead.

$^{\dagger}$ A palindrome is a string that reads the same backward as forward. For example, strings "z", "aaa", "aba", "abccba" are palindromes, but strings "codeforces", "reality", "ab" are not.

$^{\ddagger}$ A string $a$ is a subsequence of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from $b$. For example, strings "a", "aaa", "bab" are subsequences of string "abaab", but strings "codeforces", "bbb", "h" are not.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first and the only line of each test case contains a single string $s$ ($1 \le |s| \le 50$) consisting of lowercase English letters — the string that LuoTianyi gives you. It's guaranteed that $s$ is a palindrome string.

### Output

For each test case, output a single integer — the length of the longest non-empty subsequence which is not a palindrome string. If there is no such subsequence, output $-1$.

## Example

### Input


```text
4abacabaaaacodeforcesecrofedoclol
```
### Output

```text

6
-1
18
2

```
## Note

In the first test case, "abcaba" is a subsequence of "abacaba" as we can delete the third letter of "abacaba" to get "abcaba", and "abcaba" is not a palindrome string. We can prove that "abcaba" is an example of the longest subsequences of "abacaba" that isn't palindrome, so that the answer is $6$.

In the second test case, we can only get "a" and "aa", but they are all palindrome strings, so the answer is $-1$.



#### Tags 

#800 #OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_872_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
