<h1 style='text-align: center;'> B. A BIT of a Construction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given integers $n$ and $k$, construct a sequence of $n$ non-negative (i.e. $\geq 0$) integers $a_1, a_2, \ldots, a_n$ such that 

1. $\sum\limits_{i = 1}^n a_i = k$
2. The number of $1$s in the binary representation of $a_1 | a_2 | \ldots | a_n$ is maximized, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).
### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The only line of each test case contains two integers $n$ and $k$ ($1 \leq n \leq 2 \cdot 10^5$, $1 \leq k \leq 10^9$) — the number of non-negative integers to be printed and the sum respectively.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a sequence $a_1, a_2, \ldots, a_n$ on a new line that satisfies the conditions given above.

If there are multiple solutions, print any of them.

## Example

### Input


```text
41 52 32 56 51
```
### Output

```text

5
1 2
5 0
3 1 1 32 2 12
```
## Note

In the first test case, we have to print exactly one integer, hence we can only output $5$ as the answer.

In the second test case, we output $1, 2$ which sum up to $3$, and $1 | 2 = (11)_2$ has two $1$s in its binary representation, which is the maximum we can achieve in these constraints.

In the fourth test case, we output $3, 1, 1, 32, 2, 12$ which sum up to $51$, and $3 | 1 | 1 | 32 | 2 | 12 = (101\,111)_2$ has five $1$s in its binary representation, which is the maximum we can achieve in these constraints.



#### Tags 

#1100 #OK #bitmasks #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_940_(Div._2)_and_CodeCraft-23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
