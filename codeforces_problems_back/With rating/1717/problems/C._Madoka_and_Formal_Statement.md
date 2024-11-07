<h1 style='text-align: center;'> C. Madoka and Formal Statement</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array of integer $a_1, a_2, \ldots, a_n$. In one operation you can make $a_i := a_i + 1$ if $i < n$ and $a_i \leq a_{i + 1}$, or $i = n$ and $a_i \leq a_1$.

You need to check whether the array $a_1, a_2, \ldots, a_n$ can become equal to the array $b_1, b_2, \ldots, b_n$ in some number of operations (possibly, zero). Two arrays $a$ and $b$ of length $n$ are called equal if $a_i = b_i$ for all integers $i$ from $1$ to $n$.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 4 \cdot 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) – the length of the array.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^9$) – the elements of the array $a$.

The third line of each test case contains $n$ integers $b_1, \ldots, b_n$ ($1 \le b_i \le 10^9$) – the elements of the array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if you can get the array $b$, otherwise output "NO".

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

## Example

## Input


```

531 2 51 2 522 21 343 4 1 26 4 2 532 4 14 5 351 2 3 4 56 5 6 7 6
```
## Output


```

YES
NO
NO
NO
YES

```
## Note

In the first test case, the array $a$ is already equal to the array $b$.

In the second test case, we can't get the array $b$, because to do this we need to decrease $a_1$.

In the fifth test case, we can apply operations in order to the elements with indices $4, 3, 3,2,2,2,1,1,1,1$, and then get the array $[5,5,5,5,5]$. After that, you can apply operations in order to elements with indices $5,4,4,3,1$ and already get an array $[6,5,6,7,6]$.



#### tags 

#1300 #greedy 