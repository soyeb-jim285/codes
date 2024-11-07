<h1 style='text-align: center;'> F. Two Sorts</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Integers from $1$ to $n$ (inclusive) were sorted lexicographically (considering integers as strings). As a result, array $a_1, a_2, \dots, a_n$ was obtained.

Calculate value of $(\sum_{i = 1}^n ((i - a_i) \mod 998244353)) \mod 10^9 + 7$.

$x \mod y$ here means the remainder after division $x$ by $y$. This remainder is always non-negative and doesn't exceed $y - 1$. For example, $5 \mod 3 = 2$, $(-1) \mod 6 = 5$. 

## Input

The first line contains the single integer $n$ ($1 \leq n \leq 10^{12}$).

## Output

Print one integer — the required sum.

## Examples

## Input


```

3

```
## Output


```

0

```
## Input


```

12

```
## Output


```

994733045

```
## Input


```

21

```
## Output


```

978932159

```
## Input


```

1000000000000

```
## Output


```

289817887

```
## Note

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds:

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

For example, $42$ is lexicographically smaller than $6$, because they differ in the first digit, and $4 < 6$; $42 < 420$, because $42$ is a prefix of $420$.

Let's denote $998244353$ as $M$.

In the first example, array $a$ is equal to $[1, 2, 3]$. 

* $(1 - 1) \mod M = 0 \mod M = 0$
* $(2 - 2) \mod M = 0 \mod M = 0$
* $(3 - 3) \mod M = 0 \mod M = 0$

As a result, $(0 + 0 + 0) \mod 10^9 + 7 = 0$

In the second example, array $a$ is equal to $[1, 10, 11, 12, 2, 3, 4, 5, 6, 7, 8, 9]$. 

* $(1 - 1) \mod M = 0 \mod M = 0$
* $(2 - 10) \mod M = (-8) \mod M = 998244345$
* $(3 - 11) \mod M = (-8) \mod M = 998244345$
* $(4 - 12) \mod M = (-8) \mod M = 998244345$
* $(5 - 2) \mod M = 3 \mod M = 3$
* $(6 - 3) \mod M = 3 \mod M = 3$
* $(7 - 4) \mod M = 3 \mod M = 3$
* $(8 - 5) \mod M = 3 \mod M = 3$
* $(9 - 6) \mod M = 3 \mod M = 3$
* $(10 - 7) \mod M = 3 \mod M = 3$
* $(11 - 8) \mod M = 3 \mod M = 3$
* $(12 - 9) \mod M = 3 \mod M = 3$

As a result, $(0 + 998244345 + 998244345 + 998244345 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3) \mod 10^9 + 7$ $=$ $2994733059 \mod 10^9 + 7$ $=$ $994733045$



#### tags 

#3400 #binary_search #dfs_and_similar #math #meet-in-the-middle 