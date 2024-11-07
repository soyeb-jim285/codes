<h1 style='text-align: center;'> A. Add Plus Minus Sign</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

AquaMoon has a string $a$ consisting of only $0$ and $1$. She wants to add $+$ and $-$ between all pairs of consecutive positions to make the absolute value of the resulting expression as small as possible. Can you help her?

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 2\,000$)  – the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 100$) — the length of $a$.

The second line of each test case contains a string $a$ of length $n$, consisting of only $0$ and $1$.

### Output

For each test case, output a string of length $n - 1$ consisting of $-$ and $+$ on a separate line. If there is more than one assignment of signs that produces the smallest possible absolute value, any of them is accepted.

## Example

### Input


```text
3211501101510001
```
### Output

```text

-
+-++
+++-

```
## Note

In the first test case, we can get the expression $1 - 1 = 0$, with absolute value $0$.

In the second test case, we can get the expression $0 + 1 - 1 + 0 + 1 = 1$, with absolute value $1$.

In the third test case, we can get the expression $1 + 0 + 0 + 0 - 1 = 0$, with absolute value $0$.



#### Tags 

#800 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Polynomial_Round_2022_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
