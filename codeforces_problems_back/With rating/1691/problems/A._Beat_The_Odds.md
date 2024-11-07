<h1 style='text-align: center;'> A. Beat The Odds</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a sequence $a_1, a_2, \ldots, a_n$, find the minimum number of elements to remove from the sequence such that after the removal, the sum of every $2$ consecutive elements is even.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2,\dots,a_n$ ($1\leq a_i\leq10^9$) — elements of the sequence.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, print a single integer — the minimum number of elements to remove from the sequence such that the sum of every $2$ consecutive elements is even.

## Example

## Input


```

252 4 3 6 863 5 9 7 1 3
```
## Output


```

1
0

```
## Note

In the first test case, after removing $3$, the sequence becomes $[2,4,6,8]$. The pairs of consecutive elements are $\{[2, 4], [4, 6], [6, 8]\}$. Each consecutive pair has an even sum now. Hence, we only need to remove $1$ element to satisfy the condition asked.

In the second test case, each consecutive pair already has an even sum so we need not remove any element.



#### tags 

#800 #brute_force #greedy #math 