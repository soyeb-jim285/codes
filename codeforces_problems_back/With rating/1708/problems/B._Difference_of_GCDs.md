<h1 style='text-align: center;'> B. Difference of GCDs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $n$, $l$, and $r$. You need to construct an array $a_1,a_2,\dots,a_n$ ($l\le a_i\le r$) such that $\gcd(i,a_i)$ are all distinct or report there's no solution.

Here $\gcd(x, y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of the test cases follows.

The first line contains three integers $n$, $l$, $r$ ($1 \le n \le 10^5$, $1\le l\le r\le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, if there is no solution, print "NO" (without quotes). You can print letters in any case (upper or lower).

Otherwise, print "YES" (without quotes). In the next line, print $n$ integers $a_1,a_2,\ldots,a_n$ — the array you construct.

If there are multiple solutions, you may output any.

## Example

## Input


```

4
5 1 5
9 1000 2000
10 30 35
1 1000000000 1000000000

```
## Output


```

YES
1 2 3 4 5
YES
1145 1926 1440 1220 1230 1350 1001 1000 1233
NO
YES
1000000000

```
## Note

In the first test case, $\gcd(1,a_1),\gcd(2,a_2),\ldots,\gcd(5,a_5)$ are equal to $1$, $2$, $3$, $4$, $5$, respectively.



#### tags 

#1100 #constructive_algorithms #math 