<h1 style='text-align: center;'> E. Brukhovich and Exams</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The boy Smilo is learning algorithms with a teacher named Brukhovich.

Over the course of the year, Brukhovich will administer $n$ exams. For each exam, its difficulty $a_i$ is known, which is a non-negative integer.

Smilo doesn't like when the greatest common divisor of the difficulties of two consecutive exams is equal to $1$. Therefore, he considers the sadness of the academic year to be the number of such pairs of exams. More formally, the sadness is the number of indices $i$ ($1 \leq i \leq n - 1$) such that $gcd(a_i, a_{i+1}) = 1$, where $gcd(x, y)$ is the greatest common divisor of integers $x$ and $y$.

Brukhovich wants to minimize the sadness of the year of Smilo. To do this, he can set the difficulty of any exam to $0$. However, Brukhovich doesn't want to make his students' lives too easy. Therefore, he will perform this action no more than $k$ times.

Help Smilo determine the minimum sadness that Brukhovich can achieve if he performs no more than $k$ operations.

As a reminder, the greatest common divisor (GCD) of two non-negative integers $x$ and $y$ is the maximum integer that is a divisor of both $x$ and $y$ and is denoted as $gcd(x, y)$. In particular, $gcd(x, 0) = gcd(0, x) = x$ for any non-negative integer $x$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 10^5$) — the total number of exams and the maximum number of exams that can be simplified, respectively. 

The second line of each test case contains $n$ integers $a_1, a_2, a_3, \ldots, a_n$ — the elements of array $a$, which are the difficulties of the exams ($0 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^5$.

## Output

For each test case, output the minimum possible sadness that can be achieved by performing no more than $k$ operations.

## Example

## Input


```

95 21 3 5 7 95 23 5 7 9 118 217 15 10 1 1 5 14 85 31 1 1 1 15 51 1 1 1 119 71 1 2 3 4 5 5 6 6 7 8 9 10 1 1 1 2 3 115 62 1 1 1 1 2 1 1 2 1 1 1 2 1 25 21 1 1 1 25 21 0 1 0 1
```
## Output


```

1
0
2
2
0
5
5
2
1

```
## Note

In the first test case, a sadness of $1$ can be achieved. To this, you can simplify the second and fourth exams. After this, there will be only one pair of adjacent exams with a greatest common divisor (GCD) equal to one, which is the first and second exams.

In the second test case, a sadness of $0$ can be achieved by simplifying the second and fourth exams.



#### tags 

#2500 #brute_force #greedy #implementation #math #sortings 