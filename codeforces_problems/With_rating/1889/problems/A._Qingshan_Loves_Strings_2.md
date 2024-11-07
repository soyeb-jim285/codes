<h1 style='text-align: center;'> A. Qingshan Loves Strings 2</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Qingshan has a string $s$ which only contains $\texttt{0}$ and $\texttt{1}$.

A string $a$ of length $k$ is good if and only if

* $a_i \ne a_{k-i+1}$ for all $i=1,2,\ldots,k$.

For Div. 2 contestants, note that this condition is different from the condition in problem B.

For example, $\texttt{10}$, $\texttt{1010}$, $\texttt{111000}$ are good, while $\texttt{11}$, $\texttt{101}$, $\texttt{001}$, $\texttt{001100}$ are not good.

Qingshan wants to make $s$ good. To do this, she can do the following operation at most $300$ times (possibly, zero): 

* insert $\texttt{01}$ to any position of $s$ (getting a new $s$).

Please tell Qingshan if it is possible to make $s$ good. If it is possible, print a sequence of operations that makes $s$ good.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n\le 100$) — the length of string $s$, respectively.

The second line of each test case contains a string $s$ with length $n$.

It is guaranteed that $s$ only consists of $\texttt{0}$ and $\texttt{1}$.

### Output

For each test case, if it impossible to make $s$ good, output $-1$.

Otherwise, output $p$ ($0 \le p \le 300$) — the number of operations, in the first line.

Then, output $p$ integers in the second line. The $i$-th integer should be an index $x_i$ ($0 \le x_i \le n+2i-2$) — the position where you want to insert $\texttt{01}$ in the current $s$. If $x_i=0$, you insert $\texttt{01}$ at the beginning of $s$. Otherwise, you insert $\texttt{01}$ immediately after the $x_i$-th character of $s$.

We can show that under the constraints in this problem, if an answer exists, there is always an answer that requires at most $300$ operations.

## Example

### Input


```text
620130004111160011101001110011003001
```
### Output

```text

0

-1
-1
2
6 7
1
10
-1

```
## Note

In the first test case, you can do zero operations and get $s=\texttt{01}$, which is good.

Another valid solution is to do one operation: (the inserted $\texttt{01}$ is underlined)

1. $\texttt{0}\underline{\texttt{01}}\texttt{1}$

and get $s = \texttt{0011}$, which is good.

In the second and the third test case, it is impossible to make $s$ good.

In the fourth test case, you can do two operations:

1. $\texttt{001110}\underline{\texttt{01}}$
2. $\texttt{0011100}\underline{\texttt{01}}\texttt{1}$

and get $s = \texttt{0011100011}$, which is good.



#### Tags 

#1300 #NOT OK #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_906_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
