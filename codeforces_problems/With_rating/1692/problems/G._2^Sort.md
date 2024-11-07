<h1 style='text-align: center;'> G. 2^Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of length $n$ and an integer $k$, find the number of indices $1 \leq i \leq n - k$ such that the subarray $[a_i, \dots, a_{i+k}]$ with length $k+1$ (not with length $k$) has the following property: 

* If you multiply the first element by $2^0$, the second element by $2^1$, ..., and the ($k+1$)-st element by $2^k$, then this subarray is sorted in strictly increasing order.

 More formally, count the number of indices $1 \leq i \leq n - k$ such that $$2^0 \cdot a_i < 2^1 \cdot a_{i+1} < 2^2 \cdot a_{i+2} < \dots < 2^k \cdot a_{i+k}.$$ 
### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains two integers $n$, $k$ ($3 \leq n \leq 2 \cdot 10^5$, $1 \leq k < n$) — the length of the array and the number of inequalities.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^9$) — the elements of the array.

The sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the number of indices satisfying the condition in the statement.

## Example

### Input


```text
64 220 22 19 845 19 5 3 2 15 29 5 3 2 17 222 12 16 4 3 22 127 322 12 16 4 3 22 129 33 9 12 3 9 12 3 9 12
```
### Output

```text

2
3
2
3
1
0

```
## Note

In the first test case, both subarrays satisfy the condition: 

* $i=1$: the subarray $[a_1,a_2,a_3] = [20,22,19]$, and $1 \cdot 20 < 2 \cdot 22 < 4 \cdot 19$.
* $i=2$: the subarray $[a_2,a_3,a_4] = [22,19,84]$, and $1 \cdot 22 < 2 \cdot 19 < 4 \cdot 84$.

 In the second test case, three subarrays satisfy the condition: * $i=1$: the subarray $[a_1,a_2] = [9,5]$, and $1 \cdot 9 < 2 \cdot 5$.
* $i=2$: the subarray $[a_2,a_3] = [5,3]$, and $1 \cdot 5 < 2 \cdot 3$.
* $i=3$: the subarray $[a_3,a_4] = [3,2]$, and $1 \cdot 3 < 2 \cdot 2$.
* $i=4$: the subarray $[a_4,a_5] = [2,1]$, but $1 \cdot 2 = 2 \cdot 1$, so this subarray doesn't satisfy the condition.


#### Tags 

#1400 #NOT OK #data_structures #dp #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_799_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
