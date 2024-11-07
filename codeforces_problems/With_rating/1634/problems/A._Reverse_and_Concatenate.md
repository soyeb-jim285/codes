<h1 style='text-align: center;'> A. Reverse and Concatenate</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Real stupidity beats artificial intelligence every time.— Terry Pratchett, Hogfather, DiscworldYou are given a string $s$ of length $n$ and a number $k$. Let's denote by $rev(s)$ the reversed string $s$ (i.e. $rev(s) = s_n s_{n-1} ... s_1$). You can apply one of the two kinds of operations to the string:

* replace the string $s$ with $s + rev(s)$
* replace the string $s$ with $rev(s) + s$

How many different strings can you get as a result of performing exactly $k$ operations (possibly of different kinds) on the original string $s$?

In this statement we denoted the concatenation of strings $s$ and $t$ as $s + t$. In other words, $s + t = s_1 s_2 ... s_n t_1 t_2 ... t_m$, where $n$ and $m$ are the lengths of strings $s$ and $t$ respectively.

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — number of test cases. Next $2 \cdot t$ lines contain $t$ test cases:

The first line of a test case contains two integers $n$ and $k$ ($1 \le n \le 100$, $0 \le k \le 1000$) — the length of the string and the number of operations respectively.

The second string of a test case contains one string $s$ of length $n$ consisting of lowercase Latin letters.

### Output

For each test case, print the answer (that is, the number of different strings that you can get after exactly $k$ operations) on a separate line.

It can be shown that the answer does not exceed $10^9$ under the given constraints.

## Example

### Input


```text
43 2aab3 3aab7 1abacaba2 0ab
```
### Output

```text

2
2
1
1

```
## Note

In the first test case of the example:

After the first operation the string $s$ can become either aabbaa or baaaab. After the second operation there are 2 possibilities for $s$: aabbaaaabbaa and baaaabbaaaab.



#### Tags 

#800 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_770_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
