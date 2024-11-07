<h1 style='text-align: center;'> C. Parity Shuffle Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ with $n$ non-negative integers. You can apply the following operation on it. 

* Choose two indices $l$ and $r$ ($1 \le l < r \le n$).
* If $a_l + a_r$ is odd, do $a_r := a_l$. If $a_l + a_r$ is even, do $a_l := a_r$.

Find any sequence of at most $n$ operations that makes $a$ non-decreasing. It can be proven that it is always possible. 
## Note

 that you do not have to minimize the number of operations.

An array $a_1, a_2, \ldots, a_n$ is non-decreasing if and only if $a_1 \le a_2 \le \ldots \le a_n$.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

Each test case consists of two lines. The first line of each test case contains one integer $n$ ($1 \le n \le 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$)  — the array itself.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $10^5$.

### Output

For each test case, print one integer $m$ ($0 \le m \le n$), the number of operations, in the first line.

Then print $m$ lines. Each line must contain two integers $l_i, r_i$, which are the indices you chose in the $i$-th operation ($1 \le l_i < r_i \le n$).

If there are multiple solutions, print any of them.

## Example

### Input


```text
327 851 1000000000 3 0 510
```
### Output

```text

0
2
3 4
1 2
0

```
## Note

In the second test case, $a$ changes like this:

* Select indices $3$ and $4$. $a_3 + a_4 = 3$ is odd, so do $a_4 := a_3$. $a = [1, 1000000000, 3, 3, 5]$ now.
* Select indices $1$ and $2$. $a_1 + a_2 = 1000000001$ is odd, so do $a_2 := a_1$. $a = [1, 1, 3, 3, 5]$ now, and it is non-decreasing.

In the first and third test cases, $a$ is already non-decreasing.



#### Tags 

#1300 #OK #constructive_algorithms #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_821_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
