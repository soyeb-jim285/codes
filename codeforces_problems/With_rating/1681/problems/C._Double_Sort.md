<h1 style='text-align: center;'> C. Double Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$, both consisting of $n$ integers.

In one move, you can choose two indices $i$ and $j$ ($1 \le i, j \le n$; $i \neq j$) and swap $a_i$ with $a_j$ and $b_i$ with $b_j$. You have to perform the swap in both arrays.

You are allowed to perform at most $10^4$ moves (possibly, zero). Can you make both arrays sorted in a non-decreasing order at the end? If you can, print any sequence of moves that makes both arrays sorted.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 100$) — the number of elements in both arrays.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — the first array.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le n$) — the second array.

### Output

For each testcase, print the answer. If it's impossible to make both arrays sorted in a non-decreasing order in at most $10^4$ moves, print -1. Otherwise, first, print the number of moves $k$ $(0 \le k \le 10^4)$. Then print $i$ and $j$ for each move $(1 \le i, j \le n$; $i \neq j)$.

If there are multiple answers, then print any of them. You don't have to minimize the number of moves.

## Example

### Input


```text
321 21 222 11 242 3 1 22 3 2 3
```
### Output

```text

0
-1
3
3 1
3 2
4 3

```


#### Tags 

#1200 #OK #implementation #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_129_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
