<h1 style='text-align: center;'> D. Umka and a Long Flight</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The girl Umka loves to travel and participate in math olympiads. One day she was flying by plane to the next olympiad and out of boredom explored a huge checkered sheet of paper.

Denote the $n$-th Fibonacci number as $F_n = \begin{cases} 1, & n = 0; \\\ 1, & n = 1; \\\ F_{n-2} + F_{n-1}, & n \ge 2. \end{cases}$

A checkered rectangle with a height of $F_n$ and a width of $F_{n+1}$ is called a Fibonacci rectangle of order $n$.

Umka has a Fibonacci rectangle of order $n$. Someone colored a cell in it at the intersection of the row $x$ and the column $y$.

It is necessary to cut this rectangle exactly into $n+1$ squares in such way that

* the painted cell was in a square with a side of $1$;
* there was at most one pair of squares with equal sides;
* the side of each square was equal to a Fibonacci number.

Will Umka be able to cut this rectangle in that way?

## Input

The first line contains an integer $t$ ($1 \le t \le 2 \cdot 10^5$) — number of test cases.

For each test case the integers $n$, $x$, $y$ are given ($1 \le n \le 44$, $1 \le x \le F_n$, $1 \le y \le F_{n+1}$) — the order of the Fibonacci rectangle and the coordinates of the colored cell.

## Output

For each test case, print "YES" if the answer is positive, and "NO" otherwise.

You can print "YES" and "NO" in any case (for example, the strings "yEs", "yes" and "Yes" will be recognized as a positive answer).

## Example

## Input


```

121 1 12 1 23 1 43 3 24 4 64 3 35 6 55 4 125 2 124 2 11 1 244 758465880 1277583853
```
## Output


```

YES
NO
YES
YES
YES
NO
YES
NO
NO
YES
YES
NO

```
## Note

 

|  |  |  |
| --- | --- | --- |

 The first, third and fourth test cases. 

#### tags 

#1600 #constructive_algorithms #implementation #math 