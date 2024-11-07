<h1 style='text-align: center;'> F. Lisa and the Martians</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Lisa was kidnapped by martians! It okay, because she has watched a lot of TV shows about aliens, so she knows what awaits her. Let's call integer martian if it is a non-negative integer and strictly less than $2^k$, for example, when $k = 12$, the numbers $51$, $1960$, $0$ are martian, and the numbers $\pi$, $-1$, $\frac{21}{8}$, $4096$ are not.

The aliens will give Lisa $n$ martian numbers $a_1, a_2, \ldots, a_n$. Then they will ask her to name any martian number $x$. After that, Lisa will select a pair of numbers $a_i, a_j$ ($i \neq j$) in the given sequence and count $(a_i \oplus x) \\& (a_j \oplus x)$. The operation $\oplus$ means [Bitwise exclusive OR](http://tiny.cc/xor_wiki), the operation $\\&$ means [Bitwise And](http://tiny.cc/and_wiki ). For example, $(5 \oplus 17) \\& (23 \oplus 17) = (00101_2 \oplus 10001_2) \\& (10111_2 \oplus 10001_2) = 10100_2 \\& 00110_2 = 00100_2 = 4$.

Lisa is sure that the higher the calculated value, the higher her chances of returning home. Help the girl choose such $i, j, x$ that maximize the calculated value.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — number of testcases.

Each testcase is described by two lines.

The first line contains integers $n, k$ ($2 \le n \le 2 \cdot 10^5$, $1 \le k \le 30$) — the length of the sequence of martian numbers and the value of $k$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^k$) — a sequence of martian numbers.

It is guaranteed that the sum of $n$ over all testcases does not exceed $2 \cdot 10^5$.

## Output

For each testcase, print three integers $i, j, x$ ($1 \le i, j \le n$, $i \neq j$, $0 \le x < 2^k$). The value of $(a_i \oplus x) \\& (a_j \oplus x)$ should be the maximum possible.

If there are several solutions, you can print any one.

## Example

## Input


```

105 43 9 1 4 133 11 0 16 12144 1580 1024 100 9 134 37 3 0 43 20 0 12 412 29 46 14 9 4 4 4 5 10 22 11 02 411 49 42 11 10 1 6 9 11 0 5
```
## Output


```

1 3 14
1 3 0
5 6 4082
2 3 7
1 2 3
1 2 15
4 5 11
1 2 0
1 2 0
2 7 4

```
## Note

First testcase: $(3 \oplus 14) \\& (1 \oplus 14) = (0011_2 \oplus 1110_2) \\& (0001_2 \oplus 1110_2) = 1101_2 = 1101_2 \\& 1111_2 = 1101_2 = 13$.

Second testcase: $(1 \oplus 0) \\& (1 \oplus 0) = 1$.

Third testcase: $(9 \oplus 4082) \\& (13 \oplus 4082) = 4091$.

Fourth testcase: $(3 \oplus 7) \\& (0 \oplus 7) = 4$.



#### tags 

#1800 #bitmasks #greedy #math #strings #trees 