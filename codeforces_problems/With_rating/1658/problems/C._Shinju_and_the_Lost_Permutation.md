<h1 style='text-align: center;'> C. Shinju and the Lost Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Shinju loves permutations very much! Today, she has borrowed a permutation $p$ from Juju to play with.

The $i$-th cyclic shift of a permutation $p$ is a transformation on the permutation such that $p = [p_1, p_2, \ldots, p_n] $ will now become $ p = [p_{n-i+1}, \ldots, p_n, p_1,p_2, \ldots, p_{n-i}]$.

Let's define the power of permutation $p$ as the number of distinct elements in the prefix maximums array $b$ of the permutation. The prefix maximums array $b$ is the array of length $n$ such that $b_i = \max(p_1, p_2, \ldots, p_i)$. For example, the power of $[1, 2, 5, 4, 6, 3]$ is $4$ since $b=[1,2,5,5,6,6]$ and there are $4$ distinct elements in $b$.

Unfortunately, Shinju has lost the permutation $p$! The only information she remembers is an array $c$, where $c_i$ is the power of the $(i-1)$-th cyclic shift of the permutation $p$. She's also not confident that she remembers it correctly, so she wants to know if her memory is good enough.

Given the array $c$, determine if there exists a permutation $p$ that is consistent with $c$. You do not have to construct the permutation $p$.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3, 4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 5 \cdot 10^3$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $c_1,c_2,\ldots,c_n$ ($1 \leq c_i \leq n$). 

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print "YES" if there is a permutation $p$ exists that satisfies the array $c$, and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

## Example

### Input


```text
61121 222 261 2 4 6 3 562 3 1 2 3 433 2 1
```
### Output

```text

YES
YES
NO
NO
YES
NO

```
## Note

In the first test case, the permutation $[1]$ satisfies the array $c$.

In the second test case, the permutation $[2,1]$ satisfies the array $c$.

In the fifth test case, the permutation $[5, 1, 2, 4, 6, 3]$ satisfies the array $c$. Let's see why this is true.

* The zeroth cyclic shift of $p$ is $[5, 1, 2, 4, 6, 3]$. Its power is $2$ since $b = [5, 5, 5, 5, 6, 6]$ and there are $2$ distinct elements — $5$ and $6$.
* The first cyclic shift of $p$ is $[3, 5, 1, 2, 4, 6]$. Its power is $3$ since $b=[3,5,5,5,5,6]$.
* The second cyclic shift of $p$ is $[6, 3, 5, 1, 2, 4]$. Its power is $1$ since $b=[6,6,6,6,6,6]$.
* The third cyclic shift of $p$ is $[4, 6, 3, 5, 1, 2]$. Its power is $2$ since $b=[4,6,6,6,6,6]$.
* The fourth cyclic shift of $p$ is $[2, 4, 6, 3, 5, 1]$. Its power is $3$ since $b = [2, 4, 6, 6, 6, 6]$.
* The fifth cyclic shift of $p$ is $[1, 2, 4, 6, 3, 5]$. Its power is $4$ since $b = [1, 2, 4, 6, 6, 6]$.

Therefore, $c = [2, 3, 1, 2, 3, 4]$.

In the third, fourth, and sixth testcases, we can show that there is no permutation that satisfies array $c$.



#### Tags 

#1700 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_779_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
