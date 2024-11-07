<h1 style='text-align: center;'> B. Beautiful Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Stanley defines the beauty of an array $a$ of length $n$, which contains non-negative integers, as follows: $$\sum\limits_{i = 1}^{n} \left \lfloor \frac{a_{i}}{k} \right \rfloor,$$ which means that we divide each element by $k$, round it down, and sum up the resulting values.

Stanley told Sam the integer $k$ and asked him to find an array $a$ of $n$ non-negative integers, such that the beauty is equal to $b$ and the sum of elements is equal to $s$. Help Sam — find any of the arrays satisfying the conditions above.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The first line of each test case contains integers $n$, $k$, $b$, $s$ ($1 \leq n \leq 10^{5}$, $1 \leq k \leq 10^{9}$, $0 \leq b \leq 10^{9}$, $0 \leq s \leq 10^{18}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case print $-1$ if such array $a$ does not exist. Otherwise print $n$ non-negative integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_{i} \leq 10^{18}$) — the answer.

## Example

## Input


```

81 6 3 1003 6 3 123 6 3 195 4 7 385 4 7 8099978 1000000000 100000000 10000000000000000001 1 0 04 1000000000 1000000000 1000000000000000000
```
## Output


```

-1
-1
0 0 19
0 3 3 3 29
-1
-1
0
0 0 0 1000000000000000000

```
## Note

In the first, the second, the fifth and the sixth test cases of the example it is possible to show that such array does not exist.

In the third testcase of the example $a = [0, 0, 19]$. The sum of elements in it is equal to 19, the beauty of it is equal to $\left ( \left \lfloor \frac{0}{6} \right \rfloor + \left \lfloor \frac{0}{6} \right \rfloor + \left \lfloor \frac{19}{6} \right \rfloor \right ) = (0 + 0 + 3) = 3$.

In the fourth testcase of the example $a = [0, 3, 3, 3, 29]$. The sum of elements in it is equal to $38$, the beauty of it is equal to $(0 + 0 + 0 + 0 + 7) = 7$.



#### tags 

#1000 #constructive_algorithms #greedy #math 