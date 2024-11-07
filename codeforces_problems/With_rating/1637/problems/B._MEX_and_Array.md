<h1 style='text-align: center;'> B. MEX and Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let there be an array $b_1, b_2, \ldots, b_k$. Let there be a partition of this array into segments $[l_1; r_1], [l_2; r_2], \ldots, [l_c; r_c]$, where $l_1 = 1$, $r_c = k$, and for any $2 \leq i \leq c$ holds that $r_{i-1} + 1 = l_i$. In other words, each element of the array belongs to exactly one segment.

Let's define the cost of a partition as $$c + \sum_{i = 1}^{c} \operatorname{mex}(\{b_{l_i}, b_{l_i + 1}, \ldots, b_{r_i}\}),$$ where $\operatorname{mex}$ of a set of numbers $S$ is the smallest non-negative integer that does not occur in the set $S$. In other words, the cost of a partition is the number of segments plus the sum of MEX over all segments. Let's define the value of an array $b_1, b_2, \ldots, b_k$ as the maximum possible cost over all partitions of this array.

You are given an array $a$ of size $n$. Find the sum of values of all its subsegments.

An array $x$ is a subsegment of an array $y$ if $x$ can be obtained from $y$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

The input contains several test cases. The first line contains one integer $t$ ($1 \leq t \leq 30$) — the number of test cases.

The first line for each test case contains one integer $n$ ($1 \leq n \leq 100$) — the length of the array.

The second line contains a sequence of integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$) — the array elements.

It is guaranteed that the sum of the values $n$ over all test cases does not exceed $100$.

### Output

For each test case print a single integer — the answer to the problem.

## Example

### Input


```text
421 232 0 142 0 5 150 1 1 0 1
```
### Output

```text

4
14
26
48

```
## Note

In the second test case: 

* The best partition for the subsegment $[2, 0, 1]$: $[2], [0, 1]$. The cost of this partition equals to $2 + \operatorname{mex}(\{2\}) + \operatorname{mex}(\{0, 1\}) = 2 + 0 + 2 = 4$.
* The best partition for the subsegment $[2, 0]$: $[2], [0]$. The cost of this partition equals to $2 + \operatorname{mex}(\{2\}) + \operatorname{mex}(\{0\}) = 2 + 0 + 1 = 3$
* The best partition for the subsegment $[2]$: $[2]$. The cost of this partition equals to $1 + \operatorname{mex}(\{2\}) = 1 + 0 = 1$.
* The best partition for the subsegment $[0, 1]$: $[0, 1]$. The cost of this partition equals to $1 + \operatorname{mex}(\{0, 1\}) = 1 + 2 = 3$.
* The best partition for the subsegment $[0]$: $[0]$. The cost of this partition equals to $1 + \operatorname{mex}(\{0\}) = 1 + 1 = 2$.
* The best partition for the subsegment $[1]$: $[1]$. The cost of this partition equals to $1 + \operatorname{mex}(\{1\}) = 1 + 0 = 1$.

The sum of values over all subsegments equals to $4 + 3 + 1 + 3 + 2 + 1 = 14$.



#### Tags 

#1100 #NOT OK #brute_force #dp #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_19.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
