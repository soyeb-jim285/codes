<h1 style='text-align: center;'> G. Magic Square</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Aquamoon has a Rubik's Square which can be seen as an $n \times n$ matrix, the elements of the matrix constitute a permutation of numbers $1, \ldots, n^2$.

Aquamoon can perform two operations on the matrix:

* Row shift, i.e. shift an entire row of the matrix several positions (at least $1$ and at most $n-1$) to the right. The elements that come out of the right border of the matrix are moved to the beginning of the row. For example, shifting a row $\begin{pmatrix} a & b & c \end{pmatrix}$ by $2$ positions would result in $\begin{pmatrix} b & c & a \end{pmatrix}$;
* Column shift, i.e. shift an entire column of the matrix several positions (at least $1$ and at most $n-1$) downwards. The elements that come out of the lower border of the matrix are moved to the beginning of the column. For example, shifting a column $\begin{pmatrix} a \\\ b \\\ c \end{pmatrix}$ by $2$ positions would result in $\begin{pmatrix} b\\\c\\\a \end{pmatrix}$.

The rows are numbered from $1$ to $n$ from top to bottom, the columns are numbered from $1$ to $n$ from left to right. The cell at the intersection of the $x$-th row and the $y$-th column is denoted as $(x, y)$.

Aquamoon can perform several (possibly, zero) operations, but she has to obey the following restrictions:

* each row and each column can be shifted at most once;
* each integer of the matrix can be moved at most twice;
* the offsets of any two integers moved twice cannot be the same. Formally, if integers $a$ and $b$ have been moved twice, assuming $a$ has changed its position from $(x_1,y_1)$ to $(x_2,y_2)$, and $b$ has changed its position from $(x_3,y_3)$ to $(x_4,y_4)$, then $x_2-x_1 \not\equiv x_4-x_3 \pmod{n}$ or $y_2-y_1 \not\equiv y_4-y_3 \pmod{n}$.

Aquamoon wonders in how many ways she can transform the Rubik's Square from the given initial state to a given target state. Two ways are considered different if the sequences of applied operations are different. Since the answer can be very large, print the result modulo $998\,244\,353$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2\cdot 10^4$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($3\le n \le 500$).

The $i$-th of the following $n$ lines contains $n$ integers $a_{i1}, \ldots, a_{in}$, representing the $i$-th row of the initial matrix ($1 \le a_{ij} \le n^2$).

The $i$-th of the following $n$ lines contains $n$ integers $b_{i1}, \ldots, b_{in}$, representing the $i$-th row of the target matrix ($1 \le b_{ij} \le n^2$).

It is guaranteed that both the elements of the initial matrix and the elements of the target matrix constitute a permutation of numbers $1, \ldots, n^2$.

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $250\,000$.

## Output

For each test case, if it is possible to convert the initial state to the target state respecting all the restrictions, output one integer — the number of ways to do so, modulo $998\,244\,353$.

If there is no solution, print a single integer $0$.

## Example

## Input


```

431 2 34 5 67 8 97 2 31 4 56 8 931 2 34 5 67 8 93 2 16 5 49 7 831 2 34 5 67 8 97 8 12 3 45 6 931 2 34 5 67 8 93 8 45 1 97 6 2
```
## Output


```

1
0
0
4

```
## Note

In the first test case, the only way to transform the initial matrix to the target one is to shift the second row by $1$ position to the right, and then shift the first column by $1$ position downwards.

In the second test case, it can be shown that there is no correct way to transform the matrix, thus, the answer is $0$.



#### tags 

#3100 #combinatorics #constructive_algorithms #implementation 