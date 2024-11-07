<h1 style='text-align: center;'> B. Koxia and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Reve has two integers $n$ and $k$.

Let $p$ be a permutation$^\dagger$ of length $n$. Let $c$ be an array of length $n - k + 1$ such that $$c_i = \max(p_i, \dots, p_{i+k-1}) + \min(p_i, \dots, p_{i+k-1}).$$ Let the cost of the permutation $p$ be the maximum element of $c$.

Koxia wants you to construct a permutation with the minimum possible cost.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 2 \cdot 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ integers $p_1,p_2,\dots,p_n$, which is a permutation with minimal cost. If there is more than one permutation with minimal cost, you may output any of them.

## Example

### Input


```text
35 35 16 6
```
### Output

```text

5 1 2 3 4
1 2 3 4 5
3 2 4 1 6 5

```
## Note

In the first test case,

* $c_1 = \max(p_1,p_2,p_3) + \min(p_1,p_2,p_3) = 5 + 1 = 6$.
* $c_2 = \max(p_2,p_3,p_4) + \min(p_2,p_3,p_4) = 3 + 1 = 4$.
* $c_3 = \max(p_3,p_4,p_5) + \min(p_3,p_4,p_5) = 4 + 2 = 6$.

Therefore, the cost is $\max(6,4,6)=6$. It can be proven that this is the minimal cost.



#### Tags 

#1000 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Good_Bye_2022:_2023_is_NEAR.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
