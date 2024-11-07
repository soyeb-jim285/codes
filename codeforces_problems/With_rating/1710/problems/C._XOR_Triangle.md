<h1 style='text-align: center;'> C. XOR Triangle</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a positive integer $n$. Since $n$ may be very large, you are given its binary representation.

You should compute the number of triples $(a,b,c)$ with $0 \leq a,b,c \leq n$ such that $a \oplus b$, $b \oplus c$, and $a \oplus c$ are the sides of a non-degenerate triangle. 

Here, $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

You should output the answer modulo $998\,244\,353$.

Three positive values $x$, $y$, and $z$ are the sides of a non-degenerate triangle if and only if $x+y>z$, $x+z>y$, and $y+z>x$.

##### Input

The first and only line contains the binary representation of an integer $n$ ($0 < n < 2^{200\,000}$) without leading zeros.

For example, the string 10 is the binary representation of the number $2$, while the string 1010 represents the number $10$.

##### Output

Print one integer — the number of triples $(a,b,c)$ satisfying the conditions described in the statement modulo $998\,244\,353$.

## Examples

##### Input


```text
101
```
##### Output

```text

12

```
##### Input


```text
1110
```
##### Output

```text

780

```
##### Input


```text
11011111101010010
```
##### Output

```text

141427753

```
## Note

In the first test case, $101_2=5$.

* The triple $(a, b, c) = (0, 3, 5)$ is valid because $(a\oplus b, b\oplus c, c\oplus a) = (3, 6, 5)$ are the sides of a non-degenerate triangle.
* The triple $(a, b, c) = (1, 2, 4)$ is valid because $(a\oplus b, b\oplus c, c\oplus a) = (3, 6, 5)$ are the sides of a non-degenerate triangle.

The $6$ permutations of each of these two triples are all the valid triples, thus the answer is $12$.

In the third test case, $11\,011\,111\,101\,010\,010_2=114\,514$. The full answer (before taking the modulo) is $1\,466\,408\,118\,808\,164$.



#### Tags 

#2500 #NOT OK #bitmasks #brute_force #constructive_algorithms #dp #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_810_(Div._1).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [Codeforces Round #810 (en)](../blogs/Codeforces_Round_810_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
