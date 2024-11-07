<h1 style='text-align: center;'> E. Special Positions</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ of length $n$. Also you are given $m$ distinct positions $p_1, p_2, \ldots, p_m$ ($1 \leq p_i \leq n$).

A non-empty subset of these positions $T$ is randomly selected with equal probability and the following value is calculated: $$\sum_{i=1}^{n} (a_i \cdot \min_{j \in T} \left|i - j\right|).$$ In other word, for each index of the array, $a_i$ and the distance to the closest chosen position are multiplied, and then these values are summed up.

Find the expected value of this sum.

This value must be found modulo $998\,244\,353$. More formally, let $M = 998\,244\,353$. It can be shown that the answer can be represented as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \neq 0$ (mod $M$). 
#### Output

 the integer equal to $p \cdot q^{-1}$ (mod $M$). In other words, output such integer $x$ that $0 \leq x < M$ and $x \cdot q = p$ (mod $M$).

#### Input

The first line contains two integers $n$ and $m$ ($1 \leq m \leq n \leq 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i < 998\,244\,353$).

The third line contains $m$ distinct integers $p_1, p_2, \ldots, p_m$ ($1 \leq p_i \le n$).

For every $1 \leq i < m$ it is guaranteed that $p_i < p_{i+1}$.

#### Output

Print a single integer — the answer to the problem.

## Examples

#### Input


```text
4 2
1 2 3 4
1 4
```
#### Output


```text
665496247
```
#### Input


```text
6 6
4 2 4 2 4 2
1 2 3 4 5 6
```
#### Output


```text
855638030
```
## Note

In the first test: 

* If only $1$ is choosen, than the value equals to $1 \cdot 0 + 2 \cdot 1 + 3 \cdot 2 + 4 \cdot 3 = 20$.
* If only $4$ is choosen, than the value equals to $1 \cdot 3 + 2 \cdot 2 + 3 \cdot 1 + 4 \cdot 0 = 10$.
* If both positions are chosen, than the value equals to $1 \cdot 0 + 2 \cdot 1 + 3 \cdot 1 + 4 \cdot 0 = 5$.

The answer to the problem is $\frac{20 + 10 + 5}{3} = \frac{35}{3} = 665\,496\,247$ (modulo $998\,244\,353$).



#### Tags 

#3300 #NOT OK #combinatorics #divide_and_conquer #fft #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_773_(Div._1).md)
- [Codeforces Round #773](../blogs/Codeforces_Round_773.md)
- [Tutorial](../blogs/Tutorial.md)
