<h1 style='text-align: center;'> D. Double Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ strings $s_1, s_2, \dots, s_n$ of length at most $\mathbf{8}$. 

For each string $s_i$, determine if there exist two strings $s_j$ and $s_k$ such that $s_i = s_j + s_k$. That is, $s_i$ is the concatenation of $s_j$ and $s_k$. 
## Note

 that $j$ can be equal to $k$.

Recall that the concatenation of strings $s$ and $t$ is $s + t = s_1 s_2 \dots s_p t_1 t_2 \dots t_q$, where $p$ and $q$ are the lengths of strings $s$ and $t$ respectively. For example, concatenation of "code" and "forces" is "codeforces".

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$) — the number of strings.

Then $n$ lines follow, the $i$-th of which contains non-empty string $s_i$ of length at most $\mathbf{8}$, consisting of lowercase English letters. Among the given $n$ strings, there may be equal (duplicates).

The sum of $n$ over all test cases doesn't exceed $10^5$.

### Output

For each test case, output a binary string of length $n$. The $i$-th bit should be $\texttt{1}$ if there exist two strings $s_j$ and $s_k$ where $s_i = s_j + s_k$, and $\texttt{0}$ otherwise. 
## Note

 that $j$ can be equal to $k$.

## Example

### Input


```text
35ababababcabacbc3xxxxxx8codeforcescodescodforcforcesecode
```
### Output

```text

10100
011
10100101

```
## Note

In the first test case, we have the following: 

* $s_1 = s_2 + s_2$, since $\texttt{abab} = \texttt{ab} + \texttt{ab}$. Remember that $j$ can be equal to $k$.
* $s_2$ is not the concatenation of any two strings in the list.
* $s_3 = s_2 + s_5$, since $\texttt{abc} = \texttt{ab} + \texttt{c}$.
* $s_4$ is not the concatenation of any two strings in the list.
* $s_5$ is not the concatenation of any two strings in the list.

 Since only $s_1$ and $s_3$ satisfy the conditions, only the first and third bits in the answer should be $\texttt{1}$, so the answer is $\texttt{10100}$.

#### Tags 

#1100 #OK #brute_force #data_structures #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_806_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
