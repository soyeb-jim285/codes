<h1 style='text-align: center;'> D. Cyclic Rotation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an array $a$ of length $n$. You may perform the following operation any number of times:

* Choose two indices $l$ and $r$ where $1 \le l < r \le n$ and $a_l = a_r$. Then, set $a[l \ldots r] = [a_{l+1}, a_{l+2}, \ldots, a_r, a_l]$.

You are also given another array $b$ of length $n$ which is a permutation of $a$. Determine whether it is possible to transform array $a$ into an array $b$ using the above operation some number of times.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 2 \cdot 10 ^ 5$)  — the length of array $a$ and $b$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$)  — elements of the array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le n$)  — elements of the array $b$.

It is guaranteed that $b$ is a permutation of $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$

## Output

For each test case, print "YES" (without quotes) if it is possible to transform array $a$ to $b$, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

551 2 3 3 21 3 3 2 251 2 4 2 14 2 2 1 152 4 5 5 22 2 4 5 531 2 31 2 331 1 22 1 1
```
## Output


```

YES
YES
NO
YES
NO

```
## Note

In the first test case, we can choose $l=2$ and $r=5$ to form $[1, 3, 3, 2, 2]$.

In the second test case, we can choose $l=2$ and $r=4$ to form $[1, 4, 2, 2, 1]$. Then, we can choose $l=1$ and $r=5$ to form $[4, 2, 2, 1, 1]$.

In the third test case, it can be proven that it is not possible to transform array $a$ to $b$ using the operation.



#### tags 

#1700 #constructive_algorithms #greedy #implementation #two_pointers 