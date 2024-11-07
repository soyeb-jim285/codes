<h1 style='text-align: center;'> A. And Matching</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a set of $n$ ($n$ is always a power of $2$) elements containing all integers $0, 1, 2, \ldots, n-1$ exactly once.

Find $\frac{n}{2}$ pairs of elements such that:

* Each element in the set is in exactly one pair.
* The sum over all pairs of the [bitwise AND](https://en.wikipedia.org/wiki/Bitwise_operation#AND) of its elements must be exactly equal to $k$. Formally, if $a_i$ and $b_i$ are the elements of the $i$-th pair, then the following must hold: $$\sum_{i=1}^{n/2}{a_i \\& b_i} = k,$$ where $\\&$ denotes the bitwise AND operation.

If there are many solutions, print any of them, if there is no solution, print $-1$ instead.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 400$) — the number of test cases. Description of the test cases follows.

Each test case consists of a single line with two integers $n$ and $k$ ($4 \leq n \leq 2^{16}$, $n$ is a power of $2$, $0 \leq k \leq n-1$).

The sum of $n$ over all test cases does not exceed $2^{16}$. All test cases in each individual input will be pairwise different.

### Output

For each test case, if there is no solution, print a single line with the integer $-1$.

Otherwise, print $\frac{n}{2}$ lines, the $i$-th of them must contain $a_i$ and $b_i$, the elements in the $i$-th pair. 

If there are many solutions, print any of them. Print the pairs and the elements in the pairs in any order.

## Example

### Input


```text
44 04 14 24 3
```
### Output

```text

0 3
1 2
0 2
1 3
0 1
2 3
-1

```
## Note

In the first test, $(0\\&3)+(1\\&2) = 0$.

In the second test, $(0\\&2)+(1\\&3) = 1$.

In the third test, $(0\\&1)+(2\\&3) = 2$.

In the fourth test, there is no solution.



#### Tags 

#1500 #NOT OK #bitmasks #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_768_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
