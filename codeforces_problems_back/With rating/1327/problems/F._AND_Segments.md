<h1 style='text-align: center;'> F. AND Segments</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $n$, $k$, $m$ and $m$ conditions $(l_1, r_1, x_1), (l_2, r_2, x_2), \dots, (l_m, r_m, x_m)$.

Calculate the number of distinct arrays $a$, consisting of $n$ integers such that: 

* $0 \le a_i < 2^k$ for each $1 \le i \le n$;
* bitwise AND of numbers $a[l_i] \\& a[l_i + 1] \\& \dots \\& a[r_i] = x_i$ for each $1 \le i \le m$.

Two arrays $a$ and $b$ are considered different if there exists such a position $i$ that $a_i \neq b_i$. 

The number can be pretty large so print it modulo $998244353$.

## Input

The first line contains three integers $n$, $k$ and $m$ ($1 \le n \le 5 \cdot 10^5$, $1 \le k \le 30$, $0 \le m \le 5 \cdot 10^5$) — the length of the array $a$, the value such that all numbers in $a$ should be smaller than $2^k$ and the number of conditions, respectively.

Each of the next $m$ lines contains the description of a condition $l_i$, $r_i$ and $x_i$ ($1 \le l_i \le r_i \le n$, $0 \le x_i < 2^k$) — the borders of the condition segment and the required bitwise AND value on it.

## Output

Print a single integer — the number of distinct arrays $a$ that satisfy all the above conditions modulo $998244353$.

## Examples

## Input


```

4 3 2
1 3 3
3 4 6

```
## Output


```

3

```
## Input


```

5 2 3
1 3 2
2 5 0
3 3 3

```
## Output


```

33

```
## Note

You can recall what is a bitwise AND operation [here](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

In the first example, the answer is the following arrays: $[3, 3, 7, 6]$, $[3, 7, 7, 6]$ and $[7, 3, 7, 6]$.



#### tags 

#2500 #bitmasks #combinatorics #data_structures #dp #two_pointers 