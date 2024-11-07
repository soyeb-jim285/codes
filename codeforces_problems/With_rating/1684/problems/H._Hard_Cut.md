<h1 style='text-align: center;'> H. Hard Cut</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$. You have to cut it into any number of non-intersecting substrings, so that the sum of binary integers denoted by these substrings is a power of 2. Each element of $s$ should be in exactly one substring.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

Each test case contains a binary string $s$ ($1 \le |s| \le 10^6$).

It is guaranteed that the sum of $|s|$ over all test cases does not exceed $10^6$.

### Output

For each test case output the answer to the problem as follows: 

* If the answer does not exist, output $-1$.
* If the answer exists, firstly output an integer $k$ — the number of substrings in the answer. After that output $k$ non-intersecting substrings, for $i$-th substring output two integers $l_i, r_i$ ($1 \le l_i, r_i \le |s|$) — the description of $i$-th substring.

If there are multiple valid solutions, you can output any of them.

## Example

### Input


```text
4
00000
01101
0111011001011
000111100111110
```
### Output


```text
-1

3
1 3
4 4
5 5

8
1 2
3 3
4 4
5 6
7 7
8 10
11 12
13 13

5
1 5
6 7
8 11
12 14
15 15
```
## Note

In the first test case it is impossible to cut the string into substrings, so that the sum is a power of 2.

In the second test case such cut is valid: 

* $011_2 = 3_{10}$,
* $0_2 = 0_{10}$,
* $1_2 = 1_{10}$.

 $3 + 0 + 1 = 4$, $4$ is a power of 2.

#### Tags 

#3400 #NOT OK #constructive_algorithms #dfs_and_similar #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_792_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
