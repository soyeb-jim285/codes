<h1 style='text-align: center;'> B. Substring and Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $a$ and $b$, both consisting of lowercase Latin letters. 

A subsequence of a string is a string which can be obtained by removing several (possibly zero) characters from the original string. A substring of a string is a contiguous subsequence of that string.

For example, consider the string abac:

* a, b, c, ab, aa, ac, ba, bc, aba, abc, aac, bac and abac are its subsequences;
* a, b, c, ab, ba, ac, aba, bac and abac are its substrings.

Your task is to calculate the minimum possible length of the string that contains $a$ as a substring and $b$ as a subsequence.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each test case contains a string $a$ ($1 \le |a| \le 100$), consisting of lowercase Latin letters.

The second line of each test case contains a string $b$ ($1 \le |b| \le 100$), consisting of lowercase Latin letters.

## Output

For each test case, print a single integer — the minimum possible length of the string that contains $a$ as a substring and $b$ as a subsequence.

## Example

## Input


```

5abacbercfmmmmmmcontesttestcdeabcefg
```
## Output


```

4
4
3
7
7

```
## Note

In the examples below, the characters that correspond to the subsequence equal to $b$ are bolded.

In the first example, one of the possible answers is caba.

In the second example, one of the possible answers is ercf.

In the third example, one of the possible answers is mmm.

In the fourth example, one of the possible answers is contest.

In the fifth example, one of the possible answers is abcdefg.



#### tags 

#1200 #brute_force #greedy #strings 