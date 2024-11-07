<h1 style='text-align: center;'> A. We Got Everything Covered!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two positive integers $n$ and $k$. 

Your task is to find a string $s$ such that all possible strings of length $n$ that can be formed using the first $k$ lowercase English alphabets occur as a subsequence of $s$. 

If there are multiple answers, print the one with the smallest length. If there are still multiple answers, you may print any of them.

## Note

: A string $a$ is called a subsequence of another string $b$ if $a$ can be obtained by deleting some (possibly zero) characters from $b$ without changing the order of the remaining characters.

### Input

The first line of input contains a single integer $t$ ($1\leq t\leq 676$) denoting the number of test cases.

Each test case consists of a single line of input containing two integers $n$ ($1\leq n\leq 26$) and $k$ ($1\leq k\leq 26$).

### Output

For each test case, print a single line containing a single string $s$ which satisfies the above property. If there are multiple answers, print the one with the smallest length. If there are still multiple answers, you may print any of them.

## Example

### Input


```text
41 22 12 22 3
```
### Output

```text

ab
aa
baab
abcbac

```
## Note

For the first test case, there are two strings of length $1$ which can be formed using the first $2$ lowercase English alphabets, and they are present in $s$ as a subsequence as follows: 

* $\texttt{a}: {\color{red}{\texttt{a}}}\texttt{b}$
* $\texttt{b}: \texttt{a}{\color{red}{\texttt{b}}}$

For the second test case, there is only one string of length $2$ which can be formed using the first lowercase English alphabet, and it is present in $s$ as a subsequence as follows: 

* $\texttt{aa}: {\color{red}{\texttt{aa}}}$

For the third test case, there are $4$ strings of length $2$ which can be formed using the first $2$ lowercase English alphabets, and they are present in $s$ as a subsequence as follows: 

* $\texttt{aa}: \texttt{b}{\color{red}{\texttt{aa}}}\texttt{b}$
* $\texttt{ab}: \texttt{ba}{\color{red}{\texttt{ab}}}$
* $\texttt{ba}: {\color{red}{\texttt{ba}}}\texttt{ab}$
* $\texttt{bb}: {\color{red}{\texttt{b}}}\texttt{aa}{\color{red}{\texttt{b}}}$

For the fourth test case, there are $9$ strings of length $2$ which can be formed using the first $3$ lowercase English alphabets, and they are present in $s$ as a subsequence as follows: 

* $\texttt{aa}: {\color{red}{\texttt{a}}}\texttt{bcb}{\color{red}{\texttt{a}}}\texttt{c}$
* $\texttt{ab}: {\color{red}{\texttt{ab}}}\texttt{cbac}$
* $\texttt{ac}: \texttt{abcb}{\color{red}{\texttt{ac}}}$
* $\texttt{ba}: \texttt{abc}{\color{red}{\texttt{ba}}}\texttt{c}$
* $\texttt{bb}: \texttt{a}{\color{red}{\texttt{b}}}\texttt{c}{\color{red}{\texttt{b}}}\texttt{ac}$
* $\texttt{bc}: \texttt{a}{\color{red}{\texttt{bc}}}\texttt{bac}$
* $\texttt{ca}: \texttt{ab}{\color{red}{\texttt{c}}}\texttt{b}{\color{red}{\texttt{a}}}\texttt{c}$
* $\texttt{cb}: \texttt{ab}{\color{red}{\texttt{cb}}}\texttt{ac}$
* $\texttt{cc}: \texttt{ab}{\color{red}{\texttt{c}}}\texttt{ba}{\color{red}{\texttt{c}}}$


#### Tags 

#800 #NOT OK #constructive_algorithms #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_921_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
