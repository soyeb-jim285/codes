<h1 style='text-align: center;'> D. Serval and Shift-Shift-Shift</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Serval has two $n$-bit binary integer numbers $a$ and $b$. He wants to share those numbers with Toxel.

Since Toxel likes the number $b$ more, Serval decides to change $a$ into $b$ by some (possibly zero) operations. In an operation, Serval can choose any positive integer $k$ between $1$ and $n$, and change $a$ into one of the following number:

* $a\oplus(a\ll k)$
* $a\oplus(a\gg k)$

In other words, the operation moves every bit of $a$ left or right by $k$ positions, where the overflowed bits are removed, and the missing bits are padded with $0$. The bitwise XOR of the shift result and the original $a$ is assigned back to $a$.

Serval does not have much time. He wants to perform no more than $n$ operations to change $a$ into $b$. Please help him to find out an operation sequence, or determine that it is impossible to change $a$ into $b$ in at most $n$ operations. You do not need to minimize the number of operations. 

In this problem, $x\oplus y$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of $x$ and $y$. $a\ll k$ and $a\gg k$ denote the [logical left shift](https://en.wikipedia.org/wiki/Logical_shift) and [logical right shift](https://en.wikipedia.org/wiki/Logical_shift).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le2\cdot10^{3}$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le2\cdot10^{3}$) — the number of bits in numbers $a$ and $b$.

The second and the third line of each test case contain a binary string of length $n$, representing $a$ and $b$, respectively. The strings contain only characters 0 and 1.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^{3}$.

### Output

For each test case, if it is impossible to change $a$ into $b$ in at most $n$ operations, print a single integer $-1$.

Otherwise, in the first line, print the number of operations $m$ ($0\le m\le n$).

If $m>0$, in the second line, print $m$ integers $k_{1},k_{2},\dots,k_{m}$ representing the operations. If $1\le k_{i}\le n$, it means logical left shift $a$ by $k_{i}$ positions. If $-n\le k_{i}\le-1$, it means logical right shift $a$ by $-k_{i}$ positions.

If there are multiple solutions, print any of them.

## Example

### Input


```text
3500111110001113001000
```
### Output

```text

2
3 -2
0
-1
```
## Note

In the first test case:

The first operation changes $a$ into $\require{cancel}00111\oplus\cancel{001}11\underline{000}=11111$.

The second operation changes $a$ into $\require{cancel}11111\oplus\underline{00}111\cancel{11}=11000$.

The bits with strikethroughs are overflowed bits that are removed. The bits with underline are padded bits.

In the second test case, $a$ is already equal to $b$, so no operations are needed.

In the third test case, it can be shown that $a$ cannot be changed into $b$.



#### Tags 

#2200 #NOT OK #bitmasks #brute_force #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_853_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
