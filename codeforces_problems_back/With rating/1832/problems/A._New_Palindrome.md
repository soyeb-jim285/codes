<h1 style='text-align: center;'> A. New Palindrome</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A palindrome is a string that reads the same from left to right as from right to left. For example, abacaba, aaaa, abba, racecar are palindromes.

You are given a string $s$ consisting of lowercase Latin letters. The string $s$ is a palindrome.

You have to check whether it is possible to rearrange the letters in it to get another palindrome (not equal to the given string $s$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The only line of each test case contains a string $s$ ($2 \le |s| \le 50$) consisting of lowercase Latin letters. This string is a palindrome.

## Output

For each test case, print YES if it is possible to rearrange the letters in the given string to get another palindrome. Otherwise, print NO. 

You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

## Example

## Input


```

3codedocggaabaa
```
## Output


```

YES
NO
NO

```
## Note

In the first test case, it is possible to rearrange the letters in the palindrome codedoc to obtain the string ocdedco, which is different from the given string, but also a palindrome.



#### tags 

#800 #strings 