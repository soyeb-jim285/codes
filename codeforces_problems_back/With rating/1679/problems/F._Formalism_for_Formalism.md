<h1 style='text-align: center;'> F. Formalism for Formalism</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yura is a mathematician, and his cognition of the world is so absolute as if he have been solving formal problems a hundred of trillions of billions of years. This problem is just that!

Consider all non-negative integers from the interval $[0, 10^{n})$. For convenience we complement all numbers with leading zeros in such way that each number from the given interval consists of exactly $n$ decimal digits.

You are given a set of pairs $(u_i, v_i)$, where $u_i$ and $v_i$ are distinct decimal digits from $0$ to $9$.

Consider a number $x$ consisting of $n$ digits. We will enumerate all digits from left to right and denote them as $d_1, d_2, \ldots, d_n$. In one operation you can swap digits $d_i$ and $d_{i + 1}$ if and only if there is a pair $(u_j, v_j)$ in the set such that at least one of the following conditions is satisfied:

1. $d_i = u_j$ and $d_{i + 1} = v_j$,
2. $d_i = v_j$ and $d_{i + 1} = u_j$.

We will call the numbers $x$ and $y$, consisting of $n$ digits, equivalent if the number $x$ can be transformed into the number $y$ using some number of operations described above. In particular, every number is considered equivalent to itself.

You are given an integer $n$ and a set of $m$ pairs of digits $(u_i, v_i)$. You have to find the maximum integer $k$ such that there exists a set of integers $x_1, x_2, \ldots, x_k$ ($0 \le x_i < 10^{n}$) such that for each $1 \le i < j \le k$ the number $x_i$ is not equivalent to the number $x_j$.

## Input

The first line contains an integer $n$ ($1 \le n \le 50\,000$) — the number of digits in considered numbers.

The second line contains an integer $m$ ($0 \le m \le 45$) — the number of pairs of digits in the set.

Each of the following $m$ lines contains two digits $u_i$ and $v_i$, separated with a space ($0 \le u_i < v_i \le 9$).

It's guaranteed that all described pairs are pairwise distinct.

## Output

Print one integer — the maximum value $k$ such that there exists a set of integers $x_1, x_2, \ldots, x_k$ ($0 \le x_i < 10^{n}$) such that for each $1 \le i < j \le k$ the number $x_i$ is not equivalent to the number $x_j$.

As the answer can be big enough, print the number $k$ modulo $998\,244\,353$.

## Examples

## Input


```

1
0

```
## Output


```

10

```
## Input


```

2
1
0 1

```
## Output


```

99

```
## Input


```

2
9
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9

```
## Output


```

91

```
## Note

In the first example we can construct a set that contains all integers from $0$ to $9$. It's easy to see that there are no two equivalent numbers in the set.

In the second example there exists a unique pair of equivalent numbers: $01$ and $10$. We can construct a set that contains all integers from $0$ to $99$ despite number $1$.



#### tags 

#2600 #bitmasks #dp #math 