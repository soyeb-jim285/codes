<h1 style='text-align: center;'> B. Prinzessin der Verurteilung</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

I, Fischl, Prinzessin der Verurteilung, descend upon this land by the call of fate an — Oh, you are also a traveler from another world? Very well, I grant you permission to travel with me.

It is no surprise Fischl speaks with a strange choice of words. However, this time, not even Oz, her raven friend, can interpret her expressions! Maybe you can help us understand what this young princess is saying?

You are given a string of $n$ lowercase Latin letters, the word that Fischl just spoke. You think that the MEX of this string may help you find the meaning behind this message. The MEX of the string is defined as the shortest string that doesn't appear as a contiguous substring in the input. If multiple strings exist, the lexicographically smallest one is considered the MEX. Note that the empty substring does NOT count as a valid MEX.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Find out what the MEX of the string is!

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 1000$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 1000$) — the length of the word. The second line for each test case contains a single string of $n$ lowercase Latin letters.

The sum of $n$ over all test cases will not exceed $1000$.

### Output

For each test case, output the MEX of the string on a new line.

## Example

### Input


```text
3
28
qaabzwsxedcrfvtgbyhnujmiklop
13
cleanairactbd
10
aannttoonn
```
### Output


```text
ac
f
b
```


#### Tags 

#1200 #NOT OK #brute_force #constructive_algorithms #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_724_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
