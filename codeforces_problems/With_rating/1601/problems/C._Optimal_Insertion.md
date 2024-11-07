<h1 style='text-align: center;'> C. Optimal Insertion</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two arrays of integers $a_1, a_2, \ldots, a_n$ and $b_1, b_2, \ldots, b_m$.

You need to insert all elements of $b$ into $a$ in an arbitrary way. As a result you will get an array $c_1, c_2, \ldots, c_{n+m}$ of size $n + m$.

## Note

 that you are not allowed to change the order of elements in $a$, while you can insert elements of $b$ at arbitrary positions. They can be inserted at the beginning, between any elements of $a$, or at the end. Moreover, elements of $b$ can appear in the resulting array in any order.

What is the minimum possible number of inversions in the resulting array $c$? Recall that an inversion is a pair of indices $(i, j)$ such that $i < j$ and $c_i > c_j$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^4$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n, m \leq 10^6$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$).

The third line of each test case contains $m$ integers $b_1, b_2, \ldots, b_m$ ($1 \leq b_i \leq 10^9$).

It is guaranteed that the sum of $n$ for all tests cases in one input doesn't exceed $10^6$. The sum of $m$ for all tests cases doesn't exceed $10^6$ as well.

### Output

For each test case, print one integer — the minimum possible number of inversions in the resulting array $c$.

## Example

### Input


```text
3
3 4
1 2 3
4 3 2 1
3 3
3 2 1
1 2 3
5 4
1 3 5 3 1
4 3 6 1
```
### Output


```text
0
4
6
```
## Note

Below is given the solution to get the optimal answer for each of the example test cases (elements of $a$ are underscored).

* In the first test case, $c = [\underline{1}, 1, \underline{2}, 2, \underline{3}, 3, 4]$.
* In the second test case, $c = [1, 2, \underline{3}, \underline{2}, \underline{1}, 3]$.
* In the third test case, $c = [\underline{1}, 1, 3, \underline{3}, \underline{5}, \underline{3}, \underline{1}, 4, 6]$.


#### Tags 

#2300 #NOT OK #data_structures #divide_and_conquer #dp #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_751_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
