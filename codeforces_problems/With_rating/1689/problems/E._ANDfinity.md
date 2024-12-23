<h1 style='text-align: center;'> E. ANDfinity</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bit Lightyear, to the ANDfinity and beyond!

After graduating from computer sciences, Vlad has been awarded an array $a_1,a_2,\ldots,a_n$ of $n$ non-negative integers. As it is natural, he wanted to construct a graph consisting of $n$ vertices, numbered $1, 2,\ldots, n$. He decided to add an edge between $i$ and $j$ if and only if $a_i \\& a_j > 0$, where $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

Vlad also wants the graph to be connected, which might not be the case initially. In order to satisfy that, he can do the following two types of operations on the array:

1. Choose some element $a_i$ and increment it by $1$.
2. Choose some element $a_i$ and decrement it by $1$ (possible only if $a_i > 0$).

It can be proven that there exists a finite sequence of operations such that the graph will be connected. So, can you please help Vlad find the minimum possible number of operations to do that and also provide the way how to do that?

### Input

There are several test cases in the input data. The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains an integer $n$ ($2\leq n \leq 2000$). 

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0\leq a_i < 2^{30}$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

### Output

For each test case, print a single integer $m$ in the first line — the minimum number of operations. In the second line print the array after a valid sequence of operations that have been done such that the graph from the task becomes connected. 

If there are multiple solutions, output any.

## Example

### Input


```text
4
5
1 2 3 4 5
2
0 2
2
3 12
4
3 0 0 0
```
### Output


```text
0
1 2 3 4 5
2
2 2
1
3 11
3
3 1 1 1
```
## Note

In the first test case, the graph is already connected.

In the second test case, we can increment $0$ twice and end up with the array $[2,2]$. Since $2 \\& 2 = 2 > 0$, the graph is connected. It can be shown that one operation is not enough.

In the third test case, we can decrement $12$ once and we end up with an array $[3,11]$. $3 \\& 11 = 3 > 0$ hence the graph is connected. One operation has to be done since the graph is not connected at the beginning.



#### Tags 

#2500 #NOT OK #bitmasks #brute_force #constructive_algorithms #dfs_and_similar #dsu #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_798_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
