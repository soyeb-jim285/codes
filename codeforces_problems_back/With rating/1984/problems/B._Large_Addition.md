<h1 style='text-align: center;'> B. Large Addition</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A digit is large if it is between $5$ and $9$, inclusive. A positive integer is large if all of its digits are large.

You are given an integer $x$. Can it be the sum of two large positive integers with the same number of digits?

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The only line of each test case contains a single integer $x$ ($10 \leq x \leq 10^{18}$).

## Output

For each test case, output $\texttt{YES}$ if $x$ satisfies the condition, and $\texttt{NO}$ otherwise.

You can output $\texttt{YES}$ and $\texttt{NO}$ in any case (for example, strings $\texttt{yES}$, $\texttt{yes}$, and $\texttt{Yes}$ will be recognized as a positive response).

## Example

## Input


```

11133720013939381434987654321234567891111111111111111142019841069119
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
YES
YES
NO
NO

```
## Note

In the first test case, we can have $658 + 679 = 1337$.

In the second test case, it can be shown that no numbers of equal length and only consisting of large digits can add to $200$.

In the third test case, we can have $696\,969 + 696\,969 = 1\,393\,938$.

In the fourth test case, we can have $777 + 657 = 1434$.



#### tags 

#1100 #implementation #math 