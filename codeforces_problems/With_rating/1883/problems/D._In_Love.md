<h1 style='text-align: center;'> D. In Love</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Initially, you have an empty multiset of segments. You need to process $q$ operations of two types:

* $+$ $l$ $r$ — Add the segment $(l, r)$ to the multiset,
* $-$ $l$ $r$ — Remove exactly one segment $(l, r)$ from the multiset. It is guaranteed that this segment exists in the multiset.

After each operation, you need to determine if there exists a pair of segments in the multiset that do not intersect. A pair of segments $(l, r)$ and $(a, b)$ do not intersect if there does not exist a point $x$ such that $l \leq x \leq r$ and $a \leq x \leq b$.

### Input

The first line of each test case contains an integer $q$ ($1 \leq q \leq 10^5$) — the number of operations.

The next $q$ lines describe two types of operations. If it is an addition operation, it is given in the format $+$ $l$ $r$. If it is a deletion operation, it is given in the format $-$ $l$ $r$ ($1 \leq l \leq r \leq 10^9$).

### Output

After each operation, print "YES" if there exists a pair of segments in the multiset that do not intersect, and "NO" otherwise.

You can print the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

## Example

### Input


```text
12+ 1 2+ 3 4+ 2 3+ 2 2+ 3 4- 3 4- 3 4- 1 2+ 3 4- 2 2- 2 3- 3 4
```
### Output

```text

NO
YES
YES
YES
YES
YES
NO
NO
YES
NO
NO
NO

```
## Note

In the example, after the second, third, fourth, and fifth operations, there exists a pair of segments $(1, 2)$ and $(3, 4)$ that do not intersect.

Then we remove exactly one segment $(3, 4)$, and by that time we had two segments. Therefore, the answer after this operation also exists.



#### Tags 

#1500 #NOT OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_905_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
