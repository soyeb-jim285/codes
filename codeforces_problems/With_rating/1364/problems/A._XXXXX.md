<h1 style='text-align: center;'> A. XXXXX</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ehab loves number theory, but for some reason he hates the number $x$. Given an array $a$, find the length of its longest subarray such that the sum of its elements isn't divisible by $x$, or determine that such subarray doesn't exist.

An array $a$ is a subarray of an array $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

The first line contains an integer $t$ $(1 \le t \le 5)$ — the number of test cases you need to solve. The description of the test cases follows.

The first line of each test case contains 2 integers $n$ and $x$ ($1 \le n \le 10^5$, $1 \le x \le 10^4$) — the number of elements in the array $a$ and the number that Ehab hates.

The second line contains $n$ space-separated integers $a_1$, $a_2$, $\ldots$, $a_{n}$ ($0 \le a_i \le 10^4$) — the elements of the array $a$.

### Output

For each testcase, print the length of the longest subarray whose sum isn't divisible by $x$. If there's no such subarray, print $-1$.

## Example

### Input


```text
3
3 3
1 2 3
3 4
1 2 3
2 2
0 6
```
### Output


```text
2
3
-1
```
## Note

In the first test case, the subarray $[2,3]$ has sum of elements $5$, which isn't divisible by $3$.

In the second test case, the sum of elements of the whole array is $6$, which isn't divisible by $4$.

In the third test case, all subarrays have an even sum, so the answer is $-1$.



#### Tags 

#1200 #NOT OK #brute_force #data_structures #number_theory #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_649_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
