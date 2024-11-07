<h1 style='text-align: center;'> H. Fortnite</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

Timofey is writing a competition called Capture the Flag (or CTF for short). He has one task left, which involves hacking a security system. The entire system is based on polynomial hashes$^{\text{∗}}$.

Timofey can input a string consisting of lowercase Latin letters into the system, and the system will return its polynomial hash. To hack the system, Timofey needs to find the polynomial hash parameters ($p$ and $m$) that the system uses.

Timofey doesn't have much time left, so he will only be able to make $3$ queries. Help him solve the task.

$^{\text{∗}}$ The polynomial hash of a string $s$, consisting of lowercase Latin letters of length $n$, based on $p$ and modulo $m$ is $(\mathrm{ord}(s_1) \cdot p ^ 0 + \mathrm{ord}(s_2) \cdot p ^ 1 + \mathrm{ord}(s_3) \cdot p ^ 2 + \ldots + \mathrm{ord}(s_n) \cdot p ^ {n - 1}) \bmod m$. Where $s_i$ denotes the $i$-th character of the string $s$, $\mathrm{ord}(\mathrm{chr})$ denotes the ordinal number of the character $\mathrm{chr}$ in the English alphabet, and $x \bmod m$ is the remainder of $x$ when divided by $m$.

### Input

Each test consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

It is guaranteed that the $p$ and $m$ used by the system satisfy the conditions: $26 < p \leq 50$ and $p + 1 < m \leq 2 \cdot 10^9$.

## Interaction

To make a query to the system, output ? $s$, where $s$ is a string of no more than $50$ characters in length, the hash of which you want to know. In response to this query, you will receive the polynomial hash of the string $s$.

To output the answer, output ! $p$ $m$, where $p$ is the base of the hash, and $m$ is the modulus. After that, immediately proceed to the next test case.

You have to make not more than $3$ queries ?, otherwise you will get verdict Wrong Answer.

After outputting a query, do not forget to output a newline and flush the output buffer. Otherwise, you will receive the verdict Idleness limit exceeded. To flush the buffer, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.
## Example

### Input


```text

1

32

28
```
#Output
```text

? aa

? yb

! 31 59
```
## Note

Answer for the first query is $(ord(a) \cdot 31^0 + ord(a) \cdot 31^1) \mod 59 = (1 + 1 \cdot 31) \mod 59 = 32$.

Answer for the second query is $(ord(y) \cdot 31^0 + ord(b) \cdot 31^1) \mod 59 = (25 + 2 \cdot 31) \mod 59 = 28$.



#### Tags 

#3500 #NOT OK #combinatorics #constructive_algorithms #games #greedy #hashing #interactive #math #number_theory #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_959_sponsored_by_NEAR_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
