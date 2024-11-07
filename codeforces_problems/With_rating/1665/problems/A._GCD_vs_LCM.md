<h1 style='text-align: center;'> A. GCD vs LCM</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$. You have to find $4$ positive integers $a, b, c, d$ such that

* $a + b + c + d = n$, and
* $\gcd(a, b) = \operatorname{lcm}(c, d)$.

If there are several possible answers you can output any of them. It is possible to show that the answer always exists.

In this problem $\gcd(a, b)$ denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of $a$ and $b$, and $\operatorname{lcm}(c, d)$ denotes the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of $c$ and $d$.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

Each test case contains a single line with integer $n$ ($4 \le n \le 10^9$) — the sum of $a$, $b$, $c$, and $d$.

### Output

For each test case output $4$ positive integers $a$, $b$, $c$, $d$ such that $a + b + c + d = n$ and $\gcd(a, b) = \operatorname{lcm}(c, d)$.

## Example

### Input


```text
5478910
```
### Output

```text

1 1 1 1
2 2 2 1
2 2 2 2
2 4 2 1
3 5 1 1
```
## Note

In the first test case $\gcd(1, 1) = \operatorname{lcm}(1, 1) = 1$, $1 + 1 + 1 + 1 = 4$.

In the second test case $\gcd(2, 2) = \operatorname{lcm}(2, 1) = 2$, $2 + 2 + 2 + 1 = 7$.

In the third test case $\gcd(2, 2) = \operatorname{lcm}(2, 2) = 2$, $2 + 2 + 2 + 2 = 8$.

In the fourth test case $\gcd(2, 4) = \operatorname{lcm}(2, 1) = 2$, $2 + 4 + 2 + 1 = 9$.

In the fifth test case $\gcd(3, 5) = \operatorname{lcm}(1, 1) = 1$, $3 + 5 + 1 + 1 = 10$. 



#### Tags 

#800 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_781_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
