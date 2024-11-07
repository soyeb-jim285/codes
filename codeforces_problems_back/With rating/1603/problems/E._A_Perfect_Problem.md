<h1 style='text-align: center;'> E. A Perfect Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of integers $b_1, b_2, \ldots, b_m$ is called good if $max(b_1, b_2, \ldots, b_m) \cdot min(b_1, b_2, \ldots, b_m) \ge b_1 + b_2 + \ldots + b_m$.

A sequence of integers $a_1, a_2, \ldots, a_n$ is called perfect if every non-empty subsequence of $a$ is good.

YouKn0wWho has two integers $n$ and $M$, $M$ is prime. Help him find the number, modulo $M$, of perfect sequences $a_1, a_2, \ldots, a_n$ such that $1 \le a_i \le n + 1$ for each integer $i$ from $1$ to $n$.

A sequence $d$ is a subsequence of a sequence $c$ if $d$ can be obtained from $c$ by deletion of several (possibly, zero or all) elements.

## Input

The first and only line of the input contains two space-separated integers $n$ and $M$ ($1 \le n \le 200$; $10^8 \le M \le 10^9$). It is guaranteed that $M$ is prime.

## Output

Print a single integer  — the number of perfect sequences modulo $M$.

## Examples

## Input


```

2 998244353

```
## Output


```

4

```
## Input


```

4 100000007

```
## Output


```

32

```
## Input


```

69 999999937

```
## Output


```

456886663

```
## Note

In the first test case, the perfect sequences are $[2, 2]$, $[2, 3]$, $[3, 2]$ and $[3, 3]$.

In the second test case, some of the perfect sequences are $[3, 4, 3, 5]$, $[4, 5, 4, 4]$, $[4, 5, 5, 5]$ etc. One example of a sequence which is not perfect is $[2, 3, 3, 4]$, because, for example, the subsequence $[2, 3, 4]$ is not an good as $2 \cdot 4 < 2 + 3 + 4$.



#### tags 

#3200 #combinatorics #dp #math 