<h1 style='text-align: center;'> B. XOR Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two distinct non-negative integers $x$ and $y$. Consider two infinite sequences $a_1, a_2, a_3, \ldots$ and $b_1, b_2, b_3, \ldots$, where

* $a_n = n \oplus x$;
* $b_n = n \oplus y$.

Here, $x \oplus y$ denotes the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation of integers $x$ and $y$.

For example, with $x = 6$, the first $8$ elements of sequence $a$ will look as follows: $[7, 4, 5, 2, 3, 0, 1, 14, \ldots]$. 
## Note

 that the indices of elements start with $1$.

Your task is to find the length of the longest common subsegment$^\dagger$ of sequences $a$ and $b$. In other words, find the maximum integer $m$ such that $a_i = b_j, a_{i + 1} = b_{j + 1}, \ldots, a_{i + m - 1} = b_{j + m - 1}$ for some $i, j \ge 1$.

$^\dagger$A subsegment of sequence $p$ is a sequence $p_l,p_{l+1},\ldots,p_r$, where $1 \le l \le r$.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $x$ and $y$ ($0 \le x, y \le 10^9, x \neq y$) — the parameters of the sequences.

### Output

For each test case, output a single integer — the length of the longest common subsegment.

## Example

### Input


```text
40 112 457 37316560849 14570961
```
### Output

```text

1
8
4
33554432

```
## Note

In the first test case, the first $7$ elements of sequences $a$ and $b$ are as follows:

$a = [1, 2, 3, 4, 5, 6, 7,\ldots]$

$b = [0, 3, 2, 5, 4, 7, 6,\ldots]$

It can be shown that there isn't a positive integer $k$ such that the sequence $[k, k + 1]$ occurs in $b$ as a subsegment. So the answer is $1$.

In the third test case, the first $20$ elements of sequences $a$ and $b$ are as follows:

$a = [56, 59, 58, 61, 60, 63, 62, 49, 48, 51, 50, 53, 52, 55, 54, \textbf{41, 40, 43, 42}, 45, \ldots]$

$b = [36, 39, 38, 33, 32, 35, 34, 45, 44, 47, 46, \textbf{41, 40, 43, 42}, 53, 52, 55, 54, 49, \ldots]$

It can be shown that one of the longest common subsegments is the subsegment $[41, 40, 43, 42]$ with a length of $4$.



#### Tags 

#1000 #NOT OK #bitmasks #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_951_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
