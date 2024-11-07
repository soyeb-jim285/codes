<h1 style='text-align: center;'> B. Z mod X = C</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three positive integers $a$, $b$, $c$ ($a < b < c$). You have to find three positive integers $x$, $y$, $z$ such that:

$$x \bmod y = a,$$ $$y \bmod z = b,$$ $$z \bmod x = c.$$

Here $p \bmod q$ denotes the remainder from dividing $p$ by $q$. It is possible to show that for such constraints the answer always exists.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10\,000$) — the number of test cases. Description of the test cases follows.

Each test case contains a single line with three integers $a$, $b$, $c$ ($1 \le a < b < c \le 10^8$).

## Output

For each test case output three positive integers $x$, $y$, $z$ ($1 \le x, y, z \le 10^{18}$) such that $x \bmod y = a$, $y \bmod z = b$, $z \bmod x = c$.

You can output any correct answer.

## Example

## Input


```

4
1 3 4
127 234 421
2 7 8
59 94 388

```
## Output


```

12 11 4
1063 234 1484
25 23 8
2221 94 2609

```
## Note

In the first test case:

$$x \bmod y = 12 \bmod 11 = 1;$$

$$y \bmod z = 11 \bmod 4 = 3;$$

$$z \bmod x = 4 \bmod 12 = 4.$$



#### tags 

#800 #constructive_algorithms #math 