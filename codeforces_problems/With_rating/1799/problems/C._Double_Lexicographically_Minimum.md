<h1 style='text-align: center;'> C. Double Lexicographically Minimum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$. You can reorder the characters to form a string $t$. Define $t_{\mathrm{max}}$ to be the lexicographical maximum of $t$ and $t$ in reverse order.

Given $s$ determine the lexicographically minimum value of $t_{\mathrm{max}}$ over all reorderings $t$ of $s$.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. Descriptions of test cases follow.

The first and only line of each test case contains a string $s$ ($1 \leq |s| \leq 10^5$). $s$ consists of only lowercase English letters. 

It is guaranteed that the sum of $|s|$ over all test cases does not exceed $10^5$.

### Output

For each test case print the lexicographically minimum value of $t_{\mathrm{max}}$ over all reorderings $t$ of $s$. 

## Example

### Input


```text
12aaababbabcaabbaabbbaaabbabbbabbbbabbcceagaffcaba
```
### Output

```text

a
aba
bab
bca
abba
abbba
ababa
bbab
bbabb
bbcca
agea
acffba

```
## Note

For the first test case, there is only one reordering of $s$, namely "a".

For the second test case, there are three reorderings of $s$.

* $t = \mathtt{aab}$: $t_{\mathrm{max}} = \max(\mathtt{aab}, \mathtt{baa}) = \mathtt{baa}$
* $t = \mathtt{aba}$: $t_{\mathrm{max}} = \max(\mathtt{aba}, \mathtt{aba}) = \mathtt{aba}$
* $t = \mathtt{baa}$: $t_{\mathrm{max}} = \max(\mathtt{baa}, \mathtt{aab}) = \mathtt{baa}$

The lexicographical minimum of $t_{\mathrm{max}}$ over all cases is "aba". 



#### Tags 

#1700 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_854_by_cybercats_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
