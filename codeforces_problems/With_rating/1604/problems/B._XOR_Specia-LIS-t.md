<h1 style='text-align: center;'> B. XOR Specia-LIS-t</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

YouKn0wWho has an integer sequence $a_1, a_2, \ldots a_n$. Now he will split the sequence $a$ into one or more consecutive subarrays so that each element of $a$ belongs to exactly one subarray. Let $k$ be the number of resulting subarrays, and $h_1, h_2, \ldots, h_k$ be the lengths of the longest increasing subsequences of corresponding subarrays.

For example, if we split $[2, 5, 3, 1, 4, 3, 2, 2, 5, 1]$ into $[2, 5, 3, 1, 4]$, $[3, 2, 2, 5]$, $[1]$, then $h = [3, 2, 1]$.

YouKn0wWho wonders if it is possible to split the sequence $a$ in such a way that the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of $h_1, h_2, \ldots, h_k$ is equal to $0$. You have to tell whether it is possible.

The longest increasing subsequence (LIS) of a sequence $b_1, b_2, \ldots, b_m$ is the longest sequence of valid indices $i_1, i_2, \ldots, i_k$ such that $i_1 \lt i_2 \lt \ldots \lt i_k$ and $b_{i_1} \lt b_{i_2} \lt \ldots \lt b_{i_k}$. For example, the LIS of $[2, 5, 3, 3, 5]$ is $[2, 3, 5]$, which has length $3$.

An array $c$ is a subarray of an array $b$ if $c$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$)  — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print "YES" (without quotes) if it is possible to split into subarrays in the desired way, print "NO" (without quotes) otherwise. You can print each letter in any register (upper or lower).

## Example

### Input


```text
4
7
1 3 4 2 2 1 5
3
1 3 4
5
1 3 2 4 2
4
4 3 2 1
```
### Output


```text
YES
NO
YES
YES
```
## Note

In the first test case, YouKn0wWho can split the sequence in the following way: $[1, 3, 4]$, $[2, 2]$, $[1, 5]$. This way, the LIS lengths are $h = [3, 1, 2]$, and the bitwise XOR of the LIS lengths is $3 \oplus 1 \oplus 2 = 0$.

In the second test case, it can be shown that it is impossible to split the sequence into subarrays that will satisfy the condition.



#### Tags 

#1100 #NOT OK 

## Blogs
- [All Contest Problems](../Codeforces_Round_752_(Div._2).md)
- [Codeforces Round #752 (en)](../blogs/Codeforces_Round_752_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
