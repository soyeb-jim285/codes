<h1 style='text-align: center;'> A. Madoka and Strange Thoughts</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Madoka is a very strange girl, and therefore she suddenly wondered how many pairs of integers $(a, b)$ exist, where $1 \leq a, b \leq n$, for which $\frac{\operatorname{lcm}(a, b)}{\operatorname{gcd}(a, b)} \leq 3$.

In this problem, $\operatorname{gcd}(a, b)$ denotes [the greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor ) of the numbers $a$ and $b$, and $\operatorname{lcm}(a, b)$ denotes [the smallest common multiple](https://en.wikipedia.org/wiki/Least_common_multiple ) of the numbers $a$ and $b$.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first and the only line of each test case contains the integer $n$ ($1 \le n \le 10^8$).

## Output

For each test case output a single integer — the number of pairs of integers satisfying the condition.

## Example

## Input


```

612345100000000
```
## Output


```

1
4
7
10
11
266666666

```
## Note

For $n = 1$ there is exactly one pair of numbers — $(1, 1)$ and it fits.

For $n = 2$, there are only $4$ pairs — $(1, 1)$, $(1, 2)$, $(2, 1)$, $(2, 2)$ and they all fit.

For $n = 3$, all $9$ pair are suitable, except $(2, 3)$ and $(3, 2)$, since their $\operatorname{lcm}$ is $6$, and $\operatorname{gcd}$ is $1$, which doesn't fit the condition.



#### tags 

#800 #math #number_theory 