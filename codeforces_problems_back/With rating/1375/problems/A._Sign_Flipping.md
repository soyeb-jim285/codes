<h1 style='text-align: center;'> A. Sign Flipping</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers $a_1, a_2, \dots, a_n$, where $n$ is odd. You are allowed to flip the sign of some (possibly all or none) of them. You wish to perform these flips in such a way that the following conditions hold:

1. At least $\frac{n - 1}{2}$ of the adjacent differences $a_{i + 1} - a_i$ for $i = 1, 2, \dots, n - 1$ are greater than or equal to $0$.
2. At least $\frac{n - 1}{2}$ of the adjacent differences $a_{i + 1} - a_i$ for $i = 1, 2, \dots, n - 1$ are less than or equal to $0$.

Find any valid way to flip the signs. It can be shown that under the given constraints, there always exists at least one choice of signs to flip that satisfies the required condition. If there are several solutions, you can find any of them.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \le t \le 500$)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($3 \le n \le 99$, $n$ is odd)  — the number of integers given to you.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$)  — the numbers themselves.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10000$.

## Output

For each test case, print $n$ integers $b_1, b_2, \dots, b_n$, corresponding to the integers after flipping signs. $b_i$ has to be equal to either $a_i$ or $-a_i$, and of the adjacent differences $b_{i + 1} - b_i$ for $i = 1, \dots, n - 1$, at least $\frac{n - 1}{2}$ should be non-negative and at least $\frac{n - 1}{2}$ should be non-positive.

It can be shown that under the given constraints, there always exists at least one choice of signs to flip that satisfies the required condition. If there are several solutions, you can find any of them.

## Example

## Input


```

5
3
-2 4 3
5
1 1 1 1 1
5
-2 4 7 -6 4
9
9 7 -4 -2 1 -3 9 -4 -5
9
-4 1 9 4 8 9 5 1 -9

```
## Output


```

-2 -4 3
1 1 1 1 1
-2 -4 7 -6 4
-9 -7 -4 2 1 -3 -9 -4 -5
4 -1 -9 -4 -8 -9 -5 -1 9

```
## Note

In the first test case, the difference $(-4) - (-2) = -2$ is non-positive, while the difference $3 - (-4) = 7$ is non-negative.

In the second test case, we don't have to flip any signs. All $4$ differences are equal to $0$, which is both non-positive and non-negative.

In the third test case, $7 - (-4)$ and $4 - (-6)$ are non-negative, while $(-4) - (-2)$ and $(-6) - 7$ are non-positive.



#### tags 

#1100 #constructive_algorithms #math 