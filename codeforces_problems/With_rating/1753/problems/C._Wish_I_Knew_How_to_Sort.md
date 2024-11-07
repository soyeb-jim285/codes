<h1 style='text-align: center;'> C. Wish I Knew How to Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary array $a$ (all elements of the array are $0$ or $1$) of length $n$. You wish to sort this array, but unfortunately, your algorithms teacher forgot to teach you sorting algorithms. You perform the following operations until $a$ is sorted:

1. Choose two random indices $i$ and $j$ such that $i < j$. Indices are chosen equally probable among all pairs of indices $(i, j)$ such that $1 \le i < j \le n$.
2. If $a_i > a_j$, then swap elements $a_i$ and $a_j$.

What is the [expected number](https://en.wikipedia.org/wiki/Expected_value) of such operations you will perform before the array becomes sorted?

It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{998\,244\,353}$. 
### Output

 the integer equal to $p \cdot q^{-1} \bmod 998\,244\,353$. In other words, output such an integer $x$ that $0 \le x < 998\,244\,353$ and $x \cdot q \equiv p \pmod{998\,244\,353}$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 200\,000$) — the number of elements in the binary array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($a_i \in \{0, 1\}$) — elements of the array.

It's guaranteed that sum of $n$ over all test cases does not exceed $200\,000$.

### Output

For each test case print one integer — the value $p \cdot q^{-1} \bmod 998\,244\,353$.

## Example

### Input


```text
330 1 050 0 1 1 161 1 1 0 0 1
```
### Output

```text

3
0
249561107

```
## Note

Consider the first test case. If the pair of indices $(2, 3)$ will be chosen, these elements will be swapped and array will become sorted. Otherwise, if one of pairs $(1, 2)$ or $(1, 3)$ will be selected, nothing will happen. So, the probability that the array will become sorted after one operation is $\frac{1}{3}$, the probability that the array will become sorted after two operations is $\frac{2}{3} \cdot \frac{1}{3}$, the probability that the array will become sorted after three operations is $\frac{2}{3} \cdot \frac{2}{3} \cdot \frac{1}{3}$ and so on. The expected number of operations is $\sum \limits_{i=1}^{\infty} \left(\frac{2}{3} \right)^{i - 1} \cdot \frac{1}{3} \cdot i = 3$.

In the second test case the array is already sorted so the expected number of operations is zero.

In the third test case the expected number of operations equals to $\frac{75}{4}$ so the answer is $75 \cdot 4^{-1} \equiv 249\,561\,107 \pmod {998\,244\,353}$.



#### Tags 

#2000 #NOT OK #dp #math #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_829_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
