<h1 style='text-align: center;'> C. Minimizing the Sum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer array $a$ of length $n$.

You can perform the following operation: choose an element of the array and replace it with any of its neighbor's value.

For example, if $a=[3, 1, 2]$, you can get one of the arrays $[3, 3, 2]$, $[3, 2, 2]$ and $[1, 1, 2]$ using one operation, but not $[2, 1, 2$] or $[3, 4, 2]$. 

Your task is to calculate the minimum possible total sum of the array if you can perform the aforementioned operation at most $k$ times.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 3 \cdot 10^5$; $0 \le k \le 10$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

Additional constraint on the input: the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case, print a single integer — the minimum possible total sum of the array if you can perform the aforementioned operation at most $k$ times.

## Example

## Input


```

43 13 1 21 354 22 2 1 36 34 1 2 2 4 3
```
## Output


```

4
5
5
10

```
## Note

In the first example, one of the possible sequences of operations is the following: $[3, 1, 2] \rightarrow [1, 1, 2$].

In the second example, you do not need to apply the operation.

In the third example, one of the possible sequences of operations is the following: $[2, 2, 1, 3] \rightarrow [2, 1, 1, 3] \rightarrow [2, 1, 1, 1]$.

In the fourth example, one of the possible sequences of operations is the following: $[4, 1, 2, 2, 4, 3] \rightarrow [1, 1, 2, 2, 4, 3] \rightarrow [1, 1, 1, 2, 4, 3] \rightarrow [1, 1, 1, 2, 2, 3]$.



#### tags 

#1700 #dp #implementation 