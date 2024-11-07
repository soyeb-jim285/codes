<h1 style='text-align: center;'> D. Cases</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're a linguist studying a mysterious ancient language. You know that 

1. Its words consist only of the first $c$ letters of the Latin alphabet.
2. Each word has a case which can be unambiguously determined by its last letter (different letters correspond to different cases). For example, words "ABACABA" and "ABA" (if they exist) have the same case in this language because they both have the same ending 'A', whereas "ALICE" and "BOB" have different cases. If the language does not have a case corresponding to some letter, it means that the word cannot end with this letter.
3. The length of each word is $k$ or less.

You have a single text written in this language. Unfortunately, as the language is really ancient, spaces between words are missing and all letters are uppercase. You wonder what is the minimum number of cases the language can have. Can you find this out?

### Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10\,000$) — the number of test cases. It is followed by descriptions of the test cases.

The first line of each test case contains three integers $n$, $c$, $k$ ($1 \le k \le n \le 2^{18}$, $1 \le c \le 18$) — the length of the text, the number of letters in the language, and the maximum length of the word.

The second line contains a string of $n$ characters — the text itself. Each character is one of the first $c$ uppercase letters of the Latin alphabet.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2^{18}$ and the sum of $2^c$ over all test cases does not exceed $2^{18}$.

### Output

For each test case, output a single line consisting of a single integer — the minimum number of cases in the language.

## Example

### Input


```text
75 5 1ABCDE3 1 2AAA3 2 2AAB10 2 2ABABABABAB4 4 4DCBA1 17 1Q9 3 2ABCABCABC
```
### Output

```text

5
1
2
1
1
1
2

```
## Note

In the first test case, there must be five cases in the language (for each of the letters 'A', 'B', 'C', 'D', and 'E' there must be a case that has a corresponding ending).

In the fourth test case, one case with ending 'B' is sufficient. 



#### Tags 

#2300 #NOT OK #bitmasks #brute_force #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_961_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
