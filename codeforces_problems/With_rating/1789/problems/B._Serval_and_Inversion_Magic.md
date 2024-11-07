<h1 style='text-align: center;'> B. Serval and Inversion Magic</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Serval has a string $s$ that only consists of 0 and 1 of length $n$. The $i$-th character of $s$ is denoted as $s_i$, where $1\leq i\leq n$.

Serval can perform the following operation called Inversion Magic on the string $s$:

* Choose an segment $[l, r]$ ($1\leq l\leq r\leq n$). For $l\leq i\leq r$, change $s_i$ into 1 if $s_i$ is 0, and change $s_i$ into 0 if $s_i$ is 1.

For example, let $s$ be 010100 and the segment $[2,5]$ is chosen. The string $s$ will be 001010 after performing the Inversion Magic.

Serval wants to make $s$ a palindrome after performing Inversion Magic exactly once. Help him to determine whether it is possible.

A string is a palindrome iff it reads the same backwards as forwards. For example, 010010 is a palindrome but 10111 is not.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\leq t\leq 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2\leq n\leq 10^5$) — the length of string $s$.

The second line of each test case contains a binary string $s$ of length $n$. Only characters 0 and 1 can appear in $s$.

It's guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, print Yes if $s$ can be a palindrome after performing Inversion Magic exactly once, and print No if not.

You can output Yes and No in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

## Example

### Input


```text
34100151001070111011
```
### Output

```text

Yes
Yes
No

```
## Note

In the first test case, Serval can perform Inversion Magic on the segment $[1,4]$. The string $s$ will be 0110 after the magic.

In the second test case, Serval can perform Inversion Magic on the segment $[1,3]$. The string $s$ will be 01110 after the magic.

In the third test case, Serval can't make $s$ a palindrome by performing Inversion Magic exactly once.



#### Tags 

#800 #OK #brute_force #implementation #strings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_853_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
