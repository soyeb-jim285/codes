<h1 style='text-align: center;'> C. Basil's Garden</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ flowers in a row, the $i$-th of them initially has a positive height of $h_i$ meters.

Every second, the wind will blow from the left, causing the height of some flowers to decrease.

Specifically, every second, for each $i$ from $1$ to $n$, in this order, the following happens: 

* If $i = n$ or $h_i > h_{i + 1}$, the value of $h_i$ changes to $\max(0, h_i - 1)$.

How many seconds will pass before $h_i=0$ for all $1 \le i \le n$ for the first time?

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the number of flowers.

The second line of each test case contains $n$ integers $h_1, h_2, \ldots, h_n$ ($1 \le h_i \le 10 ^ 9$) — the heights of the flowers.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single integer — the number of seconds that will pass before $h_i=0$ for all $1 \le i \le n$. 

## Example

## Input


```

431 1 223 11957 4 4 3 2
```
## Output


```

4
3
9
7

```
## Note

In the first test case, the flower heights change as follows: $[1, 1, 2] \rightarrow [1, 1, 1] \rightarrow [1, 1, 0] \rightarrow [1, 0, 0] \rightarrow [0, 0, 0]$.

In the second test case, the flower heights change as follows: $[3, 1] \rightarrow [2, 0] \rightarrow [1, 0] \rightarrow [0, 0]$.



#### tags 

#1200 #dp #greedy 