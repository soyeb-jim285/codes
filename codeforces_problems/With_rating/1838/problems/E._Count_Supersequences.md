<h1 style='text-align: center;'> E. Count Supersequences</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers, where all elements $a_i$ lie in the range $[1, k]$. How many different arrays $b$ of $m$ integers, where all elements $b_i$ lie in the range $[1, k]$, contain $a$ as a subsequence? Two arrays are considered different if they differ in at least one position.

A sequence $x$ is a subsequence of a sequence $y$ if $x$ can be obtained from $y$ by the deletion of several (possibly, zero or all) elements.

Since the answer may be large, print it modulo $10^9 + 7$.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers $n$, $m$, $k$ ($1 \le n \le 2\cdot 10^5$, $n \le m \le 10^9$, $1 \le k \le 10^9$) — the size of $a$, the size of $b$, and the maximum value allowed in the arrays, respectively.

The next line of each test case contains $n$ integers $a_1, a_2, \ldots a_n$ ($1\le a_i \le k$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output a single integer — the number of suitable arrays $b$, modulo $10^9+7$.

## Example

### Input


```text
71 1000000 113 4 31 2 25 7 81 2 3 4 16 6 1818 2 2 5 2 161 10 218 10 12345671 1 2 1 2 2 2 15 1000000000 1000000000525785549 816356460 108064697 194447117 725595511
```
### Output

```text

1
9
1079
1
1023
906241579
232432822

```
## Note

For the first example, since $k=1$, there is only one array of size $m$ consisting of the integers $[1, k]$. This array ($[1, 1, \ldots, 1]$) contains the original array as a subsequence, so the answer is 1.

For the second example, the $9$ arrays are $[1, 1, 2, 2]$, $[1, 2, 1, 2]$, $[1, 2, 2, 1]$, $[1, 2, 2, 2]$, $[1, 2, 2, 3]$, $[1, 2, 3, 2]$, $[1, 3, 2, 2]$, $[2, 1, 2, 2]$, $[3, 1, 2, 2]$.

For the fourth example, since $m=n$, the only array of size $m$ that contains $a$ as a subsequence is $a$ itself.



#### Tags 

#2500 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_877_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
