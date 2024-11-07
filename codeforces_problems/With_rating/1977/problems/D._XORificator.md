<h1 style='text-align: center;'> D. XORificator</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary (consisting only of 0s and 1s) $n \times m$ matrix. You are also given a XORificator, using which you can invert all the values in a chosen row (i.e. replace 0 with 1 and 1 with 0).

A column in the matrix is considered special if it contains exactly one 1. Your task is to find the maximum number of columns that can be made special at the same time, and the set of rows the XORificator should be used on to achieve that.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n, m \leq 3 \cdot 10^5$, $n \cdot m \leq 3 \cdot 10^5$).

Each of the following $n$ lines of the test case contains a binary string of length $m$.

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, output two lines.

In the first line, output the maximum number of special columns that is possible to get simultaneously.

In the second line, output a binary string of length $n$, where the $i$-th character is 0, if you don't use the XORificator on the $i$-th row, and 1, if you use the XORificator on the $i$-th row.

If there are multiple valid XORificator configurations that achieve the optimal answer, you can output any of them.

## Example

### Input


```text
53 41010011001001 111 102 500101101103 3101111000
```
### Output

```text

3
010
1
0
1
1
3
00
2
010

```
## Note

In the first test case, you can use the XORificator on the second row to make the columns $2$, $3$, and $4$ special.

In the second test case, the only column is already special, so you don't need to use the XORificator.



#### Tags 

#2300 #NOT OK #bitmasks #brute_force #greedy #hashing 

## Blogs
- [All Contest Problems](../Codeforces_Round_948_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
