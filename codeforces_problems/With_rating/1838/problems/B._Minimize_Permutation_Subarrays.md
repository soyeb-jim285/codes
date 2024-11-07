<h1 style='text-align: center;'> B. Minimize Permutation Subarrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of size $n$. You want to minimize the number of subarrays of $p$ that are permutations. In order to do so, you must perform the following operation exactly once:

* Select integers $i$, $j$, where $1 \le i, j \le n$, then
* Swap $p_i$ and $p_j$.

For example, if $p = [5, 1, 4, 2, 3]$ and we choose $i = 2$, $j = 3$, the resulting array will be $[5, 4, 1, 2, 3]$. If instead we choose $i = j = 5$, the resulting array will be $[5, 1, 4, 2, 3]$.

Which choice of $i$ and $j$ will minimize the number of subarrays that are permutations?

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

An array $a$ is a subarray of an array $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 2\cdot 10^5$) — the size of the permutation.

The next line of each test case contains $n$ integers $p_1, p_2, \ldots p_n$ ($1 \le p_i \le n$, all $p_i$ are distinct) — the elements of the permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output two integers $i$ and $j$ ($1 \le i, j \le n$)  — the indices to swap in $p$.

If there are multiple solutions, print any of them.

## Example

### Input


```text
831 2 331 3 251 3 2 5 464 5 6 1 2 398 7 6 3 2 1 4 5 9107 10 5 1 9 8 3 2 6 4108 5 10 9 2 1 3 4 6 7102 3 5 7 10 1 8 6 4 9
```
### Output

```text

2 3
1 1
5 2
1 4
9 5
8 8
6 10
5 4

```
## Note

For the first test case, there are four possible arrays after the swap: 

* If we swap $p_1$ and $p_2$, we get the array $[2, 1, 3]$, which has 3 subarrays that are permutations ($[1]$, $[2, 1]$, $[2, 1, 3]$).
* If we swap $p_1$ and $p_3$, we get the array $[3, 2, 1]$, which has 3 subarrays that are permutations ($[1]$, $[2, 1]$, $[3, 2, 1]$).
* If we swap $p_2$ and $p_3$, we get the array $[1, 3, 2]$, which has 2 subarrays that are permutations ($[1]$, $[1, 3, 2]$).
* If we swap any element with itself, we get the array $[1, 2, 3]$, which has 3 subarrays that are permutations ($[1]$, $[1, 2]$, $[1, 2, 3]$).

 So the best swap to make is positions $2$ and $3$.For the third sample case, after we swap elements at positions $2$ and $5$, the resulting array is $[1, 4, 2, 5, 3]$. The only subarrays that are permutations are $[1]$ and $[1, 4, 2, 5, 3]$. We can show that this is minimal.



#### Tags 

#1100 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_877_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
