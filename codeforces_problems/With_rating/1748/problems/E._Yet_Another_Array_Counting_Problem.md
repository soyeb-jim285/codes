<h1 style='text-align: center;'> E. Yet Another Array Counting Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The position of the leftmost maximum on the segment $[l; r]$ of array $x = [x_1, x_2, \ldots, x_n]$ is the smallest integer $i$ such that $l \le i \le r$ and $x_i = \max(x_l, x_{l+1}, \ldots, x_r)$.

You are given an array $a = [a_1, a_2, \ldots, a_n]$ of length $n$. Find the number of integer arrays $b = [b_1, b_2, \ldots, b_n]$ of length $n$ that satisfy the following conditions: 

* $1 \le b_i \le m$ for all $1 \le i \le n$;
* for all pairs of integers $1 \le l \le r \le n$, the position of the leftmost maximum on the segment $[l; r]$ of the array $b$ is equal to the position of the leftmost maximum on the segment $[l; r]$ of the array $a$.

Since the answer might be very large, print its remainder modulo $10^9+7$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n,m \le 2 \cdot 10^5$, $n \cdot m \le 10^6$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le m$) — the array $a$.

It is guaranteed that the sum of $n \cdot m$ over all test cases doesn't exceed $10^6$.

### Output

For each test case print one integer — the number of arrays $b$ that satisfy the conditions from the statement, modulo $10^9+7$.

## Example

### Input


```text
43 31 3 24 22 2 2 26 96 9 6 9 6 99 10010 40 20 20 100 60 80 60 60
```
### Output

```text

8
5
11880
351025663

```
## Note

In the first test case, the following $8$ arrays satisfy the conditions from the statement: 

* $[1,2,1]$;
* $[1,2,2]$;
* $[1,3,1]$;
* $[1,3,2]$;
* $[1,3,3]$;
* $[2,3,1]$;
* $[2,3,2]$;
* $[2,3,3]$.

In the second test case, the following $5$ arrays satisfy the conditions from the statement: 

* $[1,1,1,1]$;
* $[2,1,1,1]$;
* $[2,2,1,1]$;
* $[2,2,2,1]$;
* $[2,2,2,2]$.


#### Tags 

#2300 #NOT OK #binary_search #data_structures #divide_and_conquer #dp #flows #math #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_833_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
