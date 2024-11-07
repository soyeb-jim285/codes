<h1 style='text-align: center;'> D. Maximum Subarray</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$, consisting of $n$ integers. You are also given two integers $k$ and $x$.

You have to perform the following operation exactly once: add $x$ to the elements on exactly $k$ distinct positions, and subtract $x$ from all the others.

For example, if $a = [2, -1, 2, 3]$, $k = 1$, $x = 2$, and we have picked the first element, then after the operation the array $a = [4, -3, 0, 1]$.

Let $f(a)$ be the maximum possible sum of a subarray of $a$. The subarray of $a$ is a contiguous part of the array $a$, i. e. the array $a_i, a_{i + 1}, \dots, a_j$ for some $1 \le i \le j \le n$. An empty subarray should also be considered, it has sum $0$.

Let the array $a'$ be the array $a$ after applying the aforementioned operation. Apply the operation in such a way that $f(a')$ is the maximum possible, and print the maximum possible value of $f(a')$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains three integers $n$, $k$ and $x$ ($1 \le n \le 2 \cdot 10^5$; $0 \le k \le \min(20, n)$; $-10^9 \le x \le 10^9$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$). 

The sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the maximum possible value of $f(a')$.

## Example

### Input


```text
44 1 22 -1 2 32 2 3-1 23 0 53 2 46 2 -84 -1 9 -3 7 -8
```
### Output

```text

5
7
0
44

```


#### Tags 

#2000 #NOT OK #data_structures #dp #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_144_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
