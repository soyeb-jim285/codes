<h1 style='text-align: center;'> A. Shuffle Party</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$. Initially, $a_i=i$ for each $1 \le i \le n$.

The operation $\texttt{swap}(k)$ for an integer $k \ge 2$ is defined as follows: 

* Let $d$ be the largest divisor$^\dagger$ of $k$ which is not equal to $k$ itself. Then swap the elements $a_d$ and $a_k$.

Suppose you perform $\texttt{swap}(i)$ for each $i=2,3,\ldots, n$ in this exact order. Find the position of $1$ in the resulting array. In other words, find such $j$ that $a_j = 1$ after performing these operations.

$^\dagger$ An integer $x$ is a divisor of $y$ if there exists an integer $z$ such that $y = x \cdot z$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The only line of each test case contains one integer $n$ ($1 \le n \le 10^9$) — the length of the array $a$.

### Output

For each test case, output the position of $1$ in the resulting array.

## Example

### Input


```text
4145120240229
```
### Output

```text

1
4
4
67108864

```
## Note

In the first test case, the array is $[1]$ and there are no operations performed.

In the second test case, $a$ changes as follows:

* Initially, $a$ is $[1,2,3,4]$.
* After performing $\texttt{swap}(2)$, $a$ changes to $[\underline{2},\underline{1},3,4]$ (the elements being swapped are underlined).
* After performing $\texttt{swap}(3)$, $a$ changes to $[\underline{3},1,\underline{2},4]$.
* After performing $\texttt{swap}(4)$, $a$ changes to $[3,\underline{4},2,\underline{1}]$.

Finally, the element $1$ lies on index $4$ (that is, $a_4 = 1$). Thus, the answer is $4$.



#### Tags 

#800 #OK #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_930_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
