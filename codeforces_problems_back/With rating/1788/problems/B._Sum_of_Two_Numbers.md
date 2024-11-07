<h1 style='text-align: center;'> B. Sum of Two Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The sum of digits of a non-negative integer $a$ is the result of summing up its digits together when written in the decimal system. For example, the sum of digits of $123$ is $6$ and the sum of digits of $10$ is $1$. In a formal way, the sum of digits of $\displaystyle a=\sum_{i=0}^{\infty} a_i \cdot 10^i$, where $0 \leq a_i \leq 9$, is defined as $\displaystyle\sum_{i=0}^{\infty}{a_i}$.

Given an integer $n$, find two non-negative integers $x$ and $y$ which satisfy the following conditions.

* $x+y=n$, and
* the sum of digits of $x$ and the sum of digits of $y$ differ by at most $1$.

It can be shown that such $x$ and $y$ always exist.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). 

Each test case consists of a single integer $n$ ($1 \leq n \leq 10^9$)

## Output

For each test case, print two integers $x$ and $y$.

If there are multiple answers, print any.

## Example

## Input


```

5
1
161
67
1206
19

```
## Output


```

1 0
67 94
60 7
1138 68
14 5
```
## Note

In the second test case, the sum of digits of $67$ and the sum of digits of $94$ are both $13$.

In the third test case, the sum of digits of $60$ is $6$, and the sum of digits of $7$ is $7$.



#### tags 

#1100 #constructive_algorithms #greedy #implementation #math #probabilities 