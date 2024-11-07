<h1 style='text-align: center;'> F. Comfortably Numb</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an array $a$ consisting of $n$ non-negative integers.

The numbness of a subarray $a_l, a_{l+1}, \ldots, a_r$ (for arbitrary $l \leq r$) is defined as $$\max(a_l, a_{l+1}, \ldots, a_r) \oplus (a_l \oplus a_{l+1} \oplus \ldots \oplus a_r),$$ where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Find the maximum numbness over all subarrays.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the maximum numbness over all subarrays of the given array.

## Example

### Input


```text
251 2 3 4 5310 47 52
```
### Output

```text

7
47

```
## Note

For the first test case, for the subarray $[3, 4, 5]$, its maximum value is $5$. Hence, its numbness is $3 \oplus 4 \oplus 5 \oplus 5$ = $7$. This is the maximum possible numbness in this array.

In the second test case the subarray $[47, 52]$ provides the maximum numbness.



#### Tags 

#2400 #NOT OK #bitmasks #data_structures #divide_and_conquer #strings #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_845_(Div._2)_and_ByteRace_2023.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
