<h1 style='text-align: center;'> E. Expected Components</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a cyclic array $a$ of size $n$, where $a_i$ is the value of $a$ in the $i$-th position, there may be repeated values. Let us define that a permutation of $a$ is equal to another permutation of $a$ if and only if their values are the same for each position $i$ or we can transform them to each other by performing some cyclic rotation. Let us define for a cyclic array $b$ its number of components as the number of connected components in a graph, where the vertices are the positions of $b$ and we add an edge between each pair of adjacent positions of $b$ with equal values (note that in a cyclic array the first and last position are also adjacents).

Find the expected value of components of a permutation of $a$ if we select it equiprobably over the set of all the different permutations of $a$.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^6$) — the size of the cyclic array $a$.

The second line of each test case contains $n$ integers, the $i$-th of them is the value $a_i$ ($1 \le a_i \le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

It is guaranteed that the total number of different permutations of $a$ is not divisible by $M$

## Output

For each test case print a single integer — the expected value of components of a permutation of $a$ if we select it equiprobably over the set of all the different permutations of $a$ modulo $998\,244\,353$. 

Formally, let $M = 998\,244\,353$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. ## Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Example

## Input


```

541 1 1 141 1 2 141 2 1 254 3 2 5 1121 3 2 3 2 1 3 3 1 3 3 2
```
## Output


```

1
2
3
5
358642921

```
## Note

In the first test case there is only $1$ different permutation of $a$:

* $[1, 1, 1, 1]$ has $1$ component.
* Therefore the expected value of components is $\frac{1}{1} = 1$

In the second test case there are $4$ ways to permute the cyclic array $a$, but there is only $1$ different permutation of $a$:

* $[1, 1, 1, 2]$, $[1, 1, 2, 1]$, $[1, 2, 1, 1]$ and $[2, 1, 1, 1]$ are the same permutation and have $2$ components.
* Therefore the expected value of components is $\frac{2}{1} = 2$

In the third test case there are $6$ ways to permute the cyclic array $a$, but there are only $2$ different permutations of $a$:

* $[1, 1, 2, 2]$, $[2, 1, 1, 2]$, $[2, 2, 1, 1]$ and $[1, 2, 2, 1]$ are the same permutation and have $2$ components.
* $[1, 2, 1, 2]$ and $[2, 1, 2, 1]$ are the same permutation and have $4$ components.
* Therefore the expected value of components is $\frac{2+4}{2} = \frac{6}{2} = 3$

In the fourth test case there are $120$ ways to permute the cyclic array $a$, but there are only $24$ different permutations of $a$:

* Any permutation of $a$ has $5$ components.
* Therefore the expected value of components is $\frac{24\cdot 5}{24} = \frac{120}{24} = 5$


#### tags 

#2900 #combinatorics #math #number_theory #probabilities 