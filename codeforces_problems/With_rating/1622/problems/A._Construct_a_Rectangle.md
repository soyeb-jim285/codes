<h1 style='text-align: center;'> A. Construct a Rectangle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are three sticks with integer lengths $l_1, l_2$ and $l_3$.

You are asked to break exactly one of them into two pieces in such a way that: 

* both pieces have positive (strictly greater than $0$) integer length;
* the total length of the pieces is equal to the original length of the stick;
* it's possible to construct a rectangle from the resulting four sticks such that each stick is used as exactly one of its sides.

A square is also considered a rectangle.

Determine if it's possible to do that.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The only line of each testcase contains three integers $l_1, l_2, l_3$ ($1 \le l_i \le 10^8$) — the lengths of the sticks.

### Output

For each testcase, print "YES" if it's possible to break one of the sticks into two pieces with positive integer length in such a way that it's possible to construct a rectangle from the resulting four sticks. Otherwise, print "NO".

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as a positive answer).

## Example

### Input


```text
4
6 1 5
2 5 2
2 4 2
5 5 4
```
### Output


```text
YES
NO
YES
YES
```
## Note

In the first testcase, the first stick can be broken into parts of length $1$ and $5$. We can construct a rectangle with opposite sides of length $1$ and $5$.

In the second testcase, breaking the stick of length $2$ can only result in sticks of lengths $1, 1, 2, 5$, which can't be made into a rectangle. Breaking the stick of length $5$ can produce results $2, 3$ or $1, 4$ but neither of them can't be put into a rectangle.

In the third testcase, the second stick can be broken into parts of length $2$ and $2$. The resulting rectangle has opposite sides $2$ and $2$ (which is a square).

In the fourth testcase, the third stick can be broken into parts of length $2$ and $2$. The resulting rectangle has opposite sides $2$ and $5$.



#### Tags 

#800 #OK #geometry #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_120_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
