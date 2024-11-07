<h1 style='text-align: center;'> F. Reconstruction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a hidden array $a_1, a_2, \ldots, a_n$ of length $n$ whose elements are integers between $-m$ and $m$, inclusive.

You are given an array $b_1, b_2, \ldots, b_n$ of length $n$ and a string $s$ of length $n$ consisting of the characters $\texttt{P}$, $\texttt{S}$, and $\texttt{?}$.

For each $i$ from $1$ to $n$ inclusive, we must have: 

* If $s_i = \texttt{P}$, $b_i$ is the sum of $a_1$ through $a_i$.
* If $s_i = \texttt{S}$, $b_i$ is the sum of $a_i$ through $a_n$.

## Output

 the number of ways to replace all $\texttt{?}$ in $s$ with either $\texttt{P}$ or $\texttt{S}$ such that there exists an array $a_1, a_2, \ldots, a_n$ with elements not exceeding $m$ by absolute value satisfying the constraints given by the array $b_1, b_2, \ldots, b_n$ and the string $s$.

Since the answer may be large, output it modulo $998\,244\,353$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($2 \leq n \leq 2 \cdot 10^3$, $2 \leq m \leq 10^{9}$) — the length of the hidden array $a_1, a_2, \ldots, a_n$ and the maximum absolute value of an element $a_i$.

The second line of each test case contains a string $s$ of length $n$ consisting of characters $\texttt{P}$, $\texttt{S}$, and $\texttt{?}$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($|b_i| \leq m \cdot n$).

The sum of $n$ over all test cases does not exceed $5 \cdot 10^3$.

## Output

For each test case, output a single integer — the number of ways to replace all $\texttt{?}$ in $s$ with either $\texttt{P}$ or $\texttt{S}$ that result in the existence of a valid array $a_1, a_2, \ldots, a_n$, modulo $998\,244\,353$.

## Example

## Input


```

64 10PSPP1 9 8 104 1000000000????1 1 1 40000000008 1000000000?P?SSP?P-857095623 -1424391899 -851974476 673437144 471253851 -543483033 364945701 -1785373324 7PPSS4 2 1 39 20?????????1 2 3 4 5 6 7 8 93 1000000000P??-145463248 -974068460 -1287458396
```
## Output


```

1
0
2
1
14
1

```
## Note

In the first test case, we can see that the following array satisfies all constraints, thus the answer is $1$: 

1. $\texttt{P}$ — ${[\color{red}{\textbf{1}},3,4,2]}$: sum of $1$.
2. $\texttt{S}$ — ${[1,\color{red}{\textbf{3},4,2}]}$: sum of $9$.
3. $\texttt{P}$ — ${[\color{red}{1,3,\textbf{4}},2]}$: sum of $8$.
4. $\texttt{P}$ — ${[\color{red}{1,3,4,\textbf{2}}]}$: sum of $10$.

In the second test case, it can be shown that no array $a$ with all $|a_i| \leq m = 10^9$ satisfies all constraints.



#### tags 

#2500 #brute_force #dp #math 