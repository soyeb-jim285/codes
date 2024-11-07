<h1 style='text-align: center;'> C. Primes and Multiplication</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's introduce some definitions that will be needed later.

Let $prime(x)$ be the set of prime divisors of $x$. For example, $prime(140) = \{ 2, 5, 7 \}$, $prime(169) = \{ 13 \}$.

Let $g(x, p)$ be the maximum possible integer $p^k$ where $k$ is an integer such that $x$ is divisible by $p^k$. For example:

* $g(45, 3) = 9$ ($45$ is divisible by $3^2=9$ but not divisible by $3^3=27$),
* $g(63, 7) = 7$ ($63$ is divisible by $7^1=7$ but not divisible by $7^2=49$).

Let $f(x, y)$ be the product of $g(y, p)$ for all $p$ in $prime(x)$. For example:

* $f(30, 70) = g(70, 2) \cdot g(70, 3) \cdot g(70, 5) = 2^1 \cdot 3^0 \cdot 5^1 = 10$,
* $f(525, 63) = g(63, 3) \cdot g(63, 5) \cdot g(63, 7) = 3^2 \cdot 5^0 \cdot 7^1 = 63$.

You have integers $x$ and $n$. Calculate $f(x, 1) \cdot f(x, 2) \cdot \ldots \cdot f(x, n) \bmod{(10^{9} + 7)}$.

##### Input

The only line contains integers $x$ and $n$ ($2 \le x \le 10^{9}$, $1 \le n \le 10^{18}$) — the numbers used in formula.

##### Output

Print the answer.

## Examples

##### Input


```text
10 2
```
##### Output


```text
2
```
##### Input


```text
20190929 1605
```
##### Output


```text
363165664
```
##### Input


```text
947 987654321987654321
```
##### Output


```text
593574252
```
## Note

In the first example, $f(10, 1) = g(1, 2) \cdot g(1, 5) = 1$, $f(10, 2) = g(2, 2) \cdot g(2, 5) = 2$.

In the second example, actual value of formula is approximately $1.597 \cdot 10^{171}$. Make sure you print the answer modulo $(10^{9} + 7)$.

In the third example, be careful about overflow issue.



#### Tags 

#1700 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_589_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
