<h1 style='text-align: center;'> A. Turtle Puzzle: Rearrange and Negate</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. You must perform the following two operations on the array (the first, then the second):

1. Arbitrarily rearrange the elements of the array or leave the order of its elements unchanged.
2. Choose at most one contiguous segment of elements and replace the signs of all elements in this segment with their opposites. Formally, you can choose a pair of indices $l, r$ such that $1 \le l \le r \le n$ and assign $a_i = -a_i$ for all $l \le i \le r$ (negate elements). 
## Note

 that you may choose not to select a pair of indices and leave all the signs of the elements unchanged.

What is the maximum sum of the array elements after performing these two operations (the first, then the second)?

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the number of elements in array $a$. 

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-100 \le a_i \le 100$) — elements of the array.

### Output

For each test case, output the maximum sum of the array elements after sequentially performing the two given operations.

## Example

### Input


```text
83-2 3 -31020 11-99410 -2 -3 75-1 -2 -3 -4 -56-41 22 -69 73 -15 -50121 2 3 4 5 6 7 8 9 10 11 12
```
### Output

```text

8
0
1
99
22
15
270
78

```
## Note

In the first test case, you can first rearrange the array to get $[3,-2,-3]$ (operation 1), then choose $l = 2, r = 3$ and get the sum $3 + -((-2) + (-3)) = 8$ (operation 2).

In the second test case, you can do nothing in both operations and get the sum $0$.

In the third test case, you can do nothing in both operations and get the sum $0 + 1 = 1$.

In the fourth test case, you can first leave the order unchanged (operation 1), then choose $l = 1, r = 1$ and get the sum $-(-99) = 99$ (operation 2).

In the fifth test case, you can first leave the order unchanged (operation 1), then choose $l = 2, r = 3$ and get the sum $10 + -((-2) + (-3)) + 7 = 22$ (operation 2).

In the sixth test case, you can first leave the order unchanged (operation 1), then choose $l = 1, r = 5$ and get the sum $-((-1)+(-2)+(-3)+(-4)+(-5))=15$ (operation 2).



#### Tags 

#800 #NOT OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_929_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
