<h1 style='text-align: center;'> C. Sort Zero</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array is sorted if it has no inversionsA Young BoyYou are given an array of $n$ positive integers $a_1,a_2,\ldots,a_n$. 

In one operation you do the following: 

1. Choose any integer $x$.
2. For all $i$ such that $a_i = x$, do $a_i := 0$ (assign $0$ to $a_i$).

Find the minimum number of operations required to sort the array in non-decreasing order.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ positive integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print one integer — the minimum number of operations required to sort the array in non-decreasing order.

## Example

### Input


```text
533 3 241 3 1 354 1 5 3 242 4 1 211
```
### Output

```text

1
2
4
3
0

```
## Note

In the first test case, you can choose $x = 3$ for the operation, the resulting array is $[0, 0, 2]$.

In the second test case, you can choose $x = 1$ for the first operation and $x = 3$ for the second operation, the resulting array is $[0, 0, 0, 0]$.



#### Tags 

#1100 #OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_813_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
