<h1 style='text-align: center;'> F. You Are So Beautiful</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a_1, a_2, \ldots, a_n$. Calculate the number of subarrays of this array $1 \leq l \leq r \leq n$, such that:

* The array $b = [a_l, a_{l+1}, \ldots, a_r]$ occurs in the array $a$ as a subsequence exactly once. In other words, there is exactly one way to select a set of indices $1 \leq i_1 < i_2 < \ldots < i_{r - l + 1} \leq n$, such that $b_j = a_{i_j}$ for all $1 \leq j \leq r - l + 1$.
### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. This is followed by their description.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$) — the size of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the number of suitable subarrays.

## Example

### Input


```text
61121 131 2 142 3 2 154 5 4 5 4101 7 7 2 3 4 3 2 1 100
```
### Output

```text

1
1
4
7
4
28

```
## Note

In the first test case, there is exactly one subarray $(1, 1)$ that suits us.

In the second test case, there is exactly one subarray $(1, 2)$ that suits us. Subarrays $(1, 1)$ and $(2, 2)$ do not suit us, as the subsequence $[1]$ occurs twice in the array.

In the third test case, all subarrays except $(1, 1)$ and $(3, 3)$ are suitable.



#### Tags 

#1400 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_905_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
