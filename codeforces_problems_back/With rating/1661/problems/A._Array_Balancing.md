<h1 style='text-align: center;'> A. Array Balancing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays of length $n$: $a_1, a_2, \dots, a_n$ and $b_1, b_2, \dots, b_n$.

You can perform the following operation any number of times: 

1. Choose integer index $i$ ($1 \le i \le n$);
2. Swap $a_i$ and $b_i$.

What is the minimum possible sum $|a_1 - a_2| + |a_2 - a_3| + \dots + |a_{n-1} - a_n|$ $+$ $|b_1 - b_2| + |b_2 - b_3| + \dots + |b_{n-1} - b_n|$ (in other words, $\sum\limits_{i=1}^{n - 1}{\left(|a_i - a_{i+1}| + |b_i - b_{i+1}|\right)}$) you can achieve after performing several (possibly, zero) operations?

## Input

The first line contains a single integer $t$ ($1 \le t \le 4000$) — the number of test cases. Then, $t$ test cases follow.

The first line of each test case contains the single integer $n$ ($2 \le n \le 25$) — the length of arrays $a$ and $b$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^9$) — the array $b$.

## Output

For each test case, print one integer — the minimum possible sum $\sum\limits_{i=1}^{n-1}{\left(|a_i - a_{i+1}| + |b_i - b_{i+1}|\right)}$.

## Example

## Input


```

343 3 10 1010 10 3 351 2 3 4 56 7 8 9 10672 101 108 108 111 4410 87 111 114 108 100
```
## Output


```

0
8
218

```
## Note

In the first test case, we can, for example, swap $a_3$ with $b_3$ and $a_4$ with $b_4$. We'll get arrays $a = [3, 3, 3, 3]$ and $b = [10, 10, 10, 10]$ with sum $3 \cdot |3 - 3| + 3 \cdot |10 - 10| = 0$.

In the second test case, arrays already have minimum sum (described above) equal to $|1 - 2| + \dots + |4 - 5| + |6 - 7| + \dots + |9 - 10|$ $= 4 + 4 = 8$.

In the third test case, we can, for example, swap $a_5$ and $b_5$.



#### tags 

#800 #greedy #math 