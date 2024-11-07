<h1 style='text-align: center;'> A. Grasshopper on a Line</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $x$ and $k$. Grasshopper starts in a point $0$ on an OX axis. In one move, it can jump some integer distance, that is not divisible by $k$, to the left or to the right.

What's the smallest number of moves it takes the grasshopper to reach point $x$? What are these moves? If there are multiple answers, print any of them.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

The only line of each testcase contains two integers $x$ and $k$ ($1 \le x \le 100$; $2 \le k \le 100$) — the endpoint and the constraint on the jumps, respectively.

### Output

For each testcase, in the first line, print a single integer $n$ — the smallest number of moves it takes the grasshopper to reach point $x$.

In the second line, print $n$ integers, each of them not divisible by $k$. A positive integer would mean jumping to the right, a negative integer would mean jumping to the left. The endpoint after the jumps should be exactly $x$.

Each jump distance should be from $-10^9$ to $10^9$. In can be shown that, for any solution with the smallest number of jumps, there exists a solution with the same number of jumps such that each jump is from $-10^9$ to $10^9$.

It can be shown that the answer always exists under the given constraints. If there are multiple answers, print any of them.

## Example

### Input


```text
310 210 33 4
```
### Output

```text

2
7 3
1
10
1
3

```


#### Tags 

#800 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_149_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
