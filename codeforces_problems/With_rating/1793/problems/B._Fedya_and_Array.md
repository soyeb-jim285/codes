<h1 style='text-align: center;'> B. Fedya and Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For his birthday recently Fedya was given an array $a$ of $n$ integers arranged in a circle, For each pair of neighboring numbers ($a_1$ and $a_2$, $a_2$ and $a_3$, $\ldots$, $a_{n - 1}$ and $a_n$, $a_n$ and $a_1$) the absolute difference between them is equal to $1$.

Let's call a local maximum an element, which is greater than both of its neighboring elements. Also call a local minimum an element, which is less than both of its neighboring elements. 
## Note

, that elements $a_1$ and $a_n$ are neighboring elements.

Unfortunately, Fedya lost an array, but he remembered in it the sum of local maximums $x$ and the sum of local minimums $y$.

Given $x$ and $y$, help Fedya find any matching array of minimum length.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

Each line of each test case contain two integers $x$ and $y$ ($-10^{9} \le y < x \le 10^{9}$) — the sum of local maximums and the sum of local minimums, respectively.

### Output

For each test case, in the first line print one integer $n$ — the minimum length of matching arrays.

In the second line print $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^{9} \leqslant a_i \leqslant 10^{9}$) — the array elements such that the the absolute difference between each pair of neighboring is equal to $1$.

If there are multiple solutions, print any of them.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^{5}$.

## Example

### Input


```text
43 -24 -42 -15 -3
```
### Output

```text

10
0 1 2 1 0 -1 0 -1 0 1
16
-2 -1 -2 -1 0 1 2 3 4 5 4 3 2 1 0 -1 
6
1 0 -1 0 1 0
16
2 3 2 1 0 -1 0 -1 0 -1 0 1 2 1 0 1
```
## Note

In the first test case, the local maximums are the numbers at $3, 7$ and $10$ positions, and the local minimums are the numbers at $1, 6$ and $8$ positions. $x = a_3 + a_7 + a_{10} = 2 + 0 + 1 = 3$, $y = a_1 + a_6 + a_8 = 0 + (-1) + (-1) = -2$.

In the second test case, the local maximums are the numbers at $2$ and $10$ positions, and the local minimums are the numbers at $1$ and $3$ positions. $x = a_2 + a_{10} = -1 + 5 = 4$, $y = a_1 + a_3 = -2 + (-2) = -4$.

In the third test case, the local maximums are the numbers at $1$ and $5$ positions, and the local minimums are the numbers at $3$ and $6$ positions.



#### Tags 

#1100 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_852_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
