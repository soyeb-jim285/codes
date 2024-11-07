<h1 style='text-align: center;'> C. Manhattan Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call the Manhattan value of a permutation$^{\dagger}$ $p$ the value of the expression $|p_1 - 1| + |p_2 - 2| + \ldots + |p_n - n|$.

For example, for the permutation $[1, 2, 3]$, the Manhattan value is $|1 - 1| + |2 - 2| + |3 - 3| = 0$, and for the permutation $[3, 1, 2]$, the Manhattan value is $|3 - 1| + |1 - 2| + |2 - 3| = 2 + 1 + 1 = 4$.

You are given integers $n$ and $k$. Find a permutation $p$ of length $n$ such that its Manhattan value is equal to $k$, or determine that no such permutation exists.

$^{\dagger}$A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^{4}$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^{5}, 0 \le k \le 10^{12}$) — the length of the permutation and the required Manhattan value.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^{5}$.

### Output

For each test case, if there is no suitable permutation, output "No". Otherwise, in the first line, output "Yes", and in the second line, output $n$ distinct integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — a suitable permutation.

If there are multiple solutions, output any of them.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

### Input


```text
83 44 57 01 10000000000008 14112 7775 125 2
```
### Output

```text

Yes
3 1 2
No
Yes
1 2 3 4 5 6 7
No
Yes
8 2 3 4 5 6 1 7
No
Yes
5 4 3 1 2
Yes
2 1 3 4 5

```
## Note

In the first test case, the permutation $[3, 1, 2]$ is suitable, its Manhattan value is $|3 - 1| + |1 - 2| + |2 - 3| = 2 + 1 + 1 = 4$.

In the second test case, it can be proven that there is no permutation of length $4$ with a Manhattan value of $5$.

In the third test case, the permutation $[1,2,3,4,5,6,7]$ is suitable, its Manhattan value is $|1-1|+|2-2|+|3-3|+|4-4|+|5-5|+|6-6|+|7-7|=0$.



#### Tags 

#1300 #NOT OK #constructive_algorithms #data_structures #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_953_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
