<h1 style='text-align: center;'> C. Remove the Bracket</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

RSJ has a sequence $a$ of $n$ integers $a_1,a_2, \ldots, a_n$ and an integer $s$. For each of $a_2,a_3, \ldots, a_{n-1}$, he chose a pair of non-negative integers $x_i$ and $y_i$ such that $x_i+y_i=a_i$ and $(x_i-s) \cdot (y_i-s) \geq 0$.

Now he is interested in the value $$F = a_1 \cdot x_2+y_2 \cdot x_3+y_3 \cdot x_4 + \ldots + y_{n - 2} \cdot x_{n-1}+y_{n-1} \cdot a_n.$$

Please help him find the minimum possible value $F$ he can get by choosing $x_i$ and $y_i$ optimally. It can be shown that there is always at least one valid way to choose them.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$, $s$ ($3 \le n \le 2 \cdot 10^5$; $0 \le s \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0 \le a_i \le 2 \cdot 10^5$).

It is guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$.

## Output

For each test case, print the minimum possible value of $F$.

## Example

## Input


```

105 02 0 1 3 45 15 3 4 3 57 27 6 5 4 3 2 15 11 2 3 4 55 21 2 3 4 54 00 1 1 15 54 3 5 6 44 10 2 1 03 99999200000 200000 2000006 81397976 129785 12984 78561 173685 15480
```
## Output


```

0
18
32
11
14
0
16
0
40000000000
2700826806

```
## Note

In the first test case, $2\cdot 0+0\cdot 1+0\cdot 3+0\cdot 4 = 0$.

In the second test case, $5\cdot 1+2\cdot 2+2\cdot 2+1\cdot 5 = 18$.



#### tags 

#1600 #dp #greedy #math 