<h1 style='text-align: center;'> B. GCD Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a positive integer $n$. Find three distinct positive integers $a$, $b$, $c$ such that $a + b + c = n$ and $\operatorname{gcd}(a, b) = c$, where $\operatorname{gcd}(x, y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first and only line of each test case contains a single integer $n$ ($10 \le n \le 10^9$).

### Output

For each test case, output three distinct positive integers $a$, $b$, $c$ satisfying the requirements. If there are multiple solutions, you can print any. We can show that an answer always exists.

## Example

### Input


```text
6
18
63
73
91
438
122690412
```
### Output


```text

6 9 3
21 39 3
29 43 1
49 35 7
146 219 73
28622 122661788 2
```
## Note

In the first test case, $6 + 9 + 3 = 18$ and $\operatorname{gcd}(6, 9) = 3$.

In the second test case, $21 + 39 + 3 = 63$ and $\operatorname{gcd}(21, 39) = 3$.

In the third test case, $29 + 43 + 1 = 73$ and $\operatorname{gcd}(29, 43) = 1$.



#### Tags 

#900 #OK #brute_force #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_761_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
