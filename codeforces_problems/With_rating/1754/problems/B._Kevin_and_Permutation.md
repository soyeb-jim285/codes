<h1 style='text-align: center;'> B. Kevin and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For his birthday, Kevin received the set of pairwise distinct numbers $1, 2, 3, \ldots, n$ as a gift.

He is going to arrange these numbers in a way such that the minimum absolute difference between two consecutive numbers be maximum possible. More formally, if he arranges numbers in order $p_1, p_2, \ldots, p_n$, he wants to maximize the value $$\min \limits_{i=1}^{n - 1} \lvert p_{i + 1} - p_i \rvert,$$ where $|x|$ denotes the absolute value of $x$.

Help Kevin to do that.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Description of the test cases follows.

The only line of each test case contains an integer $n$ ($2 \le n \leq 1\,000$) — the size of the set.

### Output

For each test case print a single line containing $n$ distinct integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) describing the arrangement that maximizes the minimum absolute difference of consecutive elements. 

Formally, you have to print a permutation $p$ which maximizes the value $\min \limits_{i=1}^{n - 1} \lvert p_{i + 1} - p_i \rvert$.

If there are multiple optimal solutions, print any of them.

## Example

### Input


```text
243
```
### Output

```text

2 4 1 3
1 2 3

```
## Note

In the first test case the minimum absolute difference of consecutive elements equals $\min \{\lvert 4 - 2 \rvert, \lvert 1 - 4 \rvert, \lvert 3 - 1 \rvert \} = \min \{2, 3, 2\} = 2$. It's easy to prove that this answer is optimal.

In the second test case each permutation of numbers $1, 2, 3$ is an optimal answer. The minimum absolute difference of consecutive elements equals to $1$.



#### Tags 

#800 #OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_829_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
