<h1 style='text-align: center;'> B. Consecutive Points Segment</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ points with integer coordinates on a coordinate axis $OX$. The coordinate of the $i$-th point is $x_i$. All points' coordinates are distinct and given in strictly increasing order.

For each point $i$, you can do the following operation no more than once: take this point and move it by $1$ to the left or to the right (i..e., you can change its coordinate $x_i$ to $x_i - 1$ or to $x_i + 1$). In other words, for each point, you choose (separately) its new coordinate. For the $i$-th point, it can be either $x_i - 1$, $x_i$ or $x_i + 1$.

Your task is to determine if you can move some points as described above in such a way that the new set of points forms a consecutive segment of integers, i. e. for some integer $l$ the coordinates of points should be equal to $l, l + 1, \ldots, l + n - 1$.

Note that the resulting points should have distinct coordinates.

You have to answer $t$ independent test cases.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. Then $t$ test cases follow.

The first line of the test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of points in the set $x$.

The second line of the test case contains $n$ integers $x_1 < x_2 < \ldots < x_n$ ($1 \le x_i \le 10^6$), where $x_i$ is the coordinate of the $i$-th point.

It is guaranteed that the points are given in strictly increasing order (this also means that all coordinates are distinct). It is also guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$ ($\sum n \le 2 \cdot 10^5$).

### Output

For each test case, print the answer — if the set of points from the test case can be moved to form a consecutive segment of integers, print YES, otherwise print NO.

## Example

### Input


```text
521 431 2 341 2 3 71100000032 5 6
```
### Output

```text

YES
YES
NO
YES
YES

```


#### Tags 

#1000 #NOT OK #brute_force #math #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_127_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
