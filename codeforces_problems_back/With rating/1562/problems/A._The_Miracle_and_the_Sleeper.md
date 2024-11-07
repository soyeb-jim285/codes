<h1 style='text-align: center;'> A. The Miracle and the Sleeper</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $l$ and $r$, $l\le r$. Find the largest possible value of $a \bmod b$ over all pairs $(a, b)$ of integers for which $r\ge a \ge b \ge l$.

As a reminder, $a \bmod b$ is a remainder we get when dividing $a$ by $b$. For example, $26 \bmod 8 = 2$.

## Input

Each test contains multiple test cases.

The first line contains one positive integer $t$ $(1\le t\le 10^4)$, denoting the number of test cases. Description of the test cases follows.

The only line of each test case contains two integers $l$, $r$ ($1\le l \le r \le 10^9$).

## Output

For every test case, output the largest possible value of $a \bmod b$ over all pairs $(a, b)$ of integers for which $r\ge a \ge b \ge l$.

## Example

## Input


```

4
1 1
999999999 1000000000
8 26
1 999999999

```
## Output


```

0
1
12
499999999

```
## Note

In the first test case, the only allowed pair is $(a, b) = (1, 1)$, for which $a \bmod b = 1 \bmod 1 = 0$.

In the second test case, the optimal choice is pair $(a, b) = (1000000000, 999999999)$, for which $a \bmod b = 1$.



#### tags 

#800 #greedy #math 