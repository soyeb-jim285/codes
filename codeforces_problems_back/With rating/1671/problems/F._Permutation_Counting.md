<h1 style='text-align: center;'> F. Permutation Counting</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Calculate the number of permutations $p$ of size $n$ with exactly $k$ inversions (pairs of indices $(i, j)$ such that $i < j$ and $p_i > p_j$) and exactly $x$ indices $i$ such that $p_i > p_{i+1}$.

Yep, that's the whole problem. Good luck!

## Input

The first line contains one integer $t$ ($1 \le t \le 3 \cdot 10^4$) — the number of test cases.

Each test case consists of one line which contains three integers $n$, $k$ and $x$ ($1 \le n \le 998244352$; $1 \le k \le 11$; $1 \le x \le 11$).

## Output

For each test case, print one integer — the answer to the problem, taken modulo $998244353$.

## Example

## Input


```

510 6 47 3 1163316 11 7136373 11 1325902 11 11
```
## Output


```

465
12
986128624
7636394
57118194

```


#### tags 

#2700 #brute_force #combinatorics #dp #fft #math 