<h1 style='text-align: center;'> A. Oh Those Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A non-empty string is called palindrome, if it reads the same from the left to the right and from the right to the left. For example, "abcba", "a", and "abba" are palindromes, while "abab" and "xy" are not.

A string is called a substring of another string, if it can be obtained from that string by dropping some (possibly zero) number of characters from the beginning and from the end of it. For example, "abc", "ab", and "c" are substrings of the string "abc", while "ac" and "d" are not.

Let's define a palindromic count of the string as the number of its substrings that are palindromes. For example, the palindromic count of the string "aaa" is $6$ because all its substrings are palindromes, and the palindromic count of the string "abc" is $3$ because only its substrings of length $1$ are palindromes.

You are given a string $s$. You can arbitrarily rearrange its characters. You goal is to obtain a string with the maximum possible value of palindromic count.

## Input

The first line contains an integer $n$ ($1 \le n \le 100\,000$) — the length of string $s$.

The second line contains string $s$ that consists of exactly $n$ lowercase characters of Latin alphabet.

## Output

Print string $t$, which consists of the same set of characters (and each characters appears exactly the same number of times) as string $s$. Moreover, $t$ should have the maximum possible value of palindromic count among all such strings strings.

If there are multiple such strings, print any of them.

## Examples

## Input


```
5  
oolol  

```
## Output


```
ololo  

```
## Input


```
16  
gagadbcgghhchbdf  

```
## Output


```
abccbaghghghgdfd  

```
## Note

In the first example, string "ololo" has $9$ palindromic substrings: "o", "l", "o", "l", "o", "olo", "lol", "olo", "ololo". ## Note

, that even though some substrings coincide, they are counted as many times as they appear in the resulting string.

In the second example, the palindromic count of string "abccbaghghghgdfd" is $29$.



#### tags 

#1300 #constructive_algorithms #strings 