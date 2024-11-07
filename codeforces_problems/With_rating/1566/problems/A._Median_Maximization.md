<h1 style='text-align: center;'> A. Median Maximization</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two positive integers $n$ and $s$. Find the maximum possible median of an array of $n$ non-negative integers (not necessarily distinct), such that the sum of its elements is equal to $s$.

A median of an array of integers of length $m$ is the number standing on the $\lceil {\frac{m}{2}} \rceil$-th (rounding up) position in the non-decreasing ordering of its elements. Positions are numbered starting from $1$. For example, a median of the array $[20,40,20,50,50,30]$ is the $\lceil \frac{m}{2} \rceil$-th element of $[20,20,30,40,50,50]$, so it is $30$. There exist other definitions of the median, but in this problem we use the described definition.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

Each test case contains a single line with two integers $n$ and $s$ ($1 \le n, s \le 10^9$) — the length of the array and the required sum of the elements.

### Output

For each test case print a single integer — the maximum possible median.

## Example

### Input


```text
8
1 5
2 5
3 5
2 1
7 17
4 14
1 1000000000
1000000000 1
```
### Output


```text
5
2
2
0
4
4
1000000000
0
```
## Note

Possible arrays for the first three test cases (in each array the median is underlined):

* In the first test case $[\underline{5}]$
* In the second test case $[\underline{2}, 3]$
* In the third test case $[1, \underline{2}, 2]$


#### Tags 

#800 #NOT OK #binary_search #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_16.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
