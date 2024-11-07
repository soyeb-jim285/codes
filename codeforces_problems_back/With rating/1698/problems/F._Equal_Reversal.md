<h1 style='text-align: center;'> F. Equal Reversal</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an array $a$ of length $n$. You may perform the following operation on it:

* Choose two indices $l$ and $r$ where $1 \le l \le r \le n$ and $a_l = a_r$. Then, reverse the subsegment from the $l$-th to the $r$-th element, i. e. set $[a_l, a_{l + 1}, \ldots, a_{r - 1}, a_r]$ to $[a_r, a_{r-1}, \ldots, a_{l+1}, a_l]$.

You are also given another array $b$ of length $n$ which is a permutation of $a$. Find a sequence of at most $n^2$ operations that transforms array $a$ into $b$, or report that no such sequence exists.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 500$) — the length of array $a$ and $b$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — elements of the array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le n$) — elements of the array $b$.

It is guaranteed that $b$ is a permutation of $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $500$.

## Output

For each test case, output "NO" (without quotes) if it is impossible to turn $a$ into $b$ using at most $n^2$ operations.

Otherwise, output "YES" (without quotes). Then output an integer $k$ ($0 \leq k \leq n^2$) denoting the number of operations you will perform. ## Note

 that you don't have to minimize the number of operations.

Afterwards, output $k$ lines. The $i$-th line should contain two integers $l_i$ and $r_i$ ($1 \leq l_i \leq r_i \leq n$) — the left and right indices for the $i$-th operation.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

If there are multiple possible sequences of operations, you may output any of them.

## Example

## Input


```

581 2 4 3 1 2 1 11 1 3 4 2 1 2 171 2 3 1 3 2 31 3 2 3 1 2 331 1 21 2 121 22 1111
```
## Output


```

YES
2
5 8
1 6
YES
2
1 4
3 6
NO
NO
YES
0

```
## Note

In the first test case, we can perform the following operations: $$[1,2,4,3,1,2,1,1] \xrightarrow[l=5,\,r=8]{} [1,2,4,3,1,1,2,1] \xrightarrow[l=1,\,r=6]{} [1,1,3,4,2,1,2,1].$$

In the second test case, we can perform the following operations: $$[1,2,3,1,3,2,3] \xrightarrow[l=1,\,r=4]{} [1,3,2,1,3,2,3] \xrightarrow[l=3,\,r=6]{} [1,3,2,3,1,2,3].$$

It can be proven that it is impossible to turn $a$ into $b$ in the third and fourth test cases.



#### tags 

#2800 #constructive_algorithms #graphs #implementation #math 