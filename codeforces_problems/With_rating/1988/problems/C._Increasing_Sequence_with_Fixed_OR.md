<h1 style='text-align: center;'> C. Increasing Sequence with Fixed OR</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a positive integer $n$. Find the longest sequence of positive integers $a=[a_1,a_2,\ldots,a_k]$ that satisfies the following conditions, and print the sequence:

* $a_i\le n$ for all $1\le i\le k$.
* $a$ is strictly increasing. That is, $a_i>a_{i-1}$ for all $2\le i\le k$.
* $a_i\,|\,a_{i-1}=n$ for all $2\le i\le k$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The only line of each test case contains one integer $n$ ($1\le n\le 10^{18}$).

It's guaranteed that the sum of lengths of the longest valid sequences does not exceed $5\cdot 10^5$.

### Output

For each testcase, print two lines. In the first line, print the length of your constructed sequence, $k$. In the second line, print $k$ positive integers, denoting the sequence. If there are multiple longest sequences, you can print any of them.

## Example

### Input


```text
4131423
```
### Output

```text

1
1
3
1 2 3
4
4 10 12 14
5
7 18 21 22 23
```


#### Tags 

#1300 #OK #bitmasks #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_958_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
