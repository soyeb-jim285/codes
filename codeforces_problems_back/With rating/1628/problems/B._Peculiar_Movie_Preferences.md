<h1 style='text-align: center;'> B. Peculiar Movie Preferences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mihai plans to watch a movie. He only likes palindromic movies, so he wants to skip some (possibly zero) scenes to make the remaining parts of the movie palindromic.

You are given a list $s$ of $n$ non-empty strings of length at most $3$, representing the scenes of Mihai's movie.

A subsequence of $s$ is called awesome if it is non-empty and the concatenation of the strings in the subsequence, in order, is a palindrome.

Can you help Mihai check if there is at least one awesome subsequence of $s$?

A palindrome is a string that reads the same backward as forward, for example strings "z", "aaa", "aba", "abccba" are palindromes, but strings "codeforces", "reality", "ab" are not.

A sequence $a$ is a non-empty subsequence of a non-empty sequence $b$ if $a$ can be obtained from $b$ by deletion of several (possibly zero, but not all) elements.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the number of scenes in the movie.

Then follows $n$ lines, the $i$-th of which containing a single non-empty string $s_i$ of length at most $3$, consisting of lowercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, print "YES" if there is an awesome subsequence of $s$, or "NO" otherwise (case insensitive).

## Example

## Input


```

65zxabcczxba2abbad4codeforces3abc3abcdcba2abab
```
## Output


```

YES
NO
NO
YES
YES
NO

```
## Note

In the first test case, an awesome subsequence of $s$ is $[ab, cc, ba]$



#### tags 

#1700 #greedy #strings 