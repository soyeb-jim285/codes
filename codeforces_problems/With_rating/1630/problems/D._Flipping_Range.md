<h1 style='text-align: center;'> D. Flipping Range</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers and a set $B$ of $m$ positive integers such that $1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor$ for $1\le i\le m$, where $b_i$ is the $i$-th element of $B$. 

You can make the following operation on $a$:

1. Select some $x$ such that $x$ appears in $B$.
2. Select an interval from array $a$ of size $x$ and multiply by $-1$ every element in the interval. Formally, select $l$ and $r$ such that $1\leq l\leq r \leq n$ and $r-l+1=x$, then assign $a_i:=-a_i$ for every $i$ such that $l\leq i\leq r$.

Consider the following example, let $a=[0,6,-2,1,-4,5]$ and $B=\{1,2\}$:

1. $[0,6,-2,-1,4,5]$ is obtained after choosing size $2$ and $l=4$, $r=5$.
2. $[0,6,2,-1,4,5]$ is obtained after choosing size $1$ and $l=3$, $r=3$.

Find the maximum $\sum\limits_{i=1}^n {a_i}$ you can get after applying such operation any number of times (possibly zero).

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2\leq n \leq 10^6$, $1 \leq m \leq \lfloor \frac{n}{2} \rfloor$) — the number of elements of $a$ and $B$ respectively. 

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^9\leq a_i \leq 10^9$). 

The third line of each test case contains $m$ distinct positive integers $b_1,b_2,\ldots,b_m$ ($1 \leq b_i \leq \lfloor \frac{n}{2} \rfloor$) — the elements in the set $B$.

It's guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case print a single integer — the maximum possible sum of all $a_i$ after applying such operation any number of times. 

## Example

### Input


```text
36 20 6 -2 1 -4 51 27 11 -1 1 -1 1 -1 125 1-1000000000 -1000000000 -1000000000 -1000000000 -10000000001
```
### Output

```text

18
5
5000000000

```
## Note

In the first test, you can apply the operation $x=1$, $l=3$, $r=3$, and the operation $x=1$, $l=5$, $r=5$, then the array becomes $[0, 6, 2, 1, 4, 5]$.

In the second test, you can apply the operation $x=2$, $l=2$, $r=3$, and the array becomes $[1, 1, -1, -1, 1, -1, 1]$, then apply the operation $x=2$, $l=3$, $r=4$, and the array becomes $[1, 1, 1, 1, 1, -1, 1]$. There is no way to achieve a sum bigger than $5$.



#### Tags 

#2400 #NOT OK #constructive_algorithms #dp #greedy #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_768_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
