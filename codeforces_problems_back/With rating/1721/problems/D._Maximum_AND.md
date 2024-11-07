<h1 style='text-align: center;'> D. Maximum AND</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$, consisting of $n$ integers each.

Let's define a function $f(a, b)$ as follows: 

* let's define an array $c$ of size $n$, where $c_i = a_i \oplus b_i$ ($\oplus$ denotes bitwise XOR);
* the value of the function is $c_1 \mathbin{\\&} c_2 \mathbin{\\&} \cdots \mathbin{\\&} c_n$ (i.e. bitwise AND of the entire array $c$).

Find the maximum value of the function $f(a, b)$ if you can reorder the array $b$ in an arbitrary way (leaving the initial order is also an option).

## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 10^5$) — the size of arrays $a$ and $b$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i < 2^{30}$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($0 \le b_i < 2^{30}$).

The sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case print one integer — the maximum value of the function $f(a, b)$ if you can reorder the array $b$ in an arbitrary way.

## Example

## Input


```

351 0 0 3 32 3 2 1 031 1 10 0 380 1 2 3 4 5 6 77 6 5 4 3 2 1 0
```
## Output


```

2
0
7

```


#### tags 

#1800 #bitmasks #dfs_and_similar #divide_and_conquer #greedy #sortings 