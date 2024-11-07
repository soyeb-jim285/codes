<h1 style='text-align: center;'> F. array-value</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of non-negative integers $a_1, a_2, \ldots, a_n$.

The value of a sub-array of length $\ge 2$, $a[l, r] = [a_l, a_{l+1}, \ldots, a_r]$ is the minimum value of $a_i \oplus a_j$ such that $l \le i < j \le r$, where $\oplus$ is the xor (exclusive-or) operator.

You have to find the $k$-th smallest value over all sub-arrays of length $\ge 2$.

### Input

The first line of the input contains multiple test cases $t$ ($1 \le t \le 2 \cdot 10^4$).

The first line of each test case contains integer numbers $n$ and $k$ ($2 \le n \le 10^5$, $1 \le k \le \frac{n\cdot(n-1)}{2}$).

The second line of the input contains $n$ non-negative integer numbers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the array itself.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

Print the $k$-th smallest value obtained over all subarrays of length at least $2$.

## Example

### Input


```text
45 21 2 3 4 52 14 34 61 2 4 85 91 2 3 4 5
```
### Output

```text

1
7
12
3

```
## Note

In the first testcase, we have subarrays with their smallest exclusive-or pair as:

$[1,2]: 3$

$[2,3]: 1$

$[3,4]: 7$

$[4,5]: 1$

$[1,2,3]: 1$

$[2,3,4]: 1$

$[3,4,5]: 1$

$[1,2,3,4]: 1$

$[2,3,4,5]: 1$

$[1,2,3,4,5]: 1$

The sorted order would be: $1, 1, 1, 1, 1, 1, 1, 1, 3, 7$. Therefore, the second smallest element would be $1$. 



#### Tags 

#2500 #NOT OK #binary_search #bitmasks #data_structures #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_956_(Div._2)_and_ByteRace_2024.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
