<h1 style='text-align: center;'> D. Many Perfect Squares</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a set $a_1, a_2, \ldots, a_n$ of distinct positive integers.

We define the squareness of an integer $x$ as the number of perfect squares among the numbers $a_1 + x, a_2 + x, \ldots, a_n + x$.

Find the maximum squareness among all integers $x$ between $0$ and $10^{18}$, inclusive.

Perfect squares are integers of the form $t^2$, where $t$ is a non-negative integer. The smallest perfect squares are $0, 1, 4, 9, 16, \ldots$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 50$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the size of the set.

The second line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ in increasing order ($1 \le a_1 < a_2 < \ldots < a_n \le 10^9$) — the set itself.

It is guaranteed that the sum of $n$ over all test cases does not exceed $50$.

## Output

For each test case, print a single integer — the largest possible number of perfect squares among $a_1 + x, a_2 + x, \ldots, a_n + x$, for some $0 \le x \le 10^{18}$.

## Example

## Input


```

451 2 3 4 551 6 13 22 97110052 5 10 17 26
```
## Output


```

2
5
1
2

```
## Note

In the first test case, for $x = 0$ the set contains two perfect squares: $1$ and $4$. It is impossible to obtain more than two perfect squares.

In the second test case, for $x = 3$ the set looks like $4, 9, 16, 25, 100$, that is, all its elements are perfect squares.



#### tags 

#1800 #brute_force #math #number_theory 