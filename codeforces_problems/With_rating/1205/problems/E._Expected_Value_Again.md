<h1 style='text-align: center;'> E. Expected Value Again</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given integers $n$, $k$. Let's consider the alphabet consisting of $k$ different elements.

Let beauty $f(s)$ of the string $s$ be the number of indexes $i$, $1\le i<|s|$, for which prefix of $s$ of length $i$ equals to suffix of $s$ of length $i$. For example, beauty of the string $abacaba$ equals $2$, as for $i = 1, 3$ prefix and suffix of length $i$ are equal.

Consider all words of length $n$ in the given alphabet. Find the expected value of $f(s)^2$ of a uniformly chosen at random word. We can show that it can be expressed as $\frac{P}{Q}$, where $P$ and $Q$ are coprime and $Q$ isn't divided by $10^9 + 7$. 
###### Output

 $P\cdot Q^{-1} \bmod 10^9 + 7$.

###### Input

The first and the only line contains two integers $n$, $k$ ($1\le n \le 10^5$, $1\le k\le 10^9$) — the length of a string and the size of alphabet respectively.

###### Output

###### Output

 a single integer — $P\times Q^{-1} \bmod 10^9 + 7$.

## Examples

###### Input


```text
2 3
```
###### Output


```text
333333336
```
###### Input


```text
1 5
```
###### Output


```text
0
```
###### Input


```text
100 1
```
###### Output


```text
9801
```
###### Input


```text
10 10
```
###### Output


```text
412377396
```
## Note

In the first example, there are $9$ words of length $2$ in alphabet of size $3$ — $aa$, $ab$, $ac$, $ba$, $bb$, $bc$, $ca$, $cb$, $cc$. $3$ of them have beauty $1$ and $6$ of them have beauty $0$, so the average value is $\frac{1}{3}$.

In the third example, there is only one such word, and it has beauty $99$, so the average value is $99^2$.



#### Tags 

#3100 #NOT OK #combinatorics #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_580_(Div._1).md)
- [Codeforces Round #580](../blogs/Codeforces_Round_580.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
