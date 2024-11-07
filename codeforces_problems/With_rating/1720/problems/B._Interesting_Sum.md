<h1 style='text-align: center;'> B. Interesting Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ that contains $n$ integers. You can choose any proper subsegment $a_l, a_{l + 1}, \ldots, a_r$ of this array, meaning you can choose any two integers $1 \le l \le r \le n$, where $r - l + 1 < n$. We define the beauty of a given subsegment as the value of the following expression:

$$\max(a_{1}, a_{2}, \ldots, a_{l-1}, a_{r+1}, a_{r+2}, \ldots, a_{n}) - \min(a_{1}, a_{2}, \ldots, a_{l-1}, a_{r+1}, a_{r+2}, \ldots, a_{n}) + \max(a_{l}, \ldots, a_{r}) - \min(a_{l}, \ldots, a_{r}).$$

Please find the maximum beauty among all proper subsegments.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Then follow the descriptions of each test case.

The first line of each test case contains a single integer $n$ $(4 \leq n \leq 10^5)$ — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_{i} \leq 10^9$) — the elements of the given array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each testcase print a single integer — the maximum beauty of a proper subsegment.

## Example

### Input


```text
4
8
1 2 2 3 1 5 6 1
5
1 2 3 100 200
4
3 3 3 3
6
7 8 3 1 1 8
```
### Output


```text
9
297
0
14
```
## Note

In the first test case, the optimal segment is $l = 7$, $r = 8$. The beauty of this segment equals to $(6 - 1) + (5 - 1) = 9$.

In the second test case, the optimal segment is $l = 2$, $r = 4$. The beauty of this segment equals $(100 - 2) + (200 - 1) = 297$.



#### Tags 

#800 #OK #brute_force #data_structures #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_815_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
