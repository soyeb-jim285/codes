<h1 style='text-align: center;'> D. Product of Binary Decimals</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a number a binary decimal if it is a positive integer and all digits in its decimal notation are either $0$ or $1$. For example, $1\,010\,111$ is a binary decimal, while $10\,201$ and $787\,788$ are not.

Given a number $n$, you are asked whether or not it is possible to represent $n$ as a product of some (not necessarily distinct) binary decimals.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 5 \cdot 10^4$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$).

## Output

For each test case, output "YES" (without quotes) if $n$ can be represented as a product of binary decimals, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will be recognized as a positive response).

## Example

## Input


```

111211146411222110110100000991122024124211001
```
## Output


```

YES
YES
YES
YES
YES
YES
NO
NO
NO
NO
YES

```
## Note

The first five test cases can be represented as a product of binary decimals as follows: 

* $121 = 11 \times 11$.
* $1 = 1$ is already a binary decimal.
* $14\,641 = 11 \times 11 \times 11 \times 11$.
* $12\,221 = 11 \times 11 \times 101$.
* $10\,110 = 10\,110$ is already a binary decimal.


#### tags 

#1100 #brute_force #dp #implementation #number_theory 