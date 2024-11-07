<h1 style='text-align: center;'> E. Nearly Shortest Repeating Substring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$ consisting of lowercase Latin characters. Find the length of the shortest string $k$ such that several (possibly one) copies of $k$ can be concatenated together to form a string with the same length as $s$ and, at most, one different character.

More formally, find the length of the shortest string $k$ such that $c = \underbrace{k + \cdots + k}_{x\rm\ \text{times}}$ for some positive integer $x$, strings $s$ and $c$ has the same length and $c_i \neq s_i$ for at most one $i$ (i.e. there exist $0$ or $1$ such positions).

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the length of string $s$.

The second line of each test case contains the string $s$, consisting of lowercase Latin characters.

The sum of $n$ over all test cases does not exceed $2\cdot10^5$.

## Output

For each test case, print the length of the shortest string $k$ satisfying the constraints in the statement.

## Example

## Input


```

54abaa4abba13slavicgslavic8hshahaha20stormflamestornflame
```
## Output


```

1
4
13
2
10

```
## Note

In the first test case, you can select $k = \texttt{a}$ and $k+k+k+k = \texttt{aaaa}$, which only differs from $s$ in the second position.

In the second test case, you cannot select $k$ of length one or two. We can have $k = \texttt{abba}$, which is equal to $s$.



#### tags 

#1500 #brute_force #implementation #number_theory #strings 