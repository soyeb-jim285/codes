<h1 style='text-align: center;'> D. Coprime</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array of $n$ positive integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 1000$). Find the maximum value of $i + j$ such that $a_i$ and $a_j$ are coprime,$^{\dagger}$ or $-1$ if no such $i$, $j$ exist.

For example consider the array $[1, 3, 5, 2, 4, 7, 7]$. The maximum value of $i + j$ that can be obtained is $5 + 7$, since $a_5 = 4$ and $a_7 = 7$ are coprime.

$^{\dagger}$ Two integers $p$ and $q$ are [coprime](https://en.wikipedia.org/wiki/Coprime_integers) if the only positive integer that is a divisor of both of them is $1$ (that is, their [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) is $1$).

### Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2\cdot10^5$) — the length of the array.

The following line contains $n$ space-separated positive integers $a_1$, $a_2$,..., $a_n$ ($1 \leq a_i \leq 1000$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$.

### Output

For each test case, output a single integer  — the maximum value of $i + j$ such that $i$ and $j$ satisfy the condition that $a_i$ and $a_j$ are coprime, or output $-1$ in case no $i$, $j$ satisfy the condition.

## Example

### Input


```text
633 2 171 3 5 2 4 7 751 2 3 4 532 2 465 4 3 15 12 1651 2 2 3 6
```
### Output

```text

6
12
9
-1
10
7

```
## Note

For the first test case, we can choose $i = j = 3$, with sum of indices equal to $6$, since $1$ and $1$ are coprime.

For the second test case, we can choose $i = 7$ and $j = 5$, with sum of indices equal to $7 + 5 = 12$, since $7$ and $4$ are coprime.



#### Tags 

#1100 #OK #brute_force #greedy #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_827_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
