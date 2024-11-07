<h1 style='text-align: center;'> B. Milena and Admirer</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Milena has received an array of integers $a_1, a_2, \ldots, a_n$ of length $n$ from a secret admirer. She thinks that making it non-decreasing should help her identify the secret admirer.

She can use the following operation to make this array non-decreasing:

* Select an element $a_i$ of array $a$ and an integer $x$ such that $1 \le x < a_i$. Then, replace $a_i$ by two elements $x$ and $a_i - x$ in array $a$. New elements ($x$ and $a_i - x$) are placed in the array $a$ in this order instead of $a_i$.More formally, let $a_1, a_2, \ldots, a_i, \ldots, a_k$ be an array $a$ before the operation. After the operation, it becomes equal to $a_1, a_2, \ldots, a_{i-1}, x, a_i - x, a_{i+1}, \ldots, a_k$. 
## Note

 that the length of $a$ increases by $1$ on each operation.

Milena can perform this operation multiple times (possibly zero). She wants you to determine the minimum number of times she should perform this operation to make array $a$ non-decreasing.

An array $x_1, x_2, \ldots, x_k$ of length $k$ is called non-decreasing if $x_i \le x_{i+1}$ for all $1 \le i < k$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10\,000$). The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1\leq n\leq 2\cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1\leq a_i\leq 10^9$) – the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output one integer — the minimum number of operations required to make the array non-decreasing.

It can be shown that it is always possible to make the array $a$ non-decreasing in the finite number of operations.

## Example

### Input


```text
431 3 241 2 3 433 2 171 4 4 3 5 7 6
```
### Output

```text

1
0
3
9

```
## Note

In the first test case, Milena can replace the second element of array $a$ by integers $1$ and $2$, so the array would become $[\, 1, \, \underline{1}, \, \underline{2}, \, 2 \,]$. Only $1$ operation is required.

In the second test case, the array $a$ is already non-decreasing, so the answer is $0$.

In the third test case, Milena can make array $a$ non-decreasing in $3$ operations as follows. 

* Select $i=1$ and $x=2$ and replace $a_1$ by $2$ and $1$. The array $a$ becomes equal to $[\, \underline{2}, \, \underline{1}, \, 2, \, 1 \, ]$.
* Select $i=3$ and $x=1$ and replace $a_3$ by $1$ and $1$. The array $a$ becomes equal to $[\, 2, \, 1, \, \underline{1}, \, \underline{1}, \, 1 \,]$.
* Select $i=1$ and $x=1$ and replace $a_1$ by $2$ and $1$. The array $a$ becomes equal to $[\, \underline{1}, \, \underline{1}, \, 1, \, 1, \, 1, \, 1 \,]$.

It can be shown that it is impossible to make it non-decreasing in $2$ or less operations, so the answer is $3$.



#### Tags 

#1500 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_910_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
