<h1 style='text-align: center;'> B. Make AP</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has $3$ positive integers $a$, $b$ and $c$. He can perform the following operation exactly once.

* Choose a positive integer $m$ and multiply exactly one of the integers $a$, $b$ or $c$ by $m$.

Can Polycarp make it so that after performing the operation, the sequence of three numbers $a$, $b$, $c$ (in this order) forms an [arithmetic progression](https://en.wikipedia.org/wiki/Arithmetic_progression)? ## Note

 that you cannot change the order of $a$, $b$ and $c$.

Formally, a sequence $x_1, x_2, \dots, x_n$ is called an arithmetic progression (AP) if there exists a number $d$ (called "common difference") such that $x_{i+1}=x_i+d$ for all $i$ from $1$ to $n-1$. In this problem, $n=3$.

For example, the following sequences are AP: $[5, 10, 15]$, $[3, 2, 1]$, $[1, 1, 1]$, and $[13, 10, 7]$. The following sequences are not AP: $[1, 2, 4]$, $[0, 1, 0]$ and $[1, 3, 2]$.

You need to answer $t$ independent test cases.

## Input

The first line contains the number $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each of the following $t$ lines contains $3$ integers $a$, $b$, $c$ ($1 \le a, b, c \le 10^8$).

## Output

For each test case print "YES" (without quotes) if Polycarp can choose a positive integer $m$ and multiply exactly one of the integers $a$, $b$ or $c$ by $m$ to make $[a, b, c]$ be an arithmetic progression. Print "NO" (without quotes) otherwise.

You can print YES and NO in any (upper or lower) case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer).

## Example

## Input


```

1110 5 3030 5 101 2 31 6 32 6 31 1 11 1 21 1 31 100000000 12 1 11 2 2
```
## Output


```

YES
YES
YES
YES
NO
YES
NO
YES
YES
NO
YES

```
## Note

In the first and second test cases, you can choose the number $m=4$ and multiply the second number ($b=5$) by $4$.

In the first test case the resulting sequence will be $[10, 20, 30]$. This is an AP with a difference $d=10$.

In the second test case the resulting sequence will be $[30, 20, 10]$. This is an AP with a difference $d=-10$.

In the third test case, you can choose $m=1$ and multiply any number by $1$. The resulting sequence will be $[1, 2, 3]$. This is an AP with a difference $d=1$.

In the fourth test case, you can choose $m=9$ and multiply the first number ($a=1$) by $9$. The resulting sequence will be $[9, 6, 3]$. This is an AP with a difference $d=-3$.

In the fifth test case, it is impossible to make an AP.



#### tags 

#900 #implementation #math 