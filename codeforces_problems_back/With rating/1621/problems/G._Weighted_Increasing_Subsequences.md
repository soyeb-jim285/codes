<h1 style='text-align: center;'> G. Weighted Increasing Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given the sequence of integers $a_1, a_2, \ldots, a_n$ of length $n$. 

The sequence of indices $i_1 < i_2 < \ldots < i_k$ of length $k$ denotes the subsequence $a_{i_1}, a_{i_2}, \ldots, a_{i_k}$ of length $k$ of sequence $a$.

The subsequence $a_{i_1}, a_{i_2}, \ldots, a_{i_k}$ of length $k$ of sequence $a$ is called increasing subsequence if $a_{i_j} < a_{i_{j+1}}$ for each $1 \leq j < k$.

The weight of the increasing subsequence $a_{i_1}, a_{i_2}, \ldots, a_{i_k}$ of length $k$ of sequence $a$ is the number of $1 \leq j \leq k$, such that exists index $i_k < x \leq n$ and $a_x > a_{i_j}$.

For example, if $a = [6, 4, 8, 6, 5]$, then the sequence of indices $i = [2, 4]$ denotes increasing subsequence $[4, 6]$ of sequence $a$. The weight of this increasing subsequence is $1$, because for $j = 1$ exists $x = 5$ and $a_5 = 5 > a_{i_1} = 4$, but for $j = 2$ such $x$ doesn't exist.

Find the sum of weights of all increasing subsequences of $a$ modulo $10^9+7$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains the single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the sequence $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the sequence $a$.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print the sum of weights of all increasing subsequences $a$ modulo $10^9+7$.

## Example

## Input


```

456 4 8 6 541 2 3 433 2 244 5 6 5
```
## Output


```

4
12
0
6

```
## Note

In the first test case the following increasing subsequences of $a$ have not zero weight: 

* The weight of $[a_1] = [6]$ is $1$.
* The weight of $[a_2] = [4]$ is $1$.
* The weight of $[a_2, a_3] = [4, 8]$ is $1$.
* The weight of $[a_2, a_4] = [4, 6]$ is $1$.

 The sum of weights of increasing subsequences is $4$.In the second test case there are $7$ increasing subsequences of $a$ with not zero weight: $3$ with weight $1$, $3$ with weight $2$ and $1$ with weight $3$. The sum of weights is $12$.



#### tags 

#3200 #data_structures #dp #math 