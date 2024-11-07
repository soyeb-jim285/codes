<h1 style='text-align: center;'> F. October 18, 2017</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It was October 18, 2017. Shohag, a melancholic soul, made a strong determination that he will pursue Competitive Programming seriously, by heart, because he found it fascinating. Fast forward to 4 years, he is happy that he took this road. He is now creating a contest on Codeforces. He found an astounding problem but has no idea how to solve this. Help him to solve the final problem of the round.

You are given three integers $n$, $k$ and $x$. Find the number, modulo $998\,244\,353$, of integer sequences $a_1, a_2, \ldots, a_n$ such that the following conditions are satisfied: 

* $0 \le a_i \lt 2^k$ for each integer $i$ from $1$ to $n$.
* There is no non-empty subsequence in $a$ such that the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of the elements of the subsequence is $x$.

A sequence $b$ is a subsequence of a sequence $c$ if $b$ can be obtained from $c$ by deletion of several (possibly, zero or all) elements.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$)  — the number of test cases.

The first and only line of each test case contains three space-separated integers $n$, $k$, and $x$ ($1 \le n \le 10^9$, $0 \le k \le 10^7$, $0 \le x \lt 2^{\operatorname{min}(20, k)}$).

It is guaranteed that the sum of $k$ over all test cases does not exceed $5 \cdot 10^7$.

## Output

For each test case, print a single integer — the answer to the problem.

## Example

## Input


```

6
2 2 0
2 1 1
3 2 3
69 69 69
2017 10 18
5 7 0

```
## Output


```

6
1
15
699496932
892852568
713939942

```
## Note

In the first test case, the valid sequences are $[1, 2]$, $[1, 3]$, $[2, 1]$, $[2, 3]$, $[3, 1]$ and $[3, 2]$.

In the second test case, the only valid sequence is $[0, 0]$.



#### tags 

#2700 #combinatorics #dp #implementation #math 