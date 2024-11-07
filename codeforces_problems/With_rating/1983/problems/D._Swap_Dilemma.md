<h1 style='text-align: center;'> D. Swap Dilemma</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given two arrays of distinct positive integers $a$ and $b$ of length $n$, we would like to make both the arrays the same. Two arrays $x$ and $y$ of length $k$ are said to be the same when for all $1 \le i \le k$, $x_i = y_i$.

Now in one move, you can choose some index $l$ and $r$ in $a$ ($l \le r$) and swap $a_l$ and $a_r$, then choose some $p$ and $q$ ($p \le q$) in $b$ such that $r-l=q-p$ and swap $b_p$ and $b_q$.

Is it possible to make both arrays the same?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2 \cdot 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the arrays $a$ and $b$.

The second line of each test case contains $n$ distinct integers $a_1,a_2,a_3,\ldots,a_n$ ($1 \le a_i \le 2 \cdot 10^5$) — the integers in the array $a$.

The third line of each test case contains $n$ distinct integers $b_1,b_2,b_3,\ldots,b_n$ ($1 \le b_i \le 2 \cdot 10^5$) — the integers in the array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each testcase, print "YES" if the arrays $a$ and $b$ can be made the same. Otherwise, print "NO". can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
641 2 3 41 2 3 451 3 4 2 57 1 2 5 441 2 3 44 3 2 131 2 31 3 251 5 7 1000 44 1 7 5 100031 4 21 3 2
```
### Output

```text

YES
NO
YES
NO
NO
NO

```
## Note

In the first testcase, you don't need to perform any operations since the arrays are same.

In the second testcase, it can be proven there exists no way to make the arrays same.

In the third testcase, one of the ways to make the arrays same is to first choose $l=1$, $r=3$, $p=1$, $q=3$ then choose $l=1$, $r=2$, $p=3$, $q=4$.



#### Tags 

#1700 #OK #constructive_algorithms #data_structures #divide_and_conquer #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_956_(Div._2)_and_ByteRace_2024.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
