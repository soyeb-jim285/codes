<h1 style='text-align: center;'> B. Jellyfish and Math</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Jellyfish is given the non-negative integers $a$, $b$, $c$, $d$ and $m$. Initially $(x,y)=(a,b)$. Jellyfish wants to do several operations so that $(x,y)=(c,d)$.

For each operation, she can do one of the following:

* $x := x\,\\&\,y$,
* $x := x\,|\,y$,
* $y := x \oplus y$,
* $y := y \oplus m$.

Here $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND), $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR) and $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Now Jellyfish asks you for the minimum number of operations such that $(x,y)=(c,d)$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). The description of the test cases follows.

The only line of each test case contains five integers, $a$, $b$, $c$, $d$ and $m$ ($0 \leq a, b, c, d, m < 2^{30}$).

## Output

For each test case, output a single integer — the minimum number of operations. If this cannot be achieved, output $-1$ instead.

## Example

## Input


```

101 0 1 1 13 3 1 2 11 6 0 7 12 4 4 9 821 4 0 17 2850 50 0 0 3995 33 1 33 110138 202 174 64 10878 340 68 340 461457 291 491 566 766
```
## Output


```

1
-1
2
-1
-1
2
1
4
1
3

```
## Note

In the first test case, we can do the operation $y = x \oplus y$.

In the second test case, it is not possible to change $(x,y)=(1,2)$ using any sequence of operations.

In the third test case, we can do the operation $x = x\,\\&\,y$ followed by the operation $y = y \oplus m$.



#### tags 

#2400 #bitmasks #brute_force #dfs_and_similar #dp #graphs #shortest_paths 