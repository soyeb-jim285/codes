<h1 style='text-align: center;'> D. Mathematical Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n > 1$, consisting of digits from $0$ to $9$. You must insert exactly $n - 2$ symbols $+$ (addition) or $\times$ (multiplication) into this string to form a valid arithmetic expression.

In this problem, the symbols cannot be placed before the first or after the last character of the string $s$, and two symbols cannot be written consecutively. Also, note that the order of the digits in the string cannot be changed. Let's consider $s = 987009$:

* From this string, the following arithmetic expressions can be obtained: $9 \times 8 + 70 \times 0 + 9 = 81$, $98 \times 7 \times 0 + 0 \times 9 = 0$, $9 + 8 + 7 + 0 + 09 = 9 + 8 + 7 + 0 + 9 = 33$. ## Note

 that the number $09$ is considered valid and is simply transformed into $9$.
* From this string, the following arithmetic expressions cannot be obtained: $+9 \times 8 \times 70 + 09$ (symbols should only be placed between digits), $98 \times 70 + 0 + 9$ (since there are $6$ digits, there must be exactly $4$ symbols).

The result of the arithmetic expression is calculated according to the rules of mathematics — first all multiplication operations are performed, then addition. You need to find the minimum result that can be obtained by inserting exactly $n - 2$ addition or multiplication symbols into the given string $s$.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follows their description.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 20$) — the length of the string $s$.

The second line of each test case contains a string $s$ of length $n$, consisting of digits from $0$ to $9$.

## Output

For each test case, output the minimum result of the arithmetic expression that can be obtained by inserting exactly $n - 2$ addition or multiplication symbols into the given string.

## Example

## Input


```

182102742002013901310152331169870097111111120999999999999999999992000000000000000000000402121805723528362134539541112201981167848732178412141121422213011
```
## Output


```

10
74
0
1
9
1
19
0
11
261
0
0
0
12
93
12
24
0

```
## Note

In the first four test cases, we cannot add symbols, so the answer will be the original number.

In the fifth test case, the optimal answer looks as follows: $9 \times 01 = 9 \times 1 = 9$.

In the sixth test case, the optimal answer looks as follows: $1 \times 01 = 1 \times 1 = 1$.

In the seventh test case, the optimal answer looks as follows: $2 + 3 + 3 + 11 = 19$.

In the eighth test case, one of the optimal answers looks as follows: $98 \times 7 \times 0 + 0 \times 9 = 0$.



#### tags 

#1400 #brute_force #dp #greedy #implementation #math #two_pointers 