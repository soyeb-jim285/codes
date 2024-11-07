<h1 style='text-align: center;'> D. Sum of XOR Functions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$ consisting of non-negative integers.

You have to calculate the value of $\sum_{l=1}^{n} \sum_{r=l}^{n} f(l, r) \cdot (r - l + 1)$, where $f(l, r)$ is $a_l \oplus a_{l+1} \oplus \dots \oplus a_{r-1} \oplus a_r$ (the character $\oplus$ denotes bitwise XOR).

Since the answer can be very large, print it modulo $998244353$.

## Input

The first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 10^9)$.

## Output

Print the one integer — the value of $\sum_{l=1}^{n} \sum_{r=l}^{n} f(l, r) \cdot (r - l + 1)$, taken modulo $998244353$.

## Examples

## Input


```

3
1 3 2

```
## Output


```

12

```
## Input


```

4
39 68 31 80

```
## Output


```

1337

```
## Input


```

7
313539461 779847196 221612534 488613315 633203958 394620685 761188160

```
## Output


```

257421502

```
## Note

In the first example, the answer is equal to $f(1, 1) + 2 \cdot f(1, 2) + 3 \cdot f(1, 3) + f(2, 2) + 2 \cdot f(2, 3) + f(3, 3) = $ $= 1 + 2 \cdot 2 + 3 \cdot 0 + 3 + 2 \cdot 1 + 2 = 12$.



#### tags 

#1700 #bitmasks #combinatorics #divide_and_conquer #dp #math 