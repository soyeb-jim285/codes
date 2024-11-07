<h1 style='text-align: center;'> B. Missing Subsequence Sum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $k$. Find a sequence $a$ of non-negative integers of size at most $25$ such that the following conditions hold.

* There is no subsequence of $a$ with a sum of $k$.
* For all $1 \le v \le n$ where $v \ne k$, there is a subsequence of $a$ with a sum of $v$.

A sequence $b$ is a subsequence of $a$ if $b$ can be obtained from $a$ by the deletion of several (possibly, zero or all) elements, without changing the order of the remaining elements. For example, $[5, 2, 3]$ is a subsequence of $[1, 5, 7, 8, 2, 4, 3]$.

It can be shown that under the given constraints, a solution always exists.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

Each test case consists of a single line containing two integers $n$ and $k$ ($2 \le n \le 10^6$, $1 \le k \le n$) — the parameters described above. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^7$.

### Output

The first line of output for each test case should contain a single integer $m$ ($1 \le m \le 25$) — the size of your chosen sequence.

The second line of output for each test case should contain $m$ integers $a_i$ ($0 \le a_i \le 10^9$) — the elements of your chosen sequence.

If there are multiple solutions, print any.

## Example

### Input


```text
52 26 18 89 310 7
```
### Output

```text

1
1
5
2 3 4 5 6
7
1 1 1 1 1 1 1
4
7 1 4 1
4
1 2 8 3

```
## Note

In the first example, we just need a subsequence that adds up to $1$, but not one that adds up to $2$. So the array $a=[1]$ suffices.

In the second example, all elements are greater than $k=1$, so no subsequence adds up to $1$. Every other integer between $1$ and $n$ is present in the array, so there is a subsequence of size $1$ adding up to each of those numbers.



#### Tags 

#1800 #NOT OK #bitmasks #constructive_algorithms #greedy #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_941_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
