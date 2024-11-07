<h1 style='text-align: center;'> D. GCD Queries </h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There is a secret permutation $p$ of $[0,1,2,\ldots,n-1]$. Your task is to find $2$ indices $x$ and $y$ ($1 \leq x, y \leq n$, possibly $x=y$) such that $p_x=0$ or $p_y=0$. In order to find it, you are allowed to ask at most $2n$ queries.

In one query, you give two integers $i$ and $j$ ($1 \leq i, j \leq n$, $i \neq j$) and receive the value of $\gcd(p_i,p_j)^\dagger$.

## Note

 that the permutation $p$ is fixed before any queries are made and does not depend on the queries.

$^\dagger$ $\gcd(x, y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$. ## Note

 that $\gcd(x,0)=\gcd(0,x)=x$ for all positive integers $x$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 2 \cdot 10^4$).

After reading the integer $n$ for each test case, you should begin the interaction.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^4$.

## Interaction

The interaction for each test case begins by reading the integer $n$.

To make a query, output "? $i$ $j$" ($1 \leq i, j \leq n$, $i \neq j$) without quotes. Afterwards, you should read a single integer — the answer to your query $\gcd(p_i,p_j)$. You can make at most $2n$ such queries in each test case.

If you want to print the answer, output "! $x$ $y$" ($1 \leq x, y \leq n$) without quotes. After doing that, read $1$ or $-1$. If $p_x=0$ or $p_y=0$, you'll receive $1$, otherwise you'll receive $-1$. If you receive $-1$, your program must terminate immediately to receive a Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

If you receive the integer $-1$ instead of an answer or a valid value of $n$, it means your program has made an invalid query, has exceeded the limit of queries, or has given an incorrect answer on the previous test case. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query or the answer, do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, use the following format.

The first line should contain a single integer $t$ ($1 \leq t \leq 10^4$).

The first line of each test case should contain a single integer $n$ ($2 \leq n \leq 2 \cdot 10^4$).

The second line of each test case should contain $n$ space separated integers $p_1,p_2,\ldots,p_n$. $p$ should be a permutation of $[0,1,2,\ldots,n-1]$.

The sum of $n$ should not exceed $2 \cdot 10^4$.

## Example

## Input


```

2
2

1

1
5

2

4

1

```
Output
```



? 1 2

! 1 2


? 1 2

? 2 3

! 3 3


```
## Note

In the first test, the interaction proceeds as follows.

 

| Solution | Jury | Explanation |
| --- | --- | --- |
|  | $\texttt{2}$ | There are 2 test cases. |
|  | $\texttt{2}$ | In the first test case, the hidden permutation is $[1,0]$, with length $2$. |
| $\texttt{? 1 2}$ | $\texttt{1}$ | The solution requests $\gcd(p_1,p_2)$, and the jury responds with $1$. |
| $\texttt{! 1 2}$ | $\texttt{1}$ | The solution knows that either $p_1=0$ or $p_2=0$, and prints the answer. Since the output is correct, the jury responds with $1$ and continues to the next test case. |
|  | $\texttt{5}$ | In the second test case, the hidden permutation is $[2,4,0,1,3]$, with length $5$. |
| $\texttt{? 1 2}$ | $\texttt{2}$ | The solution requests $\gcd(p_1,p_2)$, and the jury responds with $2$. |
| $\texttt{? 2 3}$ | $\texttt{4}$ | The solution requests $\gcd(p_2,p_3)$, and the jury responds with $4$. |
| $\texttt{! 3 3}$ | $\texttt{1}$ | The solution has somehow determined that $p_3=0$, and prints the answer. Since the output is correct, the jury responds with $1$. |

 ## Note

 that the empty lines in the example input and output are for the sake of clarity, and do not occur in the real interaction.

After each test case, make sure to read $1$ or $-1$.



#### tags 

#2100 #constructive_algorithms #interactive #number_theory 