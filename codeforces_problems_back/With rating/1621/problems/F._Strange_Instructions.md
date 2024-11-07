<h1 style='text-align: center;'> F. Strange Instructions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dasha has $10^{100}$ coins. Recently, she found a binary string $s$ of length $n$ and some operations that allows to change this string (she can do each operation any number of times):

1. Replace substring 00 of $s$ by 0 and receive $a$ coins.
2. Replace substring 11 of $s$ by 1 and receive $b$ coins.
3. Remove 0 from any position in $s$ and pay $c$ coins.

It turned out that while doing this operations Dasha should follow the rule:

* It is forbidden to do two operations with the same parity in a row. Operations are numbered by integers $1$-$3$ in the order they are given above.

Please, calculate what is the maximum profit Dasha can get by doing these operations and following this rule.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains four integers $n$, $a$, $b$, $c$ ($1 \leq n \leq 10^5, 1 \leq a, b, c \leq 10^9$).

The second line of each test case contains a binary string $s$ of length $n$.

It is guaranteed that the total sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case print the answer.

## Example

## Input


```

35 2 2 1011016 4 3 51100016 3 2 1011110
```
## Output


```

3
11
4

```
## Note

In the first test case one of the optimal sequences of operations is 01101 $\rightarrow$ 0101 $\rightarrow$ 011 $\rightarrow$ 01. This sequence of operations consists of operations $2$, $3$ and $2$ in this order. It satisfies all rules and gives profit $3$. It can be shown that it is impossible to achieve higher profit in this test case, so the answer is $3$.

In the second test case one of the optimal sequences of operations is 110001 $\rightarrow$ 11001 $\rightarrow$ 1001 $\rightarrow$ 101.

In the third test case one of the optimal sequences of operations is 011110 $\rightarrow$ 01110 $\rightarrow$ 1110 $\rightarrow$ 110 $\rightarrow$ 11 $\rightarrow$ 1.



#### tags 

#2700 #data_structures #greedy #implementation 