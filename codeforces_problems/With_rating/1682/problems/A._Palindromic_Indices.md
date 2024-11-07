<h1 style='text-align: center;'> A. Palindromic Indices</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a palindromic string $s$ of length $n$.

You have to count the number of indices $i$ $(1 \le i \le n)$ such that the string after removing $s_i$ from $s$ still remains a palindrome. 

For example, consider $s$ = "aba"

1. If we remove $s_1$ from $s$, the string becomes "ba" which is not a palindrome.
2. If we remove $s_2$ from $s$, the string becomes "aa" which is a palindrome.
3. If we remove $s_3$ from $s$, the string becomes "ab" which is not a palindrome.

A palindrome is a string that reads the same backward as forward. For example, "abba", "a", "fef" are palindromes whereas "codeforces", "acd", "xy" are not.

### Input

The input consists of multiple test cases. The first line of the input contains a single integer $t$ $(1 \leq t \leq 10^3)$  — the number of test cases. Description of the test cases follows.

The first line of each testcase contains a single integer $n$ $(2 \leq n \leq 10^5)$  — the length of string $s$.

The second line of each test case contains a string $s$ consisting of lowercase English letters. It is guaranteed that $s$ is a palindrome.

It is guaranteed that sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer  — the number of indices $i$ $(1 \le i \le n)$ such that the string after removing $s_i$ from $s$ still remains a palindrome. 

## Example

### Input


```text
33aba8acaaaaca2dd
```
### Output

```text

1
4
2

```
## Note

The first test case is described in the statement.

In the second test case, the indices $i$ that result in palindrome after removing $s_i$ are $3, 4, 5, 6$. Hence the answer is $4$. 

In the third test case, removal of any of the indices results in "d" which is a palindrome. Hence the answer is $2$.



#### Tags 

#800 #OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_793_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
