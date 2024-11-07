<h1 style='text-align: center;'> H. Codeforces Scoreboard</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are participating in a Codeforces Round with $n$ problems. 

You spend exactly one minute to solve each problem, the time it takes to submit a problem can be ignored. You can only solve at most one problem at any time. The contest starts at time $0$, so you can make your first submission at any time $t \ge 1$ minutes. Whenever you submit a problem, it is always accepted.

The scoring of the $i$-th problem can be represented by three integers $k_i$, $b_i$, and $a_i$. If you solve it at time $t$ minutes, you get $\max(b_i - k_i \cdot t,a_i)$ points.

Your task is to choose an order to solve all these $n$ problems to get the maximum possible score. You can assume the contest is long enough to solve all problems.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. 

The first line of each test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of problems.

The $n$ lines follow, the $i$-th of them contains three integers $k_i$, $b_i$, $a_i$ ($1\le k_i,b_i,a_i\le 10^9$; $a_i < b_i$), denoting that you get the score of $\max(b_i - k_i \cdot t,a_i)$ if you solve the $i$-th task at time $t$ minutes.

It's guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a line containing a single integer — the maximum score you can get.

## Example

## Input


```

4410000 1000000000 200610000 1000000000 99992 999991010 10101000000000 1000000000 99999999961 8 19 29 42 14 34 13 12 19 510 12 584 10 14 19 81 14 34 15 62 9 61 11 102 19 124 19 14105 12 75 39 122 39 113 23 155 30 113 17 135 29 143 17 113 36 183 9 8
```
## Output


```

3999961003
53
78
180

```
## Note

In the second test case, the points for all problems at each minute are listed below.

 

| Time | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ |
| --- | --- | --- | --- | --- | --- | --- |
| Problem $1$ | $7$ | $6$ | $5$ | $\color{red}{4}$ | $3$ | $2$ |
| Problem $2$ | $\color{red}{20}$ | $11$ | $4$ | $4$ | $4$ | $4$ |
| Problem $3$ | $12$ | $10$ | $\color{red}{8}$ | $6$ | $4$ | $3$ |
| Problem $4$ | $9$ | $5$ | $1$ | $1$ | $\color{red}{1}$ | $1$ |
| Problem $5$ | $17$ | $\color{red}{15}$ | $13$ | $11$ | $9$ | $7$ |
| Problem $6$ | $5$ | $5$ | $5$ | $5$ | $5$ | $\color{red}{5}$ |

 The points displayed in red denote one of the optimal orders with the score $53$.



#### tags 

#3300 #binary_search #data_structures #dp #geometry 