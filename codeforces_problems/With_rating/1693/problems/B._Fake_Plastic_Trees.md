<h1 style='text-align: center;'> B. Fake Plastic Trees</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We are given a rooted tree consisting of $n$ vertices numbered from $1$ to $n$. The root of the tree is the vertex $1$ and the parent of the vertex $v$ is $p_v$.

There is a number written on each vertex, initially all numbers are equal to $0$. Let's denote the number written on the vertex $v$ as $a_v$.

For each $v$, we want $a_v$ to be between $l_v$ and $r_v$ $(l_v \leq a_v \leq r_v)$.

In a single operation we do the following: 

* Choose some vertex $v$. Let $b_1, b_2, \ldots, b_k$ be vertices on the path from the vertex $1$ to vertex $v$ (meaning $b_1 = 1$, $b_k = v$ and $b_i = p_{b_{i + 1}}$).
* Choose a non-decreasing array $c$ of length $k$ of nonnegative integers: $0 \leq c_1 \leq c_2 \leq \ldots \leq c_k$.
* For each $i$ $(1 \leq i \leq k)$, increase $a_{b_i}$ by $c_i$.

What's the minimum number of operations needed to achieve our goal?

### Input

The first line contains an integer $t$ $(1\le t\le 1000)$  — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ $(2\le n\le 2 \cdot 10^5)$  — the number of the vertices in the tree.

The second line of each test case contains $n - 1$ integers, $p_2, p_3, \ldots, p_n$ $(1 \leq p_i < i)$, where $p_i$ denotes the parent of the vertex $i$.

The $i$-th of the following $n$ lines contains two integers $l_i$ and $r_i$ $(1 \le l_i \le r_i \le 10^9)$.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case output the minimum number of operations needed.

## Example

### Input


```text
4211 52 931 14 52 46 1041 2 16 95 64 52 451 2 3 45 54 43 32 21 1
```
### Output

```text

1
2
2
5

```
## Note

In the first test case, we can achieve the goal with a single operation: choose $v = 2$ and $c = [1, 2]$, resulting in $a_1 = 1, a_2 = 2$.

In the second test case, we can achieve the goal with two operations: first, choose $v = 2$ and $c = [3, 3]$, resulting in $a_1 = 3, a_2 = 3, a_3 = 0$. Then, choose $v = 3, c = [2, 7]$, resulting in $a_1 = 5, a_2 = 3, a_3 = 7$.



#### Tags 

#1700 #NOT OK #dfs_and_similar #dp #greedy #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_800_(Div._1).md)
- [Codeforces Round #800 (en)](../blogs/Codeforces_Round_800_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
