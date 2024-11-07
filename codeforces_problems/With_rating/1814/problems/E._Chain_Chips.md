<h1 style='text-align: center;'> E. Chain Chips</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an undirected graph consisting of $n$ vertices and $n-1$ edges. The $i$-th edge has weight $a_i$; it connects the vertices $i$ and $i+1$.

Initially, each vertex contains a chip. Each chip has an integer written on it; the integer written on the chip in the $i$-th vertex is $i$.

In one operation, you can choose a chip (if there are multiple chips in a single vertex, you may choose any one of them) and move it along one of the edges of the graph. The cost of this operation is equal to the weight of the edge.

The cost of the graph is the minimum cost of a sequence of such operations that meets the following condition:

* after all operations are performed, each vertex contains exactly one chip, and the integer on each chip is not equal to the index of the vertex where that chip is located.

You are given $q$ queries of the form:

* $k$ $x$ — change the weight of the $k$-th edge (the one which connects the vertices $k$ and $k+1$) to $x$.

After each query, print the cost of the graph. Note that you don't actually move any chips; when you compute the cost, the chips are on their initial positions.

### Input

The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line contains $n-1$ integers $a_1, a_2, \dots, a_{n-1}$ ($1 \le a_i \le 10^9$).

The third line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Then $q$ lines follow. The $i$-th of them contains two integers $k$ and $x$ ($1 \le k \le n-1$; $1 \le x \le 10^9$) for the $i$-th query.

### Output

For each query, print one integer — the cost of the graph after the query is performed.

## Example

### Input


```text
10
12 6 12 15 20 8 17 12 15
8
4 10
7 3
6 14
9 9
2 10
3 5
4 11
7 11
```
### Output


```text
126
108
120
108
112
98
98
114
```


#### Tags 

#2300 #NOT OK #data_structures #dp #matrices 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_146_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
