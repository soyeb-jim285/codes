<h1 style='text-align: center;'> F. Zeros and Ones</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $S$ be the [Thue-Morse sequence](https://en.wikipedia.org/wiki/Thue-Morse_sequence). In other words, $S$ is the $0$-indexed binary string with infinite length that can be constructed as follows: 

* Initially, let $S$ be "0".
* Then, we perform the following operation infinitely many times: concatenate $S$ with a copy of itself with flipped bits.For example, here are the first four iterations: 

 

| Iteration | $S$ before iteration | $S$ before iteration with flipped bits | Concatenated $S$ |
| --- | --- | --- | --- |
| 1 | 0 | 1 | 01 |
| 2 | 01 | 10 | 0110 |
| 3 | 0110 | 1001 | 01101001 |
| 4 | 01101001 | 10010110 | 0110100110010110 |
| $\ldots$ | $\ldots$ | $\ldots$ | $\ldots$ |

You are given two positive integers $n$ and $m$. Find the number of positions where the strings $S_0 S_1 \ldots S_{m-1}$ and $S_n S_{n + 1} \ldots S_{n + m - 1}$ are different. 

## Input

Each test contains multiple test cases. The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two positive integers, $n$ and $m$ respectively ($1 \leq n,m \leq 10^{18}$).

## Output

For each testcase, output a non-negative integer — the Hamming distance between the two required strings.

## Example

## Input


```

61 15 1034 21173 3419124639 5634877212073412269 96221437021
```
## Output


```

1
6
95
20
28208137
48102976088

```
## Note

The string $S$ is equal to 0110100110010110....

In the first test case, $S_0$ is "0", and $S_1$ is "1". The Hamming distance between the two strings is $1$.

In the second test case, $S_0 S_1 \ldots S_9$ is "0110100110", and $S_5 S_6 \ldots S_{14}$ is "0011001011". The Hamming distance between the two strings is $6$.



#### tags 

#2500 #bitmasks #divide_and_conquer #dp #math 