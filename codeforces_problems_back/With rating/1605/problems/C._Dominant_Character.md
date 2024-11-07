<h1 style='text-align: center;'> C. Dominant Character</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ashish has a string $s$ of length $n$ containing only characters 'a', 'b' and 'c'.

He wants to find the length of the smallest substring, which satisfies the following conditions: 

* Length of the substring is at least $2$
* 'a' occurs strictly more times in this substring than 'b'
* 'a' occurs strictly more times in this substring than 'c'

 Ashish is busy planning his next Codeforces round. Help him solve the problem.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

## Input

The first line contains a single integer $t$ $(1 \le t \le 10^{5})$  — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ $(2 \le n \le 10^{6})$  — the length of the string $s$.

The second line of each test case contains a string $s$ consisting only of characters 'a', 'b' and 'c'.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^{6}$.

## Output

For each test case, output the length of the smallest substring which satisfies the given conditions or print $-1$ if there is no such substring.

## Example

## Input


```

3
2
aa
5
cbabb
8
cacabccc

```
## Output


```

2
-1
3

```
## Note

Consider the first test case. In the substring "aa", 'a' occurs twice, while 'b' and 'c' occur zero times. Since 'a' occurs strictly more times than 'b' and 'c', the substring "aa" satisfies the condition and the answer is $2$. The substring "a" also satisfies this condition, however its length is not at least $2$.

In the second test case, it can be shown that in none of the substrings of "cbabb" does 'a' occur strictly more times than 'b' and 'c' each.

In the third test case, "cacabccc", the length of the smallest substring that satisfies the conditions is $3$.



#### tags 

#1400 #brute_force #greedy #implementation #strings 