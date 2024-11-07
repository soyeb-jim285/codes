<h1 style='text-align: center;'> F. I Might Be Wrong</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $S$ of length $n$ indexed from $1$ to $n$. You can perform the following operation any number of times (possibly zero):

* Choose two integers $l$ and $r$ ($1 \le l \le r \le n$). Let $cnt_0$ be the number of times 0 occurs in $S[l \ldots r]$ and $cnt_1$ be the number of times 1 occurs in $S[l \ldots r]$. You can pay $|cnt_0 - cnt_1| + 1$ coins and sort the $S[l \ldots r]$. (by $S[l \ldots r]$ we mean the substring of $S$ starting at position $l$ and ending at position $r$)

For example if $S = $ 11001, we can perform the operation on $S[2 \ldots 4]$, paying $|2 - 1| + 1 = 2$ coins, and obtain $S = $ 10011 as a new string.

Find the minimum total number of coins required to sort $S$ in increasing order.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the size of $S$.

The second line of each test case contains a binary string $S$ of $n$ characters $S_1S_2 \ldots S_n$. ($S_i = $ 0 or $S_i = $ 1 for each $1 \le i \le n$)

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, output the minimum total number of coins required to sort $S$ in increasing order.

## Example

## Input


```

71121031014100051101061100002001000010001010011000
```
## Output


```

0
1
1
3
2
2
5

```
## Note

In the first test case, $S$ is already sorted.

In the second test case, it's enough to apply the operation with $l = 1, r = 2$.

In the third test case, it's enough to apply the operation with $l = 1, r = 2$.



#### tags 

#3400 #binary_search #greedy #two_pointers 