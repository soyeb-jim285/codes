<h1 style='text-align: center;'> A. Stickogon</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ sticks of lengths $a_1, a_2, \ldots, a_n$. Find the maximum number of regular (equal-sided) polygons you can construct simultaneously, such that: 

* Each side of a polygon is formed by exactly one stick.
* No stick is used in more than $1$ polygon.

## Note

: Sticks cannot be broken.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the number of sticks available.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 100$) — the stick lengths.

### Output

For each test case, output a single integer on a new line — the maximum number of regular (equal-sided) polygons you can make simultaneously from the sticks available.

## Example

### Input


```text
41121 162 2 3 3 3 394 2 2 2 2 4 2 4 4
```
### Output

```text

0
0
1
2

```
## Note

In the first test case, we only have one stick, hence we can't form any polygon.

In the second test case, the two sticks aren't enough to form a polygon either.

In the third test case, we can use the $4$ sticks of length $3$ to create a square.

In the fourth test case, we can make a pentagon with side length $2$, and a square of side length $4$.



#### Tags 

#800 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_940_(Div._2)_and_CodeCraft-23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
