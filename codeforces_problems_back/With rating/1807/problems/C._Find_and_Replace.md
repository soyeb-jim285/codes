<h1 style='text-align: center;'> C. Find and Replace</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase Latin characters. In an operation, you can take a character and replace all occurrences of this character with $\texttt{0}$ or replace all occurrences of this character with $\texttt{1}$.

Is it possible to perform some number of moves so that the resulting string is an alternating binary string$^{\dagger}$? 

For example, consider the string $\texttt{abacaba}$. You can perform the following moves: 

* Replace $\texttt{a}$ with $\texttt{0}$. Now the string is $\color{red}{\texttt{0}}\texttt{b}\color{red}{\texttt{0}}\texttt{c}\color{red}{\texttt{0}}\texttt{b}\color{red}{\texttt{0}}$.
* Replace $\texttt{b}$ with $\texttt{1}$. Now the string is ${\texttt{0}}\color{red}{\texttt{1}}{\texttt{0}}\texttt{c}{\texttt{0}}\color{red}{\texttt{1}}{\texttt{0}}$.
* Replace $\texttt{c}$ with $\texttt{1}$. Now the string is ${\texttt{0}}{\texttt{1}}{\texttt{0}}\color{red}{\texttt{1}}{\texttt{0}}{\texttt{1}}{\texttt{0}}$. This is an alternating binary string.

$^{\dagger}$An alternating binary string is a string of $\texttt{0}$s and $\texttt{1}$s such that no two adjacent bits are equal. For example, $\texttt{01010101}$, $\texttt{101}$, $\texttt{1}$ are alternating binary strings, but $\texttt{0110}$, $\texttt{0a0a0}$, $\texttt{10100}$ are not.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2000$) — the length of the string $s$.

The second line of each test case contains a string consisting of $n$ lowercase Latin characters — the string $s$.

## Output

For each test case, output "YES" (without quotes) if you can make the string into an alternating binary string, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

87abacaba2aa1y4bkpt6ninfia6banana10codeforces8testcase
```
## Output


```

YES
NO
YES
YES
NO
YES
NO
NO

```
## Note

The first test case is explained in the statement.

In the second test case, the only possible binary strings you can make are $\texttt{00}$ and $\texttt{11}$, neither of which are alternating.

In the third test case, you can make $\texttt{1}$, which is an alternating binary string.



#### tags 

#800 #greedy #implementation #strings 