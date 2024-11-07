<h1 style='text-align: center;'> A. Select Three Sticks</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ sticks with positive integral length $a_1, a_2, \ldots, a_n$.

You can perform the following operation any number of times (possibly zero): 

* choose one stick, then either increase or decrease its length by $1$. After each operation, all sticks should have positive lengths.

What is the minimum number of operations that you have to perform such that it is possible to select three of the $n$ sticks and use them without breaking to form an equilateral triangle?

An equilateral triangle is a triangle where all of its three sides have the same length.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 300$) — the number of sticks.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the lengths of the sticks.

It is guaranteed that the sum of $n$ over all test cases does not exceed $300$. 

### Output

For each test case, print one integer on a single line — the minimum number of operations to be made.

## Example

### Input


```text
431 2 347 3 7 353 4 2 1 183 1 4 1 5 9 2 6
```
### Output

```text

2
4
1
1

```
## Note

In the first test case, you can increase the length of the first stick by $1$, then decrease the length of the third stick by $1$. In total, you perform $2$ operations, such that the three sticks form an equilateral triangle of side length $2$.

In the fourth test case, you can decrease the length of the seventh stick by $1$. An equilateral triangle of side length $1$ can be selected and formed by the second, fourth, and seventh sticks.



#### Tags 

#800 #OK #brute_force #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_822_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
