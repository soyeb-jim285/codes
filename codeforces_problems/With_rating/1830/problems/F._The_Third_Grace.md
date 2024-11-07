<h1 style='text-align: center;'> F. The Third Grace</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given $n$ intervals and $m$ points on the number line. The $i$-th intervals covers coordinates $[l_i,r_i]$ and the $i$-th point is on coordinate $i$ and has coefficient $p_i$.

Initially, all points are not activated. You should choose a subset of the $m$ points to activate. For each of $n$ interval, we define its cost as: 

* $0$, if there are no activated points in the interval;
* the coefficient of the activated point with the largest coordinate within it, otherwise.

Your task is to maximize the sum of the costs of all intervals by choosing which points to activate.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 10^6, 1 \le m \le 10^6$) — the number of intervals and the number of points.

The following $n$ lines of each test case contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le m$) — the endpoints of the $i$-th interval.

The following line of each test case contains $m$ integers $p_1,p_2,\ldots,p_m$ ($0 \le p_i \le 10^9$) — the coefficients of the points.

It is guaranteed that the sum of $n$ does not exceed $10^6$ and the sum of $m$ does not exceed $10^6$.

### Output

### Output

 the maximum possible sum of costs of all intervals.

## Example

### Input


```text
22 81 53 878 0 50 0 0 0 0 301 61 50 0 0 0 0 100
```
### Output

```text

108
0

```
## Note

In the first sample, we can activate points $1$ and $8$. The sum of costs of all intervals will be $78+30=108$.

In the second sample, we will activate no points. The sum of costs of all intervals will be $0$.



#### Tags 

#3200 #NOT OK #data_structures #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_875_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
