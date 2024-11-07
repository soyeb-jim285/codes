<h1 style='text-align: center;'> C. Array Beauty</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call beauty of an array $b_1, b_2, \ldots, b_n$ ($n > 1$)  — $\min\limits_{1 \leq i < j \leq n} |b_i - b_j|$.

You're given an array $a_1, a_2, \ldots a_n$ and a number $k$. Calculate the sum of beauty over all subsequences of the array of length exactly $k$. As this number can be very large, output it modulo $998244353$.

A sequence $a$ is a subsequence of an array $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements.

#### Input

The first line contains integers $n, k$ ($2 \le k \le n \le 1000$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^5$).

#### Output

#### Output

 one integer — the sum of beauty over all subsequences of the array of length exactly $k$. As this number can be very large, output it modulo $998244353$.

## Examples

#### Input


```text
4 3
1 7 3 5
```
#### Output


```text
8
```
#### Input

```text

5 5
1 10 100 1000 10000

```
#### Output


```text

9
```
## Note

In the first example, there are $4$ subsequences of length $3$ — $[1, 7, 3]$, $[1, 3, 5]$, $[7, 3, 5]$, $[1, 7, 5]$, each of which has beauty $2$, so answer is $8$.

In the second example, there is only one subsequence of length $5$ — the whole array, which has the beauty equal to $|10-1| = 9$.



#### Tags 

#2500 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_572_(Div._1).md)
- [Codeforces Round #572](../blogs/Codeforces_Round_572.md)
- [Tutorial](../blogs/Tutorial.md)
