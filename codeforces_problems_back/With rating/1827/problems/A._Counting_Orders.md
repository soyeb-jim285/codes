<h1 style='text-align: center;'> A. Counting Orders</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$ each consisting of $n$ integers. All elements of $a$ are pairwise distinct.

Find the number of ways to reorder $a$ such that $a_i > b_i$ for all $1 \le i \le n$, modulo $10^9 + 7$.

Two ways of reordering are considered different if the resulting arrays are different.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^{5}$) — the length of the array $a$ and $b$.

The second line of each test case contains $n$ distinct integers $a_1$, $a_2$, $\ldots$, $a_n$ ($1 \le a_i \le 10^9$) — the array $a$. It is guaranteed that all elements of $a$ are pairwise distinct.

The second line of each test case contains $n$ integers $b_1$, $b_2$, $\ldots$, $b_n$ ($1 \le b_i \le 10^9$) — the array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^{5}$.

## Output

For each test case, output the number of ways to reorder array $a$ such that $a_i > b_i$ for all $1 \le i \le n$, modulo $10^9 + 7$.

## Example

## Input


```

569 6 8 4 5 24 1 5 6 3 134 3 23 4 912132 3 41 3 3122 3 7 10 23 28 29 50 69 135 420 10001 1 2 3 5 8 13 21 34 55 89 144
```
## Output


```

32
0
1
0
13824

```


#### tags 

#1100 #combinatorics #math #sortings #two_pointers 