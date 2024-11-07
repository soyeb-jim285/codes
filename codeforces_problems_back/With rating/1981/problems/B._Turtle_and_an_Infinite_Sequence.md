<h1 style='text-align: center;'> B. Turtle and an Infinite Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a sequence $a_0, a_1, a_2, \ldots$ of infinite length. Initially $a_i = i$ for every non-negative integer $i$.

After every second, each element of the sequence will simultaneously change. $a_i$ will change to $a_{i - 1} \mid a_i \mid a_{i + 1}$ for every positive integer $i$. $a_0$ will change to $a_0 \mid a_1$. Here, $|$ denotes [bitwise OR](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

Turtle is asked to find the value of $a_n$ after $m$ seconds. In particular, if $m = 0$, then he needs to find the initial value of $a_n$. He is tired of calculating so many values, so please help him!

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n, m$ ($0 \le n, m \le 10^9$).

## Output

For each test case, output a single integer — the value of $a_n$ after $m$ seconds.

## Example

## Input


```

90 00 10 21 05 210 120 31145 1419198 10
```
## Output


```

0
1
3
1
7
11
23
1279
19455

```
## Note

After $1$ second, $[a_0, a_1, a_2, a_3, a_4, a_5]$ will become $[1, 3, 3, 7, 7, 7]$.

After $2$ seconds, $[a_0, a_1, a_2, a_3, a_4, a_5]$ will become $[3, 3, 7, 7, 7, 7]$.



#### tags 

#1300 #bitmasks #math 