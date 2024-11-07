<h1 style='text-align: center;'> C. Min-Max Array Transformation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$, which is sorted in non-descending order. You decided to perform the following steps to create array $b_1, b_2, \dots, b_n$: 

1. Create an array $d$ consisting of $n$ arbitrary non-negative integers.
2. Set $b_i = a_i + d_i$ for each $b_i$.
3. Sort the array $b$ in non-descending order.

You are given the resulting array $b$. For each index $i$, calculate what is the minimum and maximum possible value of $d_i$ you can choose in order to get the given array $b$.

## Note

 that the minimum (maximum) $d_i$-s are independent of each other, i. e. they can be obtained from different possible arrays $d$.

### Input

The first line contains the single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of arrays $a$, $b$ and $d$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$; $a_i \le a_{i+1}$) — the array $a$ in non-descending order.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^9$; $b_i \le b_{i+1}$) — the array $b$ in non-descending order.

Additional constraints on the input: 

* there is at least one way to obtain the array $b$ from the $a$ by choosing an array $d$ consisting of non-negative integers;
* the sum of $n$ doesn't exceed $2 \cdot 10^5$.
### Output

For each test case, print two lines. In the first line, print $n$ integers $d_1^{min}, d_2^{min}, \dots, d_n^{min}$, where $d_i^{min}$ is the minimum possible value you can add to $a_i$.

Secondly, print $n$ integers $d_1^{max}, d_2^{max}, \dots, d_n^{max}$, where $d_i^{max}$ is the maximum possible value you can add to $a_i$.

All $d_i^{min}$ and $d_i^{max}$ values are independent of each other. In other words, for each $i$, $d_i^{min}$ is just the minimum value among all possible values of $d_i$.

## Example

### Input


```text
432 3 57 11 1311000500041 2 3 41 2 3 4410 20 30 4022 33 33 55
```
### Output

```text

5 4 2
11 10 8
4000
4000
0 0 0 0
0 0 0 0
12 2 3 15
23 13 3 15

```
## Note

In the first test case, in order to get $d_1^{min} = 5$, we can choose, for example, $d = [5, 10, 6]$. Then $b$ $=$ $[2+5,3+10,5+6]$ $=$ $[7,13,11]$ $=$ $[7,11,13]$.

For $d_2^{min} = 4$, we can choose $d$ $=$ $[9, 4, 8]$. Then $b$ $=$ $[2+9,3+4,5+8]$ $=$ $[11,7,13]$ $=$ $[7,11,13]$.



#### Tags 

#1400 #OK #binary_search #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_134_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
