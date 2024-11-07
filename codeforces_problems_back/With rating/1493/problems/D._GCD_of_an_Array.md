<h1 style='text-align: center;'> D. GCD of an Array</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$. You are asked to process $q$ queries of the following format: given integers $i$ and $x$, multiply $a_i$ by $x$.

After processing each query you need to output the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of all elements of the array $a$.

Since the answer can be too large, you are asked to output it modulo $10^9+7$.

## Input

The first line contains two integers — $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$) — the elements of the array $a$ before the changes.

The next $q$ lines contain queries in the following format: each line contains two integers $i$ and $x$ ($1 \le i \le n$, $1 \le x \le 2 \cdot 10^5$).

## Output

Print $q$ lines: after processing each query output the GCD of all elements modulo $10^9+7$ on a separate line.

## Example

## Input


```

4 3
1 6 8 12
1 12
2 3
3 3

```
## Output


```

2
2
6

```
## Note

After the first query the array is $[12, 6, 8, 12]$, $\operatorname{gcd}(12, 6, 8, 12) = 2$.

After the second query — $[12, 18, 8, 12]$, $\operatorname{gcd}(12, 18, 8, 12) = 2$.

After the third query — $[12, 18, 24, 12]$, $\operatorname{gcd}(12, 18, 24, 12) = 6$.

Here the $\operatorname{gcd}$ function denotes the greatest common divisor.



#### tags 

#2100 #brute_force #data_structures #hashing #implementation #math #number_theory #sortings #two_pointers 