<h1 style='text-align: center;'> D. Count GCD</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $m$ and an array $a$ of $n$ integers. For each $1 \le i \le n$ it holds that $1 \le a_i \le m$.

Your task is to count the number of different arrays $b$ of length $n$ such that: 

* $1 \le b_i \le m$ for each $1 \le i \le n$, and
* $\gcd(b_1,b_2,b_3,...,b_i) = a_i$ for each $1 \le i \le n$.

Here $\gcd(a_1,a_2,\dots,a_i)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $a_1,a_2,\ldots,a_i$.

Since this number can be too large, print it modulo $998\,244\,353$.

### Input

Each test consist of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 2 \cdot 10^5$, $1 \le m \le 10^9$) — the length of the array $a$ and the maximum possible value of the element.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le m$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ across all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the number of different arrays satisfying the conditions above. Since this number can be large, print it modulo $998\,244\,353$.

## Example

### Input


```text
53 54 2 12 11 15 502 3 5 2 34 100000000060 30 1 12 10000000001000000000 2
```
### Output

```text

3
1
0
595458194
200000000

```
## Note

In the first test case, the possible arrays $b$ are: 

* $[4,2,1]$;
* $[4,2,3]$;
* $[4,2,5]$.

In the second test case, the only array satisfying the demands is $[1,1]$.

In the third test case, it can be proven no such array exists.



#### Tags 

#1800 #NOT OK #combinatorics #math #number_theory 

## Blogs
- [All Contest Problems](../CodeTON_Round_3_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
