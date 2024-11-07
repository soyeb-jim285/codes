<h1 style='text-align: center;'> H. Fumo Temple</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This temple only magnifies the mountain's power.BadelineThis is an interactive problem.

You are given two positive integers $n$ and $m$ ($\bf{n \le m}$).

The jury has hidden from you a rectangular matrix $a$ with $n$ rows and $m$ columns, where $a_{i,j} \in \{ -1, 0, 1 \}$ for all $1 \le i \le n$ and $1 \le j \le m$. The jury has also selected a cell $(i_0, j_0)$. Your goal is to find $(i_0,j_0)$.

In one query, you give a cell $(i, j)$, then the jury will reply with an integer. 

* If $(i, j) = (i_0, j_0)$, the jury will reply with $0$.
* Else, let $S$ be the sum of $a_{x,y}$ over all $x$ and $y$ such that $\min(i, i_0) \le x \le \max(i, i_0)$ and $\min(j, j_0) \le y \le \max(j, j_0)$. Then, the jury will reply with $|i - i_0| + |j - j_0| + |S|$.

Find $(i_0, j_0)$ by making at most $n + 225$ queries.

## Note

: the grader is not adaptive: $a$ and $(i_0,j_0)$ are fixed before any queries are made.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 50$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $m$ ($1 \le n \le m \le 5000$) — the numbers of rows and the number of columns of the hidden matrix $a$ respectively.

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $25 \cdot 10^6$.

## Interaction

The interaction for each test case begins by reading the integers $n$ and $m$.

To make a query, output "? i j" ($1 \le i \le n, 1 \le j \le m$) without quotes. Afterwards, you should read one single integer — the answer to your query.

If you receive the integer $-1$ instead of an answer or a valid value of $n$ or $m$, it means your program has made an invalid query, has exceeded the limit of queries, or has given an incorrect answer on the previous test case. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

When you are ready to give the final answer, output "! i j" ($1 \le i \le n, 1 \le j \le m$) without quotes — the indices of the hidden cell. After solving a test case, your program should move to the next one immediately. After solving all test cases, your program should be terminated immediately.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, use the following format:

The first line contains an integer $t$ ($1 \le t \le 50$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le m \le 5000$) — the sizes of the hidden matrix.

The second line of each test case contains two integers $i_0$ and $j_0$ ($1 \le i_0 \le n, 1 \le j_0 \le m$) — the hidden cell.

Then $n$ lines follow. The $i$-th of them contains the string $s_i$ of length $n$, consisting only of the characters -, 0, and +. Here, $a_{ij} = -1$ if $s_{ij} = \mathtt{-}$, $a_{ij} = 0$ if $s_{ij} = \mathtt{0}$, and $a_{ij} = 1$ if $s_{ij} = \mathtt{+}$.

The sum of $n \cdot m$ over all test cases should not exceed $25 \cdot 10^6$.

As an example, the hack format for the example input is:

$\texttt{2}\\\ \texttt{3}\,\texttt{4} \\\ \texttt{1}\,\texttt{4} \\\ \texttt{+0+0} \\\ \texttt{+00+} \\\ \texttt{0---} \\\ \texttt{1}\,\texttt{1}\\\\\texttt{1}\,\texttt{1}\\\\\texttt{0}$

## Example

## Input


```

2
3 4

5

3

5

1 1

0


```
Output
```



? 1 1

? 3 3

? 3 2

! 1 4

? 1 1

! 1 1

```
## Note

The hidden matrix in the first test case: 

| $1$ | $0$ | $1$ | $\color{red}{\textbf{0}}$ |
| --- | --- | --- | --- |
| $1$ | $0$ | $0$ | $1$ |
| $0$ | $-1$ | $-1$ | $-1$ |



The hidden matrix in the second test case: 

| $\color{red}{\textbf{0}}$ |
| --- |



## Note

 that the line breaks in the example input and output are for the sake of clarity, and do not occur in the real interaction.



#### tags 

#3500 #interactive 