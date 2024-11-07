<h1 style='text-align: center;'> F. Diverse Segments</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. Also you are given $m$ subsegments of that array. The left and the right endpoints of the $j$-th segment are $l_j$ and $r_j$ respectively.

You are allowed to make no more than one operation. In that operation you choose any subsegment of the array $a$ and replace each value on this segment with any integer (you are also allowed to keep elements the same).

You have to apply this operation so that for the given $m$ segments, the elements on each segment are distinct. More formally, for each $1 \le j \le m$ all elements $a_{l_{j}}, a_{l_{j}+1}, \ldots, a_{r_{j}-1}, a_{r_{j}}$ should be distinct.

You don't want to use the operation on a big segment, so you have to find the smallest length of a segment, so that you can apply the operation to this segment and meet the above-mentioned conditions. If it is not needed to use this operation, the answer is $0$.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the size of the array and the number of segments respectively.

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of $a$.

Each of the next $m$ lines contains two integers $l_j$, $r_j$ ($1 \le l_j \le r_j \le n$) — the left and the right endpoints of the $j$-th segment.

It's guaranteed that the sum of $n$ and the sum of $m$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case output a single integer — the smallest length of a segment you can apply an operation on making the elements on all given segments distinct. If it is not needed to use the operation, output $0$.

## Example

### Input


```text
57 31 1 2 1 3 3 51 44 52 45 210 1 6 14 14 52 44 55 7 5 62 21 32 43 33 47 32 2 2 7 8 2 24 44 45 51 11231 1
```
### Output

```text

2
0
1
0
0

```
## Note

In the first test case you can perform the operation on the segment $[1, 2]$ and make $a = [5, 6, 2, 1, 3, 3, 5]$. Then the elements on each segment are distinct.

* On the segment $[1, 4]$ there are $[5, 6, 2, 1]$.
* On the segment $[4, 5]$ there are $[1, 3]$.
* On the segment $[2, 4]$ there are $[6, 2, 1, 3]$.

This way on each of the given segments all elements are distinct. Also, it is impossible to change any single integer to make elements distinct on each segment. That is why the answer is $2$.

In the second test case the elements on each segment are already distinct, so we should not perform the operation.

In the third test case we can replace the first $5$ by $1$. This way we will get $[1, 7, 5, 6]$ where all elements are distinct so on each given segment all elements are distinct.



#### Tags 

#2600 #NOT OK #data_structures #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_792_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
