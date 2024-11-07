<h1 style='text-align: center;'> F. Covering Circle</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sam started playing with round buckets in the sandbox, while also scattering pebbles. His mom decided to buy him a new bucket, so she needs to solve the following task.

You are given $n$ distinct points with integer coordinates $A_1, A_2, \ldots, A_n$. All points were generated from the square $[-10^8, 10^8] \times [-10^8, 10^8]$ uniformly and independently.

You are given positive integers $k$, $l$, such that $k \leq l \leq n$. You want to select a subsegment $A_i, A_{i+1}, \ldots, A_{i+l-1}$ of the points array (for some $1 \leq i \leq n + 1 - l$), and some circle on the plane, containing $\geq k$ points of the selected subsegment (inside or on the border).

What is the smallest possible radius of that circle?

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Descriptions of test cases follow.

The first line of each test case contains three integers $n$, $l$, $k$ ($2 \leq k \leq l \leq n \leq 50\,000$, $k \leq 20$).

Each of the next $n$ lines contains two integers $x_i$, $y_i$ ($-10^8 \leq x_i, y_i \leq 10^8$) — the coordinates of the point $A_i$. It is guaranteed that all points are distinct and were generated independently from uniform distribution on $[-10^8, 10^8] \times [-10^8, 10^8]$.

It is guaranteed that the sum of $n$ for all test cases does not exceed $50\,000$.

In the first test, points were not generated from the uniform distribution on $[-10^8, 10^8] \times [-10^8, 10^8]$ for simplicity. It is the only such test and your solution must pass it.

Hacks are disabled in this problem.

### Output

For each test case print a single real number — the answer to the problem.

Your answer will be considered correct if its absolute or relative error does not exceed $10^{-9}$. Formally let your answer be $a$, jury answer be $b$. Your answer will be considered correct if $\frac{|a - b|}{\max{(1, |b|)}} \le 10^{-9}$.

## Example

### Input


```text
43 2 20 00 43 05 4 31 10 02 20 22 08 3 20 31 00 21 10 11 20 01 35 4 41 1-3 32 25 35 5
```
### Output

```text

2.00000000000000000000
1.00000000000000000000
0.50000000000000000000
4.00000000000000000000

```
## Note

In the first test case, we can select subsegment $A_1, A_2$ and a circle with center $(0, 2)$ and radius $2$.

In the second test case, we can select subsegment $A_1, A_2, A_3, A_4$ and a circle with center $(1, 2)$ and radius $1$.



#### Tags 

#3500 #NOT OK #geometry 

## Blogs
- [All Contest Problems](../Codeforces_Round_773_(Div._1).md)
- [Codeforces Round #773](../blogs/Codeforces_Round_773.md)
- [Tutorial](../blogs/Tutorial.md)
