<h1 style='text-align: center;'> B. Not Quite Latin Square</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A Latin square is a $3 \times 3$ grid made up of the letters $\texttt{A}$, $\texttt{B}$, and $\texttt{C}$ such that: 

* in each row, the letters $\texttt{A}$, $\texttt{B}$, and $\texttt{C}$ each appear once, and
* in each column, the letters $\texttt{A}$, $\texttt{B}$, and $\texttt{C}$ each appear once.

 For example, one possible Latin square is shown below. $$\begin{bmatrix} \texttt{A} & \texttt{B} & \texttt{C} \\\ \texttt{C} & \texttt{A} & \texttt{B} \\\ \texttt{B} & \texttt{C} & \texttt{A} \\\ \end{bmatrix}$$You are given a Latin square, but one of the letters was replaced with a question mark $\texttt{?}$. Find the letter that was replaced.

## Input

The first line of the input contains a single integer $t$ ($1 \leq t \leq 108$) — the number of testcases.

Each test case contains three lines, each consisting of three characters, representing the Latin square. Each character is one of $\texttt{A}$, $\texttt{B}$, $\texttt{C}$, or $\texttt{?}$.

Each test case is a Latin square with exactly one of the letters replaced with a question mark $\texttt{?}$.

## Output

For each test case, output the letter that was replaced.

## Example

## Input


```

3ABCC?BBCABCACA?ABC?ABBCAABC
```
## Output


```

A
B
C

```
## Note

The correct Latin squares for the three test cases are shown below:

$$\begin{bmatrix} \texttt{A} & \texttt{B} & \texttt{C} \\\ \texttt{C} & \color{red}{\texttt{A}} & \texttt{B} \\\ \texttt{B} & \texttt{C} & \texttt{A} \\\ \end{bmatrix} \quad \begin{bmatrix} \texttt{B} & \texttt{C} & \texttt{A} \\\ \texttt{C} & \texttt{A} & \color{red}{\texttt{B}} \\\ \texttt{A} & \texttt{B} & \texttt{C} \\\ \end{bmatrix} \quad \begin{bmatrix} \color{red}{\texttt{C}} & \texttt{A} & \texttt{B} \\\ \texttt{B} & \texttt{C} & \texttt{A} \\\ \texttt{A} & \texttt{B} & \texttt{C} \\\ \end{bmatrix}$$



#### tags 

#800 #bitmasks #brute_force #implementation 