<h1 style='text-align: center;'> E. Divisors and Table</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an $n \times n$ multiplication table and a positive integer $m = m_1 \cdot m_2$. A $n \times n$ multiplication table is a table with $n$ rows and $n$ columns numbered from $1$ to $n$, where $a_{i, j} = i \cdot j$.

For each divisor $d$ of $m$, check: does $d$ occur in the table at least once, and if it does, what is the minimum row that contains $d$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10$) — the number of test cases.

The first and only line of each test case contains three integers $n$, $m_1$ and $m_2$ ($1 \le n \le 10^9$; $1 \le m_1, m_2 \le 10^9$) — the size of the multiplication table and the integer $m$ represented as $m_1 \cdot m_2$.

## Output

For each test case, let $d_1, d_2, \dots, d_k$ be all divisors of $m$ sorted in the increasing order. And let $a_1, a_2, \dots, a_k$ be an array of answers, where $a_i$ is equal to the minimum row index where divisor $d_i$ occurs, or $0$, if there is no such row.

Since array $a$ may be large, first, print an integer $s$ — the number of divisors of $m$ that are present in the $n \times n$ table. Next, print a single value $X = a_1 \oplus a_2 \oplus \dots \oplus a_k$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

## Example

## Input


```

33 72 110 10 156 1 210
```
## Output


```

6 2
10 0
8 5

```
## Note

In the first test case, $m = 72 \cdot 1 = 72$ and has $12$ divisors $[1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 36, 72]$. The $3 \times 3$ multiplication table looks like that:

  

|  | 1 | 2 | 3 |
| --- | --- | --- | --- |
| 1 | 1 | 2 | 3 |
| 2 | 2 | 4 | 6 |
| 3 | 3 | 6 | 9 |

  For each divisor of $m$ that is present in the table, the position with minimum row index is marked. So the array of answers $a$ is equal to $[1, 1, 1, 2, 2, 0, 3, 0, 0, 0, 0, 0]$. There are only $6$ non-zero values, and xor of $a$ is equal to $2$.

In the second test case, $m = 10 \cdot 15 = 150$ and has $12$ divisors $[1, 2, 3, 5, 6, 10, 15, 25, 30, 50, 75, 150]$. All divisors except $75$ and $150$ are present in the $10 \times 10$ table. Array $a$ $=$ $[1, 1, 1, 1, 1, 1, 3, 5, 3, 5, 0, 0]$. There are $10$ non-zero values, and xor of $a$ is equal to $0$.

In the third test case, $m = 1 \cdot 210 = 210$ and has $16$ divisors $[1, 2, 3, 5, 6, 7, 10, 14, 15, 21, 30, 35, 42, 70, 105, 210]$. The $6 \times 6$ table with marked divisors is shown below:

  

|  | 1 | 2 | 3 | 4 | 5 | 6 |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 2 | 3 | 4 | 5 | 6 |
| 2 | 2 | 4 | 6 | 8 | 10 | 12 |
| 3 | 3 | 6 | 9 | 12 | 15 | 18 |
| 4 | 4 | 8 | 12 | 16 | 20 | 24 |
| 5 | 5 | 10 | 15 | 20 | 25 | 30 |
| 6 | 6 | 12 | 18 | 24 | 30 | 36 |

  Array $a$ $=$ $[1, 1, 1, 1, 1, 0, 2, 0, 3, 0, 5, 0, 0, 0, 0, 0]$. There are $8$ non-zero values, and xor of $a$ is equal to $5$.



#### tags 

#2400 #brute_force #dfs_and_similar #dp #number_theory 