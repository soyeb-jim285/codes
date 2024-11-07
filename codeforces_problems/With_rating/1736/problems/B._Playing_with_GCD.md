<h1 style='text-align: center;'> B. Playing with GCD</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer array $a$ of length $n$. 

Does there exist an array $b$ consisting of $n+1$ positive integers such that $a_i=\gcd (b_i,b_{i+1})$ for all $i$ ($1 \leq i \leq n$)? 

## Note

 that $\gcd(x, y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^5$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ space-separated integers $a_1,a_2,\ldots,a_n$ representing the array $a$ ($1 \leq a_i \leq 10^4$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output "YES" if such $b$ exists, otherwise output "NO". You can print each letter in any case (upper or lower).

## Example

### Input


```text
4134324 234 2 441 1 1 1
```
### Output

```text

YES
YES
NO
YES

```
## Note

In the first test case, we can take $b=[343,343]$.

In the second test case, one possibility for $b$ is $b=[12,8,6]$.

In the third test case, it can be proved that there does not exist any array $b$ that fulfills all the conditions.



#### Tags 

#1200 #OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_825_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
