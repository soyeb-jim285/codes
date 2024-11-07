<h1 style='text-align: center;'> C. Build Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A $\mathbf{0}$-indexed array $a$ of size $n$ is called good if for all valid indices $i$ ($0 \le i \le n-1$), $a_i + i$ is a perfect square$^\dagger$.

Given an integer $n$. Find a permutation$^\ddagger$ $p$ of $[0,1,2,\ldots,n-1]$ that is good or determine that no such permutation exists.

$^\dagger$ An integer $x$ is said to be a perfect square if there exists an integer $y$ such that $x = y^2$.

$^\ddagger$ An array $b$ is a permutation of an array $a$ if $b$ consists of the elements of $a$ in arbitrary order. For example, $[4,2,3,4]$ is a permutation of $[3,2,4,4]$ while $[1,2,2]$ is not a permutation of $[1,2,3]$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output $n$ distinct integers $p_0, p_1, \dots, p_{n-1}$ ($0 \le p_i \le n-1$) — the permutation $p$ — if the answer exists, and $-1$ otherwise.

## Example

### Input


```text
3347
```
### Output

```text

1 0 2 
0 3 2 1 
1 0 2 6 5 4 3 

```
## Note

In the first test case, we have $n=3$. The array $p = [1, 0, 2]$ is good since $1 + 0 = 1^2$, $0 + 1 = 1^2$, and $2 + 2 = 2^2$

In the second test case, we have $n=4$. The array $p = [0, 3, 2, 1]$ is good since $0 + 0 = 0^2$, $3 + 1 = 2^2$, $2+2 = 2^2$, and $1+3 = 2^2$.



#### Tags 

#1200 #OK #constructive_algorithms #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_812_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
