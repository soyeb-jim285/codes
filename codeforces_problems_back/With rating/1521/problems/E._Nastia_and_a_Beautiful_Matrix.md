<h1 style='text-align: center;'> E. Nastia and a Beautiful Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You like numbers, don't you? Nastia has a lot of numbers and she wants to share them with you! Isn't it amazing?

Let $a_i$ be how many numbers $i$ ($1 \le i \le k$) you have.

An $n \times n$ matrix is called beautiful if it contains all the numbers you have, and for each $2 \times 2$ submatrix of the original matrix is satisfied: 

1. The number of occupied cells doesn't exceed $3$;
2. The numbers on each diagonal are distinct.

Make a beautiful matrix of minimum size.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$) — the number of test cases.

The first line of each test case contains $2$ integers $m$ and $k$ ($1 \le m, k \le 10^5$) — how many numbers Nastia gave you and the length of the array $a$, respectively.

The second line of each test case contains $k$ integers $a_1, a_2, \ldots, a_{k}$ ($0 \le a_i \le m$, $a_1 + a_2 + \ldots + a_{k} = m$), where $a_i$ is how many numbers $i$ you have.

It's guaranteed that the sum of $m$ and $k$ in one test doesn't exceed $2 \cdot 10^5$.

## Output

For each $t$ test case print a single integer $n$ — the size of the beautiful matrix.

In the next $n$ lines print $n$ integers $b_{i, j}$ ($0 \le b_{i, j} \le k$; if position is empty, print $b_{i, j} = 0$) — the beautiful matrix $b$ you made up. 

## Example

## Input


```

2
3 4
2 0 0 1
15 4
2 4 8 1

```
## Output


```

2
4 1
0 1
5
3 0 0 2 2
3 2 3 3 0
0 1 0 4 0
3 0 0 0 0
2 1 3 3 3
```
## Note

## Note

 that $0$ in this problem represents a blank, not a number.

## Example

s of possible answers for the first test case:

$\begin{array}{cc} 1 & 1 \\\ 4 & 0 \\\ \end{array} \hspace{0,5cm} \begin{array}{cc} 1 & 4 \\\ 1 & 0 \\\ \end{array} \hspace{0,5cm} \begin{array}{cc} 4 & 0 \\\ 1 & 1 \\\ \end{array}$

## Example

s of not beautiful matrices for the first test case:

$\begin{array}{cc} 1 & 0 \\\ 4 & 1 \\\ \end{array} \hspace{0,5cm} \begin{array}{cc} 4 & 1 \\\ 7 & 1 \\\ \end{array} \hspace{0,5cm} \begin{array}{cc} 1 & 0 \\\ 4 & 0 \\\ \end{array}$

The example of the not beautiful matrix for the second test case:

$\begin{array}{cc} 3 & 4 & 0 & 2 & 2 \\\ 3 & 2 & 3 & 3 & 0 \\\ 0 & 1 & 0 & 0 & 0 \\\ 3 & 0 & 0 & 0 & 0 \\\ 2 & 1 & 3 & 3 & 3 \\\ \end{array}$

Everything is okay, except the left-top submatrix contains $4$ numbers.



#### tags 

#2700 #binary_search #constructive_algorithms #dp #greedy 