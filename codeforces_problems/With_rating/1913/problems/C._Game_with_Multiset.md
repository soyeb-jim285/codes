<h1 style='text-align: center;'> C. Game with Multiset</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In this problem, you are initially given an empty multiset. You have to process two types of queries:

1. ADD $x$ — add an element equal to $2^{x}$ to the multiset;
2. GET $w$ — say whether it is possible to take the sum of some subset of the current multiset and get a value equal to $w$.
#### Input

The first line contains one integer $m$ ($1 \le m \le 10^5$) — the number of queries.

Then $m$ lines follow, each of which contains two integers $t_i$, $v_i$, denoting the $i$-th query. If $t_i = 1$, then the $i$-th query is ADD $v_i$ ($0 \le v_i \le 29$). If $t_i = 2$, then the $i$-th query is GET $v_i$ ($0 \le v_i \le 10^9$).

#### Output

For each GET query, print YES if it is possible to choose a subset with sum equal to $w$, or NO if it is impossible.

## Examples

#### Input


```text
51 01 01 02 32 4
```
#### Output

```text

YES
NO

```
#### Input


```text
71 01 11 21 102 42 62 7
```
#### Output

```text

YES
YES
YES

```


#### Tags 

#1300 #NOT OK #binary_search #bitmasks #brute_force #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_160_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
