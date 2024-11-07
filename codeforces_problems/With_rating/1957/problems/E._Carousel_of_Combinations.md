<h1 style='text-align: center;'> E. Carousel of Combinations</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$. The function $C(i,k)$ represents the number of distinct ways you can select $k$ distinct numbers from the set {$1, 2, \ldots, i$} and arrange them in a circle$^\dagger$.

Find the value of $$ \sum\limits_{i=1}^n \sum\limits_{j=1}^i \left( C(i,j) \bmod j \right). $$ Here, the operation $x \bmod y$ denotes the remainder from dividing $x$ by $y$.

Since this value can be very large, find it modulo $10^9+7$.

$^\dagger$ In a circular arrangement, sequences are considered identical if one can be rotated to match the other. For instance, $[1, 2, 3]$ and $[2, 3, 1]$ are equivalent in a circle.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \le n \le 10^6$).

### Output

For each test case, output a single integer on a new line — the value of the expression to be calculated modulo $10^9+7$.

## Example

### Input


```text
4136314159
```
### Output

```text

0
4
24
78926217

```
## Note

In the first test case, $C(1,1) \bmod 1 = 0$.

In the second test case: 

* $C(1,1)=1$ (the arrangements are: $[1]$);
* $C(2,1)=2$ (the arrangements are: $[1]$, $[2]$);
* $C(2,2)=1$ (the arrangements are: $[1, 2]$);
* $C(3,1)=3$ (the arrangements are: $[1]$, $[2]$, $[3]$);
* $C(3,2)=3$ (the arrangements are: $[1, 2]$, $[2, 3]$, $[3, 1]$);
* $C(3,3)=2$ (the arrangements are: $[1, 2, 3]$, $[1, 3, 2]$).

 In total, $\left(C(1,1) \bmod 1\right) + \left(C(2,1) \bmod 1\right) + \left(C(2,2) \bmod 2\right) + \left(C(3,1) \bmod 1\right) + \left(C(3,2) \bmod 2\right) + \left(C(3,3) \bmod 3\right) = 4$.

#### Tags 

#2400 #NOT OK #brute_force #combinatorics #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_940_(Div._2)_and_CodeCraft-23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
