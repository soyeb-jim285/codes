<h1 style='text-align: center;'> A. Ntarsis' Set</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ntarsis has been given a set $S$, initially containing integers $1, 2, 3, \ldots, 10^{1000}$ in sorted order. Every day, he will remove the $a_1$-th, $a_2$-th, $\ldots$, $a_n$-th smallest numbers in $S$ simultaneously.

What is the smallest element in $S$ after $k$ days?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case consists of two integers $n$ and $k$ ($1 \leq n,k \leq 2 \cdot 10^5$) — the length of $a$ and the number of days.

The following line of each test case consists of $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the elements of array $a$.

It is guaranteed that: 

* The sum of $n$ over all test cases won't exceed $2 \cdot 10^5$;
* The sum of $k$ over all test cases won't exceed $2 \cdot 10^5$;
* $a_1 < a_2 < \cdots < a_n$ for all test cases.
## Output

For each test case, print an integer that is the smallest element in $S$ after $k$ days.

## Example

## Input


```

75 11 2 4 5 65 31 3 5 6 74 10002 3 4 59 14341 4 7 9 12 15 17 18 2010 41 3 5 7 9 11 13 15 17 1910 61 4 7 10 13 16 19 22 25 2810 1500001 3 4 5 10 11 12 13 14 15
```
## Output


```

3
9
1
12874
16
18
1499986

```
## Note

For the first test case, each day the $1$-st, $2$-nd, $4$-th, $5$-th, and $6$-th smallest elements need to be removed from $S$. So after the first day, $S$ will become $\require{cancel}$ $\{\cancel 1, \cancel 2, 3, \cancel 4, \cancel 5, \cancel 6, 7, 8, 9, \ldots\} = \{3, 7, 8, 9, \ldots\}$. The smallest element is $3$.

For the second case, each day the $1$-st, $3$-rd, $5$-th, $6$-th and $7$-th smallest elements need to be removed from $S$. $S$ will be changed as follows:

 

| Day | $S$ before |  | $S$ after |
| --- | --- | --- | --- |
| 1 | $\{\cancel 1, 2, \cancel 3, 4, \cancel 5, \cancel 6, \cancel 7, 8, 9, 10, \ldots \}$ | $\to$ | $\{2, 4, 8, 9, 10, \ldots\}$ |
| 2 | $\{\cancel 2, 4, \cancel 8, 9, \cancel{10}, \cancel{11}, \cancel{12}, 13, 14, 15, \ldots\}$ | $\to$ | $\{4, 9, 13, 14, 15, \ldots\}$ |
| 3 | $\{\cancel 4, 9, \cancel{13}, 14, \cancel{15}, \cancel{16}, \cancel{17}, 18, 19, 20, \ldots\}$ | $\to$ | $\{9, 14, 18, 19, 20, \ldots\}$ |

 The smallest element left after $k = 3$ days is $9$.



#### tags 

#1800 #binary_search #math #number_theory 