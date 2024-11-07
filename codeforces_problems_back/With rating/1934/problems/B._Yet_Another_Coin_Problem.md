<h1 style='text-align: center;'> B. Yet Another Coin Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $5$ different types of coins, each with a value equal to one of the first $5$ triangular numbers: $1$, $3$, $6$, $10$, and $15$. These coin types are available in abundance. Your goal is to find the minimum number of these coins required such that their total value sums up to exactly $n$.

We can show that the answer always exists.

## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^9$) — the target value.

## Output

For each test case, output a single number — the minimum number of coins required.

## Example

## Input


```

14123571112141617182098402931328
```
## Output


```

1
2
1
3
2
2
2
3
2
3
2
2
8
26862090

```
## Note

In the first test case, for $n = 1$, the answer is $1$ since only one $1$ value coin is sufficient. $1 = 1 \cdot 1$.

In the fourth test case, for $n = 5$, the answer is $3$, which can be achieved using two $1$ value coins and one $3$ value coin. $5 = 2 \cdot 1 + 1 \cdot 3$.

In the seventh test case, for $n = 12$, the answer is $2$, which can be achieved using two $6$ value coins.

In the ninth test case, for $n = 16$, the answer is $2$, which can be achieved using one $1$ value coin and one $15$ value coin or using one $10$ value coin and one $6$ value coin. $16 = 1 \cdot 1 + 1 \cdot 15 = 1 \cdot 6 + 1 \cdot 10$.



#### tags 

#1200 #brute_force #dp #greedy #math 