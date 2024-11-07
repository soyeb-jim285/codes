<h1 style='text-align: center;'> B. Qingshan Loves Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Qingshan has a string $s$, while Daniel has a string $t$. Both strings only contain $\texttt{0}$ and $\texttt{1}$.

A string $a$ of length $k$ is good if and only if

* $a_i \ne a_{i+1}$ for all $i=1,2,\ldots,k-1$.

For example, $\texttt{1}$, $\texttt{101}$, $\texttt{0101}$ are good, while $\texttt{11}$, $\texttt{1001}$, $\texttt{001100}$ are not good.

Qingshan wants to make $s$ good. To do this, she can do the following operation any number of times (possibly, zero):

* insert $t$ to any position of $s$ (getting a new $s$).

Please tell Qingshan if it is possible to make $s$ good.

### Input

The input consists of multiple test cases. The first line contains a single integer $T$ ($1\le T\le 2000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n,m \le 50$) — the length of the strings $s$ and $t$, respectively.

The second line of each test case contains a string $s$ of length $n$.

The third line of each test case contains a string $t$ of length $m$.

It is guaranteed that $s$ and $t$ only contain $\texttt{0}$ and $\texttt{1}$.

### Output

For each test case, print "YES" (without quotes), if it is possible to make $s$ good, and "NO" (without quotes) otherwise.

You can print letters in any case (upper or lower).

## Example

### Input


```text
51 1103 31110103 2111006 7101100101010110 2100100100010
```
### Output

```text

Yes
Yes
No
No
No

```
## Note

In the first test case, $s$ is good initially, so you can get a good $s$ by doing zero operations.

In the second test case, you can do the following two operations (the inserted string $t$ is underlined):

1. $\texttt{1}\underline{\texttt{010}}\texttt{11}$
2. $\texttt{10101}\underline{\texttt{010}}\texttt{1}$

and get $s = \texttt{101010101}$, which is good.

In the third test case, there is no way to make $s$ good after any number of operations.



#### Tags 

#800 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_906_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
