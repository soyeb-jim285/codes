<h1 style='text-align: center;'> G. Linear Congruential Generator</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tuple generator $f^{(k)} = (f_1^{(k)}, f_2^{(k)}, \dots, f_n^{(k)})$, where $f_i^{(k)} = (a_i \cdot f_i^{(k - 1)} + b_i) \bmod p_i$ and $f^{(0)} = (x_1, x_2, \dots, x_n)$. Here $x \bmod y$ denotes the remainder of $x$ when divided by $y$. All $p_i$ are primes.

One can see that with fixed sequences $x_i$, $y_i$, $a_i$ the tuples $f^{(k)}$ starting from some index will repeat tuples with smaller indices. Calculate the maximum number of different tuples (from all $f^{(k)}$ for $k \ge 0$) that can be produced by this generator, if $x_i$, $a_i$, $b_i$ are integers in the range $[0, p_i - 1]$ and can be chosen arbitrary. The answer can be large, so print the remainder it gives when divided by $10^9 + 7$

#### Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of elements in the tuple.

The second line contains $n$ space separated prime numbers — the modules $p_1, p_2, \ldots, p_n$ ($2 \le p_i \le 2 \cdot 10^6$).

#### Output

Print one integer — the maximum number of different tuples modulo $10^9 + 7$.

## Examples

#### Input


```text
4  
2 3 5 7  

```
#### Output


```text
210  

```
#### Input


```text
3  
5 3 3  

```
#### Output


```text
30  

```
## Note

In the first example we can choose next parameters: $a = [1, 1, 1, 1]$, $b = [1, 1, 1, 1]$, $x = [0, 0, 0, 0]$, then $f_i^{(k)} = k \bmod p_i$.

In the second example we can choose next parameters: $a = [1, 1, 2]$, $b = [1, 1, 0]$, $x = [0, 0, 1]$.



#### Tags 

#2900 #NOT OK #number_theory 

## Blogs
- [All Contest Problems](../Technocup_2019_-_Elimination_Round_1.md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
