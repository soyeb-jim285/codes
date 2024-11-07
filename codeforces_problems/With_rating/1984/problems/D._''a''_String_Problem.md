<h1 style='text-align: center;'> D. "a" String Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase Latin characters. Count the number of nonempty strings $t \neq$ "$\texttt{a}$" such that it is possible to partition$^{\dagger}$ $s$ into some substrings satisfying the following conditions: 

* each substring either equals $t$ or "$\texttt{a}$", and
* at least one substring equals $t$.

 $^{\dagger}$ A partition of a string $s$ is an ordered sequence of some $k$ strings $t_1, t_2, \ldots, t_k$ (called substrings) such that $t_1 + t_2 + \ldots + t_k = s$, where $+$ represents the concatenation operation.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The only line of each test case contains a string $s$ consisting of lowercase Latin characters ($2 \leq |s| \leq 2 \cdot 10^5$).

The sum of $|s|$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, output a single integer — the number of nonempty strings $t \neq$ "$\texttt{a}$" that satisfy all constraints.

## Example

### Input


```text
8aaaaababacabacbaaabaaabitsetababbaaaabbbyearnineteeneightyfour
```
### Output

```text

4
4
1
16
1
2
3
1

```
## Note

In the first test case, $t$ can be "$\texttt{aa}$", "$\texttt{aaa}$", "$\texttt{aaaa}$", or the full string.

In the second test case, $t$ can be "$\texttt{b}$", "$\texttt{bab}$", "$\texttt{ba}$", or the full string.

In the third test case, the only such $t$ is the full string.



#### Tags 

#2000 #NOT OK #brute_force #hashing #implementation #math #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_26.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
