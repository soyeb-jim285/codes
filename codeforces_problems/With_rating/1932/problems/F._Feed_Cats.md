<h1 style='text-align: center;'> F. Feed Cats</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a fun game where you need to feed cats that come and go. The level of the game consists of $n$ steps. There are $m$ cats; the cat $i$ is present in steps from $l_i$ to $r_i$, inclusive. In each step, you can feed all the cats that are currently present or do nothing. 

If you feed the same cat more than once, it will overeat, and you will immediately lose the game. Your goal is to feed as many cats as possible without causing any cat to overeat. 

Find the maximum number of cats you can feed.

Formally, you need to select several integer points from the segment from $1$ to $n$ in such a way that among given segments, none covers two or more of the selected points, and as many segments as possible cover one of the selected points.

### Input

The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 10^6$, $1 \le m\le 2\cdot 10^5$). 

The $i$-th of the next $m$ lines contains a pair of integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$).

The sum of $n$ for all tests does not exceed $10^6$, the sum of $m$ for all tests does not exceed $2\cdot 10^5$.

### Output

For each test case, print a single integer, the maximum number of cats you can feed.

## Example

### Input


```text
315 62 103 52 47 78 1211 111000 11 10005 101 23 43 43 43 41 11 23 33 43 4
```
### Output

```text

5
1
10

```
## Note

In the first example, one of the ways to feed five cats is to feed at steps $4$ and $11$.

* At step $4$, cats $1$, $2$, and $3$ will be fed.
* At step $11$, cats $5$ and $6$ will be fed.


#### Tags 

#1900 #NOT OK #data_structures #dp #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_927_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
