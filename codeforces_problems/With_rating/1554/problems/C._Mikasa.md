<h1 style='text-align: center;'> C. Mikasa</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $m$. Find the $\operatorname{MEX}$ of the sequence $n \oplus 0, n \oplus 1, \ldots, n \oplus m$. Here, $\oplus$ is the [bitwise XOR operator](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

$\operatorname{MEX}$ of the sequence of non-negative integers is the smallest non-negative integer that doesn't appear in this sequence. For example, $\operatorname{MEX}(0, 1, 2, 4) = 3$, and $\operatorname{MEX}(1, 2021) = 0$. 

### Input

The first line contains a single integer $t$ ($1 \le t \le 30\,000$)  — the number of test cases.

The first and only line of each test case contains two integers $n$ and $m$ ($0 \le n, m \le 10^9$).

### Output

For each test case, print a single integer  — the answer to the problem.

## Example

### Input


```text
5
3 5
4 6
3 2
69 696
123456 654321
```
### Output


```text
4
3
0
640
530866
```
## Note

In the first test case, the sequence is $3 \oplus 0, 3 \oplus 1, 3 \oplus 2, 3 \oplus 3, 3 \oplus 4, 3 \oplus 5$, or $3, 2, 1, 0, 7, 6$. The smallest non-negative integer which isn't present in the sequence i. e. the $\operatorname{MEX}$ of the sequence is $4$.

In the second test case, the sequence is $4 \oplus 0, 4 \oplus 1, 4 \oplus 2, 4 \oplus 3, 4 \oplus 4, 4 \oplus 5, 4 \oplus 6$, or $4, 5, 6, 7, 0, 1, 2$. The smallest non-negative integer which isn't present in the sequence i. e. the $\operatorname{MEX}$ of the sequence is $3$.

In the third test case, the sequence is $3 \oplus 0, 3 \oplus 1, 3 \oplus 2$, or $3, 2, 1$. The smallest non-negative integer which isn't present in the sequence i. e. the $\operatorname{MEX}$ of the sequence is $0$.



#### Tags 

#1800 #NOT OK #binary_search #bitmasks #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_735_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
