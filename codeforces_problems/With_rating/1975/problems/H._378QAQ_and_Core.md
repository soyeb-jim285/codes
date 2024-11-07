<h1 style='text-align: center;'> H. 378QAQ and Core</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

378QAQ has a string $s$ of length $n$. Define the core of a string as the substring$^\dagger$ with maximum lexicographic$^\ddagger$ order.

For example, the core of "$\mathtt{bazoka}$" is "$\mathtt{zoka}$", and the core of "$\mathtt{aaa}$" is "$\mathtt{aaa}$".

378QAQ wants to rearrange the string $s$ so that the core is lexicographically minimum. Find the lexicographically minimum possible core over all rearrangements of $s$.

$^\dagger$ A substring of string $s$ is a continuous segment of letters from $s$. For example, "$\mathtt{defor}$", "$\mathtt{code}$" and "$\mathtt{o}$" are all substrings of "$\mathtt{codeforces}$" while "$\mathtt{codes}$" and "$\mathtt{aaa}$" are not.

$^\ddagger$ A string $p$ is lexicographically smaller than a string $q$ if and only if one of the following holds: 

* $p$ is a prefix of $q$, but $p \ne q$; or
* in the first position where $p$ and $q$ differ, the string $p$ has a smaller element than the corresponding element in $q$ (when compared by their ASCII code).

For example, "$\mathtt{code}$" and "$\mathtt{coda}$" are both lexicographically smaller than "$\mathtt{codeforces}$" while "$\mathtt{codeforceston}$" and "$\mathtt{z}$" are not.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\leq t\leq 10^5$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\leq n\leq 10^6$) — the length of string $s$.

The next line of each test case contains the string $s$ of length $n$. The string $s$ consists of lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output the lexicographically minimum possible core over all rearrangements of $s$.

## Example

### Input


```text
63qaq4cccc6bazoka6zazzzz7ababbbb7ccbabcc
```
### Output

```text

qaq
cccc
z
zzz
bbababb
cbcacbc

```
## Note

In the first test case, all possible rearrangements and their corresponding cores are as follows: 

* "$\mathtt{qaq}$", its core is "$\mathtt{qaq}$".
* "$\mathtt{aqq}$", its core is "$\mathtt{qq}$".
* "$\mathtt{qqa}$", its core is "$\mathtt{qqa}$".

So the core with the minimum lexicographic order in all rearrangement plans is "$\mathtt{qaq}$".



#### Tags 

#3500 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_947_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
