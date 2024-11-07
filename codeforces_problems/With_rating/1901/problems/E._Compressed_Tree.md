<h1 style='text-align: center;'> E. Compressed Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree consisting of $n$ vertices. A number is written on each vertex; the number on vertex $i$ is equal to $a_i$.

You can perform the following operation any number of times (possibly zero): 

* choose a vertex which has at most $1$ incident edge and remove this vertex from the tree.

Note that you can delete all vertices.

After all operations are done, you're compressing the tree. The compression process is done as follows. While there is a vertex having exactly $2$ incident edges in the tree, perform the following operation: 

* delete this vertex, connect its neighbors with an edge.

It can be shown that if there are multiple ways to choose a vertex to delete during the compression process, the resulting tree is still the same.

Your task is to calculate the maximum possible sum of numbers written on vertices after applying the aforementioned operation any number of times, and then compressing the tree.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 5 \cdot 10^5$) — the number of vertices.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$).

Each of the next $n - 1$ lines describes an edge of the tree. Edge $i$ is denoted by two integers $v_i$ and $u_i$, the labels of vertices it connects ($1 \le v_i, u_i \le n$, $v_i \ne u_i$). These edges form a tree. 

Additional constraint on the input: the sum of $n$ over all test cases doesn't exceed $5 \cdot 10^5$.

### Output

For each test case, print a single integer — the maximum possible sum of numbers written on vertices after applying the aforementioned operation any number of times, and then compressing the tree.

## Example

### Input


```text
341 -2 2 11 23 22 42-2 -52 17-2 4 -2 3 3 2 -11 22 33 43 54 64 7
```
### Output

```text

3
0
9

```


#### Tags 

#2200 #NOT OK #dfs_and_similar #dp #graphs #greedy #sortings #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_158_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
