<h1 style='text-align: center;'> C. Banknotes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Berland, $n$ different types of banknotes are used. Banknotes of the $i$-th type have denomination $10^{a_i}$ burles (burles are the currency used in Berland); the denomination of banknotes of the first type is exactly $1$.

Let's denote $f(s)$ as the minimum number of banknotes required to represent exactly $s$ burles. For example, if the denominations of banknotes used in Berland are $1$, $10$ and $100$, then $f(59) = 14$: $9$ banknotes with denomination of $1$ burle and $5$ banknotes with denomination of $10$ burles can be used to represent exactly $9 \cdot 1 + 5 \cdot 10 = 59$ burles, and there's no way to do it with fewer banknotes.

For a given integer $k$, find the minimum positive number of burles $s$ that cannot be represented with $k$ or fewer banknotes (that is, $f(s) > k$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 10; 1 \le k \le 10^9$).

The next line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 = a_1 < a_2 < \dots < a_n \le 9$).

## Output

For each test case, print one integer — the minimum positive number of burles $s$ that cannot be represented with $k$ or fewer banknotes.

## Example

## Input


```

4
3 13
0 1 2
2 777
0 4
3 255
0 1 3
10 1000000000
0 1 2 3 4 5 6 7 8 9

```
## Output


```

59
778
148999
999999920999999999

```


#### tags 

#1400 #greedy #number_theory 