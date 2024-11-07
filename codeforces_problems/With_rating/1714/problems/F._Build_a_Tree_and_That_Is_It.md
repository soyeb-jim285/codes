<h1 style='text-align: center;'> F. Build a Tree and That Is It</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A tree is a connected undirected graph without cycles. Note that in this problem, we are talking about not rooted trees.

You are given four positive integers $n, d_{12}, d_{23}$ and $d_{31}$. Construct a tree such that:

* it contains $n$ vertices numbered from $1$ to $n$,
* the distance (length of the shortest path) from vertex $1$ to vertex $2$ is $d_{12}$,
* distance from vertex $2$ to vertex $3$ is $d_{23}$,
* the distance from vertex $3$ to vertex $1$ is $d_{31}$.

### Output

 any tree that satisfies all the requirements above, or determine that no such tree exists.

### Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) —the number of test cases in the test.

This is followed by $t$ test cases, each written on a separate line.

Each test case consists of four positive integers $n, d_{12}, d_{23}$ and $d_{31}$ ($3 \le n \le 2\cdot10^5; 1 \le d_{12}, d_{23}, d_{31} \le n-1$).

It is guaranteed that the sum of $n$ values for all test cases does not exceed $2\cdot10^5$.

### Output

For each test case, print YES if the suitable tree exists, and NO otherwise. 

If the answer is positive, print another $n-1$ line each containing a description of an edge of the tree — a pair of positive integers $x_i, y_i$, which means that the $i$th edge connects vertices $x_i$ and $y_i$. 

The edges and vertices of the edges can be printed in any order. If there are several suitable trees, output any of them.

## Example

### Input


```text
95 1 2 15 2 2 25 2 2 35 2 2 45 3 2 34 2 1 14 3 1 14 1 2 37 1 4 1
```
### Output

```text

YES
1 2
4 1
3 1
2 5
YES
4 3
2 5
1 5
5 3
NO
YES
2 4
4 1
2 5
5 3
YES
5 4
4 1
2 5
3 5
YES
2 3
3 4
1 3
NO
YES
4 3
1 2
2 4
NO

```


#### Tags 

#1900 #NOT OK #constructive_algorithms #implementation #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_811_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
