<h1 style='text-align: center;'> B. AND Reconstruction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $b$ of $n - 1$ integers.

An array $a$ of $n$ integers is called good if $b_i = a_i \, \\& \, a_{i + 1}$ for $1 \le i \le n-1$, where $\\&$ denotes the [bitwise AND operator](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

Construct a good array, or report that no good arrays exist.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$) — the length of the array $a$.

The second line of each test case contains $n - 1$ integers $b_1, b_2, \ldots, b_{n - 1}$ ($0 \le b_i < 2^{30}$) — the elements of the array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output a single integer $-1$ if no good arrays exist. 

Otherwise, output $n$ space-separated integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{30}$) — the elements of a good array $a$.

If there are multiple solutions, you may output any of them.

## Example

### Input


```text
42132 041 2 353 5 4 2
```
### Output

```text

5 3
3 2 1
-1
3 7 5 6 3

```
## Note

In the first test case, $b = [1]$. A possible good array is $a=[5, 3]$, because $a_1 \, \\& \, a_2 = 5 \, \\& \, 3 = 1 = b_1$.

In the second test case, $b = [2, 0]$. A possible good array is $a=[3, 2, 1]$, because $a_1 \, \\& \, a_2 = 3 \, \\& \, 2 = 2 = b_1$ and $a_2 \, \\& \, a_3 = 2 \, \\& \, 1 = 0 = b_2$.

In the third test case, $b = [1, 2, 3]$. It can be shown that no good arrays exist, so the output is $-1$.

In the fourth test case, $b = [3, 5, 4, 2]$. A possible good array is $a=[3, 7, 5, 6, 3]$.



#### Tags 

#NOT OK #bitmasks #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Pinely_Round_4_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
