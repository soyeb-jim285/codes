<h1 style='text-align: center;'> D. K-good</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We say that a positive integer $n$ is $k$-good for some positive integer $k$ if $n$ can be expressed as a sum of $k$ positive integers which give $k$ distinct remainders when divided by $k$.

Given a positive integer $n$, find some $k \geq 2$ so that $n$ is $k$-good or tell that such a $k$ does not exist.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

Each test case consists of one line with an integer $n$ ($2 \leq n \leq 10^{18}$).

## Output

For each test case, print a line with a value of $k$ such that $n$ is $k$-good ($k \geq 2$), or $-1$ if $n$ is not $k$-good for any $k$. If there are multiple valid values of $k$, you can print any of them.

## Example

## Input


```

5
2
4
6
15
20

```
## Output


```

-1
-1
3
3
5

```
## Note

$6$ is a $3$-good number since it can be expressed as a sum of $3$ numbers which give different remainders when divided by $3$: $6 = 1 + 2 + 3$.

$15$ is also a $3$-good number since $15 = 1 + 5 + 9$ and $1, 5, 9$ give different remainders when divided by $3$.

$20$ is a $5$-good number since $20 = 2 + 3 + 4 + 5 + 6$ and $2,3,4,5,6$ give different remainders when divided by $5$.



#### tags 

#1900 #constructive_algorithms #math #number_theory 