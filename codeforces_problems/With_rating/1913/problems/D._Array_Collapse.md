<h1 style='text-align: center;'> D. Array Collapse</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $[p_1, p_2, \dots, p_n]$, where all elements are distinct.

You can perform several (possibly zero) operations with it. In one operation, you can choose a contiguous subsegment of $p$ and remove all elements from that subsegment, except for the minimum element on that subsegment. For example, if $p = [3, 1, 4, 7, 5, 2, 6]$ and you choose the subsegment from the $3$-rd element to the $6$-th element, the resulting array is $[3, 1, 2, 6]$.

An array $a$ is called reachable if it can be obtained from $p$ using several (maybe zero) aforementioned operations. Calculate the number of reachable arrays, and print it modulo $998244353$.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$). The second line contains $n$ distinct integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le 10^9$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, print one integer — the number of reachable arrays, taken modulo $998244353$.

## Example

### Input


```text
322 142 4 1 3510 2 6 3 4
```
### Output

```text

2
6
12

```


#### Tags 

#2100 #NOT OK #data_structures #divide_and_conquer #dp #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_160_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
