<h1 style='text-align: center;'> F. Two Subtrees</h1>

<h5 style='text-align: center;'>time limit per test: 9 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a rooted tree consisting of $n$ vertices. The vertex $1$ is the root. Each vertex has an integer written on it; this integer is $val_i$ for the vertex $i$.

You are given $q$ queries to the tree. The $i$-th query is represented by two vertices, $u_i$ and $v_i$. To answer the query, consider all vertices $w$ that lie in the subtree of $u_i$ or $v_i$ (if a vertex is in both subtrees, it is counted twice). For all vertices in these two subtrees, list all integers written on them, and find the integer with the maximum number of occurrences. If there are multiple integers with maximum number of occurrences, the minimum among them is the answer.

### Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of vertices in the tree.

The second line contains $n$ integers $val_1, val_2, \dots, val_n$ ($1 \le val_i \le 2 \cdot 10^5$) — the numbers written on the vertices.

Then $n - 1$ lines follow, each containing two integers $x$ and $y$ ($1 \le x, y \le n$) representing an edge between vertices $x$ and $y$. These edges form a tree.

The next line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries to process.

Then $q$ lines follow. The $i$-th of them containing two numbers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$) — the roots of subtrees in the $i$-th query.

### Output

For each query, print one integer — the number that has the maximum amount of occurrences in the corresponding pair of subtrees (if there are multiple such numbers, print the minimum one among them).

## Example

### Input


```text
8
2 1 3 2 3 3 2 4
1 2
1 3
2 4
3 5
3 6
3 7
7 8
6
2 7
3 7
2 3
1 1
5 6
1 3
```
### Output


```text
2
3
3
2
3
3
```
## Note

In the $1$-st query, the pair of subtrees consists of vertices $[2, 4, 7, 8]$, and the numbers written on them are $\{1, 2, 2, 4\}$. The number $2$ occurs twice, all other numbers — at most once, so the answer is $2$.

In the $2$-nd query, the pair of subtrees consists of vertices $[3, 5, 6, 7, 7, 8, 8]$, and the numbers written on them are $\{3, 3, 3, 2, 2, 4, 4\}$. The number $3$ has the maximum number of occurrences.

In the $4$-th query, the pair of subtrees consists of vertices $[1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8]$, and the numbers written on them are $\{2, 2, 1, 1, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 4, 4\}$. The numbers $2$ and $3$ are the most common, the minimum of them is $2$.



#### Tags 

#3100 #NOT OK #data_structures #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_140_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
