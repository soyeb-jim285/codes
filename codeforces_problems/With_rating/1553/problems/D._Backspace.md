<h1 style='text-align: center;'> D. Backspace</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$, both consisting of lowercase English letters. You are going to type the string $s$ character by character, from the first character to the last one.

When typing a character, instead of pressing the button corresponding to it, you can press the "Backspace" button. It deletes the last character you have typed among those that aren't deleted yet (or does nothing if there are no characters in the current string). For example, if $s$ is "abcbd" and you press Backspace instead of typing the first and the fourth characters, you will get the string "bd" (the first press of Backspace deletes no character, and the second press deletes the character 'c'). Another example, if $s$ is "abcaa" and you press Backspace instead of the last two letters, then the resulting text is "a".

Your task is to determine whether you can obtain the string $t$, if you type the string $s$ and press "Backspace" instead of typing several (maybe zero) characters of $s$.

### Input

The first line contains a single integer $q$ ($1 \le q \le 10^5$) — the number of test cases.

The first line of each test case contains the string $s$ ($1 \le |s| \le 10^5$). Each character of $s$ is a lowercase English letter.

The second line of each test case contains the string $t$ ($1 \le |t| \le 10^5$). Each character of $t$ is a lowercase English letter.

It is guaranteed that the total number of characters in the strings over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print "YES" if you can obtain the string $t$ by typing the string $s$ and replacing some characters with presses of "Backspace" button, or "NO" if you cannot.

You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

## Example

### Input


```text
4
ababa
ba
ababa
bb
aaa
aaaa
aababa
ababa
```
### Output


```text
YES
NO
NO
YES
```
## Note

Consider the example test from the statement.

In order to obtain "ba" from "ababa", you may press Backspace instead of typing the first and the fourth characters.

There's no way to obtain "bb" while typing "ababa".

There's no way to obtain "aaaa" while typing "aaa".

In order to obtain "ababa" while typing "aababa", you have to press Backspace instead of typing the first character, then type all the remaining characters.



#### Tags 

#1500 #NOT OK #dp #greedy #strings #two_pointers 

## Blogs
- [All Contest Problems](../Harbour.Space_Scholarship_Contest_2021-2022_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
