<h1 style='text-align: center;'> B. Special Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Theofanis really likes sequences of positive integers, thus his teacher (Yeltsa Kcir) gave him a problem about a sequence that consists of only special numbers.

Let's call a positive number special if it can be written as a sum of different non-negative powers of $n$. For example, for $n = 4$ number $17$ is special, because it can be written as $4^0 + 4^2 = 1 + 16 = 17$, but $9$ is not.

Theofanis asks you to help him find the $k$-th special number if they are sorted in increasing order. Since this number may be too large, output it modulo $10^9+7$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first and only line of each test case contains two integers $n$ and $k$ ($2 \le n \le 10^9$; $1 \le k \le 10^9$).

## Output

For each test case, print one integer — the $k$-th special number in increasing order modulo $10^9+7$.

## Example

## Input


```

3
3 4
2 12
105 564

```
## Output


```

9
12
3595374

```
## Note

For $n = 3$ the sequence is $[1,3,4,9...]$



#### tags 

#1100 #bitmasks #math 