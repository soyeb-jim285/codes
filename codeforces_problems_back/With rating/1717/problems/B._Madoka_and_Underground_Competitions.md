<h1 style='text-align: center;'> B. Madoka and Underground Competitions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Madoka decided to participate in an underground sports programming competition. And there was exactly one task in it:

A square table of size $n \times n$, where $n$ is a multiple of $k$, is called good if only the characters '.' and 'X' are written in it, as well as in any subtable of size $1 \times k$ or $k \times 1$, there is at least one character 'X'. In other words, among any $k$ consecutive vertical or horizontal cells, there must be at least one containing the character 'X'.

## Output

 any good table that has the minimum possible number of characters 'X', and also the symbol 'X' is written in the cell $(r, c)$. Rows are numbered from $1$ to $n$ from top to bottom, columns are numbered from $1$ to $n$ from left to right.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Description of the test cases follows.

The first and the only line of each test case contains four integers $n$, $k$, $r$, $c$ ($1 \le n \le 500, 1 \le k \le n, 1 \le r, c \le n$) — the size of the table, the integer $k$ and the coordinates of the cell, which must contain the character 'X'. It is guaranteed that $n$ is a multiple of $k$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $500$.

## Output

For each test case, output $n$ lines, each consisting of $n$ characters '.' and 'X', — the desired table. If there are several answers, then you can output anyone.

## Example

## Input


```

33 3 3 22 1 1 26 3 4 2
```
## Output


```

X..
..X
.X.
XX
XX
.X..X.
X..X..
..X..X
.X..X.
X..X..
..X..X

```
## Note

Let's analyze the first test case.

The following tables can be printed as the correct answer:

 

| X.. |
| --- |
| ..X |
| .X. |

 or 

| ..X |
| --- |
| X.. |
| .X. |

  It can be proved that there cannot be less than $3$ characters 'X' in the answer.## Note

 that the following table is invalid because cell $(3, 2)$ does not contain the character 'X': 

 

| X.. |
| --- |
| .X. |
| ..X |

 In the second test case, the only correct table is: 

 

| XX |
| --- |
| XX |

  Each subtable of size $1 \times 1$ must contain a 'X' character, so all characters in the table must be equal to 'X'.

#### tags 

#1100 #constructive_algorithms #implementation 