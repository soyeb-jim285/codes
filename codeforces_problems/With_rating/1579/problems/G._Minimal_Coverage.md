<h1 style='text-align: center;'> G. Minimal Coverage</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ lengths of segments that need to be placed on an infinite axis with coordinates.

The first segment is placed on the axis so that one of its endpoints lies at the point with coordinate $0$. Let's call this endpoint the "start" of the first segment and let's call its "end" as that endpoint that is not the start. 

The "start" of each following segment must coincide with the "end" of the previous one. Thus, if the length of the next segment is $d$ and the "end" of the previous one has the coordinate $x$, the segment can be placed either on the coordinates $[x-d, x]$, and then the coordinate of its "end" is $x - d$, or on the coordinates $[x, x+d]$, in which case its "end" coordinate is $x + d$.

The total coverage of the axis by these segments is defined as their overall union which is basically the set of points covered by at least one of the segments. It's easy to show that the coverage will also be a segment on the axis. Determine the minimal possible length of the coverage that can be obtained by placing all the segments on the axis without changing their order.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The next $2t$ lines contain descriptions of the test cases. 

The first line of each test case description contains an integer $n$ ($1 \le n \le 10^4$) — the number of segments. The second line of the description contains $n$ space-separated integers $a_i$ ($1 \le a_i \le 1000$) — lengths of the segments in the same order they should be placed on the axis.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

### Output

Print $t$ lines, each line containing the answer to the corresponding test case. The answer to a test case should be a single integer — the minimal possible length of the axis coverage.

## Example

### Input


```text
6
2
1 3
3
1 2 3
4
6 2 3 9
4
6 8 4 5
7
1 2 4 6 7 7 3
8
8 6 5 1 2 2 3 6
```
### Output


```text
3
3
9
9
7
8
```
## Note

In the third sample test case the segments should be arranged as follows: $[0, 6] \rightarrow [4, 6] \rightarrow [4, 7] \rightarrow [-2, 7]$. As you can see, the last segment $[-2, 7]$ covers all the previous ones, and the total length of coverage is $9$.

In the fourth sample test case the segments should be arranged as $[0, 6] \rightarrow [-2, 6] \rightarrow [-2, 2] \rightarrow [2, 7]$. The union of these segments also occupies the area $[-2, 7]$ and has the length of $9$.



#### Tags 

#2200 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_744_(Div._3).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
