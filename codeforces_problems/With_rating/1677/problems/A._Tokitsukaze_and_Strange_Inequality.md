<h1 style='text-align: center;'> A. Tokitsukaze and Strange Inequality</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tokitsukaze has a permutation $p$ of length $n$. Recall that a permutation $p$ of length $n$ is a sequence $p_1, p_2, \ldots, p_n$ consisting of $n$ distinct integers, each of which from $1$ to $n$ ($1 \leq p_i \leq n$).

She wants to know how many different indices tuples $[a,b,c,d]$ ($1 \leq a < b < c < d \leq n$) in this permutation satisfy the following two inequalities:

 $p_a < p_c$ and $p_b > p_d$. 
## Note

 that two tuples $[a_1,b_1,c_1,d_1]$ and $[a_2,b_2,c_2,d_2]$ are considered to be different if $a_1 \ne a_2$ or $b_1 \ne b_2$ or $c_1 \ne c_2$ or $d_1 \ne d_2$.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Each test case consists of two lines.

The first line contains a single integer $n$ ($4 \leq n \leq 5000$) — the length of permutation $p$.

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \leq p_i \leq n$) — the permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$.

### Output

For each test case, print a single integer — the number of different $[a,b,c,d]$ tuples.

## Example

### Input


```text
365 3 6 1 4 241 2 3 4105 1 6 2 8 3 4 10 9 7
```
### Output

```text

3
0
28

```
## Note

In the first test case, there are $3$ different $[a,b,c,d]$ tuples.

$p_1 = 5$, $p_2 = 3$, $p_3 = 6$, $p_4 = 1$, where $p_1 < p_3$ and $p_2 > p_4$ satisfies the inequality, so one of $[a,b,c,d]$ tuples is $[1,2,3,4]$.

Similarly, other two tuples are $[1,2,3,6]$, $[2,3,5,6]$.



#### Tags 

#1600 #NOT OK #brute_force #data_structures #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_789_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
