<h1 style='text-align: center;'> D. Lucky Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation$^\dagger$ $p$ of length $n$.

In one operation, you can choose two indices $1 \le i < j \le n$ and swap $p_i$ with $p_j$.

Find the minimum number of operations needed to have exactly one inversion$^\ddagger$ in the permutation.

$^\dagger$ A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

$^\ddagger$ The number of inversions of a permutation $p$ is the number of pairs of indices $(i, j)$ such that $1 \le i < j \le n$ and $p_i > p_j$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $p_1,p_2,\ldots, p_n$ ($1 \le p_i \le n$). It is guaranteed that $p$ is a permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case output a single integer — the minimum number of operations needed to have exactly one inversion in the permutation. It can be proven that an answer always exists.

## Example

### Input


```text
422 121 243 4 1 242 4 3 1
```
### Output

```text

0
1
3
1

```
## Note

In the first test case, the permutation already satisfies the condition.

In the second test case, you can perform the operation with $(i,j)=(1,2)$, after that the permutation will be $[2,1]$ which has exactly one inversion.

In the third test case, it is not possible to satisfy the condition with less than $3$ operations. However, if we perform $3$ operations with $(i,j)$ being $(1,3)$,$(2,4)$, and $(3,4)$ in that order, the final permutation will be $[1, 2, 4, 3]$ which has exactly one inversion.

In the fourth test case, you can perform the operation with $(i,j)=(2,4)$, after that the permutation will be $[2,1,3,4]$ which has exactly one inversion.



#### Tags 

#1800 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_842_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
