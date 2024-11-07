<h1 style='text-align: center;'> D. A BIT of an Inequality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$. Find the number of tuples ($x, y, z$) such that: 

* $1 \leq x \leq y \leq z \leq n$, and
* $f(x, y) \oplus f(y, z) > f(x, z)$.

We define $f(l, r) = a_l \oplus a_{l + 1} \oplus \ldots \oplus a_{r}$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single integer on a new line — the number of described tuples.

## Example

## Input


```

336 2 41357 3 7 2 1
```
## Output


```

4
0
16

```
## Note

In the first case, there are 4 such tuples in the array $[6, 2, 4]$: 

* ($1$, $2$, $2$): $(a_1 \oplus a_2) \oplus (a_2) = 4 \oplus 2 > (a_1 \oplus a_2) = 4$
* ($1$, $1$, $3$): $(a_1) \oplus (a_1 \oplus a_2 \oplus a_3) = 6 \oplus 0 > (a_1 \oplus a_2 \oplus a_3) = 0$
* ($1$, $2$, $3$): $(a_1 \oplus a_2) \oplus (a_2 \oplus a_3) = 4 \oplus 6 > (a_1 \oplus a_2 \oplus a_3) = 0$
* ($1$, $3$, $3$): $(a_1 \oplus a_2 \oplus a_3) \oplus (a_3) = 0 \oplus 4 > (a_1 \oplus a_2 \oplus a_3) = 0$

In the second test case, there are no such tuples.



#### tags 

#1900 #bitmasks #brute_force #dp #math 