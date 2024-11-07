<h1 style='text-align: center;'> B. Prefix Sum Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Suppose $a_1, a_2, \dots, a_n$ is a sorted integer sequence of length $n$ such that $a_1 \leq a_2 \leq \dots \leq a_n$. 

For every $1 \leq i \leq n$, the prefix sum $s_i$ of the first $i$ terms $a_1, a_2, \dots, a_i$ is defined by $$ s_i = \sum_{k=1}^i a_k = a_1 + a_2 + \dots + a_i. $$

Now you are given the last $k$ terms of the prefix sums, which are $s_{n-k+1}, \dots, s_{n-1}, s_{n}$. Your task is to determine whether this is possible. 

Formally, given $k$ integers $s_{n-k+1}, \dots, s_{n-1}, s_{n}$, the task is to check whether there is a sequence $a_1, a_2, \dots, a_n$ such that 

1. $a_1 \leq a_2 \leq \dots \leq a_n$, and
2. $s_i = a_1 + a_2 + \dots + a_i$ for all $n-k+1 \leq i \leq n$.
### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains two integers $n$ ($1 \leq n \leq 10^5$) and $k$ ($1 \leq k \leq n$), indicating the length of the sequence $a$ and the number of terms of prefix sums, respectively.

The second line of each test case contains $k$ integers $s_{n-k+1}, \dots, s_{n-1}, s_{n}$ ($-10^9 \leq s_i \leq 10^9$ for every $n-k+1 \leq i \leq n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output "YES" (without quotes) if it is possible and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

### Input


```text
45 51 2 3 4 57 4-6 -5 -3 03 32 3 43 23 4
```
### Output

```text

Yes
Yes
No
No

```
## Note

In the first test case, we have the only sequence $a = [1, 1, 1, 1, 1]$.

In the second test case, we can choose, for example, $a = [-3, -2, -1, 0, 1, 2, 3]$.

In the third test case, the prefix sums define the only sequence $a = [2, 1, 1]$, but it is not sorted. 

In the fourth test case, it can be shown that there is no sequence with the given prefix sums.



#### Tags 

#1200 #OK #constructive_algorithms #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_22.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
