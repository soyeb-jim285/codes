<h1 style='text-align: center;'> A. Mainak and Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mainak has an array $a_1, a_2, \ldots, a_n$ of $n$ positive integers. He will do the following operation to this array exactly once:

* Pick a subsegment of this array and cyclically rotate it by any amount.

 Formally, he can do the following exactly once:* Pick two integers $l$ and $r$, such that $1 \le l \le r \le n$, and any positive integer $k$.
* Repeat this $k$ times: set $a_l=a_{l+1}, a_{l+1}=a_{l+2}, \ldots, a_{r-1}=a_r, a_r=a_l$ (all changes happen at the same time).

Mainak wants to maximize the value of $(a_n - a_1)$ after exactly one such operation. Determine the maximum value of $(a_n - a_1)$ that he can obtain.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 50$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2000$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 999$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

### Output

For each test case, output a single integer — the maximum value of $(a_n - a_1)$ that Mainak can obtain by doing the operation exactly once.

## Example

### Input


```text
561 3 9 11 5 712039 99 99942 1 8 132 1 5
```
### Output

```text

10
0
990
7
4

```
## Note

* In the first test case, we can rotate the subarray from index $3$ to index $6$ by an amount of $2$ (i.e. choose $l = 3$, $r = 6$ and $k = 2$) to get the optimal array: $$[1, 3, \underline{9, 11, 5, 7}] \longrightarrow [1, 3, \underline{5, 7, 9, 11}]$$ So the answer is $a_n - a_1 = 11 - 1 = 10$.
* In the second testcase, it is optimal to rotate the subarray starting and ending at index $1$ and rotating it by an amount of $2$.
* In the fourth testcase, it is optimal to rotate the subarray starting from index $1$ to index $4$ and rotating it by an amount of $3$. So the answer is $8 - 1 = 7$.


#### Tags 

#900 #OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_819_(Div._1_+_Div._2)_and_Grimoire_of_Code_Annual_Contest_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
