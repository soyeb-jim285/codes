<h1 style='text-align: center;'> D. Flexible String Revisit</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two binary strings $a$ and $b$ of length $n$. In each move, the string $a$ is modified in the following way.

* An index $i$ ($1 \leq i \leq n$) is chosen uniformly at random. The character $a_i$ will be flipped. That is, if $a_i$ is $0$, it becomes $1$, and if $a_i$ is $1$, it becomes $0$.

What is the expected number of moves required to make both strings equal for the first time?

A binary string is a string, in which the character is either $\tt{0}$ or $\tt{1}$.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^6$) — the length of the strings.

The second line of each test case contains the binary string $a$ of length $n$.

The third line of each test case contains the binary string $b$ of length $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output a single line containing the expected number of moves modulo $998\,244\,353$.

Formally, let $M = 998\,244\,353$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. 
### Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Example

### Input


```text
41012000041000111050100110111
```
### Output

```text

1
0
665496254
665496277

```
## Note

In the first test case, index $1$ is chosen randomly and $a_1$ is flipped. After the move, the strings $a$ and $b$ are equal. The expected number of moves is $1$.

The strings $a$ and $b$ are already equal in the second test case. So, the expected number of moves is $0$.

The expected number of moves for the third and fourth test cases are $\frac{56}{3}$ and $\frac{125}{3}$ respectively.



#### Tags 

#2100 #NOT OK #combinatorics #dp #math #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_848_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
