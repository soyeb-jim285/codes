<h1 style='text-align: center;'> E. Weird LCM Operations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an integer $n$, you construct an array $a$ of $n$ integers, where $a_i = i$ for all integers $i$ in the range $[1, n]$. An operation on this array is defined as follows:

* Select three distinct indices $i$, $j$, and $k$ from the array, and let $x = a_i$, $y = a_j$, and $z = a_k$.
* Update the array as follows: $a_i = \operatorname{lcm}(y, z)$, $a_j = \operatorname{lcm}(x, z)$, and $a_k = \operatorname{lcm}(x, y)$, where $\operatorname{lcm}$ represents the least common multiple.

 Your task is to provide a possible sequence of operations, containing at most $\lfloor \frac{n}{6} \rfloor + 5$ operations such that after executing these operations, if you create a set containing the greatest common divisors (GCDs) of all subsequences with a size greater than $1$, then all numbers from $1$ to $n$ should be present in this set.After all the operations $a_i \le 10^{18}$ should hold for all $1 \le i \le n$.

We can show that an answer always exists.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^2$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains an integer $n$ ($3 \leq n \leq 3 \cdot 10^{4}$) — the length of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^{4}$.

### Output

The first line should contain an integer $k$ ($0 \leq k \leq \lfloor \frac{n}{6} \rfloor + 5$) — where $k$ is the number of operations.

The next $k$ lines should contain the description of each operation i.e. $3$ integers $i$, $j$ and $k$, where $1 \leq i, j, k \leq n$ and all must be distinct.

## Example

### Input


```text
3347
```
### Output

```text

1
1 2 3
1
1 3 4
3
3 5 7
5 6 7
2 3 4
```
## Note

In the third test case, $a = [1, 2, 3, 4, 5, 6, 7]$.

First operation:

$i = 3$, $j = 5$, $k = 7$

$x = 3$, $y = 5$, $z = 7$.

$a = [1, 2, \operatorname{lcm}(y,z), 4, \operatorname{lcm}(x,z), 6, \operatorname{lcm}(x,y)]$ = $[1, 2, \color{red}{35}, 4, \color{red}{21}, 6, \color{red}{15}]$.

Second operation:

$i = 5$, $j = 6$, $k = 7$

$x = 21$, $y = 6$, $z = 15$.

$a = [1, 2, 35, 4, \operatorname{lcm}(y,z), \operatorname{lcm}(x,z), \operatorname{lcm}(x,y)]$ = $[1, 2, 35, 4, \color{red}{30}, \color{red}{105}, \color{red}{42}]$.

Third operation:

$i = 2$, $j = 3$, $k = 4$

$x = 2$, $y = 35$, $z = 4$.

$a = [1, \operatorname{lcm}(y,z), \operatorname{lcm}(x,z), \operatorname{lcm}(x,y), 30, 105, 42]$ = $[1, \color{red}{140}, \color{red}{4}, \color{red}{70}, 30, 105, 42]$.

Subsequences whose GCD equal to $i$ is as follows:

$\gcd(a_1, a_2) = \gcd(1, 140) = 1$

$\gcd(a_3, a_4) = \gcd(4, 70) = 2$

$\gcd(a_5, a_6, a_7) = \gcd(30, 105, 42) = 3$

$\gcd(a_2, a_3) = \gcd(140, 4) = 4$

$\gcd(a_2, a_4, a_5, a_6) = \gcd(140, 70, 30, 105) = 5$

$\gcd(a_5, a_7) = \gcd(30, 42) = 6$

$\gcd(a_2, a_4, a_6, a_7) = \gcd(140, 70, 105, 42) = 7$



#### Tags 

#3000 #NOT OK #brute_force #constructive_algorithms #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_931_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
