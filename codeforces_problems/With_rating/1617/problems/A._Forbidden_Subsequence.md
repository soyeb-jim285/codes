<h1 style='text-align: center;'> A. Forbidden Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given strings $S$ and $T$, consisting of lowercase English letters. It is guaranteed that $T$ is a permutation of the string abc. 

Find string $S'$, the lexicographically smallest permutation of $S$ such that $T$ is not a subsequence of $S'$.

String $a$ is a permutation of string $b$ if the number of occurrences of each distinct character is the same in both strings.

A string $a$ is a subsequence of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds:

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a string $S$ ($1 \le |S| \le 100$), consisting of lowercase English letters.

The second line of each test case contains a string $T$ that is a permutation of the string abc. (Hence, $|T| = 3$).

## Note

 that there is no limit on the sum of $|S|$ across all test cases.

### Output

For each test case, output a single string $S'$, the lexicographically smallest permutation of $S$ such that $T$ is not a subsequence of $S'$.

## Example

### Input


```text
7
abacaba
abc
cccba
acb
dbsic
bac
abracadabra
abc
dddddddddddd
cba
bbc
abc
ac
abc
```
### Output


```text
aaaacbb
abccc
bcdis
aaaaacbbdrr
dddddddddddd
bbc
ac
```
## Note

In the first test case, both aaaabbc and aaaabcb are lexicographically smaller than aaaacbb, but they contain abc as a subsequence.

In the second test case, abccc is the smallest permutation of cccba and does not contain acb as a subsequence.

In the third test case, bcdis is the smallest permutation of dbsic and does not contain bac as a subsequence.



#### Tags 

#800 #NOT OK #constructive_algorithms #greedy #sortings #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_761_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
