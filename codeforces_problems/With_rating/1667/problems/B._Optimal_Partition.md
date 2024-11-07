<h1 style='text-align: center;'> B. Optimal Partition</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers. You should divide $a$ into continuous non-empty subarrays (there are $2^{n-1}$ ways to do that).

Let $s=a_l+a_{l+1}+\ldots+a_r$. The value of a subarray $a_l, a_{l+1}, \ldots, a_r$ is: 

* $(r-l+1)$ if $s>0$,
* $0$ if $s=0$,
* $-(r-l+1)$ if $s<0$.

 What is the maximum sum of values you can get with a partition?
### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 5 \cdot 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($-10^9 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

### Output

For each test case print a single integer — the maximum sum of values you can get with an optimal parition.

## Example

### Input


```text
531 2 -340 -2 3 -45-1 -2 3 -1 -16-1 2 -3 4 -5 671 -1 -1 1 -1 -1 1
```
### Output

```text

1
2
1
6
-1

```
## Note

Test case $1$: one optimal partition is $[1, 2]$, $[-3]$. $1+2>0$ so the value of $[1, 2]$ is $2$. $-3<0$, so the value of $[-3]$ is $-1$. $2+(-1)=1$.

Test case $2$: the optimal partition is $[0, -2, 3]$, $[-4]$, and the sum of values is $3+(-1)=2$.



#### Tags 

#2100 #NOT OK #data_structures #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_783_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
