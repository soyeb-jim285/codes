<h1 style='text-align: center;'> F. Jellyfish and OEIS</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Jellyfish always uses OEIS to solve math problems, but now she finds a problem that cannot be solved by OEIS:

Count the number of permutations $p$ of $[1, 2, \dots, n]$ such that for all $(l, r)$ such that $l \leq r \leq m_l$, the subarray $[p_l, p_{l+1}, \dots, p_r]$ is not a permutation of $[l, l+1, \dots, r]$.

Since the answer may be large, you only need to find the answer modulo $10^9+7$.

##### Input

The first line of the input contains a single integer $n$ ($1 \leq n \leq 200$) — the length of the permutation.

The second line of the input contains $n$ integers $m_1, m_2, \dots, m_n$ ($0 \leq m_i \leq n$).

##### Output

##### Output

 the number of different permutations that satisfy the conditions, modulo $10^9+7$.

## Examples

##### Input


```text
3
1 2 3
```
##### Output


```text
2
```
##### Input

```text

5
2 4 3 4 5

```
##### Output


```text
38
```
##### Input

```text

5
5 1 1 1 1

```
##### Output


```text

0
```
## Note

In the first example, $[2, 3, 1]$ and $[3, 1, 2]$ satisfies the condition.



#### Tags 

#3500 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_901_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
