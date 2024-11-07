<h1 style='text-align: center;'> D. Split</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an array $b_1, b_2, \ldots, b_m$ ($m \ge 2$) good if it can be split into two parts such that all elements in the left part are strictly smaller than all elements in the right part. In other words, there must exist an index $1 \le i < m$ such that every element from $b_1, \ldots, b_i$ is strictly smaller than every element from $b_{i+1}, \ldots, b_m$.

Given an array $a_1, a_2, \ldots a_n$ consisting of distinct integers from $1$ to $n$. There are $q$ queries. Each query consists of two numbers $l$ and $r$. For each query, determine whether the array $a_l, a_{l+1}, \ldots, a_r$ is good.

#### Input

The first line contains a single integer $n$ ($2 \le n \le 3 \cdot 10^5$) — the size of the array.

The second line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ ($1 \le a_n \le n$) — the elements of the array $a$.

The third line contains a single integer $q$ ($1 \le q \le 3 \cdot 10^5$) — the number of queries.

Each of the next $q$ lines contains two integers $l_i$ and $r_i$ ($1 \le l_i < r_i \le n$) — the description of the $i$-th query.

#### Output

For each query, output "Yes" (without quotes) if the array $a_l, a_{l+1}, \ldots, a_r$ is good, and "No" (without quotes) otherwise.

You can output "Yes" and "No" in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Examples

#### Input


```text
5
3 2 1 4 5
5
1 5
1 3
1 4
1 2
2 5
```
#### Output


```text
Yes
No
Yes
No
Yes
```
#### Input


```text
6
1 6 2 4 3 5
3
3 5
2 6
4 6
```
#### Output


```text
Yes
No
Yes
```
## Note

In the first example:

* The array $[3,2,1,4,5]$ can be split into two parts: $[3,2,1]$ and $[4,5]$.
* The array $[3,2,1]$ cannot be split into two parts such that all elements in the left part are smaller than all elements in the right part.
* The array $[3,2,1,4]$ can be split into two parts: $[3,2,1]$ and $[4]$.
* The array $[3,2]$ cannot be split into two parts such that all elements in the left part are smaller than all elements in the right part.
* The array $[2,1,4,5]$ can be split into two parts: $[2,1]$ and $[4,5]$.

In the second example:

* The array $[2,4,3]$ can be split into two parts: $[2]$ and $[4,3]$.
* The array $[6,2,4,3,5]$ cannot be split into two parts such that all elements in the left part are smaller than all elements in the right part.
* The array $[4,3,5]$ can be split into two parts: $[4,3]$ and $[5]$.


#### Tags 

#2700 #NOT OK #binary_search #data_structures #divide_and_conquer #dsu #math #trees #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_905_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
