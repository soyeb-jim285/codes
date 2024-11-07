<h1 style='text-align: center;'> D. Diane</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$. Find any string $s$ of length $n$ consisting only of English lowercase letters such that each non-empty substring of $s$ occurs in $s$ an odd number of times. If there are multiple such strings, output any. It can be shown that such string always exists under the given constraints.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

## Input

The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case, print a single line containing the string $s$. If there are multiple such strings, output any. It can be shown that such string always exists under the given constraints.

## Example

## Input


```

4
3
5
9
19

```
## Output


```

abc
diane
bbcaabbba
youarethecutestuwuu

```
## Note

In the first test case, each substring of "abc" occurs exactly once.

In the third test case, each substring of "bbcaabbba" occurs an odd number of times. In particular, "b" occurs $5$ times, "a" and "bb" occur $3$ times each, and each of the remaining substrings occurs exactly once.



#### tags 

#1800 #constructive_algorithms #greedy #strings 